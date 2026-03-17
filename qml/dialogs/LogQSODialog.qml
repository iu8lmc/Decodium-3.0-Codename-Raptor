import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium

Dialog {
    id: logDialog
    title: "Log QSO"
    modal: true
    width: 480
    height: 440
    anchors.centerIn: parent

    background: Rectangle {
        color: Theme.background
        border.color: Theme.border
        border.width: 1
        radius: Theme.radiusLarge
    }

    header: Rectangle {
        width: parent.width
        height: 48
        color: Theme.surface
        radius: Theme.radiusLarge

        Rectangle {
            anchors.bottom: parent.bottom
            width: parent.width
            height: Theme.radiusLarge
            color: Theme.surface
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: Theme.margin
            anchors.rightMargin: Theme.margin

            Text {
                text: "LOG QSO"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontMedium
                font.bold: true
                font.letterSpacing: 2
                color: Theme.accent
            }
            Item { Layout.fillWidth: true }
            AbstractButton {
                implicitWidth: 28; implicitHeight: 28
                onClicked: logDialog.close()
                contentItem: Text {
                    text: "\u2715"
                    font.pixelSize: 14
                    color: Theme.textSecondary
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    radius: 4
                    color: parent.hovered ? Theme.surfaceLight : "transparent"
                }
            }
        }
    }

    contentItem: Flickable {
        contentHeight: formLayout.height
        clip: true

        GridLayout {
            id: formLayout
            width: parent.width
            columns: 2
            columnSpacing: Theme.spacingLarge
            rowSpacing: Theme.spacing

            // Top margin
            Item { Layout.columnSpan: 2; height: Theme.margin }

            // Call
            Text {
                text: "CALL"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
            }
            TextField {
                id: callField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                text: typeof tx !== "undefined" ? tx.hisCall : ""
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.accent

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: callField.activeFocus ? Theme.accent : Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
            }

            // Grid
            Text {
                text: "GRID"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
            }
            TextField {
                id: gridLogField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.textPrimary

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: gridLogField.activeFocus ? Theme.accent : Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
            }

            // RST Sent
            Text {
                text: "RST SENT"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
            }
            TextField {
                id: rstSentField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                text: "-10"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.textPrimary

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: rstSentField.activeFocus ? Theme.accent : Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
            }

            // RST Rcvd
            Text {
                text: "RST RCVD"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
            }
            TextField {
                id: rstRcvdField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                text: "-12"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.textPrimary

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: rstRcvdField.activeFocus ? Theme.accent : Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
            }

            // Contest Exchange Sent (visible only in contest mode)
            Text {
                text: "EXCH SENT"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
                visible: typeof logController !== "undefined" && logController.contestMode
            }
            TextField {
                id: exchSentField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                text: ""
                placeholderText: "e.g. 599 001"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.textPrimary
                visible: typeof logController !== "undefined" && logController.contestMode

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: exchSentField.activeFocus ? Theme.accent : Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
            }

            // Contest Exchange Received
            Text {
                text: "EXCH RCVD"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
                visible: typeof logController !== "undefined" && logController.contestMode
            }
            TextField {
                id: exchRcvdField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                text: ""
                placeholderText: "e.g. 599 015"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.textPrimary
                visible: typeof logController !== "undefined" && logController.contestMode

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: exchRcvdField.activeFocus ? Theme.accent : Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
            }

            // Frequency
            Text {
                text: "FREQ"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
            }
            TextField {
                id: freqField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                text: typeof radio !== "undefined" ? (radio.dialFrequency / 1000000).toFixed(6) : "14.075500"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.activeGreen

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: freqField.activeFocus ? Theme.accent : Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
            }

            // Mode
            Text {
                text: "MODE"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
            }
            TextField {
                id: modeField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                text: typeof radio !== "undefined" ? radio.mode : "FT2"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.textPrimary
                readOnly: true

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
            }

            // Date/Time
            Text {
                text: "DATE/TIME"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.leftMargin: Theme.marginLarge
            }
            TextField {
                id: dateTimeField
                Layout.fillWidth: true
                Layout.rightMargin: Theme.marginLarge
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontNormal
                color: Theme.textPrimary
                readOnly: true

                background: Rectangle {
                    color: Theme.surfaceLight
                    border.color: Theme.border
                    border.width: 1
                    radius: Theme.radius
                }

                Component.onCompleted: {
                    var now = new Date();
                    var y = now.getUTCFullYear();
                    var mo = String(now.getUTCMonth() + 1).padStart(2, '0');
                    var d = String(now.getUTCDate()).padStart(2, '0');
                    var h = String(now.getUTCHours()).padStart(2, '0');
                    var mi = String(now.getUTCMinutes()).padStart(2, '0');
                    text = y + "-" + mo + "-" + d + " " + h + ":" + mi + " UTC";
                }
            }
        }
    }

    footer: Rectangle {
        width: parent.width
        height: 50
        color: Theme.surface
        radius: Theme.radiusLarge

        Rectangle {
            anchors.top: parent.top
            width: parent.width
            height: Theme.radiusLarge
            color: Theme.surface
        }

        Rectangle {
            anchors.top: parent.top
            width: parent.width
            height: 1
            color: Theme.border
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: Theme.marginLarge
            anchors.rightMargin: Theme.marginLarge

            Item { Layout.fillWidth: true }

            // Cancel
            AbstractButton {
                implicitWidth: 90; implicitHeight: 34
                onClicked: logDialog.close()
                background: Rectangle {
                    color: parent.hovered ? Theme.surfaceLight : Theme.surface
                    border.color: Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
                contentItem: Text {
                    text: "Cancel"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    color: Theme.textSecondary
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            // Log
            AbstractButton {
                implicitWidth: 90; implicitHeight: 34
                onClicked: {
                    if (typeof log !== "undefined") {
                        log.logQSO(callField.text, gridLogField.text, modeField.text,
                                   rstSentField.text, rstRcvdField.text,
                                   parseFloat(freqField.text) * 1000000);
                    }
                    logDialog.close();
                }
                background: Rectangle {
                    color: parent.hovered ? Qt.rgba(0, 1, 0, 0.15) : Qt.rgba(0, 1, 0, 0.08)
                    border.color: Theme.activeGreen
                    border.width: 1.5
                    radius: Theme.radius
                }
                contentItem: Text {
                    text: "Log QSO"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    font.bold: true
                    color: Theme.activeGreen
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}
