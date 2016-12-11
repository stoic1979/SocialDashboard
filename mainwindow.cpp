#include <QDebug>


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

    /*

    -----------------------------------------------------------------------------------------------

         Facebook oauth Login

         Refer Docs at:
         https://developers.facebook.com/docs/facebook-login/manually-build-a-login-flow/

    -------------------------------------------------------------------------------------------------


    Invoking the Login Dialog and Setting the Redirect URL

    Your app must initiate a redirect to an endpoint which will display the login dialog:

    https://www.facebook.com/v2.8/dialog/oauth?client_id={app-id}&redirect_uri={redirect-uri}

    This endpoint has the following required parameters:

    - client_id:
      The ID of your app, found in your app's dashboard.

    - redirect_uri:
      The URL that you want to redirect the person logging in back to.
      This URL will capture the response from the Login Dialog.

      If you are using this in a webview within a desktop app,
      this must be set to https://www.facebook.com/connect/login_success.html.
      You can confirm that this URL is set for your app by going to the App Dashboard,
      clicking Facebook Login in the right-hand menu, and checking the Valid OAuth redirect
      URIs in the Client OAuth Settings section.

     */

    webView = new QWebEngineView(ui->browserWidget);
    webView->show();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete webView;
}

void MainWindow::on_btnLogin_clicked()
{
    qDebug() << "Username: " << ui->teUsername->toPlainText();
    qDebug() << "Password: " << ui->tePassword->toPlainText();


    QString fbSuccessUrl = "https://www.facebook.com/connect/login_success.html";
    QString fbOAuthUrl   = "https://www.facebook.com/v2.8/dialog/oauth?client_id=" + ui->teFbClientId->toPlainText() + QString("&redirect_uri=") + fbSuccessUrl;
    qDebug() << "QAuth Url: " << fbOAuthUrl;

    webView->load(QUrl(fbOAuthUrl));


}
