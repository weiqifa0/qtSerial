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
    user_interaction.cpp \
    uart_setting.cpp \
    uart_core.cpp

HEADERS  += \
    uart_core.h \
    uart_setting.h \
    uart_interaction.h

FORMS    += \
    uart_interface.ui \
    uart_setting.ui

TRANSLATIONS += \
    MySerial_zh_CN.ts

DISTFILES += \
        MySerial_zh_CN.qm

RC_FILE = logo.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
