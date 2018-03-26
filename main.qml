import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    ColumnLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10

        Label {
            text: qsTr("Demo приложение Android Bade Demo")
            wrapMode: Label.WordWrap
            Layout.fillWidth: true
        }

        Label {
            text: qsTr("Данное приложение демонстринует, как реализовать отображение цифор рядом с иконкой Android приложения.")
            wrapMode: Label.WordWrap
            Layout.fillWidth: true
        }

        Label {
            text: qsTr('Откройте во браузере ссылку <a href="https://android-badge-demo.firebaseapp.com/send/')
                  + appFirebase.messageToken + '">https://android-badge-demo.firebaseapp.com/send/' + appFirebase.messageToken
                  + '</a> и попробуйте отправить сообщение.'
            wrapMode: Label.WordWrap
            onLinkActivated: Qt.openUrlExternally(link)
            Layout.fillWidth: true
        }
    }
}
