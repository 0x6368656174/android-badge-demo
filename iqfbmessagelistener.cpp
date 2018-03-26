#include "iqfbmessagelistener.h"
#include <QMap>
#include <QDebug>

IqFbMessageListener::IqFbMessageListener(QObject *parent) : QObject(parent)
{
}

void IqFbMessageListener::OnTokenReceived(const char *token)
{
    emit tokenReserved(QString(token));
}

void IqFbMessageListener::OnMessage(const firebase::messaging::Message &)
{
    qDebug() << "Message reserved";
}
