import QtQuick
import QtQuick.Layouts
import Decodium
import "../components" as Components

Rectangle {
    id: statusBar
    color: Theme.surface

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Theme.margin
        anchors.rightMargin: Theme.margin
        spacing: Theme.spacing

        // ── S-meter (horizontal bar) ──
        Row {
            Layout.alignment: Qt.AlignVCenter
            spacing: 4

            Text {
                text: "S"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.bold: true
                color: Theme.textDim
                anchors.verticalCenter: parent.verticalCenter
            }

            Rectangle {
                width: 80
                height: 10
                color: Theme.surfaceLight
                border.color: Theme.borderLight
                border.width: 1
                radius: 2
                anchors.verticalCenter: parent.verticalCenter

                Rectangle {
                    width: {
                        var level = typeof audio !== "undefined" ? audio.rxLevel : 0;
                        return Math.min(parent.width - 2, Math.max(0, (level / 100.0) * (parent.width - 2)));
                    }
                    height: parent.height - 2
                    x: 1; y: 1
                    radius: 1
                    gradient: Gradient {
                        orientation: Gradient.Horizontal
                        GradientStop { position: 0.0; color: Theme.activeGreen }
                        GradientStop { position: 0.7; color: Theme.warning }
                        GradientStop { position: 1.0; color: Theme.alertRed }
                    }
                }
            }
        }

        // Separator
        Rectangle { width: 1; height: 16; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // ── Status dots: MON, TX, DEC, FT1 ──
        Row {
            Layout.alignment: Qt.AlignVCenter
            spacing: Theme.spacing

            // MON dot
            Row {
                spacing: 3
                Rectangle {
                    width: 8; height: 8; radius: 4
                    color: (typeof audio !== "undefined" && audio.monitoring) ? Theme.activeGreen : Theme.textDim
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: "MON"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontTiny
                    color: (typeof audio !== "undefined" && audio.monitoring) ? Theme.activeGreen : Theme.textDim
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            // TX dot
            Row {
                spacing: 3
                Rectangle {
                    width: 8; height: 8; radius: 4
                    color: (typeof tx !== "undefined" && tx.transmitting) ? Theme.alertRed : Theme.textDim
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: "TX"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontTiny
                    color: (typeof tx !== "undefined" && tx.transmitting) ? Theme.alertRed : Theme.textDim
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            // DEC dot
            Row {
                spacing: 3
                Rectangle {
                    width: 8; height: 8; radius: 4
                    color: (typeof decoder !== "undefined" && decoder.decoding) ? Theme.warning : Theme.textDim
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: "DEC"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontTiny
                    color: (typeof decoder !== "undefined" && decoder.decoding) ? Theme.warning : Theme.textDim
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            // FT2 indicator
            Row {
                spacing: 3
                Rectangle {
                    width: 8; height: 8; radius: 4
                    color: (typeof decoder !== "undefined" && decoder.ft2AsyncMode) ? Theme.accent : Theme.textDim
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: "FT2"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontTiny
                    color: (typeof decoder !== "undefined" && decoder.ft2AsyncMode) ? Theme.accent : Theme.textDim
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }

        // Separator
        Rectangle { width: 1; height: 16; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // ── CAT status ──
        Row {
            Layout.alignment: Qt.AlignVCenter
            spacing: 3
            Rectangle {
                width: 8; height: 8; radius: 4
                color: (typeof radio !== "undefined" && radio.connected) ? Theme.activeGreen : Theme.textDim
                anchors.verticalCenter: parent.verticalCenter
            }
            Text {
                text: "CAT"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: (typeof radio !== "undefined" && radio.connected) ? Theme.activeGreen : Theme.textDim
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        // Separator
        Rectangle { width: 1; height: 16; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // ── CPU% / Decode latency ──
        Text {
            text: {
                var lat = typeof decoder !== "undefined" ? decoder.decodeLatencyMs : 0;
                return "CPU " + Math.round(lat) + "ms"
            }
            font.family: Theme.digitalFont
            font.pixelSize: Theme.fontTiny
            color: {
                var lat = typeof decoder !== "undefined" ? decoder.decodeLatencyMs : 0;
                if (lat > 2000) return Theme.alertRed;
                if (lat > 1000) return Theme.warning;
                return Theme.textDim;
            }
            Layout.alignment: Qt.AlignVCenter
        }

        // Spacer
        Item { Layout.fillWidth: true }

        // Separator
        Rectangle { width: 1; height: 16; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // ── Callsign ──
        Text {
            text: typeof app !== "undefined" && app.callsign ? app.callsign : "N0CALL"
            font.family: Theme.digitalFont
            font.pixelSize: Theme.fontSmall
            font.bold: true
            color: Theme.accent
            Layout.alignment: Qt.AlignVCenter
        }

        // Separator
        Rectangle { width: 1; height: 16; color: Theme.border; Layout.alignment: Qt.AlignVCenter }

        // ── Version ──
        Text {
            text: "v3.0"
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontTiny
            color: Theme.textDim
            Layout.alignment: Qt.AlignVCenter
        }
    }
}
