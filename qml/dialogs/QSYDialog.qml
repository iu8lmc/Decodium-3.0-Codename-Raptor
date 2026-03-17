import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium

Dialog {
    id: qsyDialog
    title: "QSY"
    modal: true
    width: 340
    height: 360
    anchors.centerIn: parent

    property string currentMode: typeof decoder !== "undefined" ? decoder.currentMode : "FT8"
    property string currentBand: typeof radio !== "undefined" ? radio.currentBand : "20m"

    // Common FT8/FT4 frequencies per band (kHz dial)
    readonly property var qsyFrequencies: ({
        "160m": [{"dial": 1840, "mode": "FT8"}, {"dial": 1840, "mode": "FT4"}],
        "80m":  [{"dial": 3573, "mode": "FT8"}, {"dial": 3575, "mode": "FT4"}, {"dial": 3568, "mode": "JT65"}],
        "60m":  [{"dial": 5357, "mode": "FT8"}],
        "40m":  [{"dial": 7074, "mode": "FT8"}, {"dial": 7047.5, "mode": "FT4"}, {"dial": 7076, "mode": "JT65"}],
        "30m":  [{"dial": 10136, "mode": "FT8"}, {"dial": 10140, "mode": "FT4"}],
        "20m":  [{"dial": 14074, "mode": "FT8"}, {"dial": 14080, "mode": "FT4"}, {"dial": 14076, "mode": "JT65"}],
        "17m":  [{"dial": 18100, "mode": "FT8"}, {"dial": 18104, "mode": "FT4"}],
        "15m":  [{"dial": 21074, "mode": "FT8"}, {"dial": 21140, "mode": "FT4"}, {"dial": 21076, "mode": "JT65"}],
        "12m":  [{"dial": 24915, "mode": "FT8"}, {"dial": 24919, "mode": "FT4"}],
        "10m":  [{"dial": 28074, "mode": "FT8"}, {"dial": 28180, "mode": "FT4"}],
        "6m":   [{"dial": 50313, "mode": "FT8"}, {"dial": 50318, "mode": "FT4"}],
        "2m":   [{"dial": 144174, "mode": "FT8"}, {"dial": 144170, "mode": "FT4"}],
        "70cm": [{"dial": 432065, "mode": "FT8"}, {"dial": 432065, "mode": "FT4"}]
    })

    background: Rectangle {
        color: Theme.background
        border.color: Theme.border
        border.width: 1
        radius: Theme.radiusLarge
    }

    header: Rectangle {
        width: parent.width
        height: 44
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
                text: "QSY - CHANGE FREQUENCY"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontSmall
                font.bold: true
                font.letterSpacing: 2
                color: Theme.accent
            }
            Item { Layout.fillWidth: true }
            AbstractButton {
                implicitWidth: 28; implicitHeight: 28
                onClicked: qsyDialog.close()
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

    contentItem: ColumnLayout {
        spacing: Theme.spacing

        Text {
            Layout.leftMargin: Theme.marginLarge
            Layout.topMargin: Theme.spacing
            text: "Current: " + currentBand + " / " + currentMode
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontSmall
            color: Theme.textSecondary
        }

        Text {
            Layout.leftMargin: Theme.marginLarge
            text: "SUGGESTED FREQUENCIES"
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontTiny
            font.letterSpacing: 2
            color: Theme.textSecondary
        }

        ListView {
            id: freqList
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: Theme.marginLarge
            Layout.rightMargin: Theme.marginLarge
            clip: true
            spacing: 2

            model: {
                var result = [];
                var bands = Object.keys(qsyFrequencies);
                for (var b = 0; b < bands.length; b++) {
                    var band = bands[b];
                    var freqs = qsyFrequencies[band];
                    for (var f = 0; f < freqs.length; f++) {
                        result.push({
                            "band": band,
                            "dial": freqs[f].dial,
                            "mode": freqs[f].mode,
                            "isCurrent": (band === currentBand && freqs[f].mode === currentMode)
                        });
                    }
                }
                return result;
            }

            delegate: AbstractButton {
                width: freqList.width
                height: 34

                onClicked: {
                    if (typeof radio !== "undefined") {
                        radio.setDialFrequency(modelData.dial * 1000); // kHz to Hz
                    }
                    if (typeof decoder !== "undefined" && decoder.currentMode !== modelData.mode) {
                        decoder.currentMode = modelData.mode;
                    }
                    qsyDialog.close();
                }

                background: Rectangle {
                    color: modelData.isCurrent ? Qt.rgba(0, 0.83, 1.0, 0.1)
                         : parent.hovered ? Theme.surfaceLight : Theme.surface
                    border.color: modelData.isCurrent ? Theme.accent : Theme.border
                    border.width: modelData.isCurrent ? 1 : 0
                    radius: Theme.radius
                }

                contentItem: RowLayout {
                    spacing: Theme.spacing

                    Text {
                        text: modelData.band
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSmall
                        font.bold: true
                        color: Theme.textPrimary
                        Layout.preferredWidth: 50
                    }

                    Text {
                        text: modelData.dial.toFixed(1) + " kHz"
                        font.family: Theme.digitalFont
                        font.pixelSize: Theme.fontSmall
                        color: Theme.accent
                        Layout.fillWidth: true
                    }

                    Text {
                        text: modelData.mode
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontTiny
                        font.bold: true
                        color: modelData.mode === currentMode ? Theme.activeGreen : Theme.textSecondary
                        Layout.preferredWidth: 40
                        horizontalAlignment: Text.AlignRight
                    }
                }
            }

            Rectangle {
                anchors.fill: parent
                color: "transparent"
                border.color: Theme.border
                border.width: 1
                radius: Theme.radius
                z: -1
            }
        }
    }
}
