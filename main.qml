import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("mdlens")

    ScrollView {
        anchors.fill: parent

        Text {
            text: MD_CONTENT
            textFormat: Text.MarkdownText
        }
    }
}
