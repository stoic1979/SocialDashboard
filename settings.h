#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

class Settings: public QSettings
{
public:
    Settings();

    QString FacebookClientId();
    QString FacebookClientSecret();
};

#endif // SETTINGS_H
