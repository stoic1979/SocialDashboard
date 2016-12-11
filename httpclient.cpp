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

#include "httpclient.h"

#include <QMapIterator>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrlQuery>

HttpClient::HttpClient(QObject *parent): QObject(parent) {}


void HttpClient::TestGetRequest() {
    qDebug() << "[HttpClient] test get request";

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

    QNetworkRequest request(QUrl("http://test-url.com"));
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
