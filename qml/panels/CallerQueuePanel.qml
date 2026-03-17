import QtQuick
import QtQuick.Layouts
import Decodium

Rectangle {
    id: callerQueuePanel
    color: Theme.surface
    border.color: Theme.border
    border.width: 1
    visible: typeof tx !== "undefined" && tx.foxMode

    Column {
        anchors.fill: parent
        anchors.margins: Theme.spacingSmall
        spacing: Theme.spacingSmall

        // Header
        RowLayout {
            width: parent.width
            spacing: Theme.spacingSmall

            Text {
                text: "FOX CALLER QUEUE"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.bold: true
                color: Theme.accent
            }

            Item { Layout.fillWidth: true }

            Text {
                text: typeof tx !== "undefined" ? tx.callerQueueSize + "/20" : "0/20"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontTiny
                color: Theme.textSecondary
            }

            // Clear queue button
            Rectangle {
                width: 20; height: 20; radius: 2
                color: mouseAreaClear.containsMouse ? Theme.border : "transparent"

                Text {
                    anchors.centerIn: parent
                    text: "✕"
                    font.pixelSize: Theme.fontTiny
                    color: Theme.textDim
                }

                MouseArea {
                    id: mouseAreaClear
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        if (typeof tx !== "undefined") tx.clearCallerQueue()
                    }
                }
            }
        }

        // Separator
        Rectangle {
            width: parent.width
            height: 1
            color: Theme.border
        }

        // Queue list
        ListView {
            id: queueList
            width: parent.width
            Layout.fillHeight: true
            height: Math.min(contentHeight, 200)
            clip: true
            model: typeof tx !== "undefined" ? tx.callerQueue : []

            delegate: Rectangle {
                width: queueList.width
                height: 24
                color: delegateMouse.containsMouse ? Qt.rgba(Theme.accent.r, Theme.accent.g, Theme.accent.b, 0.1) : "transparent"

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: Theme.spacingSmall
                    anchors.rightMargin: Theme.spacingSmall
                    spacing: Theme.spacingSmall

                    Text {
                        text: (index + 1) + "."
                        font.family: Theme.digitalFont
                        font.pixelSize: Theme.fontTiny
                        color: Theme.textDim
                        Layout.preferredWidth: 20
                    }

                    Text {
                        text: modelData
                        font.family: Theme.digitalFont
                        font.pixelSize: Theme.fontSmall
                        font.bold: true
                        color: index === 0 ? Theme.accent : Theme.textPrimary
                        Layout.fillWidth: true
                    }

                    // Remove from queue
                    Text {
                        text: "✕"
                        font.pixelSize: Theme.fontTiny
                        color: Theme.textDim
                        visible: delegateMouse.containsMouse

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if (typeof tx !== "undefined") tx.dequeueStation(modelData)
                            }
                        }
                    }
                }

                MouseArea {
                    id: delegateMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    acceptedButtons: Qt.NoButton
                }
            }

            // Empty state
            Text {
                anchors.centerIn: parent
                visible: queueList.count === 0
                text: "No callers in queue"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
        }
    }
}
