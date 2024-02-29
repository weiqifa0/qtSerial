QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UI/basicfunc.cpp \
    UI/chartanalize.cpp \
    UI/customformat.cpp \
    UI/portconfig.cpp \
    UI/preference.cpp \
    dataformat.cpp \
    main.cpp \
    serialport.cpp \
    serialportassissant.cpp

HEADERS += \
    UI/basicfunc.h \
    UI/chartanalize.h \
    UI/customformat.h \
    UI/portconfig.h \
    UI/preference.h \
    dataformat.h \
    serialport.h \
    serialportassissant.h

TRANSLATIONS += \
    SerialPortAssissant_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
