/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *openButton;
    QPushButton *saveButton;
    QScrollArea *screenArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *imageLabel;
    QScrollArea *controlArea;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *buttonsArea;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *showGrey;
    QLabel *sampling;
    QLabel *quantization;
    QSpinBox *quantizationBox;
    QLabel *bitPlane;
    QSpinBox *bitPlaneBox;
    QSpinBox *samplingBox;
    QLabel *threshold;
    QSpinBox *thresholdBox;
    QTextEdit *diagramText;
    QLabel *potFuncLabel;
    QLabel *lineFuncLabel;
    QComboBox *lineFunc;
    QLabel *unlineFuncLabel;
    QComboBox *unlineFunc;
    QPushButton *tradEqual;
    QPushButton *bmp2txt;
    QPushButton *preimg;
    QLabel *zoomLabel;
    QComboBox *zoomType;
    QDoubleSpinBox *zoomSizeX;
    QLabel *zoomLabelX;
    QLabel *zoomLabelY;
    QDoubleSpinBox *zoomSizeY;
    QPushButton *zoomButton;
    QLabel *rollLabel_X;
    QPushButton *rollButton;
    QSpinBox *rollSize;
    QLabel *rollLabel;
    QComboBox *rollType;
    QSpinBox *translationSizeX;
    QLabel *translationLabelX;
    QSpinBox *translationSizeY;
    QPushButton *translationButton;
    QLabel *translationLabel;
    QLabel *translationLabelY;
    QLabel *circle1;
    QLabel *magicLabel;
    QComboBox *magicType;
    QPushButton *showMagic;
    QPushButton *magicBack;
    QPushButton *betterEqual;
    QPushButton *magicButton;
    QLabel *label;
    QComboBox *comboBox;
    QCustomPlot *diagram;
    QLabel *diagramLabel;
    QPushButton *saveChange;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1500, 900);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(230, 800, 93, 28));
        openButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:rgba(100,225,100,100);\n"
"border-style:outset;\n"
"border-width:4px;\n"
"border-radius:10px;\n"
"border-color:rgba(255,255,255,30);}\n"
"QPushButton:pressed{\n"
"background-color:rgba(100,255,100,200);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);}\n"
"QPushButton:hover{\n"
"background-color:rgba(100,255,100,100);\n"
"border-color:rgba(255,255,255,200);\n"
"color:rgba(0,0,0,200);}"));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(780, 800, 93, 28));
        saveButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:rgba(100,225,100,100);\n"
"border-style:outset;\n"
"border-width:4px;\n"
"border-radius:10px;\n"
"border-color:rgba(255,255,255,30);}\n"
"QPushButton:pressed{\n"
"background-color:rgba(100,255,100,200);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);}\n"
"QPushButton:hover{\n"
"background-color:rgba(100,255,100,100);\n"
"border-color:rgba(255,255,255,200);\n"
"color:rgba(0,0,0,200);}"));
        screenArea = new QScrollArea(centralWidget);
        screenArea->setObjectName(QStringLiteral("screenArea"));
        screenArea->setGeometry(QRect(10, 10, 1120, 780));
        screenArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1118, 778));
        imageLabel = new QLabel(scrollAreaWidgetContents);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(0, 0, 1120, 780));
        screenArea->setWidget(scrollAreaWidgetContents);
        controlArea = new QScrollArea(centralWidget);
        controlArea->setObjectName(QStringLiteral("controlArea"));
        controlArea->setGeometry(QRect(1150, 10, 340, 821));
        controlArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 338, 819));
        buttonsArea = new QScrollArea(scrollAreaWidgetContents_2);
        buttonsArea->setObjectName(QStringLiteral("buttonsArea"));
        buttonsArea->setGeometry(QRect(15, 195, 310, 601));
        buttonsArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        buttonsArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, -401, 287, 1000));
        scrollAreaWidgetContents_3->setMinimumSize(QSize(0, 1000));
        showGrey = new QPushButton(scrollAreaWidgetContents_3);
        showGrey->setObjectName(QStringLiteral("showGrey"));
        showGrey->setGeometry(QRect(10, 10, 120, 28));
        showGrey->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:rgba(100,225,100,100);\n"
