#include "settings.h"

Settings::Settings() : QSettings("config.ini", QSettings::IniFormat)
{}

QString Settings::FacebookClientId() {
    return value("client_id").toString();

}

QString Settings::FacebookClientSecret() {
    return value("client_secret").toString();
}
