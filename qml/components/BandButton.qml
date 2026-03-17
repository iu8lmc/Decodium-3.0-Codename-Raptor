import QtQuick
import QtQuick.Controls
import Decodium

AbstractButton {
    id: bandBtn
    implicitWidth: 48
    implicitHeight: 32

    property string bandName: "20m"
    property bool active: false

    onClicked: {
        if (typeof radio !== "undefined") {
            radio.band = bandName;
        }
    }

    background: Rectangle {
        color: {
            if (bandBtn.active) return Qt.rgba(0, 0.83, 1.0, 0.15);   // accent at 15%
            if (bandBtn.pressed) return Theme.surfaceLight;
            if (bandBtn.hovered) return Theme.surfaceMid;
            return Theme.surface;
        }
        border.color: bandBtn.active ? Theme.accent : Theme.border
        border.width: bandBtn.active ? 1.5 : 1
        radius: Theme.radius

        Behavior on color {
            ColorAnimation { duration: Theme.animFast }
        }
        Behavior on border.color {
            ColorAnimation { duration: Theme.animFast }
        }
    }

    contentItem: Text {
        text: bandBtn.bandName
        font.family: Theme.digitalFont
        font.pixelSize: Theme.fontSmall
        font.bold: bandBtn.active
        color: bandBtn.active ? Theme.accent : Theme.textPrimary
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        Behavior on color {
            ColorAnimation { duration: Theme.animFast }
        }
    }
}
