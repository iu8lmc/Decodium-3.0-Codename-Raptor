import QtQuick
import Decodium

Item {
    id: audioMeter
    width: 20
    height: 50

    property int level: 0       // 0..100
    property int barCount: 12
    property int barSpacing: 2

    Rectangle {
        anchors.fill: parent
        color: Theme.background
        radius: 2
        border.color: Theme.border
        border.width: 1

        Column {
            id: barColumn
            anchors.fill: parent
            anchors.margins: 2
            spacing: barSpacing

            Repeater {
                model: audioMeter.barCount

                Rectangle {
                    width: barColumn.width
                    height: Math.max(1, (barColumn.height - (audioMeter.barCount - 1) * barSpacing) / audioMeter.barCount)

                    // Bars are ordered top-down: index 0 = top (red), index N = bottom (green)
                    property int barIndex: index
                    property real threshold: (1.0 - (barIndex / audioMeter.barCount)) * 100
                    property bool lit: audioMeter.level >= threshold

                    color: {
                        if (!lit) return Theme.surfaceLight;
                        // Top 2 bars = red, next 2 = yellow, rest = green
                        if (barIndex <= 1) return Theme.alertRed;
                        if (barIndex <= 3) return Theme.warning;
                        return Theme.activeGreen;
                    }
                    opacity: lit ? 1.0 : 0.3
                    radius: 1

                    Behavior on opacity {
                        NumberAnimation { duration: Theme.animFast }
                    }
                }
            }
        }
    }
}
