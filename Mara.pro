#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T08:28:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mara
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../Permutation/Permutation/Permute.cpp

HEADERS  += mainwindow.h \
    ../Permutation/Permutation/Permute.h

FORMS    += mainwindow.ui
