#-------------------------------------------------
#
# Project created by QtCreator 2012-08-10T12:51:00
#
#-------------------------------------------------
include (../qgoogleauth/qgoogleauth.pro)
QT       += core

QT       -= gui

TARGET = qgoogleauth_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

DEPENDPATH += . ../qgoogleauth/
INCLUDEPATH += . ../qgoogleauth/
