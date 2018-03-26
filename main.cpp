#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include "iqandroidshortcutbadger.h"
#include "iqfirebase.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    IqFirebase appFirebase;
    QObject::connect(&appFirebase, &IqFirebase::messageTokenChanged, &app, [](const QString &token){
        qDebug() << "Reserved token" << token;
    });

    //IqAndroidShortcutBadger::applyCount(2);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QLatin1String("appFirebase"), &appFirebase);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
