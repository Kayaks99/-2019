#include "painttree.h"
int refindMinNode(Node* nodes, int length) {
    int index = -1;
    for (int i = 0; i < length; i++) {
        if ((index == -1 || nodes[i].count < nodes[index].count) && !nodes[i].removed && nodes[i].count > 0) {
            index = i;
        }
    }
    if (index != -1) {
        nodes[index].removed = 1;
    }
    return index;
}

int rebuildTree(Node* nodes, int* counts) {
    for (int i = 0; i < 256; i++) {
        nodes[i].left = -1;
        nodes[i].right = -1;
        nodes[i].count = counts[i];
        nodes[i].removed = 0;
        nodes[i].id = i;
    }
    int length = 256;

    while (1) {
        int l = refindMinNode(nodes, length);
        if (l == -1) {
            break;
        }
        int r = refindMinNode(nodes, length);
        if (r == -1) {
            break;
        }
        nodes[length].left = l;
        nodes[length].right = r;
        nodes[length].count = nodes[l].count + nodes[r].count;
        nodes[length].removed = 0;
        nodes[length].id = -1;
        length++;
    }
    return length;
}

Tree::Tree(QImage oimg, QWidget *parent):
    QDialog(parent)
{
    int counts[256];
    memset(counts,0,sizeof(int)*256);
    QColor color;
    for(int i=0 ; i<oimg.width() ; i++)
        for(int j=0 ; j<oimg.height() ; j++)
        {
            color=QColor(oimg.pixel(i,j));
            int average=(color.red()*30+color.green()*59+color.blue()*11)/100;
            counts[average]++;
        }
    length=rebuildTree(nodes,counts);//树大小
    setMaximumSize(3000,500);
    //resize(3000,500);
}

Tree::~Tree()
{
    ;
}

void Tree::paintEvent(QPaintEvent *event)//10.17改
{
    QPainter painter(this);

    qDebug()<<length;
    nodes[length-1].idx=1;
    nodes[length-1].idy=1;
    int total=0;
    for(int i=length-1;i>=256;i--)//将哈夫曼树与完全二叉树对应起来
    {
        nodes[nodes[i].left].idx=2*nodes[i].idx;
        nodes[nodes[i].right].idx=2*nodes[i].idx+1;
        nodes[nodes[i].left].idy=2*nodes[i].idy;
        nodes[nodes[i].right].idy=2*nodes[i].idy+1;
    }
    int k;
    for(int i=0;i<=255;i++)//求出每个i叶子节点的idx排序
    {
        k=1;
        for(int j=0;j<256;j++)
        {
            if(nodes[j].idx<nodes[i].idx)k++;
        }
        nodes[i].p.x=k*30;//根据叶子节点的idx排序求出叶子节点的x坐标
    }

    for(int i=256;i<length;i++)//根据叶子节点求出双亲的x坐标
    {
        nodes[i].p.x=(nodes[nodes[i].left].p.x+
               nodes[nodes[i].right].p.x)/2;
    }
    for(int i=0;i<length;i++)
    nodes[i].p.y=20*int(log10(nodes[i].idy)/log10(2));//根据节点的层数求出节点的y坐标
    for(int i=0;i<length;i++)
    {
        if(nodes[i].id==-1)
            painter.drawText(nodes[i].p.x,nodes[i].p.y,"#");
        else
            painter.drawText(nodes[i].p.x,nodes[i].p.y,QString::number(nodes[i].id));
    }
}
