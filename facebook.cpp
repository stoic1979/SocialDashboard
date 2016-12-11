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


#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include "facebook.h"

using namespace nsFacebook;

static Facebook *instance;

Facebook::Facebook(QString clientId, QString clientSecret, QObject *parent):
    QObject(parent), clientId(clientId), clientSecret(clientSecret)
{
    oauthUrl = QString("https://www.facebook.com/v2.8/dialog/oauth?client_id=%1&redirect_uri=%2").
            arg(clientId).arg(FB_SUCCESS_URL);
}

Facebook* Facebook::InitializeFacebook(QString clientId, QString clientSecret) {
    if(!instance) {
        instance = new Facebook(clientId, clientSecret);
    }
    return instance;
}

Facebook* Facebook::Instance() {
    return instance;
}

void Facebook::ParseLoginResponse(QString jsonStr) {
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

void Facebook::SetAccessCode(QString code){

    accessCode = code;

    // Note:
    // after setting the access code, the access url gets completed,
    // otheriwse it is not valid
    accessTokenUrl = QString("https://graph.facebook.com/v2.8/oauth/access_token?client_id=%1&redirect_uri=https://www.facebook.com/connect/login_success.html&client_secret=%2&code=%3").
            arg(clientId). arg(clientSecret). arg(code);

}

QString Facebook::ClientId() {
    return clientId;
}

QString Facebook::ClientSecret() {
    return clientSecret;
}

QString Facebook::AccessToken() {
    return accessToken;
}

void Facebook::SetAccessToken(QString accessToken) {
    this->accessToken = accessToken;
}

QUrl Facebook::OAuthUrl() {
    return QUrl(oauthUrl);
}

QUrl Facebook::AccessTokenUrl() {
    return QUrl(accessTokenUrl);
}
