#-------------------------------------------------
#
# Project created by QtCreator 2018-03-12T22:22:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET += PLCMonitor
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

LIBS += -Ldll -lws2_32
QT += xml
QT += serialport
QT += charts
QT += widgets
QT += sql
#CONFIG+=qaxcontainer
QT+=axcontainer
SOURCES += \
    main.cpp \
    datamenu.cpp \
    GloableData/gloabledata.cpp \
    tea123.cpp \
    tools.cpp

HEADERS += \
    datamenu.h \
    GloableData/gloabledata.h \
    GloableData/datatype.h \
    macro_define.h \
    tea123.h \
    tools.h

FORMS += \
    datamenu.ui

RESOURCES += \
    mypic.qrc


RC_FILE = monitor_logo.rc


#TARGET = QExcel
#CONFIG   += console
#CONFIG   -= app_bundle






