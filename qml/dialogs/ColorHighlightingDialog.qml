import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import Decodium

Dialog {
    id: colorDialog
    title: "Color Highlighting"
    modal: true
    standardButtons: Dialog.Ok | Dialog.Cancel
    width: Math.min(400, parent.width * 0.9)

    property var colorModel: [
        { label: "CQ Calls", prop: "colorCQ", color: typeof app !== "undefined" ? app.colorCQ : "#008000" },
        { label: "My Call", prop: "colorMyCall", color: typeof app !== "undefined" ? app.colorMyCall : "#FF0000" },
        { label: "DX Entity", prop: "colorDXEntity", color: typeof app !== "undefined" ? app.colorDXEntity : "#FF8C00" },
        { label: "73 / RR73", prop: "color73", color: typeof app !== "undefined" ? app.color73 : "#0064C8" },
        { label: "B4 (Worked)", prop: "colorB4", color: typeof app !== "undefined" ? app.colorB4 : "#A0A0A0" }
    ]

    ColumnLayout {
        anchors.fill: parent
        spacing: Theme.spacingSmall

        Repeater {
            model: colorDialog.colorModel

            RowLayout {
                Layout.fillWidth: true
                spacing: Theme.spacingSmall

                Text {
                    text: modelData.label
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    color: Theme.textPrimary
                    Layout.preferredWidth: 100
                }

                Rectangle {
                    width: 32; height: 24; radius: 4
                    color: modelData.color
                    border.color: Theme.border
                    border.width: 1

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            colorPickerDialog.currentProp = modelData.prop
                            colorPickerDialog.currentIndex = index
                            colorPickerDialog.open()
                        }
                    }
                }

                Item { Layout.fillWidth: true }
            }
        }

        // B4 Strikethrough toggle
        RowLayout {
            Layout.fillWidth: true
            spacing: Theme.spacingSmall

            Text {
                text: "B4 Strikethrough:"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontSmall
                color: Theme.textPrimary
                Layout.preferredWidth: 100
            }

            Switch {
                checked: typeof app !== "undefined" ? app.b4Strikethrough : true
                onToggled: {
                    if (typeof app !== "undefined") app.b4Strikethrough = checked
                }
            }
        }
    }

    // Simple color picker dialog (using text input for hex color)
    Dialog {
        id: colorPickerDialog
        title: "Enter Color"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel

        property string currentProp: ""
        property int currentIndex: 0

        ColumnLayout {
            spacing: Theme.spacingSmall

            Text {
                text: "Hex color (e.g. #FF0000):"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontSmall
                color: Theme.textPrimary
            }

            TextField {
                id: colorInput
                Layout.fillWidth: true
                placeholderText: "#RRGGBB"
                text: colorPickerDialog.currentIndex < colorDialog.colorModel.length
                    ? colorDialog.colorModel[colorPickerDialog.currentIndex].color : ""
            }

            Rectangle {
                width: 60; height: 30; radius: 4
                color: colorInput.text.length === 7 ? colorInput.text : "transparent"
                border.color: Theme.border
            }
        }

        onAccepted: {
            if (typeof app !== "undefined" && colorInput.text.length === 7) {
                app[currentProp] = colorInput.text
            }
        }
    }
}
