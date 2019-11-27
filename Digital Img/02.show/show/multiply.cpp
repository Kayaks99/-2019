#include "multiply.h"
#include <QDebug>
using namespace cv;

QImage Multiply::blurSmooth(QImage img)//取平均值
{
    Mat src  = opencv.QImageToMat(img);
    Mat out;
    blur(src,out,Size(5,5));

    //显示
    QImage ret = opencv.MatToQImage(out);
    return ret;
}

QImage Multiply::medianblurSmooth(QImage img)//取中间值
{
    Mat src  = opencv.QImageToMat(img);
    Mat out;
    medianBlur(src,out,5);

    //显示
    QImage ret = opencv.MatToQImage(out);
    return ret;
}

QImage Multiply::bilateralSmooth(QImage img)//边界保持 取k个与中心像素接近求平均
{
    Mat I  = opencv.QImageToMat(img);
    Mat out,src;
    cvtColor(I,src,CV_RGBA2RGB);
    bilateralFilter(src,out,25,25*2,25/2);

    //显示
    QImage ret = opencv.MatToQImage(out);
    return ret;
}

QImage Multiply::robertsSharpen(QImage img)//局部差分 对角线像素差
{
    Mat srcImage = opencv.QImageToMat(img);
    Mat srcGray;
    cvtColor(srcImage, srcGray, CV_BGR2GRAY);
    //高斯滤波
    //GaussianBlur(srcGray, srcGray, Size(3, 3), 0, 0, BORDER_DEFAULT);
    Mat dstImage = srcGray.clone();
    int nRows = dstImage.rows;
    int nCols = dstImage.cols;
    for (int i = 0; i < nRows - 1; i++){
        for (int j = 0; j < nCols - 1; j++){
            //根据公式计算
            int t1 = (srcGray.at<uchar>(i, j) -
                srcGray.at<uchar>(i + 1, j + 1))*
                (srcGray.at<uchar>(i, j) -
                srcGray.at<uchar>(i + 1, j + 1));
            int t2 = (srcGray.at<uchar>(i+1, j) -
                srcGray.at<uchar>(i , j + 1))*
                (srcGray.at<uchar>(i+1, j) -
                srcGray.at<uchar>(i , j + 1));
            //计算g（x,y）
            dstImage.at<uchar>(i, j) = (uchar)sqrt(t1 + t2);
        }
    }
    return opencv.MatToQImage(dstImage);
}

