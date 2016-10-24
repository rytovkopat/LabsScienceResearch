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
    valuecell.cpp \
    appexception.cpp \
    accessexception.cpp \
    dataexception.cpp

HEADERS  += mainwindow.h \
    valuegrid.h \
    valuecell.h \
    appexception.h \
    accessexception.h \
    dataexception.h

FORMS    += mainwindow.ui
