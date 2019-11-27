#include "opencv.h"
#include <QDebug>
using namespace cv;
Opencv::Opencv()
{
}

Opencv::~Opencv()
{
}

cv::Mat Opencv::QImageToMat(QImage image)
{
    Mat mat;
    switch (image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}

QImage Opencv::MatToQImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

void Opencv::radioShow1(QImage img)
{
    Mat src  = QImageToMat(img);
    Mat I;
    cvtColor(src,I,CV_BGR2GRAY);
    //读入图像灰度图


    //Mat padded;                 //以0填充输入图像矩阵
    int m = getOptimalDFTSize(I.rows);
    int n = getOptimalDFTSize(I.cols);

    //填充输入图像I，输入矩阵为padded，上方和左方不做填充处理
    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));


    //padded.convertTo(padded, CV_32F, 1/255.0);
    Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(),CV_32F) };
    //Mat complexI;
    merge(planes, 2, complexI);     //将planes融合合并成一个多通道数组complexI

    dft(complexI, complexI);        //进行傅里叶变换

    //计算幅值，转换到对数尺度(logarithmic scale)
    //=> log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
    split(complexI, planes);        //planes[0] = Re(DFT(I),planes[1] = Im(DFT(I))
                                    //即planes[0]为实部,planes[1]为虚部
    magnitude(planes[0], planes[1], planes[0]);     //planes[0] = magnitude
    magI = planes[0];

    magI += Scalar::all(1);
    log(magI, magI);                //转换到对数尺度(logarithmic scale)

    //如果有奇数行或列，则对频谱进行裁剪
    magI = magI(Rect(0, 0, magI.cols&-2, magI.rows&-2));

    //重新排列傅里叶图像中的象限，使得原点位于图像中心
    int cx = magI.cols / 2;
    int cy = magI.rows / 2;

    Mat q0(magI, Rect(0, 0, cx, cy));       //左上角图像划定ROI区域
    Mat q1(magI, Rect(cx, 0, cx, cy));      //右上角图像
    Mat q2(magI, Rect(0, cy, cx, cy));      //左下角图像
    Mat q3(magI, Rect(cx, cy, cx, cy));     //右下角图像

    //变换左上角和右下角象限
    //Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    //变换右上角和左下角象限
    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    //归一化处理，用0-1之间的浮点数将矩阵变换为可视的图像格式
    normalize(magI, magI, 0, 1, CV_MINMAX);

    //imshow("000", I);
    namedWindow("dft",0);
    resizeWindow("dft", 1120, 780);
    imshow("dft", magI);
}

void Opencv::radioShow2(QImage img)
{
    Mat src =  QImageToMat(img);
    Mat I;
    cvtColor(src,I,CV_BGR2GRAY);
    //读入图像灰度图
    I.convertTo(I,CV_32FC1,1.0/255);

    I.resize(int(I.rows/2)*2,int(I.cols/2)*2);
    //qDebug()<<I.rows<<I.cols;
    //Mat srcDCT;
    dct(I, srcDCT);

    namedWindow("dct",0);
    resizeWindow("dct", 1120, 780);
    imshow("dct", srcDCT);

}

void Opencv::radioShow3(QImage image, int s)
{
    Mat I = QImageToMat(image);
    Mat src;
    cvtColor(I,src,CV_BGR2GRAY);
    //读入图像灰度图
    src.convertTo(I,CV_32FC1,1.0/255);
    Mat full_src(src.rows, src.cols, CV_32FC1);
    Mat dst = src.clone();
    dst.convertTo(dst, CV_32FC1);

    for (int m = 0; m < s; m++)
    {
        dst.convertTo(dst, CV_32FC1);
        Mat wave_src(dst.rows, dst.cols, CV_32FC1);
        //列变换，detail=mean-original
        for (int i = 0; i < wave_src.rows; i++)
        {
            for (int j = 0; j < wave_src.cols/2; j++)
            {
                wave_src.at<float>(i, j) = (dst.at<float>(i, 2 * j) + dst.at<float>(i, 2 * j + 1)) / 2;
                wave_src.at<float>(i, j + wave_src.cols/2) = wave_src.at<float>(i, j) - dst.at<float>(i, 2 * j);
            }
        }
        Mat temp = wave_src.clone();
        for (int i = 0; i < wave_src.rows/2; i++)
        {
            for (int j = 0; j < wave_src.cols / 2; j++)
            {
                wave_src.at<float>(i, j) = (temp.at<float>(2 * i, j) + temp.at<float>(2 * i + 1, j)) / 2;
                wave_src.at<float>(i + wave_src.rows / 2, j) = wave_src.at<float>(i, j) - temp.at<float>(2 * i, j);
            }
        }
        dst.release();
        dst = wave_src(Rect(0, 0, wave_src.cols / 2, wave_src.rows /2));
        wave_src.copyTo(full_src(Rect(0, 0, wave_src.cols, wave_src.rows)));
    }
    wave = full_src.clone();
    namedWindow("wdt",0);
    resizeWindow("wdt", 1120, 780);
    imshow("wdt", wave);
}

