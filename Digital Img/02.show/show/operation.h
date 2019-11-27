#ifndef OPERATION_H
#define OPERATION_H

#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <QTimer>
#include <QMessageBox>
#include <QScreen>
#include <QGuiApplication>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>

class Operation
{

public:
    Operation();
    ~Operation();
    QImage returnGrey(QImage image);
    QImage returnSampling(QImage image,int i);
    QImage returnQuanti(QImage image,int i);
    QImage returnBitPlane(QImage image, int i);
    QImage returnThreshold(QImage image,int i);
    QImage lineFunction(QImage image,double a, double b);
    QImage unlineFunction(QImage image, double a, double b, double c);
    QImage tradEqual(QImage image);
    QImage bmp2txt(QImage image);
    QImage zoom1(QImage image, double x, double y);
    QImage zoom2(QImage image, double x, double y);
    QImage roll1(QImage image, int x);
    QImage roll2(QImage image, int x);
    QImage translate(QImage image, int x, int y);

    QImage transform_256(QImage img);

private slots:


private:
    QImage *img = new QImage;
    QImage *preimg = new QImage;

};

#endif // OPERATION_H