"border-style:outset;\n"
"border-width:4px;\n"
"border-radius:10px;\n"
"border-color:rgba(255,255,255,30);}\n"
"QPushButton:pressed{\n"
"background-color:rgba(100,255,100,200);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);}\n"
"QPushButton:hover{\n"
"background-color:rgba(100,255,100,100);\n"
"border-color:rgba(255,255,255,200);\n"
"color:rgba(0,0,0,200);}"));
        sampling = new QLabel(scrollAreaWidgetContents_3);
        sampling->setObjectName(QStringLiteral("sampling"));
        sampling->setGeometry(QRect(10, 50, 72, 15));
        quantization = new QLabel(scrollAreaWidgetContents_3);
        quantization->setObjectName(QStringLiteral("quantization"));
        quantization->setGeometry(QRect(160, 50, 72, 15));
        quantizationBox = new QSpinBox(scrollAreaWidgetContents_3);
        quantizationBox->setObjectName(QStringLiteral("quantizationBox"));
        quantizationBox->setGeometry(QRect(230, 45, 46, 22));
        quantizationBox->setMinimum(1);
        quantizationBox->setMaximum(8);
        quantizationBox->setValue(8);
        bitPlane = new QLabel(scrollAreaWidgetContents_3);
        bitPlane->setObjectName(QStringLiteral("bitPlane"));
        bitPlane->setGeometry(QRect(10, 100, 72, 15));
        bitPlaneBox = new QSpinBox(scrollAreaWidgetContents_3);
        bitPlaneBox->setObjectName(QStringLiteral("bitPlaneBox"));
        bitPlaneBox->setGeometry(QRect(70, 95, 46, 22));
        bitPlaneBox->setMinimum(0);
        bitPlaneBox->setMaximum(8);
        bitPlaneBox->setValue(0);
        samplingBox = new QSpinBox(scrollAreaWidgetContents_3);
        samplingBox->setObjectName(QStringLiteral("samplingBox"));
        samplingBox->setGeometry(QRect(70, 45, 46, 22));
        samplingBox->setMinimum(1);
        threshold = new QLabel(scrollAreaWidgetContents_3);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setGeometry(QRect(10, 150, 72, 15));
        thresholdBox = new QSpinBox(scrollAreaWidgetContents_3);
        thresholdBox->setObjectName(QStringLiteral("thresholdBox"));
        thresholdBox->setGeometry(QRect(70, 145, 46, 22));
        thresholdBox->setMaximum(255);
        diagramText = new QTextEdit(scrollAreaWidgetContents_3);
        diagramText->setObjectName(QStringLiteral("diagramText"));
        diagramText->setGeometry(QRect(25, 180, 240, 100));
        potFuncLabel = new QLabel(scrollAreaWidgetContents_3);
        potFuncLabel->setObjectName(QStringLiteral("potFuncLabel"));
        potFuncLabel->setGeometry(QRect(20, 300, 72, 15));
        lineFuncLabel = new QLabel(scrollAreaWidgetContents_3);
        lineFuncLabel->setObjectName(QStringLiteral("lineFuncLabel"));
        lineFuncLabel->setGeometry(QRect(20, 330, 72, 15));
        lineFunc = new QComboBox(scrollAreaWidgetContents_3);
        lineFunc->setObjectName(QStringLiteral("lineFunc"));
        lineFunc->setGeometry(QRect(120, 325, 87, 22));
        unlineFuncLabel = new QLabel(scrollAreaWidgetContents_3);
        unlineFuncLabel->setObjectName(QStringLiteral("unlineFuncLabel"));
        unlineFuncLabel->setGeometry(QRect(20, 360, 90, 15));
        unlineFunc = new QComboBox(scrollAreaWidgetContents_3);
        unlineFunc->setObjectName(QStringLiteral("unlineFunc"));
        unlineFunc->setGeometry(QRect(120, 355, 87, 22));
        tradEqual = new QPushButton(scrollAreaWidgetContents_3);
        tradEqual->setObjectName(QStringLiteral("tradEqual"));
        tradEqual->setGeometry(QRect(20, 390, 101, 28));
        bmp2txt = new QPushButton(scrollAreaWidgetContents_3);
        bmp2txt->setObjectName(QStringLiteral("bmp2txt"));
        bmp2txt->setGeometry(QRect(160, 90, 93, 28));
        preimg = new QPushButton(scrollAreaWidgetContents_3);
        preimg->setObjectName(QStringLiteral("preimg"));
        preimg->setGeometry(QRect(170, 10, 93, 28));
        preimg->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:rgba(100,225,100,100);\n"
