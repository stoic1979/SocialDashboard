#include "httpclient.h"

#include <QMapIterator>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrlQuery>

HttpClient::HttpClient(QString url, QObject *parent): QObject(parent), url(url) {}


void HttpClient::TestGetRequest() {
    qDebug() << "[HttpClient] test get request";

    bool status = true;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    // creating get request
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.google.com")); // test URL for google
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    manager->get(request);
}

/**
 * @brief HttpClient::SendPostRequest
 * @param params a QMap containg post param name and value
 */
void HttpClient::SendPostRequest(QMap<QString, QString> &params) {
    QMapIterator<QString, QString> itr(params);


    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QNetworkRequest request(url);
    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery postData;
    while (itr.hasNext()) {
        itr.next();
        postData.addQueryItem(itr.key(), itr.value());
    }

    connect(manager, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(replyFinished(QNetworkReply *)));

    manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());

    qDebug() << "[HttpClient] sent post request";
}

void HttpClient::replyFinished(QNetworkReply *reply) {
    qDebug() << "[HttpClient] got network reply";

    // Getting the http status code
    int HttpStatusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "[HttpClient] HttpStatusCode: " << HttpStatusCode;

    if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "[HttpClient] replyFinished() Success: \n got content:-\n" << reply->readAll();
            delete reply;
        }
        else {
            qDebug() << "[HttpClient] replyFinished() Failure" << reply->errorString();
            qDebug() << "[HttpClient] reply content:-\n" << reply->readAll();
            delete reply;
        }
}
