import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium

Dialog {
    id: settingsDialog
    title: "Settings"
    modal: true
    width: 560
    height: 480
    anchors.centerIn: parent

    background: Rectangle {
        color: Theme.background
        border.color: Theme.border
        border.width: 1
        radius: Theme.radiusLarge
    }

    header: Rectangle {
        width: parent.width
        height: 48
        color: Theme.surface
        radius: Theme.radiusLarge

        // Flatten bottom corners
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
                text: "SETTINGS"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontMedium
                font.bold: true
                font.letterSpacing: 2
                color: Theme.accent
            }
            Item { Layout.fillWidth: true }
            AbstractButton {
                implicitWidth: 28; implicitHeight: 28
                onClicked: settingsDialog.close()
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
        spacing: 0

        // Tab bar
        TabBar {
            id: tabBar
            Layout.fillWidth: true

            background: Rectangle { color: Theme.surface }

            Repeater {
                model: ["General", "Decoder", "Audio", "Radio", "WiFi", "Time", "Advanced"]
                TabButton {
                    text: modelData
                    width: implicitWidth
                    contentItem: Text {
                        text: parent.text
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSmall
                        font.bold: parent.checked
                        color: parent.checked ? Theme.accent : Theme.textSecondary
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    background: Rectangle {
                        color: parent.checked ? Theme.surfaceLight : Theme.surface
                        Rectangle {
                            anchors.bottom: parent.bottom
                            width: parent.width
                            height: 2
                            color: parent.parent.checked ? Theme.accent : "transparent"
                        }
                    }
                }
            }
        }

        Rectangle { Layout.fillWidth: true; height: 1; color: Theme.border }

        // Tab content
        StackLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            currentIndex: tabBar.currentIndex

            // ── General tab ──
            Flickable {
                contentHeight: generalColumn.height
                clip: true

                ColumnLayout {
                    id: generalColumn
                    width: parent.width
                    spacing: Theme.spacingLarge

                    Item { height: Theme.margin }

                    // Callsign
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "CALLSIGN"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        TextField {
                            id: callsignField
                            Layout.fillWidth: true
                            text: typeof app !== "undefined" ? app.callsign : ""
                            placeholderText: "Your callsign"
                            font.family: Theme.digitalFont
                            font.pixelSize: Theme.fontNormal
                            color: Theme.textPrimary

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: callsignField.activeFocus ? Theme.accent : Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                        }
                    }

                    // Grid locator
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "GRID LOCATOR"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        TextField {
                            id: gridField
                            Layout.fillWidth: true
                            text: typeof app !== "undefined" ? app.grid : ""
                            placeholderText: "e.g. JN70FU"
                            font.family: Theme.digitalFont
                            font.pixelSize: Theme.fontNormal
                            color: Theme.textPrimary

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: gridField.activeFocus ? Theme.accent : Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                        }
                    }

                    Item { Layout.fillHeight: true }
                }
            }

            // ── Decoder tab ──
            Flickable {
                contentHeight: decoderColumn.height
                clip: true

                ColumnLayout {
                    id: decoderColumn
                    width: parent.width
                    spacing: Theme.spacingLarge

                    Item { height: Theme.margin }

                    // FT8 Sensitivity
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "FT8 SENSITIVITY"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        ComboBox {
                            id: ft8SensCombo
                            Layout.fillWidth: true
                            model: ["Low", "Normal", "High"]
                            currentIndex: typeof app !== "undefined" ? app.ft8Sensitivity : 1
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall
                            background: Rectangle { color: Theme.surfaceLight; border.color: Theme.border; border.width: 1; radius: Theme.radius }
                            contentItem: Text { text: ft8SensCombo.displayText; font: ft8SensCombo.font; color: Theme.textPrimary; verticalAlignment: Text.AlignVCenter; leftPadding: Theme.spacing }
                        }
                    }

                    // FT8 Decode Cycles
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "FT8 DECODE CYCLES"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        ComboBox {
                            id: ft8CyclesCombo
                            Layout.fillWidth: true
                            model: ["1", "2", "3"]
                            currentIndex: typeof app !== "undefined" ? app.ft8Cycles - 1 : 2
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall
                            background: Rectangle { color: Theme.surfaceLight; border.color: Theme.border; border.width: 1; radius: Theme.radius }
                            contentItem: Text { text: ft8CyclesCombo.displayText; font: ft8CyclesCombo.font; color: Theme.textPrimary; verticalAlignment: Text.AlignVCenter; leftPadding: Theme.spacing }
                        }
                    }

                    // FT8 Decoder Start
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "DECODER START (sec before end)"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        ComboBox {
                            id: decStartCombo
                            Layout.fillWidth: true
                            model: ["1", "2", "3", "4", "5"]
                            currentIndex: typeof app !== "undefined" ? app.ft8DecoderStart - 1 : 2
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall
                            background: Rectangle { color: Theme.surfaceLight; border.color: Theme.border; border.width: 1; radius: Theme.radius }
                            contentItem: Text { text: decStartCombo.displayText; font: decStartCombo.font; color: Theme.textPrimary; verticalAlignment: Text.AlignVCenter; leftPadding: Theme.spacing }
                        }
                    }

                    // Multithread FT8
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "MULTITHREAD FT8"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: multithreadSwitch
                            checked: typeof app !== "undefined" ? app.multithreadFT8 : false
                        }
                    }

                    // Hide FT8 Dupes
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "HIDE FT8 DUPES"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: hideDupesSwitch
                            checked: typeof app !== "undefined" ? app.hideFT8Dupes : false
                        }
                    }

                    // Wide DX Call Search
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "WIDE DX CALL SEARCH"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: wideDxSwitch
                            checked: typeof app !== "undefined" ? app.wideDxCallSearch : false
                        }
                    }

                    // PSK Reporter
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "PSK REPORTER"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: pskReporterSwitch
                            checked: typeof app !== "undefined" ? app.pskReporterEnabled : false
                        }
                    }

                    Item { Layout.fillHeight: true }
                }
            }

            // ── Audio tab ──
            Flickable {
                contentHeight: audioColumn.height
                clip: true

                ColumnLayout {
                    id: audioColumn
                    width: parent.width
                    spacing: Theme.spacingLarge

                    Item { height: Theme.margin }

                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "INPUT DEVICE"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        ComboBox {
                            id: inputDeviceCombo
                            Layout.fillWidth: true
                            model: typeof audio !== "undefined" ? audio.availableInputDevices() : ["Default Input"]
                            currentIndex: {
                                if (typeof audio === "undefined") return 0;
                                var devices = audio.availableInputDevices();
                                var cur = audio.rxDevice;
                                for (var i = 0; i < devices.length; i++) {
                                    if (devices[i] === cur) return i;
                                }
                                return 0;
                            }
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                            contentItem: Text {
                                text: inputDeviceCombo.displayText
                                font: inputDeviceCombo.font
                                color: Theme.textPrimary
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: Theme.spacing
                            }
                        }
                    }

                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "OUTPUT DEVICE"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        ComboBox {
                            id: outputDeviceCombo
                            Layout.fillWidth: true
                            model: typeof audio !== "undefined" ? audio.availableOutputDevices() : ["Default Output"]
                            currentIndex: {
                                if (typeof audio === "undefined") return 0;
                                var devices = audio.availableOutputDevices();
                                var cur = audio.txDevice;
                                for (var i = 0; i < devices.length; i++) {
                                    if (devices[i] === cur) return i;
                                }
                                return 0;
                            }
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                            contentItem: Text {
                                text: outputDeviceCombo.displayText
                                font: outputDeviceCombo.font
                                color: Theme.textPrimary
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: Theme.spacing
                            }
                        }
                    }

                    Item { Layout.fillHeight: true }
                }
            }

            // ── Radio tab ──
            Flickable {
                contentHeight: radioColumn.height
                clip: true

                ColumnLayout {
                    id: radioColumn
                    width: parent.width
                    spacing: Theme.spacingLarge

                    Item { height: Theme.margin }

                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "CAT CONTROL"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        ComboBox {
                            id: catCombo
                            Layout.fillWidth: true
                            model: ["None", "Hamlib", "OmniRig", "Flrig"]
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                            contentItem: Text {
                                text: catCombo.displayText
                                font: catCombo.font
                                color: Theme.textPrimary
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: Theme.spacing
                            }
                        }
                    }

                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "SERIAL PORT"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        ComboBox {
                            id: portCombo
                            Layout.fillWidth: true
                            model: ["COM1", "COM2", "COM3"]
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                            contentItem: Text {
                                text: portCombo.displayText
                                font: portCombo.font
                                color: Theme.textPrimary
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: Theme.spacing
                            }
                        }
                    }

                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "BAUD RATE"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        ComboBox {
                            id: baudCombo
                            Layout.fillWidth: true
                            model: ["4800", "9600", "19200", "38400", "57600", "115200"]
                            currentIndex: 3
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                            contentItem: Text {
                                text: baudCombo.displayText
                                font: baudCombo.font
                                color: Theme.textPrimary
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: Theme.spacing
                            }
                        }
                    }

                    Item { Layout.fillHeight: true }
                }
            }

            // ── WiFi Bridge tab ──
            Flickable {
                contentHeight: wifiColumn.height
                clip: true

                ColumnLayout {
                    id: wifiColumn
                    width: parent.width
                    spacing: Theme.spacingLarge

                    Item { height: Theme.margin }

                    // WiFi mode toggle
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "WIFI BRIDGE MODE"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: wifiModeSwitch
                            checked: typeof audio !== "undefined" ? audio.wifiMode : false
                            onToggled: {
                                if (typeof audio !== "undefined")
                                    audio.wifiMode = checked
                            }
                        }
                    }

                    // Connection status badge
                    Rectangle {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        Layout.fillWidth: true
                        height: 36
                        radius: Theme.radius
                        color: (typeof audio !== "undefined" && audio.bridgeConnected)
                               ? Qt.rgba(0, 1, 0, 0.1) : Qt.rgba(1, 0.2, 0.2, 0.1)
                        border.color: (typeof audio !== "undefined" && audio.bridgeConnected)
                                      ? Theme.activeGreen : Theme.alertRed
                        border.width: 1

                        Text {
                            anchors.centerIn: parent
                            text: (typeof audio !== "undefined" && audio.bridgeConnected)
                                  ? "CONNECTED" : "DISCONNECTED"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall
                            font.bold: true
                            font.letterSpacing: 2
                            color: (typeof audio !== "undefined" && audio.bridgeConnected)
                                   ? Theme.activeGreen : Theme.alertRed
                        }
                    }

                    // Bridge IP address
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "BRIDGE ADDRESS"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        RowLayout {
                            Layout.fillWidth: true
                            spacing: Theme.spacingSmall

                            TextField {
                                id: bridgeAddressField
                                Layout.fillWidth: true
                                text: typeof audio !== "undefined" ? audio.bridgeAddress : ""
                                placeholderText: "192.168.1.100"
                                font.family: Theme.digitalFont
                                font.pixelSize: Theme.fontNormal
                                color: Theme.textPrimary
                                inputMethodHints: Qt.ImhPreferNumbers

                                background: Rectangle {
                                    color: Theme.surfaceLight
                                    border.color: bridgeAddressField.activeFocus ? Theme.accent : Theme.border
                                    border.width: 1
                                    radius: Theme.radius
                                }
                            }

                            // Scan button
                            AbstractButton {
                                implicitWidth: 70; implicitHeight: 34
                                onClicked: {
                                    if (typeof audio !== "undefined")
                                        audio.startBridgeDiscovery()
                                }
                                background: Rectangle {
                                    color: parent.hovered ? Theme.surfaceLight : Theme.surface
                                    border.color: Theme.accent
                                    border.width: 1
                                    radius: Theme.radius
                                }
                                contentItem: Text {
                                    text: "Scan"
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontSmall
                                    color: Theme.accent
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }
                            }
                        }
                    }

                    // Discovered bridges list
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "DISCOVERED BRIDGES"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }

                        ListView {
                            id: bridgeList
                            Layout.fillWidth: true
                            Layout.preferredHeight: Math.max(60, contentHeight)
                            clip: true
                            model: ListModel { id: bridgeListModel }

                            delegate: AbstractButton {
                                width: bridgeList.width
                                height: 32
                                onClicked: {
                                    bridgeAddressField.text = model.address
                                    if (typeof audio !== "undefined")
                                        audio.bridgeAddress = model.address
                                }
                                background: Rectangle {
                                    color: parent.hovered ? Theme.surfaceLight : Theme.surface
                                    radius: Theme.radius
                                }
                                contentItem: Text {
                                    text: model.address + ":" + model.port
                                    font.family: Theme.digitalFont
                                    font.pixelSize: Theme.fontSmall
                                    color: Theme.textPrimary
                                    verticalAlignment: Text.AlignVCenter
                                    leftPadding: Theme.spacing
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

                    // Connect / Disconnect button
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        Layout.fillWidth: true

                        Item { Layout.fillWidth: true }

                        AbstractButton {
                            implicitWidth: 140; implicitHeight: 38
                            onClicked: {
                                if (typeof audio !== "undefined") {
                                    audio.bridgeAddress = bridgeAddressField.text
                                    if (audio.bridgeConnected)
                                        audio.disconnectFromBridge()
                                    else
                                        audio.connectToBridge()
                                }
                            }
                            background: Rectangle {
                                color: (typeof audio !== "undefined" && audio.bridgeConnected)
                                       ? Qt.rgba(1, 0.2, 0.2, 0.15)
                                       : Qt.rgba(0, 0.83, 1.0, 0.15)
                                border.color: (typeof audio !== "undefined" && audio.bridgeConnected)
                                              ? Theme.alertRed : Theme.accent
                                border.width: 1
                                radius: Theme.radius
                            }
                            contentItem: Text {
                                text: (typeof audio !== "undefined" && audio.bridgeConnected)
                                      ? "Disconnect" : "Connect"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSmall
                                font.bold: true
                                color: (typeof audio !== "undefined" && audio.bridgeConnected)
                                       ? Theme.alertRed : Theme.accent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }

                    Item { Layout.fillHeight: true }
                }

                // Handle bridge discovery signal
                Connections {
                    target: typeof audio !== "undefined" ? audio : null
                    function onBridgeDiscovered(address, port) {
                        // Avoid duplicates
                        for (var i = 0; i < bridgeListModel.count; i++) {
                            if (bridgeListModel.get(i).address === address) return
                        }
                        bridgeListModel.append({"address": address, "port": port})
                    }
                }
            }

            // ── Time tab ──
            Flickable {
                contentHeight: timeColumn.height
                clip: true

                ColumnLayout {
                    id: timeColumn
                    width: parent.width
                    spacing: Theme.spacingLarge

                    Item { height: Theme.margin }

                    // NTP Enable
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "NTP TIME SYNC"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: ntpSwitch
                            checked: typeof app !== "undefined" ? app.ntpEnabled : true
                        }
                    }

                    // NTP Status
                    Rectangle {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        Layout.fillWidth: true
                        height: 36
                        radius: Theme.radius
                        color: (typeof app !== "undefined" && app.ntpSynced)
                               ? Qt.rgba(0, 1, 0, 0.1) : Qt.rgba(1, 0.2, 0.2, 0.1)
                        border.color: (typeof app !== "undefined" && app.ntpSynced)
                                      ? Theme.activeGreen : Theme.alertRed
                        border.width: 1

                        Text {
                            anchors.centerIn: parent
                            text: (typeof app !== "undefined" && app.ntpSynced)
                                  ? "SYNCED" : "NOT SYNCED"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall
                            font.bold: true
                            font.letterSpacing: 2
                            color: (typeof app !== "undefined" && app.ntpSynced)
                                   ? Theme.activeGreen : Theme.alertRed
                        }
                    }

                    // NTP Offset Display
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall

                        Text {
                            text: "CLOCK OFFSET"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        Text {
                            text: (typeof app !== "undefined")
                                  ? app.ntpOffsetMs.toFixed(1) + " ms"
                                  : "-- ms"
                            font.family: Theme.digitalFont
                            font.pixelSize: Theme.fontLarge
                            color: {
                                if (typeof app === "undefined") return Theme.textSecondary
                                var abs = Math.abs(app.ntpOffsetMs)
                                if (abs < 100) return Theme.activeGreen
                                if (abs < 500) return Theme.warning
                                return Theme.alertRed
                            }
                        }
                    }

                    Item { Layout.fillHeight: true }
                }
            }

            // ── Advanced tab ──
            Flickable {
                contentHeight: advancedColumn.height
                clip: true

                ColumnLayout {
                    id: advancedColumn
                    width: parent.width
                    spacing: Theme.spacingLarge

                    Item { height: Theme.margin }

                    // LOTW Integration
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "LOTW INTEGRATION"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: lotwSwitch
                            checked: typeof logController !== "undefined" ? logController.lotwEnabled : false
                        }
                    }

                    // Update LOTW Users button
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        Layout.fillWidth: true
                        visible: lotwSwitch.checked

                        Text {
                            text: "Download latest LOTW user list"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        AbstractButton {
                            implicitWidth: 80; implicitHeight: 30
                            onClicked: {
                                if (typeof logController !== "undefined")
                                    logController.updateLotwUsers()
                            }
                            background: Rectangle {
                                color: parent.hovered ? Theme.surfaceLight : Theme.surface
                                border.color: Theme.accent
                                border.width: 1
                                radius: Theme.radius
                            }
                            contentItem: Text {
                                text: "Update"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSmall
                                color: Theme.accent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }

                    Rectangle { Layout.fillWidth: true; Layout.leftMargin: Theme.marginLarge; Layout.rightMargin: Theme.marginLarge; height: 1; color: Theme.border }

                    // Alert Sounds
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "ALERT SOUNDS"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: alertSoundsSwitch
                            checked: typeof app !== "undefined" ? app.alertSoundsEnabled : false
                        }
                    }

                    Rectangle { Layout.fillWidth: true; Layout.leftMargin: Theme.marginLarge; Layout.rightMargin: Theme.marginLarge; height: 1; color: Theme.border }

                    // Contest Mode
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "CONTEST MODE"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: contestSwitch
                            checked: typeof logController !== "undefined" ? logController.contestMode : false
                        }
                    }

                    // Contest Name
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall
                        visible: contestSwitch.checked

                        Text {
                            text: "CONTEST NAME"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        TextField {
                            id: contestNameField
                            Layout.fillWidth: true
                            text: typeof logController !== "undefined" ? logController.contestName : ""
                            placeholderText: "e.g. CQ-WW-CW"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontNormal
                            color: Theme.textPrimary

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: contestNameField.activeFocus ? Theme.accent : Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                        }
                    }

                    Rectangle { Layout.fillWidth: true; Layout.leftMargin: Theme.marginLarge; Layout.rightMargin: Theme.marginLarge; height: 1; color: Theme.border }

                    // Color Highlighting
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        Layout.fillWidth: true

                        Text {
                            text: "COLOR HIGHLIGHTING"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        AbstractButton {
                            implicitWidth: 100; implicitHeight: 30
                            onClicked: {
                                settingsDialog.close()
                                if (typeof colorHighlightingDialog !== "undefined")
                                    colorHighlightingDialog.open()
                            }
                            background: Rectangle {
                                color: parent.hovered ? Theme.surfaceLight : Theme.surface
                                border.color: Theme.accent
                                border.width: 1
                                radius: Theme.radius
                            }
                            contentItem: Text {
                                text: "Configure..."
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSmall
                                color: Theme.accent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }

                    Rectangle { Layout.fillWidth: true; Layout.leftMargin: Theme.marginLarge; Layout.rightMargin: Theme.marginLarge; height: 1; color: Theme.border }

                    // Cloudlog
                    RowLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacing

                        Text {
                            text: "CLOUDLOG"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: cloudlogSwitch
                            checked: typeof app !== "undefined" ? app.cloudlogEnabled : false
                        }
                    }

                    // Cloudlog URL
                    ColumnLayout {
                        Layout.leftMargin: Theme.marginLarge
                        Layout.rightMargin: Theme.marginLarge
                        spacing: Theme.spacingSmall
                        visible: cloudlogSwitch.checked

                        Text {
                            text: "CLOUDLOG URL"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        TextField {
                            id: cloudlogUrlField
                            Layout.fillWidth: true
                            text: typeof app !== "undefined" ? app.cloudlogUrl : ""
                            placeholderText: "https://cloudlog.example.com"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall
                            color: Theme.textPrimary

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: cloudlogUrlField.activeFocus ? Theme.accent : Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                        }

                        Text {
                            text: "CLOUDLOG API KEY"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontTiny
                            font.letterSpacing: 2
                            color: Theme.textSecondary
                        }
                        TextField {
                            id: cloudlogApiKeyField
                            Layout.fillWidth: true
                            text: typeof app !== "undefined" ? app.cloudlogApiKey : ""
                            placeholderText: "API key"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSmall
                            color: Theme.textPrimary
                            echoMode: TextInput.Password

                            background: Rectangle {
                                color: Theme.surfaceLight
                                border.color: cloudlogApiKeyField.activeFocus ? Theme.accent : Theme.border
                                border.width: 1
                                radius: Theme.radius
                            }
                        }
                    }

                    Item { Layout.fillHeight: true }
                }
            }
        }
    }

    footer: Rectangle {
        width: parent.width
        height: 50
        color: Theme.surface
        radius: Theme.radiusLarge

        Rectangle {
            anchors.top: parent.top
            width: parent.width
            height: Theme.radiusLarge
            color: Theme.surface
        }

        Rectangle {
            anchors.top: parent.top
            width: parent.width
            height: 1
            color: Theme.border
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: Theme.marginLarge
            anchors.rightMargin: Theme.marginLarge

            Item { Layout.fillWidth: true }

            AbstractButton {
                implicitWidth: 90; implicitHeight: 34
                onClicked: settingsDialog.close()
                background: Rectangle {
                    color: parent.hovered ? Theme.surfaceLight : Theme.surface
                    border.color: Theme.border
                    border.width: 1
                    radius: Theme.radius
                }
                contentItem: Text {
                    text: "Cancel"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    color: Theme.textSecondary
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            AbstractButton {
                implicitWidth: 90; implicitHeight: 34
                onClicked: {
                    if (typeof app !== "undefined") {
                        app.callsign = callsignField.text;
                        app.grid = gridField.text;
                        // Decoder settings
                        app.ft8Sensitivity = ft8SensCombo.currentIndex;
                        app.ft8Cycles = ft8CyclesCombo.currentIndex + 1;
                        app.ft8DecoderStart = decStartCombo.currentIndex + 1;
                        app.multithreadFT8 = multithreadSwitch.checked;
                        app.hideFT8Dupes = hideDupesSwitch.checked;
                        app.wideDxCallSearch = wideDxSwitch.checked;
                        app.pskReporterEnabled = pskReporterSwitch.checked;
                        // NTP
                        app.ntpEnabled = ntpSwitch.checked;
                        // Advanced
                        app.alertSoundsEnabled = alertSoundsSwitch.checked;
                        if (typeof app.cloudlogEnabled !== "undefined") {
                            app.cloudlogEnabled = cloudlogSwitch.checked;
                            app.cloudlogUrl = cloudlogUrlField.text;
                            app.cloudlogApiKey = cloudlogApiKeyField.text;
                        }
                    }
                    if (typeof audio !== "undefined") {
                        audio.rxDevice = inputDeviceCombo.currentText;
                        audio.txDevice = outputDeviceCombo.currentText;
                    }
                    if (typeof logController !== "undefined") {
                        logController.lotwEnabled = lotwSwitch.checked;
                        logController.contestMode = contestSwitch.checked;
                        logController.contestName = contestNameField.text;
                    }
                    settingsDialog.close();
                }
                background: Rectangle {
                    color: parent.hovered ? Qt.rgba(0, 0.83, 1.0, 0.2) : Qt.rgba(0, 0.83, 1.0, 0.1)
                    border.color: Theme.accent
                    border.width: 1
                    radius: Theme.radius
                }
                contentItem: Text {
                    text: "Apply"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    font.bold: true
                    color: Theme.accent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
}
