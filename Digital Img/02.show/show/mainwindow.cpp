#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openButton,SIGNAL(clicked(bool)),this,SLOT(openButton_clicked()));
    connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(saveButton_clicked()));
    connect(ui->showGrey,SIGNAL(clicked(bool)),this,SLOT(greyButton_clicked()));
    connect(ui->samplingBox,SIGNAL(valueChanged(int)), this,SLOT(samplingChange()));
    connect(ui->quantizationBox,SIGNAL(valueChanged(int)), this,SLOT(quantizationChange()));
    connect(ui->bitPlaneBox,SIGNAL(valueChanged(int)), this,SLOT(bitPlaneChange()));
    connect(ui->thresholdBox,SIGNAL(valueChanged(int)), this,SLOT(thresholdChange()));
    connect(ui->lineFunc,SIGNAL(currentIndexChanged(QString)),this,SLOT(lineFunc()));
    connect(ui->unlineFunc,SIGNAL(currentIndexChanged(QString)),this,SLOT(unlineFunc()));
    connect(ui->tradEqual,SIGNAL(clicked(bool)),this,SLOT(tradEqualPush()));
    connect(ui->betterEqual,SIGNAL(clicked(bool)),this,SLOT(betterEqualPush()));
    connect(ui->bmp2txt,SIGNAL(clicked(bool)),this,SLOT(bmp2txt()));
    connect(ui->preimg,SIGNAL(clicked(bool)),this,SLOT(preimg_show()));
    connect(ui->saveChange,SIGNAL(clicked(bool)),this,SLOT(saveChange()));
    connect(ui->zoomButton,SIGNAL(clicked(bool)),this,SLOT(zoom()));
    connect(ui->rollButton,SIGNAL(clicked(bool)),this,SLOT(roll()));
    connect(ui->translationButton,SIGNAL(clicked(bool)),this,SLOT(translate()));
    connect(ui->showMagic,SIGNAL(clicked(bool)),this,SLOT(showMagic()));
    connect(ui->magicBack,SIGNAL(clicked(bool)),this,SLOT(magicBack()));
    connect(ui->magicButton,SIGNAL(clicked(bool)),this,SLOT(magicChange()));
    connect(ui->smoothButton,SIGNAL(clicked(bool)),this,SLOT(smooth()));
    connect(ui->sharpenButton,SIGNAL(clicked(bool)),this,SLOT(sharpen()));
    connect(ui->diyButton,SIGNAL(clicked(bool)),this,SLOT(diymultiply()));
    connect(ui->edgeButton,SIGNAL(clicked(bool)),this,SLOT(predge()));
    connect(ui->edgeTrack,SIGNAL(clicked(bool)),this,SLOT(edgeTrack()));
    connect(ui->HoughTransform,SIGNAL(clicked(bool)),this,SLOT(Hough()));

    connect(ui->turning256,SIGNAL(clicked(bool)),this,SLOT(turning256()));
    connect(ui->HomoButton,SIGNAL(clicked(bool)),this,SLOT(homoTransform()));

    connect(ui->enCode,SIGNAL(clicked(bool)),this,SLOT(enCode()));
    connect(ui->deCode,SIGNAL(clicked(bool)),this,SLOT(deCode()));

    ui->diagram->addGraph();
    ui->diagram->xAxis->setRange(0,255);

    flag=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::labelShow(QImage image)
{
    //ui->imageLabel->setScaledContents(true);//图像大小自适应
    ui->imageLabel->setAlignment(Qt::AlignCenter);
    QImage show;
    if(image.width()>1120){
        double bi = 1120.0/image.width();
        show = image.scaled(1120,image.height()*bi);
    }
    else if(image.height()>780){
        double bi = 780.0/image.height();
        show = image.scaled(image.width()*bi,780.0);
    }
    else
        show = image;
    ui->imageLabel->setPixmap(QPixmap::fromImage(show));
}

void MainWindow::preimg_show()
{
    img = preimg;
    labelShow(preimg);
    diagramChange(preimg);
}

