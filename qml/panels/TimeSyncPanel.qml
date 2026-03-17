import QtQuick
import QtQuick.Layouts
import Decodium

Rectangle {
    id: timeSyncPanel
    color: Theme.surface
    border.color: Theme.border
    border.width: 1

    property bool expanded: false
    implicitHeight: expanded ? contentCol.implicitHeight + 2 * Theme.margin : headerRow.implicitHeight + 2 * Theme.spacingSmall

    Column {
        id: contentCol
        anchors.fill: parent
        anchors.margins: Theme.spacingSmall
        spacing: Theme.spacingSmall

        // Header (always visible, clickable to expand)
        RowLayout {
            id: headerRow
            width: parent.width
            spacing: Theme.spacingSmall

            Text {
                text: expanded ? "▼" : "▶"
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }

            Text {
                text: "TIME SYNC"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.bold: true
                color: Theme.textSecondary
            }

            Item { Layout.fillWidth: true }

            // UTC Clock
            Text {
                id: utcClock
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                font.bold: true
                color: Theme.accent
                text: Qt.formatDateTime(new Date(), "HH:mm:ss.zzz") + " UTC"
            }

            // NTP status indicator
            Rectangle {
                width: 8; height: 8; radius: 4
                color: {
                    if (typeof app === "undefined") return Theme.textDim
                    if (!app.ntpSynced) return Theme.alertRed
                    var offset = Math.abs(app.ntpOffsetMs)
                    if (offset < 20) return "#4CAF50"      // green
                    if (offset < 100) return "#FF9800"      // yellow/orange
                    return Theme.alertRed
                }
                Layout.alignment: Qt.AlignVCenter
            }

            MouseArea {
                anchors.fill: parent
                onClicked: timeSyncPanel.expanded = !timeSyncPanel.expanded
            }
        }

        // Expanded content
        GridLayout {
            visible: expanded
            columns: 2
            columnSpacing: Theme.spacingLarge
            rowSpacing: Theme.spacingSmall
            width: parent.width

            // NTP Offset
            Text {
                text: "NTP Offset:"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            Text {
                text: {
                    if (typeof app === "undefined") return "N/A"
                    if (!app.ntpSynced) return "Not synced"
                    return app.ntpOffsetMs.toFixed(1) + " ms"
                }
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: {
                    if (typeof app === "undefined" || !app.ntpSynced) return Theme.alertRed
                    var offset = Math.abs(app.ntpOffsetMs)
                    if (offset < 20) return "#4CAF50"
                    if (offset < 100) return "#FF9800"
                    return Theme.alertRed
                }
            }

            // Soundcard Drift
            Text {
                text: "SC Drift:"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            Text {
                text: {
                    if (typeof audio === "undefined") return "N/A"
                    return audio.soundcardDriftPpm.toFixed(1) + " ppm (" +
                           audio.soundcardDriftMsPerPeriod.toFixed(1) + " ms/T)"
                }
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: {
                    if (typeof audio === "undefined") return Theme.textDim
                    if (audio.driftSeverity === "green") return "#4CAF50"
                    if (audio.driftSeverity === "yellow") return "#FF9800"
                    return Theme.alertRed
                }
            }

            // Average DT
            Text {
                text: "Avg DT:"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            Text {
                text: {
                    if (typeof decoder === "undefined") return "N/A"
                    var dt = decoder.avgDt
                    var status = Math.abs(dt) < 0.1 ? "LOCKED" :
                                 Math.abs(dt) < 0.3 ? "Converging" : "Adjusting"
                    return dt.toFixed(3) + " s (" + status + ")"
                }
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: {
                    if (typeof decoder === "undefined") return Theme.textDim
                    var dt = Math.abs(decoder.avgDt)
                    if (dt < 0.1) return "#4CAF50"
                    if (dt < 0.3) return "#FF9800"
                    return Theme.alertRed
                }
            }

            // Decode Latency
            Text {
                text: "Decode Latency:"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
            }
            Text {
                text: {
                    if (typeof decoder === "undefined") return "N/A"
                    if (decoder.decodeLatencyMs < 0) return "TIMEOUT"
                    return decoder.decodeLatencyMs.toFixed(0) + " ms"
                }
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: {
                    if (typeof decoder === "undefined") return Theme.textDim
                    if (decoder.decodeLatencyMs < 0) return Theme.alertRed
                    if (decoder.decodeLatencyMs < 3000) return "#4CAF50"
                    if (decoder.decodeLatencyMs < 8000) return "#FF9800"
                    return Theme.alertRed
                }
            }
        }
    }

    // UTC clock update timer
    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: utcClock.text = Qt.formatDateTime(new Date(), "HH:mm:ss.zzz") + " UTC"
    }

    // Click-to-expand on header
    MouseArea {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: headerRow.implicitHeight + 2 * Theme.spacingSmall
        onClicked: timeSyncPanel.expanded = !timeSyncPanel.expanded
    }
}
