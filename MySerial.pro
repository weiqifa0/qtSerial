#-------------------------------------------------
#
# Project created by QtCreator 2022-01-20T22:04:57
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TARGET = MySerial
TEMPLATE = app


SOURCES += main.cpp\
        serial.cpp \
    uartcore.cpp

HEADERS  += serial.h \
    uartcore.h

FORMS    += serial.ui

TRANSLATIONS += \
    MySerial_zh_CN.ts

DISTFILES += \
        MySerial_zh_CN.qm

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
