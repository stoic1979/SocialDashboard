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
    HttpClient(QString url, QObject *parent=0);

    void TestGetRequest();
    void SendPostRequest(QMap<QString, QString> &params);

public slots:
    void replyFinished(QNetworkReply *reply);

private:
    QString url;
};

#endif // HTTPCLIENT_H
