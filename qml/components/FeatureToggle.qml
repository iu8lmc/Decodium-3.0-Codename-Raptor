import QtQuick
import QtQuick.Controls
import Decodium

Item {
    id: featureToggle
    implicitWidth: toggleRow.implicitWidth
    implicitHeight: 32

    property string label: "ASQ"
    property bool checked: false

    signal toggled(bool value)

    Row {
        id: toggleRow
        anchors.verticalCenter: parent.verticalCenter
        spacing: Theme.spacingSmall

        // Label
        Text {
            text: featureToggle.label
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontSmall
            font.bold: true
            color: featureToggle.checked ? Theme.accent : Theme.textSecondary
            anchors.verticalCenter: parent.verticalCenter

            Behavior on color {
                ColorAnimation { duration: Theme.animFast }
            }
        }

        // Switch track
        Rectangle {
            id: track
            width: 36
            height: 18
            radius: 9
            anchors.verticalCenter: parent.verticalCenter
            color: featureToggle.checked ? Qt.rgba(0, 0.83, 1.0, 0.25) : Theme.surfaceLight
            border.color: featureToggle.checked ? Theme.accent : Theme.border
            border.width: 1

            Behavior on color {
                ColorAnimation { duration: Theme.animNormal }
            }
            Behavior on border.color {
                ColorAnimation { duration: Theme.animNormal }
            }

            // Thumb
            Rectangle {
                id: thumb
                width: 14
                height: 14
                radius: 7
                y: 2
                x: featureToggle.checked ? track.width - width - 2 : 2
                color: featureToggle.checked ? Theme.accent : Theme.textSecondary

                Behavior on x {
                    NumberAnimation { duration: Theme.animNormal; easing.type: Easing.InOutQuad }
                }
                Behavior on color {
                    ColorAnimation { duration: Theme.animNormal }
                }
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    featureToggle.checked = !featureToggle.checked;
                    featureToggle.toggled(featureToggle.checked);
                }
            }
        }
    }
}
