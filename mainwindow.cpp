#include <QDebug>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QSettings>

#include "mainwindow.h"
#include "ui_mainwindow.h"
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


    fbWebView = new FacebookWebView(ui->browserWidget, settings.FacebookClientId(), settings.FacebookClientSecret());


    connect(fbWebView, SIGNAL(GotFacebookAccessToken(bool, QString)),
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


    QJsonDocument document = QJsonDocument::fromJson(jsonStr.toLatin1());
        if (!document.isObject()) {
            qDebug() << "ERROR:: Document is not an object";
            return ;
        }
        QJsonObject object = document.object();
        QJsonValue jsonValue = object.value("access_token");
        if (jsonValue.isUndefined()) {
            qDebug() << "Key access_token does not exist";
        }

        QString accessToken = jsonValue.toString();

        qDebug () << "---> acces_token: " << accessToken;



}
