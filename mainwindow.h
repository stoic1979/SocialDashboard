#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "httpclient.h"
#include "settings.h"
#include "facebookwebview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnLogin_clicked();
    void GotFacebookAccessToken(bool error, QString jsonStr);

private:
    Ui::MainWindow *ui;

    FacebookWebView *fbWebView;

    HttpClient httpClient;

    Settings settings;
};

#endif // MAINWINDOW_H
