#-------------------------------------------------
#
# Project created by QtCreator 2013-02-26T20:44:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GigaPi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    adjustments.cpp \
    progress.cpp \
    numberedit.cpp \
    editbox.cpp

HEADERS  += mainwindow.h \
    settings.h \
    adjustments.h \
    progress.h \
    numberedit.h \
    editbox.h

FORMS    += \
    settings.ui \
    mainwindow.ui \
    adjustments.ui \
    progress.ui \
    numberedit.ui

symbian: LIBS += -lwiringPi
else:unix|win32: LIBS += -L$$PWD/../wiringPi/wiringPi/ -lwiringPi

INCLUDEPATH += $$PWD/../wiringPi/wiringPi
DEPENDPATH += $$PWD/../wiringPi/wiringPi
