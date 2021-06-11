import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    visibility: Window.Maximized
    title: qsTr("mdlens")

    Flickable {
        id: flickable
        anchors.fill: parent
        focus: true
        contentWidth: parent.width
        contentHeight: text.height
        flickableDirection: Flickable.VerticalFlick

        Text {
            id: text
            width: parent.width
            text: MD_CONTENT
            wrapMode: Text.WordWrap
            font.pixelSize: 30
            textFormat: Text.MarkdownText
        }

        ScrollBar.vertical: ScrollBar {
            policy: (flickable.contentHeight > flickable.height ?
                    ScrollBar.AlwaysOn : ScrollBar.AlwaysOff)
        }
        Keys.onEscapePressed: Qt.quit();
    }
}
