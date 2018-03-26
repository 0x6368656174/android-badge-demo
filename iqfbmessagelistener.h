#ifndef IQFBMESSAGELISTENER_H
#define IQFBMESSAGELISTENER_H

#include <QObject>
#include <firebase/messaging.h>

class IqFbMessageListener :
        public QObject,
        public firebase::messaging::Listener
{
    Q_OBJECT
public:
    explicit IqFbMessageListener(QObject *parent = nullptr);

    virtual void OnTokenReceived(const char *token) override;

    virtual void OnMessage(const firebase::messaging::Message &message) override;

signals:
    void tokenReserved(const QString &token) const;
};

#endif // IQFBMESSAGELISTENER_H
