import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import Decodium

Rectangle {
    id: activePanel
    color: Theme.surface
    border.color: Theme.border
    border.width: 1

    Column {
        anchors.fill: parent
        anchors.margins: Theme.spacingSmall
        spacing: Theme.spacingSmall

        // Header
        RowLayout {
            width: parent.width
            spacing: Theme.spacingSmall

            Text {
                text: "ACTIVE STATIONS"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.bold: true
                color: Theme.accent
            }

            Item { Layout.fillWidth: true }

            Text {
                text: (typeof activeStations !== "undefined" ? activeStations.count : 0) + " stn"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontTiny
                color: Theme.textSecondary
            }
        }

        Rectangle { width: parent.width; height: 1; color: Theme.border }

        // Filter buttons
        RowLayout {
            width: parent.width
            spacing: Theme.spacingSmall

            AbstractButton {
                implicitWidth: 60; implicitHeight: 20
                property bool active: typeof activeStations !== "undefined" && activeStations.filterCqOnly
                onClicked: { if (typeof activeStations !== "undefined") activeStations.filterCqOnly = !activeStations.filterCqOnly }
                background: Rectangle {
                    color: parent.active ? Qt.rgba(0, 0.83, 1.0, 0.15) : "transparent"
                    border.color: parent.active ? Theme.accent : Theme.border
                    border.width: 1
                    radius: 3
                }
                contentItem: Text {
                    text: "CQ Only"
                    font.family: Theme.fontFamily
                    font.pixelSize: 9
                    color: parent.active ? Theme.accent : Theme.textDim
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            AbstractButton {
                implicitWidth: 60; implicitHeight: 20
                property bool active: typeof activeStations !== "undefined" && activeStations.filterWantedOnly
                onClicked: { if (typeof activeStations !== "undefined") activeStations.filterWantedOnly = !activeStations.filterWantedOnly }
                background: Rectangle {
                    color: parent.active ? Qt.rgba(0, 0.83, 1.0, 0.15) : "transparent"
                    border.color: parent.active ? Theme.accent : Theme.border
                    border.width: 1
                    radius: 3
                }
                contentItem: Text {
                    text: "Wanted"
                    font.family: Theme.fontFamily
                    font.pixelSize: 9
                    color: parent.active ? Theme.accent : Theme.textDim
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Item { Layout.fillWidth: true }

            AbstractButton {
                implicitWidth: 40; implicitHeight: 20
                onClicked: { if (typeof activeStations !== "undefined") activeStations.clear() }
                contentItem: Text {
                    text: "Clear"
                    font.family: Theme.fontFamily
                    font.pixelSize: 9
                    color: Theme.alertRed
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle { color: "transparent" }
            }
        }

        // Column headers
        RowLayout {
            width: parent.width
            spacing: 4

            Text { text: "Call"; font.pixelSize: Theme.fontTiny; color: Theme.textDim; Layout.preferredWidth: 80 }
            Text { text: "Freq"; font.pixelSize: Theme.fontTiny; color: Theme.textDim; Layout.preferredWidth: 50 }
            Text { text: "SNR"; font.pixelSize: Theme.fontTiny; color: Theme.textDim; Layout.preferredWidth: 35 }
            Text { text: "Grid"; font.pixelSize: Theme.fontTiny; color: Theme.textDim; Layout.preferredWidth: 50 }
            Text { text: "UTC"; font.pixelSize: Theme.fontTiny; color: Theme.textDim; Layout.fillWidth: true }
        }

        Rectangle { width: parent.width; height: 1; color: Theme.border }

        // Station list
        ListView {
            id: stationList
            width: parent.width
            height: parent.height - 100
            clip: true
            model: typeof activeStations !== "undefined" ? activeStations : null

            delegate: Rectangle {
                width: stationList.width
                height: 22
                color: stnMouse.containsMouse ? Qt.rgba(Theme.accent.r, Theme.accent.g, Theme.accent.b, 0.1) : "transparent"

                RowLayout {
                    anchors.fill: parent
                    spacing: 4

                    Text {
                        text: model.callsign
                        font.family: Theme.digitalFont
                        font.pixelSize: Theme.fontTiny
                        font.bold: true
                        color: {
                            if (model.isNewDxcc) return "#FF4081";  // pink - new DXCC
                            if (model.isNewGrid) return "#7C4DFF";  // purple - new grid
                            if (model.isWanted) return "#FFAB00";   // amber - wanted
                            if (model.age === 0) return Theme.accent;
                            return Theme.textPrimary;
                        }
                        Layout.preferredWidth: 80
                        elide: Text.ElideRight
                    }
                    Text {
                        text: model.frequency
                        font.family: Theme.digitalFont
                        font.pixelSize: Theme.fontTiny
                        color: Theme.textSecondary
                        Layout.preferredWidth: 50
                    }
                    Text {
                        text: model.snr
                        font.family: Theme.digitalFont
                        font.pixelSize: Theme.fontTiny
                        color: model.snr >= 0 ? "#4CAF50" : (model.snr >= -15 ? "#FF9800" : Theme.alertRed)
                        Layout.preferredWidth: 35
                    }
                    Text {
                        text: model.grid || ""
                        font.family: Theme.digitalFont
                        font.pixelSize: Theme.fontTiny
                        color: model.isLotwUser ? "#64DD17" : Theme.textSecondary
                        Layout.preferredWidth: 50
                    }
                    Text {
                        text: model.lastUtc
                        font.family: Theme.digitalFont
                        font.pixelSize: Theme.fontTiny
                        color: Theme.textDim
                        Layout.fillWidth: true
                    }
                }

                MouseArea {
                    id: stnMouse
                    anchors.fill: parent
                    hoverEnabled: true
                    onDoubleClicked: {
                        if (typeof tx !== "undefined" && typeof app !== "undefined" && typeof activeStations !== "undefined") {
                            var call = activeStations.callsignAt(index)
                            var freq = activeStations.frequencyAt(index)
                            var msg = "CQ " + call + " " + (model.grid || "")
                            tx.handleDoubleClick(msg, freq, app.callsign, app.grid)
                        }
                    }
                }
            }

            Text {
                anchors.centerIn: parent
                visible: typeof activeStations === "undefined" || activeStations.count === 0
                text: "No active stations"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
        }
    }
}