"border-style:outset;\n"
"border-width:4px;\n"
"border-radius:10px;\n"
"border-color:rgba(255,255,255,30);}\n"
"QPushButton:pressed{\n"
"background-color:rgba(100,255,255,200);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);}\n"
""));
        preimg->setCheckable(true);
        preimg->setChecked(false);
        preimg->setAutoExclusive(true);
        zoomLabel = new QLabel(scrollAreaWidgetContents_3);
        zoomLabel->setObjectName(QStringLiteral("zoomLabel"));
        zoomLabel->setGeometry(QRect(20, 445, 72, 15));
        zoomType = new QComboBox(scrollAreaWidgetContents_3);
        zoomType->setObjectName(QStringLiteral("zoomType"));
        zoomType->setGeometry(QRect(70, 440, 111, 22));
        zoomSizeX = new QDoubleSpinBox(scrollAreaWidgetContents_3);
        zoomSizeX->setObjectName(QStringLiteral("zoomSizeX"));
        zoomSizeX->setGeometry(QRect(40, 470, 61, 22));
        zoomSizeX->setSingleStep(0.1);
        zoomSizeX->setValue(1);
        zoomLabelX = new QLabel(scrollAreaWidgetContents_3);
        zoomLabelX->setObjectName(QStringLiteral("zoomLabelX"));
        zoomLabelX->setGeometry(QRect(20, 475, 21, 16));
        zoomLabelY = new QLabel(scrollAreaWidgetContents_3);
        zoomLabelY->setObjectName(QStringLiteral("zoomLabelY"));
        zoomLabelY->setGeometry(QRect(110, 475, 21, 16));
        zoomSizeY = new QDoubleSpinBox(scrollAreaWidgetContents_3);
        zoomSizeY->setObjectName(QStringLiteral("zoomSizeY"));
        zoomSizeY->setGeometry(QRect(130, 470, 61, 22));
        zoomSizeY->setSingleStep(0.1);
        zoomSizeY->setValue(1);
        zoomButton = new QPushButton(scrollAreaWidgetContents_3);
        zoomButton->setObjectName(QStringLiteral("zoomButton"));
        zoomButton->setGeometry(QRect(200, 465, 71, 28));
        rollLabel_X = new QLabel(scrollAreaWidgetContents_3);
        rollLabel_X->setObjectName(QStringLiteral("rollLabel_X"));
        rollLabel_X->setGeometry(QRect(20, 550, 31, 16));
        rollButton = new QPushButton(scrollAreaWidgetContents_3);
        rollButton->setObjectName(QStringLiteral("rollButton"));
        rollButton->setGeometry(QRect(150, 540, 71, 28));
        rollSize = new QSpinBox(scrollAreaWidgetContents_3);
        rollSize->setObjectName(QStringLiteral("rollSize"));
        rollSize->setGeometry(QRect(70, 545, 61, 22));
        rollSize->setMaximum(360);
        rollLabel = new QLabel(scrollAreaWidgetContents_3);
        rollLabel->setObjectName(QStringLiteral("rollLabel"));
        rollLabel->setGeometry(QRect(20, 520, 72, 15));
        rollType = new QComboBox(scrollAreaWidgetContents_3);
        rollType->setObjectName(QStringLiteral("rollType"));
        rollType->setGeometry(QRect(70, 515, 111, 22));
        translationSizeX = new QSpinBox(scrollAreaWidgetContents_3);
        translationSizeX->setObjectName(QStringLiteral("translationSizeX"));
        translationSizeX->setGeometry(QRect(40, 615, 61, 22));
        translationLabelX = new QLabel(scrollAreaWidgetContents_3);
        translationLabelX->setObjectName(QStringLiteral("translationLabelX"));
        translationLabelX->setGeometry(QRect(20, 620, 21, 16));
        translationSizeY = new QSpinBox(scrollAreaWidgetContents_3);
        translationSizeY->setObjectName(QStringLiteral("translationSizeY"));
        translationSizeY->setGeometry(QRect(130, 615, 61, 22));
        translationButton = new QPushButton(scrollAreaWidgetContents_3);
        translationButton->setObjectName(QStringLiteral("translationButton"));
        translationButton->setGeometry(QRect(200, 610, 71, 28));
        translationLabel = new QLabel(scrollAreaWidgetContents_3);
        translationLabel->setObjectName(QStringLiteral("translationLabel"));
        translationLabel->setGeometry(QRect(20, 590, 72, 15));
        translationLabelY = new QLabel(scrollAreaWidgetContents_3);
        translationLabelY->setObjectName(QStringLiteral("translationLabelY"));
        translationLabelY->setGeometry(QRect(110, 620, 21, 16));
        circle1 = new QLabel(scrollAreaWidgetContents_3);
        circle1->setObjectName(QStringLiteral("circle1"));
        circle1->setGeometry(QRect(10, 430, 271, 221));
        circle1->setStyleSheet(QLatin1String("border-color:rgb(0, 0, 255);\n"
"border-style:outset;\n"
"border-width:1px;"));
        magicLabel = new QLabel(scrollAreaWidgetContents_3);
        magicLabel->setObjectName(QStringLiteral("magicLabel"));
        magicLabel->setGeometry(QRect(20, 680, 72, 15));
        magicType = new QComboBox(scrollAreaWidgetContents_3);
        magicType->setObjectName(QStringLiteral("magicType"));
        magicType->setGeometry(QRect(110, 675, 141, 22));
        showMagic = new QPushButton(scrollAreaWidgetContents_3);
        showMagic->setObjectName(QStringLiteral("showMagic"));
        showMagic->setGeometry(QRect(40, 710, 93, 28));
        magicBack = new QPushButton(scrollAreaWidgetContents_3);
        magicBack->setObjectName(QStringLiteral("magicBack"));
        magicBack->setGeometry(QRect(160, 710, 93, 28));
        betterEqual = new QPushButton(scrollAreaWidgetContents_3);
        betterEqual->setObjectName(QStringLiteral("betterEqual"));
        betterEqual->setGeometry(QRect(130, 390, 141, 28));
        magicButton = new QPushButton(scrollAreaWidgetContents_3);
        magicButton->setObjectName(QStringLiteral("magicButton"));
        magicButton->setGeometry(QRect(200, 750, 71, 28));
        label = new QLabel(scrollAreaWidgetContents_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 760, 72, 15));
        comboBox = new QComboBox(scrollAreaWidgetContents_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 755, 87, 22));
        buttonsArea->setWidget(scrollAreaWidgetContents_3);
        circle1->raise();
        showGrey->raise();
        sampling->raise();
        quantization->raise();
        quantizationBox->raise();
        bitPlane->raise();
        bitPlaneBox->raise();
        samplingBox->raise();
        threshold->raise();
        thresholdBox->raise();
        diagramText->raise();
        potFuncLabel->raise();
        lineFuncLabel->raise();
        lineFunc->raise();
        unlineFuncLabel->raise();
        unlineFunc->raise();
        tradEqual->raise();
        bmp2txt->raise();
        preimg->raise();
        zoomLabel->raise();
        zoomType->raise();
        zoomSizeX->raise();
        zoomLabelX->raise();
        zoomLabelY->raise();
        zoomSizeY->raise();
        zoomButton->raise();
        rollLabel_X->raise();
        rollButton->raise();
        rollSize->raise();
        rollLabel->raise();
        rollType->raise();
        translationSizeX->raise();
        translationLabelX->raise();
        translationSizeY->raise();
        translationButton->raise();
        translationLabel->raise();
        translationLabelY->raise();
        magicLabel->raise();
        magicType->raise();
        showMagic->raise();
        magicBack->raise();
        betterEqual->raise();
        magicButton->raise();
        label->raise();
        comboBox->raise();
        diagram = new QCustomPlot(scrollAreaWidgetContents_2);
        diagram->setObjectName(QStringLiteral("diagram"));
        diagram->setGeometry(QRect(45, 10, 250, 150));
        diagramLabel = new QLabel(scrollAreaWidgetContents_2);
        diagramLabel->setObjectName(QStringLiteral("diagramLabel"));
        diagramLabel->setGeometry(QRect(130, 170, 100, 15));
        controlArea->setWidget(scrollAreaWidgetContents_2);
        saveChange = new QPushButton(centralWidget);
        saveChange->setObjectName(QStringLiteral("saveChange"));
        saveChange->setGeometry(QRect(500, 800, 93, 28));
        saveChange->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:rgba(100,225,100,100);\n"
