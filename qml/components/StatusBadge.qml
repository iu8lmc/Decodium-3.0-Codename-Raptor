import QtQuick
import Decodium

Rectangle {
    id: badge
    implicitWidth: badgeText.implicitWidth + 16
    implicitHeight: 22
    radius: 11
    color: Qt.rgba(badgeColor.r, badgeColor.g, badgeColor.b, 0.15)
    border.color: Qt.rgba(badgeColor.r, badgeColor.g, badgeColor.b, 0.4)
    border.width: 1

    property string text: "OK"
    property color badgeColor: Theme.accent

    Text {
        id: badgeText
        anchors.centerIn: parent
        text: badge.text
        font.family: Theme.fontFamily
        font.pixelSize: Theme.fontTiny
        font.bold: true
        font.letterSpacing: 0.5
        color: badge.badgeColor
    }
}
