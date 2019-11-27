#ifndef BMP2TXT_H
#define BMP2TXT_H

#include <QPushButton>
#include <QDialog>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include <QImage>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QString>
#include <string.h>
class Bmp2txt : public QDialog
{
    Q_OBJECT

public:
    explicit Bmp2txt(QImage img, QWidget *parent = nullptr);
    ~Bmp2txt();
    void paintEvent(QPaintEvent *event);

private slots:


signals:

private:
    int pot[3000][3000];
    int width;
    int height;
    int wbi;
    int hbi;

    QTextEdit *text;

protected:

};

#endif // BMP2TXT_H
