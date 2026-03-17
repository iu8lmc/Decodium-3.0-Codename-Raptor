import QtQuick
import QtQuick.Controls
import Decodium

AbstractButton {
    id: txBtn
    implicitWidth: 180
    implicitHeight: Theme.txRowHeight

    property int txNum: 1
    property string message: ""
    property bool active: false
    property bool transmitting: typeof tx !== "undefined" ? tx.transmitting : false

    onClicked: {
        if (typeof tx !== "undefined") {
            tx.sendMessage(txNum);
        }
    }

    background: Rectangle {
        color: {
            if (txBtn.active && txBtn.transmitting) return Qt.rgba(1, 0.2, 0.2, 0.2);
            if (txBtn.active) return Qt.rgba(0, 0.83, 1.0, 0.12);
            if (txBtn.pressed) return Theme.surfaceLight;
            if (txBtn.hovered) return Theme.surfaceMid;
            return Theme.surface;
        }
        border.color: {
            if (txBtn.active && txBtn.transmitting) return Theme.alertRed;
            if (txBtn.active) return Theme.accent;
            return Theme.border;
        }
        border.width: txBtn.active ? 1.5 : 1
        radius: Theme.radius

        Behavior on color {
            ColorAnimation { duration: Theme.animFast }
        }
        Behavior on border.color {
            ColorAnimation { duration: Theme.animFast }
        }
    }

    contentItem: Row {
        spacing: Theme.spacing
        anchors.verticalCenter: parent.verticalCenter
        leftPadding: Theme.spacing

        // TX number badge
        Rectangle {
            width: 26
            height: 20
            radius: 3
            anchors.verticalCenter: parent.verticalCenter
            color: {
                if (txBtn.active && txBtn.transmitting) return Theme.alertRed;
                if (txBtn.active) return Theme.accent;
                return Theme.surfaceLight;
            }

            Text {
                anchors.centerIn: parent
                text: "T" + txBtn.txNum
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontTiny
                font.bold: true
                color: {
                    if (txBtn.active) return Theme.background;
                    return Theme.textSecondary;
                }
            }
        }

        // TX message text
        Text {
            text: txBtn.message
            font.family: Theme.digitalFont
            font.pixelSize: Theme.fontSmall
            color: {
                if (txBtn.active && txBtn.transmitting) return Theme.alertRed;
                if (txBtn.active) return Theme.accent;
                return Theme.textPrimary;
            }
            elide: Text.ElideRight
            anchors.verticalCenter: parent.verticalCenter
            width: txBtn.width - 50
        }
    }

    // Blinking indicator when transmitting
    Rectangle {
        visible: txBtn.active && txBtn.transmitting
        width: 4
        height: parent.height
        color: Theme.alertRed
        anchors.left: parent.left
        opacity: txBlink.running ? (txBlinkState ? 1.0 : 0.3) : 1.0

        property bool txBlinkState: true
        Timer {
            id: txBlink
            running: txBtn.active && txBtn.transmitting
            interval: 500
            repeat: true
            onTriggered: parent.txBlinkState = !parent.txBlinkState
        }
    }
}
