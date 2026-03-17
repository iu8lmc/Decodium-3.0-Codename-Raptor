import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium
import "../components" as Components

Rectangle {
    id: bottomToolbar
    color: Theme.surface

    property string currentBand: typeof radio !== "undefined" ? radio.band : "20m"
    property string currentMode: typeof radio !== "undefined" ? radio.mode : "FT2"

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Theme.margin
        anchors.rightMargin: Theme.margin
        spacing: Theme.spacingSmall

        // ── Band label ──
        Text {
            text: "BAND"
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontTiny
            font.letterSpacing: 2
            color: Theme.textDim
            Layout.alignment: Qt.AlignVCenter
        }

        // ── Band buttons ──
        Repeater {
            model: ["160m", "80m", "60m", "40m", "30m", "20m", "17m", "15m", "12m", "10m", "6m", "2m"]
            delegate: Components.BandButton {
                bandName: modelData
                active: bottomToolbar.currentBand === modelData
                Layout.alignment: Qt.AlignVCenter
            }
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 32
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── Mode label ──
        Text {
            text: "MODE"
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontTiny
            font.letterSpacing: 2
            color: Theme.textDim
            Layout.alignment: Qt.AlignVCenter
        }

        // ── Mode buttons ──
        Repeater {
            model: ["FT8", "FT4", "FT2", "JT65", "JT9", "WSPR", "FST4", "Q65", "MSK144"]
            delegate: Components.ModeButton {
                modeName: modelData
                active: bottomToolbar.currentMode === modelData
                Layout.alignment: Qt.AlignVCenter
            }
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 32
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── Fox/Hound toggles ──
        Components.FeatureToggle {
            label: "FOX"
            checked: typeof tx !== "undefined" ? tx.foxMode : false
            Layout.alignment: Qt.AlignVCenter
            onToggled: function(val) {
                if (typeof tx !== "undefined") tx.foxMode = val;
            }
        }

        Components.FeatureToggle {
            label: "HND"
            checked: typeof tx !== "undefined" ? tx.houndMode : false
            Layout.alignment: Qt.AlignVCenter
            onToggled: function(val) {
                if (typeof tx !== "undefined") tx.houndMode = val;
            }
        }

        // ── Separator ──
        Rectangle {
            Layout.preferredWidth: 1
            Layout.preferredHeight: 32
            Layout.alignment: Qt.AlignVCenter
            color: Theme.border
        }

        // ── Feature toggles ──
        Components.FeatureToggle {
            label: "ASQ"
            checked: typeof tx !== "undefined" ? tx.autoSequence : false
            Layout.alignment: Qt.AlignVCenter
            onToggled: function(val) {
                if (typeof tx !== "undefined") tx.autoSequence = val;
            }
        }

        Components.FeatureToggle {
            label: "ACQ"
            checked: typeof tx !== "undefined" ? tx.autoCQ : false
            Layout.alignment: Qt.AlignVCenter
            onToggled: function(val) {
                if (typeof tx !== "undefined") tx.autoCQ = val;
            }
        }

        Components.FeatureToggle {
            label: "DEEP"
            checked: typeof decoder !== "undefined" ? decoder.deepSearch > 1 : false
            Layout.alignment: Qt.AlignVCenter
            onToggled: function(val) {
                if (typeof decoder !== "undefined") decoder.deepSearch = val ? 3 : 1;
            }
        }

        // ── FT2 Async toggle ──
        Components.FeatureToggle {
            label: "ASYNC"
            visible: typeof decoder !== "undefined" && decoder.currentMode === "FT2"
            checked: typeof decoder !== "undefined" ? decoder.ft2AsyncMode : false
            Layout.alignment: Qt.AlignVCenter
            onToggled: function(val) {
                if (typeof decoder !== "undefined") decoder.ft2AsyncMode = val;
            }
        }

        // ── Spacer ──
        Item { Layout.fillWidth: true }

        // ── Tune button ──
        AbstractButton {
            id: tuneBtn
            implicitWidth: 60
            implicitHeight: 32
            Layout.alignment: Qt.AlignVCenter

            property bool tuning: typeof radio !== "undefined" ? radio.tuning : false

            onClicked: {
                if (typeof radio !== "undefined")
                    radio.tune(!tuning);
            }

            background: Rectangle {
                color: tuneBtn.tuning ? Qt.rgba(1.0, 0.6, 0, 0.15) : Theme.surface
                border.color: tuneBtn.tuning ? Theme.warning : Theme.border
                border.width: 1
                radius: Theme.radius
            }

            contentItem: Text {
                text: tuneBtn.tuning ? "TUNE" : "Tune"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontSmall
                font.bold: tuneBtn.tuning
                color: tuneBtn.tuning ? Theme.warning : Theme.textSecondary
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        // ── Monitor button ──
        AbstractButton {
            id: monitorBtn
            implicitWidth: 80
            implicitHeight: 32
            Layout.alignment: Qt.AlignVCenter

            property bool monitoring: typeof audio !== "undefined" ? audio.monitoring : false

            onClicked: {
                if (typeof audio !== "undefined") {
                    if (monitoring) audio.stopMonitoring();
                    else audio.startMonitoring();
                }
            }

            background: Rectangle {
                color: monitorBtn.monitoring ? Qt.rgba(0, 1.0, 0, 0.12) : Theme.surface
                border.color: monitorBtn.monitoring ? Theme.activeGreen : Theme.border
                border.width: 1
                radius: Theme.radius
            }

            contentItem: Text {
                text: monitorBtn.monitoring ? "MON ON" : "MON OFF"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontSmall
                font.bold: true
                color: monitorBtn.monitoring ? Theme.activeGreen : Theme.textSecondary
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}
