#-----------------------------------------------------------------------------------------
#
#  SocialDashboard is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  SocialDashboard is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with SocialDashboard.  If not, see <http://www.gnu.org/licenses/>.
#
#
#  -------------------------------------------------------------------------------
#      About: This SDK is under development by Weavebytes Infotech Pvt Ltd, India
#     Author: Navjot Singh
#    Website: www.weavebytes.com
#  -------------------------------------------------------------------------------
#
#  Project created by QtCreator 2016-12-11T04:22:24
#
#
#---------------------------------------------------------------------------------

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