void Opencv::radioBack3(QImage img, int level)
{
    Mat original;
    //每一个循环中把一个级数的小波还原
    for (int m = 0; m < level; m++)
    {
        Mat temp = wave(Rect(0, 0, wave.cols / pow(2, level - m-1), wave.rows / pow(2, level - m-1)));

        //先恢复左边
        Mat recover_src(temp.rows, temp.cols, CV_32FC1);
        for (int i = 0; i < recover_src.rows; i++)
        {
            for (int j = 0; j < recover_src.cols/2; j++)
            {
                if (i % 2 == 0)
                    recover_src.at<float>(i, j) = temp.at <float>(i / 2, j) - temp.at<float>(i / 2 + recover_src.rows / 2, j);
                else
                    recover_src.at<float>(i, j) = temp.at <float>(i / 2, j)+ temp.at<float>(i / 2 + recover_src.rows / 2, j);
            }
        }
        Mat temp2 = recover_src.clone();
        //再恢复整个
        for (int i = 0; i < recover_src.rows; i++)
        {
            for (int j = 0; j < recover_src.cols; j++)
            {
                if (j % 2 == 0)
                    recover_src.at<float>(i, j) = temp2.at<float>(i, j / 2) - temp.at<float>(i, j / 2 + temp.cols / 2);
                else
                    recover_src.at<float>(i, j) = temp2.at<float>(i, j / 2) + temp.at<float>(i, j / 2 + temp.cols / 2);
            }
        }
        recover_src.copyTo(temp);
    }
    original = wave.clone();
    original.convertTo(original, CV_8UC1);
    namedWindow("iwdt",0);
    resizeWindow("iwdt", 1120, 780);
    imshow("iwdt", original);
}

void Opencv::radioBack1(QImage img)
{
    Mat invDFT,invDFTcvt;
    idft(complexI, invDFT, DFT_SCALE | DFT_REAL_OUTPUT );//离散傅立叶逆变换
    invDFT.convertTo(invDFTcvt, CV_8U);
    namedWindow("idft",0);
    resizeWindow("idft", 1120, 780);
    imshow("idft", invDFTcvt);
}

void Opencv::radioBack2(QImage img)
{
    Mat I;
    idct(srcDCT, I);

    namedWindow("idct",0);
    resizeWindow("idct", 1120, 780);
    imshow("idct", I);

}

QImage Opencv::betterEqual(QImage image)//限制对比度自适应直方图均衡
{
    Mat I = QImageToMat(image);
    Mat src;
    cvtColor(I,src,CV_BGR2GRAY);
    //读入图像灰度图
    //创建CLAHE分块
    Ptr<cv::CLAHE> clahe = createCLAHE(2.0);
    //执行CLAHE均衡化
    Mat res_clahe;
    clahe->apply(src,res_clahe);
    //imshow("res_clahe", res_clahe);
    QImage ret = MatToQImage(res_clahe);
    return ret;
}

