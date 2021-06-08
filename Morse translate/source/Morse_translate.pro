QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    translator.cpp

HEADERS += \
    mainwindow.h \
    translator.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc


win32:{
    VERSION = 1.0.0
    QMAKE_TARGET_COMPANY = ZCorporation
    QMAKE_TARGET_PRODUCT = Morse translate
    QMAKE_TARGET_DESCRIPTION = Instant translator of latin characters to morse code and vice versa.
    QMAKE_TARGET_COPYRIGHT = Dzmitry Zhuk
}

#   icon of execution file from resources file
win32:RC_ICONS = $$PWD/res/img/icon2.ico
