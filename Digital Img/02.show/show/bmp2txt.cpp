#include "bmp2txt.h"

Bmp2txt::Bmp2txt(QImage image, QWidget *parent) :
    QDialog(parent)
{
    height = image.height();
    width = image.width();
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i,j);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          int a=(r*30+g*59+b*11)/100;
          pot[i][j]=a;
         }
    }
    resize(960,650);
    if(width>120)
    {
        wbi=width/120;
        hbi=height/50;
        width=120;
        height=50;
    }

}

Bmp2txt::~Bmp2txt()
{
    ;
}

void Bmp2txt::paintEvent(QPaintEvent *event)//10.17改
{
    QPainter painter(this);             // 创建QPainter一个对象

    QString c("MNHQ$OC?7>!:–;,. ");
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
             QString str(c[pot[i*wbi][j*hbi]/16]);
             painter.drawText(i*8,j*15,str);
         }
    }
}
