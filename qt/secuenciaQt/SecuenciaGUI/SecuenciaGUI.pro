#-------------------------------------------------
#
# Project created by QtCreator 2015-08-30T23:56:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SecuenciaGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        juego.cpp \
        secuencia.cpp \
        secuenciapar.cpp \
        secuenciaimpar.cpp \
        secuenciaconsaltos.cpp \
        secjuan.cpp

HEADERS  += mainwindow.h  \
           juego.h \
    secuencia.h \
    secuenciapar.h \
    secuenciaimpar.h\
    secuenciaconsaltos.h \
    secjuan.h

FORMS    += mainwindow.ui
