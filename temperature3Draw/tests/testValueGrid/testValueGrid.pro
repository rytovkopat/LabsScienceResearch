#-------------------------------------------------
#
# Project created by QtCreator 2016-10-24T14:02:17
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testvaluegridtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testvaluegridtest.cpp \
    ../../valuegrid.cpp \
    ../../valuecell.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../valuegrid.h \
    ../../valuecell.h
