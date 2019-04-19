#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T16:24:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphe
TEMPLATE = app


SOURCES += main.cpp \
    MainWin.cpp \
    WGraphe.cpp \
    sommet.cpp \
    grapheOV.cpp \
    grapheONV.cpp \
    grapheNOV.cpp \
    grapheNONV.cpp \
    graphe.cpp \
    couts.cpp \
    arc.cpp \
    liste.cpp

HEADERS  += \
    MainWin.h \
    WGraphe.h \
    sommet.h \
    grapheOV.h \
    grapheONV.h \
    grapheNOV.h \
    grapheNONV.h \
    graphe.h \
    couts.h \
    arc.h \
    liste.h

FORMS    += mainwindow.ui
