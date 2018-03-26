#include "iqandroidshortcutbadger.h"
#include <QtAndroid>
#include <QAndroidJniObject>

bool IqAndroidShortcutBadger::applyCount(int count)
{
    auto context = QtAndroid::androidContext();
    return QAndroidJniObject::callStaticMethod<jboolean>("me/leolin/shortcutbadger/ShortcutBadger",
                                                         "applyCount",
                                                         "(Landroid/content/Context;I)Z",
                                                         context.object(),
                                                         count);
}

bool IqAndroidShortcutBadger::removeCount()
{
    auto context = QtAndroid::androidContext();
    return QAndroidJniObject::callStaticMethod<jboolean>("me/leolin/shortcutbadger/ShortcutBadger",
                                                         "removeCount",
                                                         "(Landroid/content/Context;)Z",
                                                         context.object());
}
