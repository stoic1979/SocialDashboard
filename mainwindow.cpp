#include <QDebug>
#include <QWebEngineView>

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

    QWebEngineView *view = new QWebEngineView(ui->browserWidget);
    view->load(QUrl("http://qt-project.org/"));
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    qDebug() << "Username: " << ui->teUsername->toPlainText();
    qDebug() << "Password: " << ui->tePassword->toPlainText();
}