QImage Multiply::sobelSharpen(QImage img)//梯度幅度
{
    Mat srcImage = opencv.QImageToMat(img);
    Mat blurImage;
    blur(srcImage, blurImage, Size(3, 3));
    Mat srcGray;
    cvtColor(blurImage, srcGray, CV_BGR2GRAY);
    //定义边缘图，水平方向和垂直方向的
    Mat edgeMat, edgeXMat, edgeYMat;
    //求x方向的Sobel边缘
    Sobel(srcGray, edgeXMat, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
    //求y方向的Sobel边缘
    Sobel(srcGray, edgeYMat, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
    //线性变换，转换输入数组元素为8位无符号整形
    convertScaleAbs(edgeXMat, edgeXMat);
    convertScaleAbs(edgeYMat, edgeYMat);
    //x与y方向边缘叠加
    addWeighted(edgeXMat, 0.5, edgeYMat, 0.5, 0, edgeMat);
    return opencv.MatToQImage(edgeMat);
}
//x
//3 3
//1 2 1
//0 0 0
//-1 -2 -1

//y
//3 3
//1 0 -1
//2 0 -2
//1 0 -1

QImage Multiply::laplacianSharpen(QImage img)//求二阶导
{
    Mat srcImage = opencv.QImageToMat(img);
    Mat srcGray;
    cvtColor(srcImage, srcGray, CV_BGR2GRAY);
    //高斯滤波
    GaussianBlur(srcGray, srcGray, Size(3, 3),
        0, 0, BORDER_DEFAULT);
    //拉普拉斯变换
    Mat laplace_result;
    Laplacian(srcGray, laplace_result, CV_16S, 3);
    convertScaleAbs(laplace_result, laplace_result);
    return opencv.MatToQImage(laplace_result);
}
//1 1 1
//1 -8 1
//1 1 1

Mat getkernel(std::vector<int> a)
{
    int m = a[0], n = a[1], k = 2;
    Mat kernel = (Mat_<float>(m, n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   kernel.ptr<float>(i)[j] = a[k];
            k++;}
            //kernel.ptr<float>(i)[j] = 1.0 / (kernel_size*kernel_size);
    }
    return kernel;
}

QImage Multiply::diyKernel(QImage img, std::vector<int> diy)
{
    Mat src = opencv.QImageToMat(img);
    Mat dst;
    Point anchor;
    double delta;
    int ddepth;
    Mat kernel = getkernel(diy);

    anchor = Point(-1, -1);
    delta = 0;
    ddepth = -1;
    //将核设置好之后，使用函数 filter2D 就可以生成滤波器：
    filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);

    cvtColor(dst,dst,CV_RGBA2RGB);
    QImage ret = opencv.MatToQImage(dst);
    return ret;
}

//3 3
//-1 0 1
//-2 0 2
//-1 0 1

QImage Multiply::prewittEdge(QImage img)
{
    Mat src = opencv.QImageToMat(img);
    Mat I;
    cvtColor(src,I,CV_RGB2GRAY);
    float prewittx[9] =
    {
        -1,0,1,
        -1,0,1,
        -1,0,1
    };
    float prewitty[9] =
    {
        1,1,1,
        0,0,0,
        -1,-1,-1
    };
    Mat px=Mat(3,3,CV_32F,prewittx);
    Mat py=Mat(3,3,CV_32F,prewitty);
    Mat dstx=Mat(I.size(),I.type(),I.channels());
    Mat dsty=Mat(I.size(),I.type(),I.channels());
    Mat dst=Mat(I.size(),I.type(),I.channels());
    filter2D(I,dstx,I.depth(),px);
    filter2D(I,dsty,I.depth(),py);
    float tempx,tempy,temp;
    for(int i=0;i<I.rows;i++)
    {
        for(int j=0;j<I.cols;j++)
        {
            tempx=dstx.at<uchar>(i,j);
            tempy=dsty.at<uchar>(i,j);
            temp=sqrt(tempx*tempx+tempy*tempy);
            dst.at<uchar>(i,j)=temp;
        }
    }
    return opencv.MatToQImage(dst);
}

QImage Multiply::edgeTrack(QImage img)
{
    Mat edgeImg;
    Mat grayImg = opencv.QImageToMat(img);
    Canny(grayImg, edgeImg, 50, 100);//梯度图像
    //imshow("000",edgeImg);
    std::vector<Point> edge_t;
    std::vector<std::vector<Point>> edges;
    // 8 neighbors
    const Point directions[8] = { { 0, 1 }, {1,1}, { 1, 0 }, { 1, -1 }, { 0, -1 },  { -1, -1 }, { -1, 0 },{ -1, 1 } };
    int i, j, counts = 0, curr_d = 0;
    for (i = 0; i < edgeImg.rows; i++)
        for (j = 0; j < edgeImg.cols; j++)
        {
            // 起始点及当前点
            Point b_pt = Point(i, j);//当前点
            Point c_pt = Point(i, j);
            // 如果当前点为前景点
            if (255 == edgeImg.at<uchar>(c_pt.x, c_pt.y))
            {
                edge_t.clear();
                bool tra_flag = false;
                edge_t.push_back(c_pt);
                edgeImg.at<uchar>(c_pt.x, c_pt.y) = 0;    // 用过的点直接给设置为0

                // 进行跟踪
                while (!tra_flag)
                {
                    // 循环八次
                    for (counts = 0; counts < 8; counts++)
                    {
                        if (curr_d >= 8)
                        {
                            curr_d -= 8;
                        }
                        if (curr_d < 0)
                        {
                            curr_d += 8;
                        }
                        c_pt = Point(b_pt.x + directions[curr_d].x, b_pt.y + directions[curr_d].y);
                        if ((c_pt.x >= 0) && (c_pt.x < edgeImg.rows) &&
                            (c_pt.y >= 0) && (c_pt.y < edgeImg.cols))
                        {
                            if (255 == edgeImg.at<uchar>(c_pt.x, c_pt.y))
                            {
                                curr_d -= 2;   // 更新当前方向
                                edge_t.push_back(c_pt);
                                edgeImg.at<uchar>(c_pt.x, c_pt.y) = 0;

                                // 更新b_pt:跟踪的root点
                                b_pt.x = c_pt.x;
                                b_pt.y = c_pt.y;

                                break;   // 跳出for循环
                            }
                        }
                        curr_d++;
                    }
                    if (8 == counts )
                    {
                        // 清零
                        curr_d = 0;
                        tra_flag = true;//结束while
                        edges.push_back(edge_t);
                        break;
                    }
                }
            }
        }
    Mat trace_edge = Mat::zeros(edgeImg.rows, edgeImg.cols, CV_8UC1);
    for (i = 0; i < edges.size(); i++)
    {
        // 过滤掉较小的边缘
        if (edges[i].size() > 10)
        {
            for (j = 0; j < edges[i].size(); j++)
            {
                trace_edge.at<uchar>(edges[i][j].x, edges[i][j].y) = 255;
            }
        }
    }
    return opencv.MatToQImage(trace_edge);
}

QImage Multiply::HoughTransform(QImage img)
{
    Mat  src = cv::Mat(img.height(), img.width(), CV_8UC1, (void*)img.constBits(), img.bytesPerLine());
    std::vector<Vec4f>plines;//定义一个存放直线信息的向量
    Mat ret;
    src.convertTo(ret,CV_8UC3);
    HoughLinesP(src, plines, 1, CV_PI / 180, 30, 120, 10);//Hough直线检测API

    //标记出直线
    for (size_t i = 0; i < plines.size(); i++)
    {
        Vec4f point1 = plines[i];
        line(ret, Point(point1[0], point1[1]), Point(point1[2], point1[3]), Scalar(255, 255, 0), 2, LINE_AA);
    }
    return opencv.MatToQImage(ret);
}
double pixelDistance(double u, double v)
{
    return std::sqrt(u*u + v*v);
}
double gaussianCoeff(double u, double v, double d0)
{
    double d = pixelDistance(u, v);
    return 1.0 - std::exp((-d*d) / (2*d0*d0));
}
QImage Multiply::HomoTransform(QImage img)
{
    ///log变换
    //将源图像转为float类型  然后进行log变换
    Mat srcImage = opencv.QImageToMat(img);
    cvtColor(srcImage,srcImage,CV_BGR2GRAY);
    cv::Mat srcFloatImage;
    cv::Mat logImage;
    srcImage.convertTo(srcFloatImage,CV_32FC1);

    cv::log(srcFloatImage+1,logImage);

    ///高通滤波
    //使滤波器的大小（M，N）为偶数来加速FFT计算
    Mat padded;
    logImage.convertTo(padded,CV_32FC1,1.0/255);
    padded.resize(int(padded.rows/2)*2,int(padded.cols/2)*2);

    //傅里叶变换 FFT
    Mat fourierImage;

    dct(padded,fourierImage);

    //imshow("000",fourierImage);
    //构造一个高斯频域高通滤波器
    int sigma = 3;
    cv::Point2f center;
    center.x = fourierImage.rows/2;
    center.y = fourierImage.cols/2;

    cv::Mat gaussFilter = cv::Mat::zeros(fourierImage.rows,fourierImage.cols, CV_32FC1);
    for(int row=0; row<fourierImage.rows; row++)
    {
      for(int col=0; col<fourierImage.cols; col++)
      {
        gaussFilter.at<float>(row,col) = gaussianCoeff(row, col, sigma);
      }
    }

    fourierImage = fourierImage.mul(gaussFilter);

    cv::Mat resultImage;
    cv::idct(fourierImage, resultImage, DFT_INVERSE);

    //imshow("111",resultImage);
    cv::exp(resultImage-1,resultImage);
    resultImage = resultImage * 255;
    Mat dst;
    resultImage.convertTo(dst,CV_8UC3);

    //imshow("dst",dst);
    return opencv.MatToQImage(dst);
}
