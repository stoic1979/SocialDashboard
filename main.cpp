/*
 *  This file is part of SocialDashboard.
 *
 *  SocialDashboard is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SocialDashboard is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SocialDashboard.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *  ------------------------------------------------------------------------------
 *     About: This SDK is under development by Weavebytes Infotech Pvt Ltd, India
 *    Author: Navjot Singh
 *   Website: www.weavebytes.com
 *  ------------------------------------------------------------------------------
 */

#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // showing splash
    QPixmap pixmap(":images/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    splash.showMessage("Loading Please Wait...");

    app.processEvents();

    // showing main window
    MainWindow w;
    w.show();

    // hiding splash
    splash.hide();

    return app.exec();
}
