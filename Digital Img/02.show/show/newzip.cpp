#include "newzip.h"
#include <QDebug>

using namespace std;
Image_Code::Image_Code()
{

}

//struct Node {
//    int count;//出现次数
//    int left;
//    int right;
//    int removed;
//    int idx;//转为完全二叉树
//    int id;//初始值
//};

int findMinNode(Node* nodes, int length) {
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

int buildTree(Node* nodes, int* counts) {
    for (int i = 0; i < 256; i++) {
        nodes[i].left = -1;
        nodes[i].right = -1;
        nodes[i].count = counts[i];
        nodes[i].removed = 0;
        nodes[i].id = i;
    }
    int length = 256;

    while (1) {
        int l = findMinNode(nodes, length);
        if (l == -1) {
            break;
        }
        int r = findMinNode(nodes, length);
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

void buildTable(Node* nodes, int pos, string bits, string * table) {
    int l = nodes[pos].left;
    int r = nodes[pos].right;
    if (nodes[pos].left == -1 && nodes[pos].right == -1) {
        table[pos] = bits;
        return;
    }
    buildTable(nodes, r, bits + "1", table);
    buildTable(nodes, l, bits + "0", table);
}

void Image_Code::image_encode_huffman(QImage oimg,QString filename)
{
    FILE *fp;
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

    Node nodes[256*2];
    int length=buildTree(nodes,counts);//树大小

    string table[256];
    QString width=QString::number(oimg.width());
    QString height=QString::number(oimg.height());
    buildTable(nodes,length-1,"",table);

    Tree *tt = new Tree(oimg);
    tt->show();


    string table_path=filename.toStdString()+".tab";
    string write_path=filename.toStdString()+".huf";
    fp=fopen(table_path.c_str(),"w");
    fprintf(fp,"%s\n",width.toStdString().c_str());
    fprintf(fp,"%s\n",height.toStdString().c_str());
    for(int i=0 ; i<256; i++)
    {
        if(table[i].size()==0)
        {
            fprintf(fp,"2\n");
        }
        else
        {
            fprintf(fp,"%s\n",table[i].c_str());
        }
    }
    fclose(fp);

    int total_bit_length = 0;
    for (int i = 0; i < 256; i++) {
        total_bit_length += counts[i] * table[i].size();
    }
    fp=fopen(write_path.c_str(),"wb");
    fwrite(&total_bit_length,sizeof(int),1,fp);

    string total="";
    for(int i=0 ; i<oimg.width();i++)
    {
        for(int j=0 ; j<oimg.height();j++)
        {
            color=QColor(oimg.pixel(i,j));
            int average=(color.red()*30+color.green()*59+color.blue()*11)/100;
            for(int k=0 ; k<table[average].size();k++)
            {
                total=total+table[average][k];//
            }
            while(total.size()>=32)
            {
                bitset<32>byte(total.substr(0,32));
                unsigned long tmp=byte.to_ulong();
                fwrite(&tmp,sizeof(unsigned long),1,fp);
                total.erase(0,32);
            }
        }
    }
    int times=total_bit_length/32+1;

    for(int i=0 ; i<32*times-total_bit_length ; i++)
    {
        total=total+"0";
    }

    bitset<32>byte(total.substr(0,32));
    unsigned long tmp=byte.to_ulong();
    fwrite(&tmp,sizeof(unsigned long),1,fp);
    fclose(fp);

}


vector<int> decodeString(string &total, map<string, int> table_map) {
    int cur = 1;
    int head = 0;
    vector<int> s;
    while (cur <= total.size()) {

        if (total[0] != '1' && total[0] != '0') {
            total.erase(0,1);
            cur = 1;
            continue;
        }
        if (table_map.count(total.substr(head, cur - head))) {
            s.push_back(table_map[total.substr(0, cur)]);
            total.erase(0,cur);
            cur = 1;
        } else {
            cur++;
        }
    }
    return s;
}
QImage Image_Code::image_decode_huffman(QString filename)
{
    FILE* fp;
    string table[256];
    string path=filename.toStdString()+".tab";;
    fp=fopen(path.c_str(),"rb");
    char width[30];
    char height[30];
    fscanf(fp,"%s",width);
    fscanf(fp,"%s",height);
    int w=QString::fromUtf8(width).toInt();
    int h=QString::fromUtf8(height).toInt();
    cout<<w;
    cout<<h;
    int table_size_max=0;
    for(int i=0 ; i<256; i++)
    {
        char tmp[256];
        fscanf(fp,"%s",tmp);
        table[i]=table[i]+tmp;
        if(table[i].size()>table_size_max) table_size_max=table[i].size();
    }
    fclose(fp);
    map<string,int> table_map;
    for(int i=0 ; i<256; i++)
    {
        table_map[table[i]]=i;
    }

    string readpath=filename.toStdString()+".huf";
    fp=fopen(readpath.c_str(),"rb");
    int total_bit_length;
    fread(&total_bit_length,sizeof(int),1,fp);
    int times=total_bit_length/32+1;
    string total="";
    unsigned long *words=new unsigned long[times];
    fread(words,sizeof(unsigned long),times,fp);
    vector<int> data;
    for(int i=0 ; i<times ; i++)
    {
        bitset<32>bits(words[i]);
        string tmp=bits.to_string();
        total=total+tmp;
        if(total.size() >= table_size_max)
        {
            vector<int> s=decodeString(total,table_map);
            data.insert(data.end(),s.begin(),s.end());
        }
    }
    vector<int> s=decodeString(total,table_map);
    data.insert(data.end(),s.begin(),s.end());
    fclose(fp);
    QImage img=QImage(w,h,QImage::Format_ARGB32);

    for(int i=0 ; i<w; i++)
        for(int j=0 ; j<h ; j++)
        {
            int average=data[i*w+j];
            img.setPixel(i,j,qRgb(average,average,average));
        }
    return img;
}


void Image_Code::image_encode_RLC(QImage oimg, QString filename)
{

    FILE *opfile = fopen((const char*)filename.toLocal8Bit(),"wb+");
    int height = oimg.height(), width = oimg.width();
    fwrite(&height, sizeof(int), 1, opfile);
    fwrite(&width, sizeof(int), 1, opfile);

    unsigned char data=0, last=0, num=0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data = qRed(oimg.pixel(j, i));
            if ((data != last&&num!=0)|| num>UCHAR_MAX)
            {
                fwrite(&data, 1, 1, opfile);
                fwrite(&num, 1, 1, opfile);
                num=1;//上一种颜色出现次数
            }
            else num++;
            last = data;
        }
    }
    fclose(opfile);
}

QImage Image_Code::image_decode_RLC(QString filename)
{
    FILE *ipfile = fopen((const char*)filename.toLocal8Bit(), "rb");
    int height, width;
    fread(&height, sizeof(int), 1, ipfile);
    fread(&width, sizeof(int), 1, ipfile);
    QImage newImage = QImage(width, height, QImage::Format_ARGB32);
    unsigned char data=0, num=0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (num == 0)
            {
                fread(&data, 1, 1, ipfile);
                fread(&num, 1, 1, ipfile);
            }
            newImage.setPixel(j, i, qRgb((int)data,(int)data,(int)data));
            num--;
        }
    }
    fclose(ipfile);
    return newImage;
}
