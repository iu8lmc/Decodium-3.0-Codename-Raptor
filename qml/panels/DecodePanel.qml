import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium
import "../components" as Components

Rectangle {
    id: decodePanel
    color: Theme.background

    property string title: "Decodes"
    property bool autoScroll: true
    property var model: typeof decodeModel !== "undefined" ? decodeModel : null

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        // ── Panel header ──
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 28
            color: Theme.surface

            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: Theme.marginSmall
                anchors.rightMargin: Theme.marginSmall

                // Title
                Text {
                    text: decodePanel.title
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    font.bold: true
                    font.letterSpacing: 1
                    color: Theme.accent
                }

                Item { Layout.fillWidth: true }

                // Decode count
                Text {
                    text: decodeListView.count + " decodes"
                    font.family: Theme.digitalFont
                    font.pixelSize: Theme.fontTiny
                    color: Theme.textSecondary
                }

                // Auto-scroll toggle
                Rectangle {
                    width: 16; height: 16
                    radius: 2
                    color: decodePanel.autoScroll ? Qt.rgba(0, 0.83, 1.0, 0.2) : "transparent"
                    border.color: decodePanel.autoScroll ? Theme.accent : Theme.border
                    border.width: 1

                    Text {
                        anchors.centerIn: parent
                        text: "\u2193"  // down arrow
                        font.pixelSize: 10
                        color: decodePanel.autoScroll ? Theme.accent : Theme.textSecondary
                    }

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: decodePanel.autoScroll = !decodePanel.autoScroll
                    }
                }
            }
        }

        // Header separator
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Theme.border
        }

        // ── Column headers ──
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 20
            color: Theme.surfaceMid

            Row {
                anchors.fill: parent
                anchors.leftMargin: Theme.marginSmall
                spacing: Theme.spacing

                Text { width: 52; text: "UTC";  font.family: Theme.digitalFont; font.pixelSize: Theme.fontTiny; color: Theme.textDim }
                Text { width: 36; text: "dB";   font.family: Theme.digitalFont; font.pixelSize: Theme.fontTiny; color: Theme.textDim; horizontalAlignment: Text.AlignRight }
                Text { width: 40; text: "DT";   font.family: Theme.digitalFont; font.pixelSize: Theme.fontTiny; color: Theme.textDim; horizontalAlignment: Text.AlignRight }
                Text { width: 48; text: "Freq"; font.family: Theme.digitalFont; font.pixelSize: Theme.fontTiny; color: Theme.textDim; horizontalAlignment: Text.AlignRight }
                Text { width: 10; text: "";      font.pixelSize: Theme.fontTiny }
                Text { text: "Message"; font.family: Theme.digitalFont; font.pixelSize: Theme.fontTiny; color: Theme.textDim }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Theme.border
        }

        // ── Decode list ──
        ListView {
            id: decodeListView
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: decodePanel.model
            delegate: Components.DecodeLine {}

            // Auto-scroll to bottom when new items are added
            onCountChanged: {
                if (decodePanel.autoScroll) {
                    positionTimer.restart();
                }
            }

            Timer {
                id: positionTimer
                interval: 50
                onTriggered: {
                    decodeListView.positionViewAtEnd();
                }
            }

            ScrollBar.vertical: ScrollBar {
                id: vScrollBar
                active: true
                policy: ScrollBar.AsNeeded

                contentItem: Rectangle {
                    implicitWidth: 6
                    radius: 3
                    color: vScrollBar.pressed ? Theme.accent : Theme.surfaceLight
                    opacity: vScrollBar.active ? 1.0 : 0.0

                    Behavior on opacity {
                        NumberAnimation { duration: Theme.animNormal }
                    }
                    Behavior on color {
                        ColorAnimation { duration: Theme.animFast }
                    }
                }

                background: Rectangle {
                    implicitWidth: 6
                    color: "transparent"
                }
            }

            // Empty state
            Text {
                anchors.centerIn: parent
                visible: decodeListView.count === 0
                text: "Waiting for decodes..."
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontNormal
                color: Theme.textDim
            }
        }
    }
}
