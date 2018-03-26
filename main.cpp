#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <QAndroidJniObject>
#include "iqandroidshortcutbadger.h"
#include "iqfirebase.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QLatin1String("appFirebase"), IqFirebase::instance());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
    Java_ru_itquasar_IqFirebaseInstanceIDService_setAppCloudMessagingToken(JNIEnv */*env*/, jobject /*obj*/, jstring token) {
    auto messagingToken = QAndroidJniObject(token).toString();
    qDebug() << "setAppCloudMessagingToken() from C++" << messagingToken;
    IqFirebase::instance()->setMessagingToken(messagingToken);
}

#ifdef __cplusplus
}
#endif
