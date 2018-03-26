#include "iqfirebase.h"
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QDebug>

IqFirebase::IqFirebase(QObject *parent):
    QObject(parent),
    m_jniEnv(new QAndroidJniEnvironment()),
    m_app(firebase::App::Create(firebase::AppOptions(), *m_jniEnv, QtAndroid::androidActivity().object())),
    m_listener(new IqFbMessageListener())
{
    firebase::messaging::Initialize(*m_app.get(), m_listener.get());

    connect(m_listener.get(), &IqFbMessageListener::tokenReserved, this, &IqFirebase::setMessageToken);
}

QString IqFirebase::messageToken() const
{
    return m_messageToken;
}

void IqFirebase::setMessageToken(const QString &token)
{
    if (m_messageToken != token) {
        m_messageToken = token;
        emit messageTokenChanged(token);
    }
}
