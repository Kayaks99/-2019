#include "operation.h"
#include <QDebug>

Operation::Operation()
{
    ;
}
Operation::~Operation()
{
    ;
}


QImage Operation::returnGrey(QImage image)//导出灰度图
{
    int height = image.height();
    int width = image.width();
    QImage ret = image;
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i,j);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          int a=(r*30+g*59+b*11)/100;
          ret.setPixel(i,j,qRgb(a,a,a));
         }
    }
    return ret;
}

QImage Operation::returnSampling(QImage image,int n)
{
    int height = image.height()/n;
    int width = image.width()/n;
    QImage ret(width,height,QImage::Format_RGB32);
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i*n,j*n);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          ret.setPixel(i,j,qRgb(r,g,b));
         }
    }
    return ret;
}

int f1(int x, int k)//四舍五入
{
    if(x % k != 0)
    {
        if(x % k > k / 2)
            x = x/k * k + k;
        else {
            x = x - x%k;
        }
    }
    return x;
}
QImage Operation::returnQuanti(QImage image, int n)//量化
{
    int aa = n,m = 256,k = 1;
    while(aa < 8)
    {
        m /= 2;
        k *= 2;//倍数
        aa++;
    }
    int height = image.height();
    int width = image.width();
    QImage ret(width,height,QImage::Format_RGB32);
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i,j);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          r=f1(r,k);
          g=f1(g,k);
          b=f1(b,k);
          ret.setPixel(i,j,qRgb(r,g,b));
         }
    }
    return ret;
}

QImage Operation::returnBitPlane(QImage image, int l)
{
    int height = image.height();
    int width = image.width();
    QImage ret = image;
    //qDebug() << l;
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i,j);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          int a=(r*30+g*59+b*11)/100;
          if((a>>(l-1))&1)
              ret.setPixel(i,j,qRgb(255,255,255));
          else
              ret.setPixel(i,j,qRgb(0,0,0));
         }
    }

    return ret;
}

QImage Operation::returnThreshold(QImage image, int n)
{
    int height = image.height();
    int width = image.width();
    QImage ret = image;
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i,j);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          int a=(r*30+g*59+b*11)/100;
          if(a<n)
              ret.setPixel(i,j,qRgb(255,255,255));
          else
              ret.setPixel(i,j,qRgb(0,0,0));
         }
    }
    return ret;
}

QImage Operation::lineFunction(QImage image,double a, double c)
{
    int height = image.height();
    int width = image.width();
    QImage ret = image;
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i,j);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          r=r*a+c;
          g=g*a+c;
          b=b*a+c;
          ret.setPixel(i,j,qRgb(r,g,b));
         }
    }
    return ret;
}

QImage Operation::unlineFunction(QImage image, double a, double d, double c)
{
    int height = image.height();
    int width = image.width();
    QImage ret = image;
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
          QRgb pixel=image.pixel(i,j);
          int r=qRed(pixel);
          int g=qGreen(pixel);
          int b=qBlue(pixel);
          r=r*r*a+r*d+c;
          g=g*g*a+g*d+c;
          b=b*b*a+b*d+c;
          ret.setPixel(i,j,qRgb(r,g,b));
         }
    }
    return ret;
}

QImage Operation::tradEqual(QImage image)
{
    int height = image.height();
    int width = image.width();
    int size = height * width;
    int grey[256] = {0};
    int equalgrey[256] = {0};
    int ans[256] = {0};
    QImage ret = image;
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
             QRgb pixel=image.pixel(i,j);
             int r=qRed(pixel);
             int g=qGreen(pixel);
             int b=qBlue(pixel);
             int a=(r*30+g*59+b*11)/100;
             grey[a]++;
         }
    }
    equalgrey[0] = grey[0];
    for(int i =1; i<256; i++)
        equalgrey[i] = equalgrey[i-1] + grey[i];
    for(int i = 0; i<256; i++)
        ans[i] = (int)(255 * equalgrey[i] /size + 0.5);//优化算法
    for(int i =0;i<width;i++)
    {
         for(int j=0;j<height;j++)
         {
             QRgb pixel=image.pixel(i,j);
             int r=qRed(pixel);
             int g=qGreen(pixel);
             int b=qBlue(pixel);
             int a=(r*30+g*59+b*11)/100;//变灰度图
             a=ans[a];
             ret.setPixel(i,j,qRgb(a,a,a));
         }
    }
    return ret;
}


