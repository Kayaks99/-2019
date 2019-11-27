#ifndef OPENCV_H
#define OPENCV_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <QImage>

class Opencv
{
public:
    explicit Opencv();
    ~Opencv();
    void radioShow1(QImage img);//傅里叶
    void radioShow2(QImage img);//离散余弦
    void radioShow3(QImage img, int s);//小波
    void radioBack1(QImage img);
    void radioBack2(QImage img);
    void radioBack3(QImage img, int s);
    QImage betterEqual(QImage image);
    void gaussianBlur(QImage image);
    void gaussianSharpen(QImage image);
    void gaussianDai(QImage image);

    cv::Mat QImageToMat(QImage image);
    QImage MatToQImage(const cv::Mat& mat);

    cv::Mat savegaussianS;

private:
    cv::Mat complexI;//dft结果
    cv::Mat srcDCT;//dct结果
    cv::Mat wave;
    cv::Mat padded;//dft中间变量
    cv::Mat magI;
    cv::Mat tmp;


protected:

};


#endif // OPENCV_H
