#include <QDebug>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QSettings>

#include "mainwindow.h"
#include "ui_mainwindow.h"
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

#include "qfilelogger.h"

using namespace logger;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFileLogger::CreateLogger(QString("logs.txt"), DEBUG);
    QFileLogger::Instance()->Debug("debug");
    QFileLogger::Instance()->Info("info");
    QFileLogger::Instance()->Warning("warning");
    QFileLogger::Instance()->Critical("critical");
    QFileLogger::Instance()->Error("error");

    facebook  = Facebook::InitializeFacebook(settings.FacebookClientId(), settings.FacebookClientSecret());
    fbWebView = new FacebookWebView(ui->browserWidget);


    connect(FB, SIGNAL(GotFacebookAccessToken(bool, QString)),
            this, SLOT( GotFacebookAccessToken(bool, QString) )
                        );

    statusBar()->showMessage(tr("Ready"));
}

MainWindow::~MainWindow()
{
    delete fbWebView;
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    statusBar()->showMessage(tr("Logging to facebook"));
    fbWebView->LoginAndGetAccessToken();
}

void MainWindow::GotFacebookAccessToken(bool error, QString jsonStr) {
    qDebug() << "[MainWindow] GotFacebookAccessToken :: " << jsonStr;

    //FIXME - check error and work accordingly, http code and tidy up !!!!
    if(error) {
        qDebug() << "[MainWindow] got error in getting facebook token";
        return;
    }

}
