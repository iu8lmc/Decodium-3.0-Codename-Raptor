import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium

Dialog {
    id: aboutDialog
    title: "About Decodium 3"
    modal: true
    width: 440
    height: 420
    anchors.centerIn: parent

    background: Rectangle {
        color: Theme.background
        border.color: Theme.border
        border.width: 1
        radius: Theme.radiusLarge
    }

    header: Item { height: 0 }  // No separate header; content is the header

    contentItem: Item {
        ColumnLayout {
            anchors.fill: parent
            anchors.margins: Theme.marginLarge
            spacing: Theme.spacingLarge

            Item { Layout.preferredHeight: Theme.spacing }

            // ── Decorative accent line ──
            Rectangle {
                Layout.preferredWidth: 80
                Layout.preferredHeight: 2
                Layout.alignment: Qt.AlignHCenter
                color: Theme.accent

                // Glow effect
                Rectangle {
                    anchors.centerIn: parent
                    width: parent.width + 20
                    height: 8
                    radius: 4
                    color: Qt.rgba(0, 0.83, 1.0, 0.08)
                }
            }

            // ── Logo ──
            Text {
                text: "DECODIUM 3"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontGiant
                font.bold: true
                font.letterSpacing: 4
                color: Theme.accent
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                text: "FT2 DIGITAL SUITE"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontNormal
                font.letterSpacing: 6
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignHCenter
            }

            // ── Version ──
            Text {
                text: "Version " + (typeof app !== "undefined" ? app.version : "3.0.0")
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: Theme.textDim
                Layout.alignment: Qt.AlignHCenter
            }

            Item { Layout.preferredHeight: Theme.spacing }

            // ── Separator ──
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 1
                color: Theme.border
            }

            Item { Layout.preferredHeight: Theme.spacingSmall }

            // ── Author ──
            Text {
                text: "by IU8LMC"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontMedium
                font.bold: true
                color: Theme.textPrimary
                Layout.alignment: Qt.AlignHCenter
            }

            Item { Layout.preferredHeight: Theme.spacingSmall }

            // ── Credits ──
            Text {
                text: "Based on WSJT-X by K1JT et al."
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontSmall
                color: Theme.textSecondary
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                text: "WSJT-X Copyright (C) 2001-2025 by Joe Taylor, K1JT"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textDim
                Layout.alignment: Qt.AlignHCenter
            }

            Item { Layout.preferredHeight: Theme.spacing }

            // ── License ──
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: licenseText.implicitHeight + 16
                color: Theme.surfaceLight
                radius: Theme.radius
                border.color: Theme.border
                border.width: 1

                Text {
                    id: licenseText
                    anchors.centerIn: parent
                    width: parent.width - 20
                    text: "This program is free software: you can redistribute it and/or modify it " +
                          "under the terms of the GNU General Public License as published by the " +
                          "Free Software Foundation, either version 3 of the License, or (at your " +
                          "option) any later version."
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontTiny
                    color: Theme.textDim
                    wrapMode: Text.WordWrap
                    horizontalAlignment: Text.AlignHCenter
                    lineHeight: 1.3
                }
            }

            Item { Layout.fillHeight: true }

            // ── Close button ──
            AbstractButton {
                Layout.alignment: Qt.AlignHCenter
                implicitWidth: 100
                implicitHeight: 34

                onClicked: aboutDialog.close()

                background: Rectangle {
                    color: parent.hovered ? Qt.rgba(0, 0.83, 1.0, 0.15) : Qt.rgba(0, 0.83, 1.0, 0.06)
                    border.color: Theme.accent
                    border.width: 1
                    radius: Theme.radius
                }

                contentItem: Text {
                    text: "Close"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    color: Theme.accent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }

    footer: Item { height: 0 }
}
