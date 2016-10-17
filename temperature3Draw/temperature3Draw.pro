#-------------------------------------------------
#
# Project created by QtCreator 2016-10-17T12:28:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = temperature3Draw
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    valuegrid.cpp \
    valuecell.cpp

HEADERS  += mainwindow.h \
    valuegrid.h \
    valuecell.h

FORMS    += mainwindow.ui
