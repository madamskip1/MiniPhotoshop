#-------------------------------------------------
#
# Project created by QtCreator 2019-05-01T00:35:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiniPhotoshop
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
        brush.cpp \
        displayimagelabel.cpp \
        draw.cpp \
        filter.cpp \
        filterblur.cpp \
        filtergaussblur.cpp \
        image.cpp \
        main.cpp \
        mainwindow.cpp \
        mouse.cpp \
        picker.cpp \
        rubber.cpp

HEADERS += \
        brush.h \
        displayimagelabel.h \
        draw.h \
        filter.h \
        filterblur.h \
        filtergaussblur.h \
        image.h \
        mainwindow.h \
        mouse.h \
        picker.h \
        rubber.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += $$PWD\lib\opencv\include

LIBS += $$PWD\lib\opencv\bin\libopencv_core420.dll
LIBS += $$PWD\lib\opencv\bin\libopencv_highgui420.dll
LIBS += $$PWD\lib\opencv\bin\libopencv_imgcodecs420.dll
LIBS += $$PWD\lib\opencv\bin\libopencv_imgproc420.dll
LIBS += $$PWD\lib\opencv\bin\libopencv_features2d420.dll
LIBS += $$PWD\lib\opencv\bin\libopencv_calib3d420.dll

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
