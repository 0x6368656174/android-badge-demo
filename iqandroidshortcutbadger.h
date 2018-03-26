#ifndef QTSHORTCUTBADGER_H
#define QTSHORTCUTBADGER_H

/**
 * @brief The IqAndroidShortcutBadger class
 *
 * Класс реализующий обертку над Android библиотекой ShortcutBadger
 * (@link https://github.com/leolin310148/ShortcutBadger).
 *
 * Данный класс позволяет устанавливать для иконок android-приложения цифру,
 * которая отображается рядом с иконкой.
 *
 * Для работы с данным классом нужно, чтоб android-приложение было скомпилировано
 * с библиотекой ShortcutBadger, для этого нужно в файл `android/build.gradle`
 * в секцию `allprojects.repositories` добавить `mavenCentral()`, и в секцию
 * `dependencies` добавить `compile 'me.leolin:ShortcutBadger:1.1.21@aar'`.
 *
 * Так же нужно, чтоб проект был собран с поддержкой `QtAndroidExtras`, для этого нужно
 * в `*.pro` в секцию `QT` добавить `androidextras`.
 *
 * Для установки цифры рядом с иконкой, нужно использовать метод @sa applyCount().
 *
 * Для удаления цифры рядом с иконкой, нужн использовать метод @sa removeCount().
 *
 */
class IqAndroidShortcutBadger
{
public:
    /**
     * @brief Добавляет цифру рядом с иконкой
     *
     * @param int count Цифра
     * @return bool `true`, если цифра добавлена
     */
    static bool applyCount(int count);

    /**
     * @brief Удаляет цифру рядом с иконкой
     * @return bool `true`, если цифра удалена
     */
    static bool removeCount();
};

#endif // QTSHORTCUTBADGER_H
