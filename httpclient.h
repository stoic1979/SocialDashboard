#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QMap>
#include <QNetworkReply>

/**
 * @brief The HttpClient class
 * Description:
 * Http Client is used to send http get/post etc requests to server.
 */
class HttpClient: public QObject
{
    Q_OBJECT
public:
    HttpClient(QObject *parent=0);

    void TestGetRequest();

    void GetFacebookAccessToken(QString accessTokenUrl);

    void SendPostRequest(QMap<QString, QString> &params);

 signals:
    void GotFacebookAccessToken(bool error, QString jsonStr);

public slots:
    void replyFinished(QNetworkReply *reply);


};

#endif // HTTPCLIENT_H
