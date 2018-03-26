#define SETTING_CLOUD_MESSAGING_TOKEN "cloudMessagingToken"

#include "iqfirebase.h"
#include <QSettings>

IqFirebase* IqFirebase::instance() {
    static IqFirebase* instance = new IqFirebase();
    return instance;
}

QString IqFirebase::messagingToken() const
{
    QSettings settings;
    return settings.value(SETTING_CLOUD_MESSAGING_TOKEN).toString();
}

void IqFirebase::setMessagingToken(const QString &token)
{
    auto old = messagingToken();
    if (old != token) {
        QSettings settings;
        settings.setValue(SETTING_CLOUD_MESSAGING_TOKEN, token);
        emit messagingTokenChanged(token);
    }
}
