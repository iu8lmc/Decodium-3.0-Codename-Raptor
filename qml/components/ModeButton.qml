import QtQuick
import QtQuick.Controls
import Decodium

AbstractButton {
    id: modeBtn
    implicitWidth: 64
    implicitHeight: 36

    property string modeName: "FT8"
    property bool active: false

    onClicked: {
        if (typeof radio !== "undefined") {
            radio.mode = modeName;
        }
    }

    background: Rectangle {
        color: {
            if (modeBtn.active) return Qt.rgba(0, 0.83, 1.0, 0.15);
            if (modeBtn.pressed) return Theme.surfaceLight;
            if (modeBtn.hovered) return Theme.surfaceMid;
            return Theme.surface;
        }
        border.color: modeBtn.active ? Theme.accent : Theme.border
        border.width: modeBtn.active ? 2 : 1
        radius: Theme.radius

        Behavior on color {
            ColorAnimation { duration: Theme.animFast }
        }
        Behavior on border.color {
            ColorAnimation { duration: Theme.animFast }
        }
    }

    contentItem: Text {
        text: modeBtn.modeName
        font.family: Theme.fontFamily
        font.pixelSize: Theme.fontNormal
        font.bold: true
        font.letterSpacing: 1
        color: modeBtn.active ? Theme.accent : Theme.textPrimary
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        Behavior on color {
            ColorAnimation { duration: Theme.animFast }
        }
    }
}