void Opencv::gaussianBlur(QImage image)
{
    //高斯低通滤波函数（中间高两边低）
    Mat gaussianBlur(padded.size(),CV_32FC2);
    //高斯高通滤波函数（中间低两边高）
    Mat gaussianSharpen(padded.size(),CV_32FC2);
    double D0=2*10*10*10;
    for(int i=0;i<padded.rows;i++)
    {
        float*p=gaussianBlur.ptr<float>(i);
        float*q=gaussianSharpen.ptr<float>(i);
        for(int j=0;j<padded.cols;j++)
        {
            double d=pow(i-padded.rows/2,2)+pow(j-padded.cols/2,2);
            p[2*j]=expf(-d/D0);
            p[2*j+1]=expf(-d/D0);

            q[2*j]=1-expf(-d/D0);
            q[2*j+1]=1-expf(-d/D0);
        }
    }
    //将实部和虚部按照频谱图的方式换位
    //低频在图像中心，用于滤波
    Mat matArray[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat cc = complexI;
    split(cc, matArray);

    int colToCut = magI.cols/2;
    int rowToCut = magI.rows/2;

    //matArray[0]表示DFT的实部
    Mat q1(matArray[0], Rect(0, 0, colToCut, rowToCut));
    Mat q2(matArray[0], Rect(colToCut, 0, colToCut, rowToCut));
    Mat q3(matArray[0], Rect(0, rowToCut, colToCut, rowToCut));
    Mat q4(matArray[0], Rect(colToCut, rowToCut, colToCut, rowToCut));

    //第二象限和第四象限进行交换
    q1.copyTo(tmp);
    q4.copyTo(q1);
    tmp.copyTo(q4);

    //第一象限和第三象限进行交换
    q2.copyTo(tmp);
    q3.copyTo(q2);
    tmp.copyTo(q3);

    //matArray[1]表示DFT的虚部
    Mat qq1(matArray[1], Rect(0, 0, colToCut, rowToCut));
    Mat qq2(matArray[1], Rect(colToCut, 0, colToCut, rowToCut));
    Mat qq3(matArray[1], Rect(0, rowToCut, colToCut, rowToCut));
    Mat qq4(matArray[1], Rect(colToCut, rowToCut, colToCut, rowToCut));

    //第二象限和第四象限进行交换
    qq1.copyTo(tmp);
    qq4.copyTo(qq1);
    tmp.copyTo(qq4);

    //第一象限和第三象限进行交换
    qq2.copyTo(tmp);
    qq3.copyTo(qq2);
    tmp.copyTo(qq3);

    merge(matArray, 2, cc);


    //滤波器和DFT结果相乘（矩阵内积）
    multiply(cc,gaussianBlur,gaussianBlur);
    multiply(cc,gaussianSharpen,gaussianSharpen);

    //IDFT得到滤波结果
    Mat complexIDFT;
    Mat gaussianBlurImg;
    idft(gaussianBlur, complexIDFT);
    split(complexIDFT, matArray);
    magnitude(matArray[0], matArray[1], gaussianBlurImg);
    normalize(gaussianBlurImg, gaussianBlurImg, 0, 1, CV_MINMAX);

    Mat gaussianSharpenImg;
    idft(gaussianSharpen, complexIDFT);
    split(complexIDFT, matArray);
    magnitude(matArray[0], matArray[1], gaussianSharpenImg);
    normalize(gaussianSharpenImg, gaussianSharpenImg, 0, 1, CV_MINMAX);

    imshow("low", gaussianBlurImg);
    savegaussianS = gaussianSharpenImg;
}

void Opencv::gaussianSharpen(QImage image)
{
    imshow("high", savegaussianS);
}

void Opencv::gaussianDai(QImage image)
{
    int d0 = 80, w = 30;
    Mat gaussianDai(padded.size(),CV_32FC2);
    int r = padded.rows;
    int c = padded.cols;
    for(int i = 0;i < r; i++)
        for(int j = 0;j < c;j++)
        {
            int distance = sqrt((i- r / 2)*(i- r / 2) + (j - c / 2)*(j - c / 2));
            //qDebug()<<distance;
            if ((d0-w/2) <= distance && distance <= (d0+w/2)){
                //qDebug()<<"000";
                gaussianDai.at<float>(i, j) = 1.0;
            }
            else{
                //qDebug()<<"111";
                gaussianDai.at<float>(i, j) = 0.0;
            }
        }
//    for(int i=0;i<padded.rows;i++)
//    {
//        float*p=gaussianBlur.ptr<float>(i);
//        float*q=gaussianSharpen.ptr<float>(i);
//        for(int j=0;j<padded.cols;j++)
//        {
//            double d=pow(i-padded.rows/2,2)+pow(j-padded.cols/2,2);
//            p[2*j]=expf(-d/D0);
//            p[2*j+1]=expf(-d/D0);

//            q[2*j]=1-expf(-d/D0);
//            q[2*j+1]=1-expf(-d/D0);
//        }
//    }
    //将实部和虚部按照频谱图的方式换位
    //低频在图像中心，用于滤波
    Mat matArray[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat cc = complexI;
    split(cc, matArray);

    int colToCut = magI.cols/2;
    int rowToCut = magI.rows/2;

    //matArray[0]表示DFT的实部
    Mat q1(matArray[0], Rect(0, 0, colToCut, rowToCut));
    Mat q2(matArray[0], Rect(colToCut, 0, colToCut, rowToCut));
    Mat q3(matArray[0], Rect(0, rowToCut, colToCut, rowToCut));
    Mat q4(matArray[0], Rect(colToCut, rowToCut, colToCut, rowToCut));

    //第二象限和第四象限进行交换
    q1.copyTo(tmp);
    q4.copyTo(q1);
    tmp.copyTo(q4);

    //第一象限和第三象限进行交换
    q2.copyTo(tmp);
    q3.copyTo(q2);
    tmp.copyTo(q3);

    //matArray[1]表示DFT的虚部
    Mat qq1(matArray[1], Rect(0, 0, colToCut, rowToCut));
    Mat qq2(matArray[1], Rect(colToCut, 0, colToCut, rowToCut));
    Mat qq3(matArray[1], Rect(0, rowToCut, colToCut, rowToCut));
    Mat qq4(matArray[1], Rect(colToCut, rowToCut, colToCut, rowToCut));

    //第二象限和第四象限进行交换
    qq1.copyTo(tmp);
    qq4.copyTo(qq1);
    tmp.copyTo(qq4);

    //第一象限和第三象限进行交换
    qq2.copyTo(tmp);
    qq3.copyTo(qq2);
    tmp.copyTo(qq3);

    merge(matArray, 2, cc);


    //滤波器和DFT结果相乘（矩阵内积）
    multiply(cc,gaussianDai,gaussianDai);

    //IDFT得到滤波结果
    Mat complexIDFT;
    Mat gaussianDaiImg;
    idft(gaussianDai, complexIDFT);
    split(complexIDFT, matArray);
    magnitude(matArray[0], matArray[1], gaussianDaiImg);
    normalize(gaussianDaiImg, gaussianDaiImg, 0, 1, CV_MINMAX);

    imshow("Dai", gaussianDaiImg);

}
