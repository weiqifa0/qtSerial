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