"border-style:outset;\n"
"border-width:4px;\n"
"border-radius:10px;\n"
"border-color:rgba(255,255,255,30);}\n"
"QPushButton:pressed{\n"
"background-color:rgba(100,255,100,200);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);}\n"
"QPushButton:hover{\n"
"background-color:rgba(100,255,100,100);\n"
"border-color:rgba(255,255,255,200);\n"
"color:rgba(0,0,0,200);}\n"
""));
        MainWindow->setCentralWidget(centralWidget);
        screenArea->raise();
        controlArea->raise();
        saveChange->raise();
        saveButton->raise();
        openButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1500, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "imgShow", Q_NULLPTR));
        openButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", Q_NULLPTR));
        saveButton->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272\345\233\276\347\211\207", Q_NULLPTR));
        imageLabel->setText(QString());
        showGrey->setText(QApplication::translate("MainWindow", "\350\275\254\344\270\272\347\201\260\345\272\246\345\233\276", Q_NULLPTR));
        sampling->setText(QApplication::translate("MainWindow", "\351\207\207\346\240\267\347\216\2071/", Q_NULLPTR));
        quantization->setText(QApplication::translate("MainWindow", "\351\207\217\345\214\226\347\255\211\347\272\247", Q_NULLPTR));
        bitPlane->setText(QApplication::translate("MainWindow", "\344\275\215\345\271\263\351\235\242", Q_NULLPTR));
        threshold->setText(QApplication::translate("MainWindow", "\351\230\210\345\200\274", Q_NULLPTR));
        potFuncLabel->setText(QApplication::translate("MainWindow", "\347\202\271\350\277\220\347\256\227", Q_NULLPTR));
        lineFuncLabel->setText(QApplication::translate("MainWindow", "\347\272\277\346\200\247\350\277\220\347\256\227", Q_NULLPTR));
        lineFunc->clear();
        lineFunc->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "(NULL)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "y=1.5*x", Q_NULLPTR)
         << QApplication::translate("MainWindow", "y=x+50", Q_NULLPTR)
        );
        unlineFuncLabel->setText(QApplication::translate("MainWindow", "\351\235\236\347\272\277\346\200\247\350\277\220\347\256\227", Q_NULLPTR));
        unlineFunc->clear();
        unlineFunc->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "(NULL)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "A", Q_NULLPTR)
         << QApplication::translate("MainWindow", "B", Q_NULLPTR)
        );
        tradEqual->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", Q_NULLPTR));
        bmp2txt->setText(QApplication::translate("MainWindow", "Bmp2txt", Q_NULLPTR));
        preimg->setText(QApplication::translate("MainWindow", "\345\216\237\345\233\276", Q_NULLPTR));
        zoomLabel->setText(QApplication::translate("MainWindow", "\347\274\251\346\224\276", Q_NULLPTR));
        zoomType->clear();
        zoomType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "(NULL)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\200\350\277\221\351\202\273\345\267\256\345\200\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\214\347\272\277\346\200\247\345\267\256\345\200\274", Q_NULLPTR)
        );
        zoomLabelX->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        zoomLabelY->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        zoomButton->setText(QApplication::translate("MainWindow", "\347\274\251\346\224\276", Q_NULLPTR));
        rollLabel_X->setText(QApplication::translate("MainWindow", "\350\247\222\345\272\246", Q_NULLPTR));
        rollButton->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254", Q_NULLPTR));
        rollLabel->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254", Q_NULLPTR));
        rollType->clear();
        rollType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "(NULL)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\234\200\350\277\221\351\202\273\345\267\256\345\200\274", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\217\214\347\272\277\346\200\247\345\267\256\345\200\274", Q_NULLPTR)
        );
        translationLabelX->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        translationButton->setText(QApplication::translate("MainWindow", "\345\271\263\347\247\273", Q_NULLPTR));
        translationLabel->setText(QApplication::translate("MainWindow", "\345\271\263\347\247\273", Q_NULLPTR));
        translationLabelY->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        circle1->setText(QString());
        magicLabel->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\217\230\346\215\242", Q_NULLPTR));
        magicType->clear();
        magicType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "(NULL)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\202\205\351\207\214\345\217\266\345\217\230\346\215\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\246\273\346\225\243\344\275\231\345\274\246\345\217\230\346\215\242", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\260\217\346\263\242\345\217\230\346\215\242(\344\270\200\347\272\247\357\274\211", Q_NULLPTR)
        );
        showMagic->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\351\242\221\350\260\261\345\233\276", Q_NULLPTR));
        magicBack->setText(QApplication::translate("MainWindow", "\345\217\215\345\217\230\346\215\242\351\207\215\346\236\204", Q_NULLPTR));
        betterEqual->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226(\344\274\230\345\214\226)", Q_NULLPTR));
        magicButton->setText(QApplication::translate("MainWindow", "\345\217\230\345\214\226", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\273\244\346\263\242\347\261\273\345\236\213", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "(NULL)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\275\216\351\200\232", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\253\230\351\200\232", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\270\246\351\200\232", Q_NULLPTR)
        );
        diagramLabel->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        saveChange->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\217\230\345\214\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
