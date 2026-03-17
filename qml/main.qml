import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium

import "components" as Components
import "panels"     as Panels
import "dialogs"    as Dialogs

ApplicationWindow {
    id: root

    visible: true
    title: "Decodium 3 FT2"
    width: Theme.isMobile ? Screen.width : 1400
    height: Theme.isMobile ? Screen.height : 900
    minimumWidth: Theme.isMobile ? 320 : 1200
    minimumHeight: Theme.isMobile ? 480 : 800
    color: Theme.background

    // ── Desktop menu bar (hidden on mobile) ──
    menuBar: Theme.isMobile ? null : desktopMenuBar

    MenuBar {
        id: desktopMenuBar
        visible: !Theme.isMobile
        background: Rectangle { color: Theme.surface }

        Menu {
            title: qsTr("&File")
            Action { text: qsTr("&Settings...");  onTriggered: settingsDialog.open() }
            MenuSeparator {}
            Action { text: qsTr("E&xit");         onTriggered: Qt.quit() }
        }
        Menu {
            title: qsTr("&View")
            Action { text: qsTr("&Waterfall");     checkable: true; checked: true }
            Action {
                text: qsTr("&Time Sync Panel")
                checkable: true
                checked: timeSyncPanel.expanded
                onTriggered: timeSyncPanel.expanded = !timeSyncPanel.expanded
            }
            Action {
                text: qsTr("&Active Stations")
                checkable: true
                checked: activeStationsPanel.visible
                onTriggered: activeStationsPanel.visible = !activeStationsPanel.visible
            }
            Action {
                text: qsTr("Astro / &EME")
                checkable: true
                checked: astroPanel.visible
                onTriggered: astroPanel.visible = !astroPanel.visible
            }
            Action {
                text: qsTr("&Message Averaging")
                checkable: true
                checked: msgAvgPanel.visible
                onTriggered: msgAvgPanel.visible = !msgAvgPanel.visible
            }
            MenuSeparator {}
            Action { text: qsTr("&Color Highlighting..."); onTriggered: colorDialog.open() }
        }
        Menu {
            title: qsTr("&Tools")
            Action { text: qsTr("&QSY..."); onTriggered: qsyDialog.open() }
            Action { text: qsTr("Export &Cabrillo..."); onTriggered: { if (typeof logController !== "undefined") logController.exportCabrillo("") } }
            Action { text: qsTr("Update &cty.dat"); onTriggered: { if (typeof app !== "undefined") app.checkCtyDatUpdate() } }
            Action { text: qsTr("Update &LOTW Users"); onTriggered: { if (typeof logController !== "undefined") logController.updateLotwUsers() } }
        }
        Menu {
            title: qsTr("&Mode")
            Action {
                text: qsTr("Fox Mode")
                checkable: true
                checked: typeof tx !== "undefined" && tx.foxMode
                onTriggered: { if (typeof tx !== "undefined") tx.foxMode = checked }
            }
            Action {
                text: qsTr("Hound Mode")
                checkable: true
                checked: typeof tx !== "undefined" && tx.houndMode
                onTriggered: { if (typeof tx !== "undefined") tx.houndMode = checked }
            }
            MenuSeparator {}
            Action {
                text: qsTr("SuperFox")
                checkable: true
                checked: typeof tx !== "undefined" && tx.superFoxMode
                onTriggered: { if (typeof tx !== "undefined") tx.superFoxMode = checked }
            }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("Check for &Updates"); onTriggered: { if (typeof app !== "undefined") app.checkForUpdates() } }
            MenuSeparator {}
            Action { text: qsTr("&About...");      onTriggered: aboutDialog.open() }
        }

        delegate: MenuBarItem {
            id: menuBarItem
            contentItem: Text {
                text: menuBarItem.text
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontNormal
                color: menuBarItem.highlighted ? Theme.accent : Theme.textPrimary
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            background: Rectangle {
                color: menuBarItem.highlighted ? Theme.surfaceLight : Theme.surface
            }
        }
    }

    // ── Mobile hamburger drawer ──
    Drawer {
        id: mobileDrawer
        visible: false
        width: Math.min(root.width * 0.75, 280)
        height: root.height
        edge: Qt.LeftEdge

        background: Rectangle {
            color: Theme.surface
            border.color: Theme.border
            border.width: 1
        }

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            // Drawer header
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 60
                color: Theme.background

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: Theme.margin
                    anchors.rightMargin: Theme.margin

                    Text {
                        text: "DECODIUM 3"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontMedium
                        font.bold: true
                        font.letterSpacing: 2
                        color: Theme.accent
                    }
                }
            }

            Rectangle { Layout.fillWidth: true; height: 1; color: Theme.border }

            // Menu items
            Repeater {
                model: [
                    { text: "Settings", icon: "\u2699", action: function() { settingsDialog.open(); mobileDrawer.close() } },
                    { text: "WiFi Bridge", icon: "\u21C4", action: function() { settingsDialog.open(); mobileDrawer.close() } },
                    { text: "Time Sync", icon: "\u23F1", action: function() { timeSyncPanel.expanded = !timeSyncPanel.expanded; mobileDrawer.close() } },
                    { text: "Active Stations", icon: "\u2637", action: function() { activeStationsPanel.visible = !activeStationsPanel.visible; mobileDrawer.close() } },
                    { text: "Astro / EME", icon: "\u263D", action: function() { astroPanel.visible = !astroPanel.visible; mobileDrawer.close() } },
                    { text: "Message Avg", icon: "\u2261", action: function() { msgAvgPanel.visible = !msgAvgPanel.visible; mobileDrawer.close() } },
                    { text: "QSY", icon: "\u21C5", action: function() { qsyDialog.open(); mobileDrawer.close() } },
                    { text: "Colors", icon: "\u2726", action: function() { colorDialog.open(); mobileDrawer.close() } },
                    { text: "About", icon: "\u2139", action: function() { aboutDialog.open(); mobileDrawer.close() } }
                ]

                delegate: AbstractButton {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 48
                    onClicked: modelData.action()

                    background: Rectangle {
                        color: parent.pressed ? Theme.surfaceLight : "transparent"
                    }

                    contentItem: RowLayout {
                        spacing: Theme.spacing

                        Text {
                            text: modelData.icon
                            font.pixelSize: Theme.fontLarge
                            color: Theme.accent
                            Layout.preferredWidth: 40
                            horizontalAlignment: Text.AlignHCenter
                            Layout.leftMargin: Theme.margin
                        }
                        Text {
                            text: modelData.text
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontNormal
                            color: Theme.textPrimary
                            Layout.fillWidth: true
                        }
                    }
                }
            }

            Item { Layout.fillHeight: true }

            // WiFi status in drawer
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                color: Theme.background

                RowLayout {
                    anchors.fill: parent
                    anchors.leftMargin: Theme.margin
                    anchors.rightMargin: Theme.margin

                    Rectangle {
                        width: 8; height: 8; radius: 4
                        color: (typeof audio !== "undefined" && audio.bridgeConnected)
                               ? Theme.activeGreen : Theme.textDim
                    }
                    Text {
                        text: (typeof audio !== "undefined" && audio.bridgeConnected)
                              ? "Bridge connected" : "Bridge offline"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSmall
                        color: Theme.textSecondary
                        Layout.fillWidth: true
                    }
                }
            }
        }
    }

    // ── Main layout ──
    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        // Mobile: hamburger button row
        Rectangle {
            visible: Theme.isMobile
            Layout.fillWidth: true
            Layout.preferredHeight: Theme.isMobile ? 44 : 0
            color: Theme.surface

            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: Theme.spacingSmall
                anchors.rightMargin: Theme.margin

                // Hamburger button
                AbstractButton {
                    implicitWidth: 40; implicitHeight: 40
                    onClicked: mobileDrawer.open()
                    contentItem: Text {
                        text: "\u2630"
                        font.pixelSize: Theme.fontLarge
                        color: Theme.textPrimary
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    background: Rectangle {
                        radius: Theme.radius
                        color: parent.pressed ? Theme.surfaceLight : "transparent"
                    }
                }

                Text {
                    text: "DECODIUM 3"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    font.bold: true
                    font.letterSpacing: 2
                    color: Theme.accent
                    Layout.fillWidth: true
                }

                // WiFi indicator
                Rectangle {
                    visible: typeof audio !== "undefined" && audio.wifiMode
                    width: 10; height: 10; radius: 5
                    color: (typeof audio !== "undefined" && audio.bridgeConnected)
                           ? Theme.activeGreen : Theme.alertRed
                }
            }
        }

        // Row 1 - Header
        Components.HeaderBar {
            Layout.fillWidth: true
            Layout.preferredHeight: Theme.headerHeight
        }

        // Separator
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Theme.border
        }

        // Row 2 - Waterfall
        Panels.WaterfallPanel {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: Theme.isMobile ? 150 : 200
        }

        // ── Progress bar P1/TX ──
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 25
            color: Theme.surfaceMid

            RowLayout {
                anchors.fill: parent
                spacing: 0

                // Period label
                Text {
                    text: {
                        if (typeof tx !== "undefined" && tx.transmitting) return " TX ";
                        var p = typeof decoder !== "undefined" ? decoder.isEvenPeriod : true;
                        return p ? " P1 " : " P2 ";
                    }
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontSmall
                    font.bold: true
                    color: (typeof tx !== "undefined" && tx.transmitting) ? Theme.alertRed : Theme.accent
                    Layout.preferredWidth: 36
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                // Progress bar
                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.margins: 4
                    color: Theme.surfaceLight
                    radius: 3

                    Rectangle {
                        width: {
                            var prog = typeof decoder !== "undefined" ? decoder.periodProgress : 0;
                            return Math.max(0, Math.min(1, prog)) * parent.width;
                        }
                        height: parent.height
                        radius: 3
                        color: {
                            if (typeof tx !== "undefined" && tx.transmitting)
                                return Qt.rgba(1, 0.2, 0.2, 0.5);
                            return Qt.rgba(0, 0.83, 1.0, 0.3);
                        }

                        Behavior on width {
                            NumberAnimation { duration: 100 }
                        }
                    }
                }

                // Seconds display
                Text {
                    text: {
                        var s = typeof decoder !== "undefined" ? decoder.secInPeriod : 0;
                        return s.toFixed(1) + "s";
                    }
                    font.family: Theme.digitalFont
                    font.pixelSize: Theme.fontTiny
                    color: Theme.textSecondary
                    Layout.preferredWidth: 40
                    horizontalAlignment: Text.AlignRight
                    Layout.rightMargin: 4
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Theme.border
        }

        // Time Sync Panel (collapsible)
        Panels.TimeSyncPanel {
            id: timeSyncPanel
            Layout.fillWidth: true
            Layout.preferredHeight: implicitHeight
        }

        // Row 3 - Decode panels + Active Stations
        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: Theme.isMobile ? 200 : 300
            spacing: 0

            Panels.DecodePanelRow {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            // Active Stations side panel
            Panels.ActiveStationsPanel {
                id: activeStationsPanel
                visible: false
                Layout.preferredWidth: 280
                Layout.fillHeight: true
            }
        }

        // Fox Caller Queue Panel (visible only in Fox mode)
        Panels.CallerQueuePanel {
            id: callerQueuePanel
            Layout.fillWidth: true
            Layout.preferredHeight: typeof tx !== "undefined" && tx.foxMode ? 150 : 0
            visible: typeof tx !== "undefined" && tx.foxMode
        }

        // Astro / EME Panel (togglable)
        Panels.AstroPanel {
            id: astroPanel
            Layout.fillWidth: true
            Layout.preferredHeight: visible ? 160 : 0
            myLat: {
                if (typeof app !== "undefined" && app.grid.length >= 4) {
                    // Quick grid-to-lat approximation
                    var g = app.grid.toUpperCase();
                    return (g.charCodeAt(1) - 65) * 10 + parseInt(g.charAt(3)) - 90;
                }
                return 0;
            }
            myLon: {
                if (typeof app !== "undefined" && app.grid.length >= 4) {
                    var g = app.grid.toUpperCase();
                    return (g.charCodeAt(0) - 65) * 20 + parseInt(g.charAt(2)) * 2 - 180;
                }
                return 0;
            }
        }

        // Message Averaging Panel (togglable)
        Panels.MessageAvgPanel {
            id: msgAvgPanel
            Layout.fillWidth: true
            Layout.preferredHeight: visible ? 140 : 0
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Theme.border
        }

        // Row 4 - Bottom toolbar (bands + modes)
        Panels.BottomToolbar {
            Layout.fillWidth: true
            Layout.preferredHeight: Theme.toolbarHeight
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Theme.border
        }

        // Row 5 - QSO Panel
        Panels.QSOPanel {
            Layout.fillWidth: true
            Layout.preferredHeight: Theme.qsoRowHeight
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Theme.border
        }

        // Row 6 - TX button row
        Panels.TxButtonRow {
            Layout.fillWidth: true
            Layout.preferredHeight: Theme.txRowHeight
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Theme.border
        }

        // Row 6 - Status bar
        Panels.StatusBar {
            Layout.fillWidth: true
            Layout.preferredHeight: Theme.statusBarHeight
        }
    }

    // ── Dialogs ──
    Dialogs.SettingsDialog          { id: settingsDialog }
    Dialogs.LogQSODialog            { id: logQSODialog   }
    Dialogs.AboutDialog             { id: aboutDialog    }
    Dialogs.ColorHighlightingDialog { id: colorDialog    }
    Dialogs.QSYDialog               { id: qsyDialog      }

    // ── Update notification banner ──
    Rectangle {
        id: updateBanner
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 50
        anchors.leftMargin: parent.width * 0.2
        anchors.rightMargin: parent.width * 0.2
        height: visible ? 36 : 0
        visible: typeof app !== "undefined" && app.updateAvailable
        color: Qt.rgba(0, 0.83, 1.0, 0.15)
        border.color: Theme.accent
        border.width: 1
        radius: Theme.radius
        z: 100

        RowLayout {
            anchors.fill: parent
            anchors.margins: Theme.spacingSmall

            Text {
                text: "Update available: " + (typeof app !== "undefined" ? app.latestVersion : "")
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontSmall
                color: Theme.accent
                Layout.fillWidth: true
            }

            AbstractButton {
                implicitWidth: 20; implicitHeight: 20
                onClicked: updateBanner.visible = false
                contentItem: Text {
                    text: "\u2715"
                    font.pixelSize: 12
                    color: Theme.textSecondary
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle { color: "transparent" }
            }
        }
    }
}
