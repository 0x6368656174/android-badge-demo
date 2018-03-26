#ifndef IQFRIEBASE_H
#define IQFRIEBASE_H

#include <QObject>

class IqFirebase: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString messagingToken READ messagingToken NOTIFY messagingTokenChanged)
public:
    static IqFirebase* instance();

    QString messagingToken() const;
    void setMessagingToken(const QString &token);

signals:
    void messagingTokenChanged(const QString &token) const;
};

#endif // IQFRIEBASE_H