void MainWindow::openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),
                                    ".",tr("Image Files (*.png *.jpg *.bmp)"));
    //qDebug()<<"filenames:"<<fileName;
    if(!fileName.isEmpty())
    {
        img.load(fileName);//获得图像
        preimg = img;
        labelShow(img);
        diagramChange(img);
        flag=1;
        w = img.width();
        h = img.height();
        ui->translationSizeX->setMaximum(w);//获得平移数据
        ui->translationSizeX->setMinimum(-w);
        ui->translationSizeY->setMaximum(h);
        ui->translationSizeY->setMinimum(-h);
    }
}
void MainWindow::saveButton_clicked()
{
    QString filename1 = QFileDialog::getSaveFileName(this,tr("Save Image"),"",tr("Images (*.png *.bmp *.jpg)")); //选择路径
    QScreen *screen = QGuiApplication::primaryScreen();
    screen->grabWindow(ui->imageLabel->winId()).save(filename1);

}
void MainWindow::greyButton_clicked()
{
    tmp = op.returnGrey(img);
    img = tmp;
    labelShow(img);
    diagramChange(img);
}

void MainWindow::samplingChange()
{
    int i = ui->samplingBox->value();
    if(i == 1)
        tmp = img;
    else
        tmp = op.returnSampling(img,i);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::quantizationChange()
{
    int i = ui->quantizationBox->value();
    if(i == 8)
        tmp = img;
    else
        tmp = op.returnQuanti(img,i);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::bitPlaneChange()
{
    int i = ui->bitPlaneBox->value();
    if(i == 0)
        tmp = img;
    else
        tmp = op.returnBitPlane(img,i);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::thresholdChange()
{
    int i = ui->thresholdBox->value();
    if(i == 0)
        tmp = img;
    else
        tmp = op.returnThreshold(img,i);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::lineFunc()
{
    int i = ui->lineFunc->currentIndex();
    if(i == 0)
        tmp = img;
    else if(i == 1)
        tmp = op.lineFunction(img,1.5,0);
    else
        tmp = op.lineFunction(img,1,50);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::unlineFunc()
{
    int i = ui->unlineFunc->currentIndex();
    if(i == 0)
        tmp = img;
    else if(i == 1)
        tmp = op.unlineFunction(img,0.004,0,0);//0.004x^2
    else
        tmp = op.unlineFunction(img,-0.004,0,0);//-0.004x^2
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::tradEqualPush()
{
    tmp = op.tradEqual(img);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::betterEqualPush()
{
    tmp = opencv.betterEqual(img);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::bmp2txt()//500*300
{
    if(flag == 0)
        return;
    Bmp2txt *bb = new Bmp2txt(img);
    bb->show();
}

void MainWindow::saveChange()
{
    img = tmp;
}

void MainWindow::zoom()
{
    int ff = ui->zoomType->currentIndex();
    if(ff == 0) return;
    double xx = ui->zoomSizeX->value();
    double yy = ui->zoomSizeY->value();
    if(ff == 1){
        tmp = op.zoom1(img,xx,yy);
    }
    else if(ff == 2){
        tmp = op.zoom2(img,xx,yy);
    }
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::roll()
{
    int ff = ui->rollType->currentIndex();
    if(ff == 0) return;
    double xx = ui->rollSize->value();
    if(ff == 1){
        tmp = op.roll1(img,xx);
    }
    else if(ff == 2){
        tmp = op.roll2(img,xx);
    }
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::translate()
{
    double xx = ui->translationSizeX->value();
    double yy = ui->translationSizeY->value();
    tmp = op.translate(img,xx,yy);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::showMagic()
{
    int ff = ui->magicType->currentIndex();
    if(ff == 0) return;
    if(ff == 1){
        opencv.radioShow1(img);
    }
    else if(ff == 2){
        opencv.radioShow2(img);
    }
    else if(ff == 3){
        opencv.radioShow3(img, 3);
    }
//    labelShow(tmp);
//    diagramChange(tmp);
}

void MainWindow::magicBack()
{
    int ff = ui->magicType->currentIndex();
    if(ff == 0) return;
    if(ff == 1){
        opencv.radioBack1(img);
    }
    else if(ff == 2){
        opencv.radioBack2(img);
    }
    else if(ff == 3){
        opencv.radioBack3(img, 3);
    }
}

void MainWindow::magicChange()
{
    int ff1 = ui->magicType->currentIndex();
    int ff2 = ui->gaussianBox->currentIndex();
    if(ff1 == 0 || ff2 == 0) return;
    if(ff1 == 1){
        if(ff2 == 1)
            opencv.gaussianBlur(img);
        else if(ff2 == 2)
            opencv.gaussianSharpen(img);
        else if(ff2 == 3)
            opencv.gaussianDai(img);
    }
    else if(ff1 == 2){
        opencv.radioBack2(img);
    }
    else if(ff1 == 3){
        opencv.radioBack3(img, 3);
    }
}

void MainWindow::smooth()
{
    int ff = ui->smoothBox->currentIndex();
    if(ff == 0) return;
    if(ff == 1){
        tmp = mul.blurSmooth(img);
    }
    else if(ff == 2){
        tmp = mul.medianblurSmooth(img);
    }
    else if(ff == 3){
        tmp = mul.bilateralSmooth(img);
    }
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::sharpen()
{
    int ff = ui->sharpenBox->currentIndex();
    if(ff == 0) return;
    if(ff == 1){
        tmp = mul.robertsSharpen(img);
    }
    else if(ff == 2){
        tmp = mul.sobelSharpen(img);
    }
    else if(ff == 3){
        tmp = mul.laplacianSharpen(img);
    }
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::diymultiply()
{
    QString src = ui->diyKernel->toPlainText();
    std::string s = src.toStdString();
    int j;
    diy.clear();
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            j = s[i] - '0';
            if(s[i-1] == '-')
                j *= -1;
            diy.push_back(j);
        }
    }
    tmp = mul.diyKernel(img, diy);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::predge()
{
    int ff = ui->edgeBox->currentIndex();
    if(ff == 0) return;
    if(ff == 1){
        tmp = mul.sobelSharpen(img);
    }
    else if(ff == 2){
        tmp = mul.prewittEdge(img);
    }
    else if(ff == 3){
        tmp = mul.laplacianSharpen(img);
    }
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::edgeTrack()
{
    tmp = mul.edgeTrack(img);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::Hough()
{
    tmp = mul.HoughTransform(img);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::enCode()
{
    int ff = ui->codeBox->currentIndex();
    if(ff == 0) return;
    if(ff == 1){
        newzip.image_encode_huffman(img,"test1");
        QMessageBox::about(NULL, "Success", "压缩成功！");
    }
    else if(ff == 2){
        newzip.image_encode_RLC(img,"test2");
        QMessageBox::about(NULL, "Success", "压缩成功");
    }
}

void MainWindow::deCode()
{
    int ff = ui->codeBox->currentIndex();
    if(ff == 0) return;
    if(ff == 1){
        tmp = newzip.image_decode_huffman("test1");
    }
    else if(ff == 2){
        tmp = newzip.image_decode_RLC("test2");
    }
    QDialog *dialog = new QDialog();
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *label = new QLabel();
    label->setPixmap(QPixmap::fromImage(tmp));
    layout->addWidget(label);
    dialog->setLayout(layout);
    dialog->show();
}

void MainWindow::diagramChange(QImage image)//灰度直方图
{
    int width = image.width();
    int height = image.height();
    QVector<double> vecX;
    QVector<double> vecY(256,0);
    QVector<int> pot;
    long sum = 0, n = 0;
    for(int i=0; i<256; i++)
    {
        vecX.append(i);
    }
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i,j);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          int a=(r*30+g*59+b*11)/100;
          sum+=a;
          n++;
          pot.append(a);
          vecY[a]=vecY.at(a) + 1;
         }
    }
    double yMax = 0;
    for(int j = 0; j < 256 ; j++)
    {
        if(yMax < vecY.at(j))
            yMax = vecY.at(j);
    }
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::black);
    ui->diagram->graph()->setPen(pen);
    ui->diagram->yAxis->setRange(0,yMax);
    ui->diagram->graph()->setData(vecX,vecY);
    ui->diagram->graph()->setBrush(QBrush(QColor(0,0,0,150)));
    ui->diagram->replot();

    double aLevel = sum/n;
    qSort(pot.begin(),pot.end());
    long s = 0;
    for(int i=0; i<n; i++)
    {
        if(pot.at(i) < aLevel)
            s += (aLevel - pot.at(i)) * (aLevel - pot.at(i));
        else
            s += (pot.at(i) - aLevel) * (pot.at(i) - aLevel);
    }
    s /= n;
    ui->diagramText->setText("");
    ui->diagramText->append("平均灰度："+QString::number(aLevel,10,2));
    ui->diagramText->append("中值灰度："+QString::number(pot.at(n/2),10));
    ui->diagramText->append("标准差："+QString::number(sqrt(s),10,2));
    ui->diagramText->append("像素总数："+QString::number(width,10)+" * "+QString::number(height,10)+" = "+QString::number(n,10));

}

void MainWindow::turning256()
{
    tmp = op.transform_256(img);
    labelShow(tmp);
    diagramChange(tmp);
}

void MainWindow::homoTransform()
{
    tmp = mul.HomoTransform(img);
    labelShow(tmp);
    diagramChange(tmp);
}
