#ifndef NEWZIP_H
#define NEWZIP_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <QImage>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <malloc.h>
#include <bitset>
#include "painttree.h"

class Image_Code
{
public:
    explicit Image_Code();
    void image_encode_huffman(QImage oimg,QString filename);
    QImage image_decode_huffman(QString filename);
    void image_encode_RLC(QImage oimg, QString filename);
    QImage image_decode_RLC(QString filename);


private:


protected:

};

#endif // NEWZIP_H
