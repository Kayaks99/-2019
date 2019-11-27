#-------------------------------------------------
#
# Project created by QtCreator 2019-10-08T11:03:44
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = show
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    operation.cpp \
    qcustomplot.cpp \
    bmp2txt.cpp \
    a2b.cpp \
    opencv.cpp \
    multiply.cpp \
    zip.cpp \
    newzip.cpp \
    painttree.cpp

HEADERS += \
        mainwindow.h \
    operation.h \
    qcustomplot.h \
    bmp2txt.h \
    a2b.h \
    opencv.h \
    multiply.h \
    zip.h \
    newzip.h \
    painttree.h

FORMS += \
        mainwindow.ui

UI_DIR=./UI

INCLUDEPATH += D:\study\Opencv\opencv3.2.0\opencv\build\include
               D:\study\Opencv\opencv3.2.0\opencv\build\include\opencv
               D:\study\Opencv\opencv3.2.0\opencv\build\include\opencv2
LIBS += D:\study\Opencv\opencv3.2.0\build-Qt\lib\libopencv_*.a


# Default rules for deployment.

