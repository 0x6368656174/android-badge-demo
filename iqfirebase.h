#ifndef IQFRIEBASE_H
#define IQFRIEBASE_H

#include <QAndroidJniEnvironment>
#include <firebase/app.h>
#include <QObject>
#include <memory>
#include "iqfbmessagelistener.h"

class IqFirebase: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString messageToken READ messageToken NOTIFY messageTokenChanged)
public:
    explicit IqFirebase(QObject *parent = nullptr);

    QString messageToken() const;

signals:
    void messageTokenChanged(const QString &token) const;

private:
    std::unique_ptr<QAndroidJniEnvironment> m_jniEnv;
    std::unique_ptr<firebase::App> m_app;
    std::unique_ptr<IqFbMessageListener> m_listener;

    QString m_messageToken;
    void setMessageToken(const QString &token);
};

#endif // IQFRIEBASE_H
