import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium
import "../components" as Components

Rectangle {
    id: txRow
    color: Theme.surface

    property int activeTx: 1

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Theme.marginSmall
        anchors.rightMargin: Theme.marginSmall
        spacing: Theme.spacingSmall

        // TX1 - CQ
        Components.TxButton {
            txNum: 1
            message: typeof tx !== "undefined" && tx.tx1 ? tx.tx1 : "CQ IU8LMC JN70"
            active: txRow.activeTx === 1
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: txRow.activeTx = 1
        }

        // TX2 - Report
        Components.TxButton {
            txNum: 2
            message: typeof tx !== "undefined" && tx.tx2 ? tx.tx2 : "<call> IU8LMC -10"
            active: txRow.activeTx === 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: txRow.activeTx = 2
        }

        // TX3 - R+Report
        Components.TxButton {
            txNum: 3
            message: typeof tx !== "undefined" && tx.tx3 ? tx.tx3 : "<call> IU8LMC R-12"
            active: txRow.activeTx === 3
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: txRow.activeTx = 3
        }

        // TX4 - RR73
        Components.TxButton {
            txNum: 4
            message: typeof tx !== "undefined" && tx.tx4 ? tx.tx4 : "<call> IU8LMC RR73"
            active: txRow.activeTx === 4
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: txRow.activeTx = 4
        }

        // TX5 - 73
        Components.TxButton {
            txNum: 5
            message: typeof tx !== "undefined" && tx.tx5 ? tx.tx5 : "<call> IU8LMC 73"
            active: txRow.activeTx === 5
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: txRow.activeTx = 5
        }

        // TX6 - Free text
        Components.TxButton {
            txNum: 6
            message: typeof tx !== "undefined" && tx.tx6 ? tx.tx6 : "Free msg"
            active: txRow.activeTx === 6
            Layout.fillWidth: true
            Layout.fillHeight: true
            onClicked: txRow.activeTx = 6
        }

        // Separator
        Rectangle {
            Layout.preferredWidth: 1
            Layout.fillHeight: true
            Layout.topMargin: 6
            Layout.bottomMargin: 6
            color: Theme.border
        }

        // CQ Button
        AbstractButton {
            id: cqBtn
            Layout.preferredWidth: 70
            Layout.fillHeight: true
            Layout.topMargin: 4
            Layout.bottomMargin: 4

            onClicked: {
                if (typeof tx !== "undefined") tx.startCQ();
            }

            background: Rectangle {
                color: cqBtn.pressed ? Qt.rgba(0, 0.83, 1.0, 0.2) : Qt.rgba(0, 0.83, 1.0, 0.08)
                border.color: Theme.accent
                border.width: 1.5
                radius: Theme.radius
            }

            contentItem: Text {
                text: "CQ"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontMedium
                font.bold: true
                color: Theme.accent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        // Halt TX button
        AbstractButton {
            id: haltBtn
            Layout.preferredWidth: 80
            Layout.fillHeight: true
            Layout.topMargin: 4
            Layout.bottomMargin: 4

            property bool txActive: typeof tx !== "undefined" ? tx.transmitting : false

            onClicked: {
                if (typeof tx !== "undefined") tx.halt();
            }

            background: Rectangle {
                color: {
                    if (haltBtn.txActive) return Qt.rgba(1, 0.2, 0.2, 0.2);
                    if (haltBtn.pressed) return Qt.rgba(1, 0.2, 0.2, 0.15);
                    return Qt.rgba(1, 0.2, 0.2, 0.05);
                }
                border.color: Theme.alertRed
                border.width: haltBtn.txActive ? 2 : 1
                radius: Theme.radius

                // Blinking border when transmitting
                SequentialAnimation on border.color {
                    running: haltBtn.txActive
                    loops: Animation.Infinite
                    ColorAnimation { to: Theme.alertRed; duration: 500 }
                    ColorAnimation { to: Qt.rgba(1, 0.2, 0.2, 0.3); duration: 500 }
                }
            }

            contentItem: Text {
                text: haltBtn.txActive ? "HALT TX" : "Halt"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontSmall
                font.bold: true
                color: Theme.alertRed
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
