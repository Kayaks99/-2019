#ifndef PAINTTREE_H
#define PAINTTREE_H

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
typedef struct   //坐标数据结构
{double x;
 double y;
}Point;
struct Node {
    int count;//出现次数
    int left;
    int right;
    int removed;
    int idx,idy;//转为完全二叉树
    int id;//初始值
    Point p;
};
class Tree : public QDialog
{
    Q_OBJECT

public:
    explicit Tree(QImage img, QWidget *parent = nullptr);
    ~Tree();
    void paintEvent(QPaintEvent *event);

private slots:


signals:

private:
    Node nodes[256*2];
    int length;

    QTextEdit *text;

protected:

};

#endif // PAINTTREE_H
