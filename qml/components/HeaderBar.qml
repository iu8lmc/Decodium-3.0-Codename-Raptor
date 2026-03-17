import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium

Rectangle {
    id: headerBar
    color: Theme.surface

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Theme.margin
        anchors.rightMargin: Theme.margin
        spacing: Theme.spacingLarge

        // ── Logo ──
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 2

            Text {
                text: "DECODIUM 3"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontLarge
                font.bold: true
                font.letterSpacing: 2
                color: Theme.accent
            }
            Text {
                text: "FT2 DIGITAL SUITE"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 4
                color: Theme.textSecondary
            }
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── Frequency display ──
        FrequencyDisplay {
            Layout.alignment: Qt.AlignVCenter
            frequency: typeof radio !== "undefined" ? radio.dialFrequency : 14075500
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── Audio meter ──
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 4

            Text {
                text: "RX"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textSecondary
                anchors.horizontalCenter: parent.horizontalCenter
            }
            AudioMeter {
                width: 20
                height: 50
                level: typeof audio !== "undefined" ? audio.rxLevel : 35
            }
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── Mode button ──
        ModeButton {
            Layout.alignment: Qt.AlignVCenter
            modeName: typeof radio !== "undefined" ? radio.mode : "FT2"
            active: true
        }

        // ── TX/RX Freq ──
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 2

            Row {
                spacing: 4
                Text {
                    text: "RX:"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontTiny
                    color: Theme.activeGreen
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: typeof waterfall !== "undefined" ? String(waterfall.rxFreq) : "1500"
                    font.family: Theme.digitalFont
                    font.pixelSize: Theme.fontSmall
                    color: Theme.activeGreen
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
            Row {
                spacing: 4
                Text {
                    text: "TX:"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontTiny
                    color: Theme.alertRed
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: typeof waterfall !== "undefined" ? String(waterfall.txFreq) : "1500"
                    font.family: Theme.digitalFont
                    font.pixelSize: Theme.fontSmall
                    color: Theme.alertRed
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }

        // ── Spacer ──
        Item { Layout.fillWidth: true }

        // ── Font size controls ──
        Row {
            Layout.alignment: Qt.AlignVCenter
            spacing: 2

            AbstractButton {
                width: 26; height: 24
                onClicked: Theme.fontScale = Math.max(0.7, Theme.fontScale - 0.1)
                contentItem: Text {
                    text: "A\u2212"
                    font.family: Theme.fontFamily
                    font.pixelSize: 11
                    color: Theme.textSecondary
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    color: parent.pressed ? Theme.surfaceLight : "transparent"
                    border.color: Theme.borderLight
                    border.width: 1
                    radius: 2
                }
            }
            AbstractButton {
                width: 26; height: 24
                onClicked: Theme.fontScale = Math.min(1.5, Theme.fontScale + 0.1)
                contentItem: Text {
                    text: "A+"
                    font.family: Theme.fontFamily
                    font.pixelSize: 11
                    color: Theme.textSecondary
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    color: parent.pressed ? Theme.surfaceLight : "transparent"
                    border.color: Theme.borderLight
                    border.width: 1
                    radius: 2
                }
            }
            Text {
                text: Math.round(Theme.fontScale * 100) + "%"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
                anchors.verticalCenter: parent.verticalCenter
                width: 32
                horizontalAlignment: Text.AlignHCenter
            }
            AbstractButton {
                width: 26; height: 24
                onClicked: Theme.fontScale = 1.0
                contentItem: Text {
                    text: "Rst"
                    font.family: Theme.fontFamily
                    font.pixelSize: 10
                    color: Theme.textDim
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    color: parent.pressed ? Theme.surfaceLight : "transparent"
                    border.color: Theme.borderLight
                    border.width: 1
                    radius: 2
                }
            }
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── PSK Reporter indicator ──
        Row {
            Layout.alignment: Qt.AlignVCenter
            spacing: 4
            Rectangle {
                width: 8; height: 8; radius: 4
                color: (typeof app !== "undefined" && app.pskReporterEnabled) ? Theme.activeGreen : Theme.textDim
                anchors.verticalCenter: parent.verticalCenter
            }
            Text {
                text: "PSK"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textSecondary
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── Countdown timer ──
        CountdownTimer {
            Layout.alignment: Qt.AlignVCenter
            period: typeof decoder !== "undefined" ? decoder.period : 15.0
            progress: {
                var now = new Date();
                var secs = now.getUTCSeconds() + now.getUTCMilliseconds() / 1000.0;
                var p = typeof decoder !== "undefined" ? decoder.period : 15.0;
                return (secs % p) / p;
            }
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 50
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── Analog UTC Clock ──
        AnalogClock {
            Layout.alignment: Qt.AlignVCenter
            width: 56
            height: 56
        }

        // ── Digital UTC Clock ──
        Column {
            Layout.alignment: Qt.AlignVCenter
            spacing: 2

            Text {
                text: "UTC"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                color: Theme.textSecondary
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                id: utcClock
                font.family: Theme.digitalFont
                font.pixelSize: 22
                color: Theme.accent

                function updateTime() {
                    var now = new Date();
                    var h = String(now.getUTCHours()).padStart(2, '0');
                    var m = String(now.getUTCMinutes()).padStart(2, '0');
                    var s = String(now.getUTCSeconds()).padStart(2, '0');
                    text = h + ":" + m + ":" + s;
                }

                Timer {
                    interval: 1000
                    running: true
                    repeat: true
                    triggeredOnStart: true
                    onTriggered: utcClock.updateTime()
                }
            }
        }
    }
}
