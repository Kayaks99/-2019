#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <QTimer>
#include <QMessageBox>
#include <QScreen>
#include <QGuiApplication>
#include <QtAlgorithms>
#include <QPainter>
#include "operation.h"
#include "bmp2txt.h"
#include "opencv.h"
#include "multiply.h"
#include "zip.h"
#include "newzip.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openButton_clicked();
    void saveButton_clicked();
    void greyButton_clicked();
    void preimg_show();
    void samplingChange();
    void quantizationChange();
    void bitPlaneChange();
    void thresholdChange();
    void diagramChange(QImage image);
    void lineFunc();
    void unlineFunc();
    void tradEqualPush();
    void betterEqualPush();//优化
    void bmp2txt();
    void saveChange();
    void zoom();//缩放
    void roll();//旋转
    void translate();//平移
    void showMagic();//显示频谱图
    void magicBack();//反变换重构
    void magicChange();//滤波器变换
    void smooth();//平滑
    void sharpen();//锐化
    void diymultiply();
    void predge();//边缘检测
    void edgeTrack();//边缘跟踪
    void Hough();//霍夫变换

    void enCode();
    void deCode();

    void turning256();
    void homoTransform();

private:
    Ui::MainWindow *ui;
    QImage img;
    QImage tmp;
    QImage preimg;
    QImage saveimg;
    Operation op;
    Opencv opencv;
    Multiply mul;
    Zip zip;
    Image_Code newzip;
    int flag;
    std::vector<int> diy;//自定义模板

    int w;
    int h;

    void labelShow(QImage);

};

#endif // MAINWINDOW_H
