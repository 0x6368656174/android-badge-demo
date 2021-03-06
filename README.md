# android-badge-demo

Приложение, демонстриующее как в можно, используя Qt5, на Android устанавливать цифру рядом с иконкой приложения.

## Установка и сборка

1. Скачайте репозиторий.
2. Соберите и установите проект на мобильное устройство

## Основные принципы работы приложения

Приложение для реализации отображения значка рядом с иконкой использует библиотеку на JAVA 
https://github.com/leolin310148/ShortcutBadger. Для работы этой библиотеки в `build.gradle` нужно добавить следущие строчки:
````
allprojects {
    repositories {
        ...
        mavenCentral() // Подключим репозиторий для ShortcutBadger
        ...
    }
}

dependencies {
    ...
    compile 'me.leolin:ShortcutBadger:1.1.21@aar' // Подключим ShortcutBadger
    ...
}
````

Для работы с данной библиотекой из C++ создан класс [`IqAndroidShortcutBadger`](https://github.com/0x6368656174/android-badge-demo/blob/master/iqandroidshortcutbadger.h), который при помощи `QtAndroidExtras` вызывает
JAVA методы `ShortcutBadger` для установления и удаления цифры рядом с иконкой.

Собраное приложение можно скачать из Google Play по ссылке 
https://play.google.com/store/apps/details?id=ru.itquasar.android_badge_demo

Так же для тестирования приложения создан простая реализация уведомления, использующая Google Firebase Cloud Messaging.
На странице https://android-badge-demo.firebaseapp.com/ можно попробовать отравить приложению на телефоне сообщения. Код
реализации бекенд-логики Firebase расположен в https://github.com/0x6368656174/android-badge-demo-server.
