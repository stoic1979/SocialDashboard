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

public slots:
    void replyFinished(QNetworkReply *reply);


};

#endif // HTTPCLIENT_H
