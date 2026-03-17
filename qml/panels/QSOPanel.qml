import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium
import "../components" as Components

Rectangle {
    id: qsoPanel
    color: Theme.surface

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Theme.margin
        anchors.rightMargin: Theme.margin
        spacing: Theme.spacing

        // Status badge
        Components.StatusBadge {
            text: {
                if (typeof tx === "undefined") return "IDLE";
                if (tx.transmitting) return "TX";
                if (tx.txEnabled) return "ARMED";
                return "IDLE";
            }
            badgeColor: {
                if (typeof tx === "undefined") return Theme.textDim;
                if (tx.transmitting) return Theme.alertRed;
                if (tx.txEnabled) return Theme.warning;
                return Theme.textDim;
            }
            Layout.alignment: Qt.AlignVCenter
        }

        // Separator
        Rectangle { width: 1; height: 30; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // DX Call
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 1
            Text {
                text: "DX Call"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            TextField {
                id: dxCallField
                width: 100
                height: 24
                text: typeof tx !== "undefined" && tx.hisCall ? tx.hisCall : ""
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                font.bold: true
                color: Theme.accent
                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: Theme.borderLight
                    border.width: 1
                    radius: 2
                }
                onEditingFinished: {
                    if (typeof tx !== "undefined") tx.hisCall = text;
                }
            }
        }

        // DX Grid
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 1
            Text {
                text: "DX Grid"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            TextField {
                id: dxGridField
                width: 60
                height: 24
                text: typeof tx !== "undefined" && tx.hisGrid ? tx.hisGrid : ""
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: Theme.textPrimary
                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: Theme.borderLight
                    border.width: 1
                    radius: 2
                }
                onEditingFinished: {
                    if (typeof tx !== "undefined") tx.hisGrid = text;
                }
            }
        }

        // Separator
        Rectangle { width: 1; height: 30; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // Report Sent
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 1
            Text {
                text: "Sent"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            Text {
                text: typeof tx !== "undefined" && tx.rptSent ? tx.rptSent : "--"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontMedium
                font.bold: true
                color: Theme.activeGreen
            }
        }

        // Report Rcvd
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 1
            Text {
                text: "Rcvd"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            Text {
                text: typeof tx !== "undefined" && tx.rptRcvd ? tx.rptRcvd : "--"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontMedium
                font.bold: true
                color: Theme.accent
            }
        }

        // Separator
        Rectangle { width: 1; height: 30; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // Next message
        Column {
            Layout.alignment: Qt.AlignVCenter
            Layout.fillWidth: true
            spacing: 1
            Text {
                text: "Next"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            Text {
                text: typeof tx !== "undefined" && tx.activeTxMessage ? tx.activeTxMessage : "---"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: (typeof tx !== "undefined" && tx.transmitting) ? Theme.alertRed : Theme.textPrimary
                elide: Text.ElideRight
                width: parent.width
            }
        }

        // Separator
        Rectangle { width: 1; height: 30; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // QSO count
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 1
            Text {
                text: "QSOs"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                text: typeof log !== "undefined" ? String(log.qsoCount) : "0"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontLarge
                font.bold: true
                color: Theme.accent
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        // LOG button
        AbstractButton {
            id: logBtn
            Layout.preferredWidth: 70
            Layout.preferredHeight: 36
            Layout.alignment: Qt.AlignVCenter

            onClicked: {
                if (typeof logQSODialog !== "undefined") logQSODialog.open();
            }

            background: Rectangle {
                color: logBtn.pressed ? Qt.rgba(0, 1.0, 0, 0.2) : Qt.rgba(0, 1.0, 0, 0.08)
                border.color: Theme.activeGreen
                border.width: 1.5
                radius: Theme.radius
            }

            contentItem: Text {
                text: "LOG"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontMedium
                font.bold: true
                color: Theme.activeGreen
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