QImage Operation::zoom1(QImage img, double xx, double yy)
{
    int w = img.width()*xx;
    int h = img.height()*yy;
    QImage ret(w,h,QImage::Format_RGB32);
    for (int i = 0; i < w; i++)
    {
        //根据水平因子计算在原图中的坐标
        int x = i / xx;
        for (int j = 0; j < h; j++)
        {
            //根据垂直因子计算在原图中的坐标
            int y = j / yy;
            QRgb pixel=img.pixel(x,y);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            ret.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return ret;
}

QImage Operation::zoom2(QImage img, double xx, double yy)
{
    int prew = img.width();
    int preh = img.height();
    int w = img.width()*xx;
    int h = img.height()*yy;
    QImage ret(w,h,QImage::Format_RGB32);
    for (int i = 0; i < w; i++)
    {
        //根据水平因子计算在原图中的坐标
        double x1 = i / xx;
        for (int j = 0; j < h; j++)
        {
            //根据垂直因子计算在原图中的坐标
            double y1 = j / yy;
            int x = int(x1);//左下角坐标
            int y = int(y1);
            double xd = x1 - x;//差值
            double yd = y1 - y;
            x = x > 0 ? x : 0;
            x = x < prew - 1 ? x : prew - 2;
            y = y > 0 ? y : 0;
            y = y < preh - 1 ? y : preh - 2;

            int r=(1 - xd)*(1 - yd)*qRed(img.pixel(x, y))
                    + (1 - xd)*yd*qRed(img.pixel(x, y+1))
                    + xd*(1 - yd)*qRed(img.pixel(x+1, y))
                    + xd*yd*qRed(img.pixel(x+1, y+1));
            int g=(1 - xd)*(1 - yd)*qGreen(img.pixel(x, y))
                    + (1 - xd)*yd*qGreen(img.pixel(x, y+1))
                    + xd*(1 - yd)*qGreen(img.pixel(x+1, y))
                    + xd*yd*qGreen(img.pixel(x+1, y+1));;
            int b=(1 - xd)*(1 - yd)*qBlue(img.pixel(x, y))
                    + (1 - xd)*yd*qBlue(img.pixel(x, y+1))
                    + xd*(1 - yd)*qBlue(img.pixel(x+1, y))
                    + xd*yd*qBlue(img.pixel(x+1, y+1));;
            ret.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return ret;
}

QImage Operation::roll1(QImage img, int xx)
{
    double b = xx/180.0*3.1415926;
    int prew = img.width();
    int preh = img.height();
    int w = abs(prew*cos(b)) + abs(preh*sin(b));
    int h = abs(prew*sin(b)) + abs(preh*cos(b));
    int dx = -0.5*w*cos(b) - 0.5*h*sin(b) +0.5*prew;
    int dy = 0.5*w*sin(b) - 0.5*h*cos(b) +0.5*preh;
    QImage ret(w,h,QImage::Format_RGB32);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            int x = i*cos(b)+j*sin(b);
            int y = -i*sin(b)+j*cos(b);
            if((x <= -dx - 1)||(x >= prew - dx)||(y <= -dy - 1)||(y >= preh - dy)){
                ret.setPixel(i,j,qRgb(255,255,255));
                continue;
            }
            QRgb pixel=img.pixel(x+dx,y+dy);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            ret.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return ret;
}

QImage Operation::roll2(QImage img, int xx)
{
    double b = xx/180.0*3.1415926;
    int prew = img.width();
    int preh = img.height();
    int w = abs(prew*cos(b)) + abs(preh*sin(b));
    int h = abs(prew*sin(b)) + abs(preh*cos(b));
    int dx = -0.5*w*cos(b) - 0.5*h*sin(b) +0.5*prew;
    int dy = 0.5*w*sin(b) - 0.5*h*cos(b) +0.5*preh;
    QImage ret(w,h,QImage::Format_RGB32);
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            double x1 = i*cos(b)+j*sin(b);
            double y1 = -i*sin(b)+j*cos(b);
            int x = int(x1);
            int y = int(y1);
            double xd = abs(x1 - x);//差值
            double yd = abs(y1 - y);
            if((x <= -dx)||(x >= prew - dx - 1)||(y <= -dy)||(y >= preh - dy - 1)){
                ret.setPixel(i,j,qRgb(255,255,255));
                continue;
            }
            x = x + dx;
            y = y + dy;
            int r=(1 - xd)*(1 - yd)*qRed(img.pixel(x, y))
                    + (1 - xd)*yd*qRed(img.pixel(x, y+1))
                    + xd*(1 - yd)*qRed(img.pixel(x+1, y))
                    + xd*yd*qRed(img.pixel(x+1, y+1));
            int g=(1 - xd)*(1 - yd)*qGreen(img.pixel(x, y))
                    + (1 - xd)*yd*qGreen(img.pixel(x, y+1))
                    + xd*(1 - yd)*qGreen(img.pixel(x+1, y))
                    + xd*yd*qGreen(img.pixel(x+1, y+1));;
            int b=(1 - xd)*(1 - yd)*qBlue(img.pixel(x, y))
                    + (1 - xd)*yd*qBlue(img.pixel(x, y+1))
                    + xd*(1 - yd)*qBlue(img.pixel(x+1, y))
                    + xd*yd*qBlue(img.pixel(x+1, y+1));;
            ret.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return ret;
}

QImage Operation::translate(QImage img, int xx, int yy)
{
    int w = img.width();
    int h = img.height();
    QImage ret(w,h,QImage::Format_RGB32);
    for (int i = 0; i < w; i++)
    {
        //根据水平因子计算在原图中的坐标
        int x = i + xx;
        for (int j = 0; j < h; j++)
        {
            //根据垂直因子计算在原图中的坐标
            int y = j + yy;
            if((x < 0)||(x >= w)||(y < 0)||(y >= h)){
                ret.setPixel(i,j,qRgb(255,255,255));
                continue;
            }
            QRgb pixel=img.pixel(x,y);
            int r=qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            ret.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return ret;
}

QImage Operation::transform_256(QImage img)
{
    /*-----------windows 256色颜色索引表----------------------*/
    unsigned char rgb_quad[1024] = {
    0, 0, 0, 0, 0, 0, 128, 0, 0, 128, 0, 0, 0, 128, 128, 0,
    128, 0, 0, 0, 128, 0, 128, 0, 128, 128, 0, 0, 192, 192, 192, 0,
    192, 220, 192, 0, 240, 202, 166, 0, 0, 32, 64, 0, 0, 32, 96, 0,
    0, 32, 128, 0, 0, 32, 160, 0, 0, 32, 192, 0, 0, 32, 224, 0,
    0, 64, 0, 0, 0, 64, 32, 0, 0, 64, 64, 0, 0, 64, 96, 0,
    0, 64, 128, 0, 0, 64, 160, 0, 0, 64, 192, 0, 0, 64, 224, 0,
    0, 96, 0, 0, 0, 96, 32, 0, 0, 96, 64, 0, 0, 96, 96, 0,
    0, 96, 128, 0, 0, 96, 160, 0, 0, 96, 192, 0, 0, 96, 224, 0,
    0, 128, 0, 0, 0, 128, 32, 0, 0, 128, 64, 0, 0, 128, 96, 0,
    0, 128, 128, 0, 0, 128, 160, 0, 0, 128, 192, 0, 0, 128, 224, 0,
    0, 160, 0, 0, 0, 160, 32, 0, 0, 160, 64, 0, 0, 160, 96, 0,
    0, 160, 128, 0, 0, 160, 160, 0, 0, 160, 192, 0, 0, 160, 224, 0,
    0, 192, 0, 0, 0, 192, 32, 0, 0, 192, 64, 0, 0, 192, 96, 0,
    0, 192, 128, 0, 0, 192, 160, 0, 0, 192, 192, 0, 0, 192, 224, 0,
    0, 224, 0, 0, 0, 224, 32, 0, 0, 224, 64, 0, 0, 224, 96, 0,
    0, 224, 128, 0, 0, 224, 160, 0, 0, 224, 192, 0, 0, 224, 224, 0,
    64, 0, 0, 0, 64, 0, 32, 0, 64, 0, 64, 0, 64, 0, 96, 0,
    64, 0, 128, 0, 64, 0, 160, 0, 64, 0, 192, 0, 64, 0, 224, 0,
    64, 32, 0, 0, 64, 32, 32, 0, 64, 32, 64, 0, 64, 32, 96, 0,
    64, 32, 128, 0, 64, 32, 160, 0, 64, 32, 192, 0, 64, 32, 224, 0,
    64, 64, 0, 0, 64, 64, 32, 0, 64, 64, 64, 0, 64, 64, 96, 0,
    64, 64, 128, 0, 64, 64, 160, 0, 64, 64, 192, 0, 64, 64, 224, 0,
    64, 96, 0, 0, 64, 96, 32, 0, 64, 96, 64, 0, 64, 96, 96, 0,
    64, 96, 128, 0, 64, 96, 160, 0, 64, 96, 192, 0, 64, 96, 224, 0,
    64, 128, 0, 0, 64, 128, 32, 0, 64, 128, 64, 0, 64, 128, 96, 0,
    64, 128, 128, 0, 64, 128, 160, 0, 64, 128, 192, 0, 64, 128, 224, 0,
    64, 160, 0, 0, 64, 160, 32, 0, 64, 160, 64, 0, 64, 160, 96, 0,
    64, 160, 128, 0, 64, 160, 160, 0, 64, 160, 192, 0, 64, 160, 224, 0,
    64, 192, 0, 0, 64, 192, 32, 0, 64, 192, 64, 0, 64, 192, 96, 0,
    64, 192, 128, 0, 64, 192, 160, 0, 64, 192, 192, 0, 64, 192, 224, 0,
    64, 224, 0, 0, 64, 224, 32, 0, 64, 224, 64, 0, 64, 224, 96, 0,
    64, 224, 128, 0, 64, 224, 160, 0, 64, 224, 192, 0, 64, 224, 224, 0,
    128, 0, 0, 0, 128, 0, 32, 0, 128, 0, 64, 0, 128, 0, 96, 0,
    128, 0, 128, 0, 128, 0, 160, 0, 128, 0, 192, 0, 128, 0, 224, 0,
    128, 32, 0, 0, 128, 32, 32, 0, 128, 32, 64, 0, 128, 32, 96, 0,
    128, 32, 128, 0, 128, 32, 160, 0, 128, 32, 192, 0, 128, 32, 224, 0,
    128, 64, 0, 0, 128, 64, 32, 0, 128, 64, 64, 0, 128, 64, 96, 0,
    128, 64, 128, 0, 128, 64, 160, 0, 128, 64, 192, 0, 128, 64, 224, 0,
    128, 96, 0, 0, 128, 96, 32, 0, 128, 96, 64, 0, 128, 96, 96, 0,
    128, 96, 128, 0, 128, 96, 160, 0, 128, 96, 192, 0, 128, 96, 224, 0,
    128, 128, 0, 0, 128, 128, 32, 0, 128, 128, 64, 0, 128, 128, 96, 0,
    128, 128, 128, 0, 128, 128, 160, 0, 128, 128, 192, 0, 128, 128, 224, 0,
    128, 160, 0, 0, 128, 160, 32, 0, 128, 160, 64, 0, 128, 160, 96, 0,
    128, 160, 128, 0, 128, 160, 160, 0, 128, 160, 192, 0, 128, 160, 224, 0,
    128, 192, 0, 0, 128, 192, 32, 0, 128, 192, 64, 0, 128, 192, 96, 0,
    128, 192, 128, 0, 128, 192, 160, 0, 128, 192, 192, 0, 128, 192, 224, 0,
    128, 224, 0, 0, 128, 224, 32, 0, 128, 224, 64, 0, 128, 224, 96, 0,
    128, 224, 128, 0, 128, 224, 160, 0, 128, 224, 192, 0, 128, 224, 224, 0,
    192, 0, 0, 0, 192, 0, 32, 0, 192, 0, 64, 0, 192, 0, 96, 0,
    192, 0, 128, 0, 192, 0, 160, 0, 192, 0, 192, 0, 192, 0, 224, 0,
    192, 32, 0, 0, 192, 32, 32, 0, 192, 32, 64, 0, 192, 32, 96, 0,
    192, 32, 128, 0, 192, 32, 160, 0, 192, 32, 192, 0, 192, 32, 224, 0,
    192, 64, 0, 0, 192, 64, 32, 0, 192, 64, 64, 0, 192, 64, 96, 0,
    192, 64, 128, 0, 192, 64, 160, 0, 192, 64, 192, 0, 192, 64, 224, 0,
    192, 96, 0, 0, 192, 96, 32, 0, 192, 96, 64, 0, 192, 96, 96, 0,
    192, 96, 128, 0, 192, 96, 160, 0, 192, 96, 192, 0, 192, 96, 224, 0,
    192, 128, 0, 0, 192, 128, 32, 0, 192, 128, 64, 0, 192, 128, 96, 0,
    192, 128, 128, 0, 192, 128, 160, 0, 192, 128, 192, 0, 192, 128, 224, 0,
    192, 160, 0, 0, 192, 160, 32, 0, 192, 160, 64, 0, 192, 160, 96, 0,
    192, 160, 128, 0, 192, 160, 160, 0, 192, 160, 192, 0, 192, 160, 224, 0,
    192, 192, 0, 0, 192, 192, 32, 0, 192, 192, 64, 0, 192, 192, 96, 0,
    192, 192, 128, 0, 192, 192, 160, 0, 240, 251, 255, 0, 164, 160, 160, 0,
    128, 128, 128, 0, 0, 0, 255, 0, 0, 255, 0, 0, 0, 255, 255, 0,
    255, 0, 0, 0, 255, 0, 255, 0, 255, 255, 0, 0, 255, 255, 255, 0
    };
    QVector<QRgb> colorTable;
    for (int i = 0; i < 256; i++){
        colorTable.push_back(qRgb(rgb_quad[i * 4], rgb_quad[i * 4 + 1],  rgb_quad[i * 4 + 2]));
    }

    QImage ret = img.convertToFormat(QImage::Format_Indexed8, colorTable, Qt::AutoColor);
    return ret;
}
