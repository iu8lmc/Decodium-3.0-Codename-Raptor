import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium

SplitView {
    id: decodePanelRow
    orientation: Qt.Horizontal

    handle: Rectangle {
        implicitWidth: 3
        color: SplitHandle.hovered ? Theme.accent : Theme.border

        Behavior on color {
            ColorAnimation { duration: Theme.animFast }
        }

        // Grip dots
        Column {
            anchors.centerIn: parent
            spacing: 3
            Repeater {
                model: 3
                Rectangle {
                    width: 3; height: 3
                    radius: 1.5
                    color: SplitHandle.hovered ? Theme.accent : Theme.textDim
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }

    // Panel 1 - Period 1
    DecodePanel {
        SplitView.fillWidth: true
        SplitView.minimumWidth: 200
        title: "PERIOD 1"
        model: typeof decodeModelP1 !== "undefined" ? decodeModelP1 : null
    }

    // Panel 2 - Period 2
    DecodePanel {
        SplitView.fillWidth: true
        SplitView.minimumWidth: 200
        title: "PERIOD 2"
        model: typeof decodeModelP2 !== "undefined" ? decodeModelP2 : null
    }

    // Panel 3 - RX Frequency
    DecodePanel {
        SplitView.fillWidth: true
        SplitView.minimumWidth: 200
        title: "RX FREQUENCY"
        model: typeof decodeModelRx !== "undefined" ? decodeModelRx : null
    }
}
