#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T04:22:24
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SocialDashboard
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp\
           qfilelogger.cpp\
           httpclient.cpp \
    settings.cpp \
    facebookwebview.cpp \
    facebook.cpp

HEADERS  += mainwindow.h\
            qfilelogger.h\
            httpclient.h \
    settings.h \
    facebookwebview.h \
    facebook.h

FORMS    += mainwindow.ui
