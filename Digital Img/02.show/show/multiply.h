#ifndef MULTIPLY_H
#define MULTIPLY_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <QImage>
#include "opencv.h"

class Multiply
{
public:
    QImage blurSmooth(QImage);//均值滤波
    QImage medianblurSmooth(QImage);//中值滤波
    QImage bilateralSmooth(QImage);//双边
    QImage robertsSharpen(QImage);//Roberts
    QImage sobelSharpen(QImage);
    QImage laplacianSharpen(QImage);
    QImage diyKernel(QImage, std::vector<int>);//自定义卷积核

    QImage prewittEdge(QImage);
    QImage edgeTrack(QImage);
    QImage HoughTransform(QImage);

    QImage HomoTransform(QImage);

private:
    Opencv opencv;

protected:

};


#endif // MULTIPLY_H
