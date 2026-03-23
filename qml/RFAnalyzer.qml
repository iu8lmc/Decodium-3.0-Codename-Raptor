import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    color: "#060A16"

    // ── Color palette ──
    readonly property color cBg:    "#060A16"
    readonly property color cBg2:   "#0A1020"
    readonly property color cBg3:   "#0E1630"
    readonly property color cGold:  "#C9A84C"
    readonly property color cGoldL: "#E8C97A"
    readonly property color cTeal:  "#1BBFB0"
    readonly property color cTealD: "#0E7068"
    readonly property color cRed:   "#D44632"
    readonly property color cGreen: "#2ECC71"
    readonly property color cWhite: "#F0F4F8"
    readonly property color cGrey:  "#8AA0B0"
    readonly property color cGreyD: "#3A5060"

    // ── Mode database ──
    readonly property var modes: ({
        "FT2":  {bw:167, tr:3.75, sym:103, mod:"4-GFSK",    snr:"-25 dB", sp:"41.7 Hz",  freq:"14.084 MHz"},
        "FT8":  {bw:50,  tr:15,   sym:79,  mod:"8-GFSK",    snr:"-20 dB", sp:"6.25 Hz",  freq:"14.074 MHz"},
        "FT4":  {bw:83,  tr:7.5,  sym:103, mod:"4-GFSK",    snr:"-18 dB", sp:"20.8 Hz",  freq:"14.080 MHz"},
        "JT65": {bw:178, tr:60,   sym:126, mod:"65-FSK",     snr:"-25 dB", sp:"2.69 Hz",  freq:"\u2014"},
        "WSPR": {bw:6,   tr:120,  sym:162, mod:"4-FSK",      snr:"-31 dB", sp:"1.46 Hz",  freq:"14.0956 MHz"},
        "CW":   {bw:500, tr:0,    sym:0,   mod:"OOK",        snr:"~10 dB", sp:"\u2014",   freq:"\u2014"},
        "SSB":  {bw:2700,tr:0,    sym:0,   mod:"AM-DSB-SC",  snr:"~10 dB", sp:"\u2014",   freq:"\u2014"}
    })

    property string currentMode: analyzer ? analyzer.mode : "FT8"

    // ── Controls bar ──
    Rectangle {
        id: controlsBar
        anchors { left: parent.left; right: parent.right; top: parent.top }
        height: 34
        color: Qt.rgba(0.04, 0.06, 0.12, 0.8)
        border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1

        RowLayout {
            anchors.fill: parent; anchors.margins: 4; spacing: 10

            Text { text: "MODE"; color: root.cGreyD; font.family: "Consolas"; font.pixelSize: 10; Layout.alignment: Qt.AlignVCenter }
            ComboBox {
                id: modeCombo
                model: ["FT2","FT8","FT4","JT65","WSPR","CW","SSB"]
                currentIndex: 1
                font.family: "Consolas"; font.pixelSize: 11
                onCurrentTextChanged: { if (analyzer) analyzer.mode = currentText; root.currentMode = currentText }
                background: Rectangle { color: root.cBg3; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); radius: 3 }
                contentItem: Text { text: modeCombo.currentText; color: root.cWhite; font: modeCombo.font; verticalAlignment: Text.AlignVCenter; leftPadding: 6 }
                implicitWidth: 70; implicitHeight: 24
            }

            Text { text: "REF dB"; color: root.cGreyD; font.family: "Consolas"; font.pixelSize: 10; Layout.alignment: Qt.AlignVCenter }
            Slider { id: refSlider; from: -120; to: 0; value: analyzer ? analyzer.refDB : -30; stepSize: 1; implicitWidth: 90; implicitHeight: 20
                onValueChanged: if (analyzer) analyzer.refDB = value
                background: Rectangle { x: refSlider.leftPadding; width: refSlider.availableWidth; height: 4; radius: 2; color: root.cBg3; y: refSlider.topPadding + refSlider.availableHeight/2 - 2 }
                handle: Rectangle { x: refSlider.leftPadding + refSlider.visualPosition * refSlider.availableWidth - 7; y: refSlider.topPadding + refSlider.availableHeight/2 - 7; width: 14; height: 14; radius: 7; color: root.cGold }
            }
            Text { text: refSlider.value.toFixed(0); color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10; Layout.alignment: Qt.AlignVCenter }

            Text { text: "RANGE"; color: root.cGreyD; font.family: "Consolas"; font.pixelSize: 10; Layout.alignment: Qt.AlignVCenter }
            Slider { id: rangeSlider; from: 40; to: 120; value: analyzer ? analyzer.rangeDB : 80; stepSize: 1; implicitWidth: 90; implicitHeight: 20
                onValueChanged: if (analyzer) analyzer.rangeDB = value
                background: Rectangle { x: rangeSlider.leftPadding; width: rangeSlider.availableWidth; height: 4; radius: 2; color: root.cBg3; y: rangeSlider.topPadding + rangeSlider.availableHeight/2 - 2 }
                handle: Rectangle { x: rangeSlider.leftPadding + rangeSlider.visualPosition * rangeSlider.availableWidth - 7; y: rangeSlider.topPadding + rangeSlider.availableHeight/2 - 7; width: 14; height: 14; radius: 7; color: root.cGold }
            }
            Text { text: rangeSlider.value.toFixed(0); color: root.cGoldL; font.family: "Consolas"; font.pixelSize: 10; Layout.alignment: Qt.AlignVCenter }

            Item { Layout.fillWidth: true }

            Rectangle {
                width: 90; height: 22; radius: 3
                color: Qt.rgba(0.83,0.27,0.2,0.08); border.color: Qt.rgba(0.83,0.27,0.2,0.4)
                Text { anchors.centerIn: parent; text: "RESET PEAK"; color: root.cRed; font.family: "Consolas"; font.pixelSize: 9 }
                MouseArea { anchors.fill: parent; cursorShape: Qt.PointingHandCursor; onClicked: if (analyzer) analyzer.resetPeak() }
            }
        }
    }

    // ── Main grid ──
    GridLayout {
        anchors { left: parent.left; right: parent.right; top: controlsBar.bottom; bottom: parent.bottom; margins: 2 }
        columns: 3; rows: 4; columnSpacing: 2; rowSpacing: 2

        // ═══ Row 0: Spectrum (wide) + Meters ═══
        Rectangle {
            color: root.cBg2; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1
            Layout.columnSpan: 2; Layout.fillWidth: true; Layout.fillHeight: true; Layout.preferredHeight: 3
            Rectangle { anchors.fill: parent; color: Qt.rgba(0.1, 0.75, 0.69, 0.03) }
            Rectangle {
                id: specHdr; anchors { left: parent.left; right: parent.right; top: parent.top }; height: 26; color: Qt.rgba(0, 0, 0, 0.3)
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: Qt.rgba(0.79, 0.66, 0.30, 0.18) }
                Text { x: 12; anchors.verticalCenter: parent.verticalCenter; text: "\u25C8 SPECTRUM FFT"; color: root.cGold; font.family: "Segoe UI"; font.pixelSize: 10; font.bold: true; font.letterSpacing: 2 }
                Text { anchors { right: parent.right; rightMargin: 12; verticalCenter: parent.verticalCenter }
                    text: analyzer ? "Peak: " + analyzer.peakFreq.toFixed(1) + " Hz / " + analyzer.peakLevel.toFixed(1) + " dBFS" : ""
                    color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10 }
            }
            Canvas {
                id: specCanvas; anchors { fill: parent; topMargin: 26 }
                onPaint: drawFn.drawSpectrum(specCanvas)
                Connections { target: analyzer; onDataChanged: specCanvas.requestPaint() }
            }
        }

        Rectangle {
            color: root.cBg2; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1
            Layout.fillWidth: true; Layout.fillHeight: true; Layout.preferredHeight: 3; Layout.minimumWidth: 200
            Rectangle { anchors.fill: parent; color: Qt.rgba(0.1, 0.75, 0.69, 0.03) }
            Rectangle {
                anchors { left: parent.left; right: parent.right; top: parent.top }; height: 26; color: Qt.rgba(0, 0, 0, 0.3)
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: Qt.rgba(0.79, 0.66, 0.30, 0.18) }
                Text { x: 12; anchors.verticalCenter: parent.verticalCenter; text: "\u25C8 LIVE METERS"; color: root.cGold; font.family: "Segoe UI"; font.pixelSize: 10; font.bold: true; font.letterSpacing: 2 }
                Text { anchors { right: parent.right; rightMargin: 12; verticalCenter: parent.verticalCenter }
                    text: analyzer ? "SNR " + analyzer.snr.toFixed(1) + " dB" : ""; color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10 }
            }
            Canvas {
                id: metersCanvas; anchors { fill: parent; topMargin: 26 }
                onPaint: drawFn.drawMeters(metersCanvas)
                Connections { target: analyzer; onDataChanged: metersCanvas.requestPaint() }
            }
        }

        // ═══ Row 1: Waterfall (wide) + Mode Info ═══
        Rectangle {
            color: root.cBg2; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1
            Layout.columnSpan: 2; Layout.fillWidth: true; Layout.fillHeight: true; Layout.preferredHeight: 2
            Rectangle { anchors.fill: parent; color: Qt.rgba(0.1, 0.75, 0.69, 0.03) }
            Rectangle {
                anchors { left: parent.left; right: parent.right; top: parent.top }; height: 26; color: Qt.rgba(0, 0, 0, 0.3)
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: Qt.rgba(0.79, 0.66, 0.30, 0.18) }
                Text { x: 12; anchors.verticalCenter: parent.verticalCenter; text: "\u25C8 WATERFALL"; color: root.cGold; font.family: "Segoe UI"; font.pixelSize: 10; font.bold: true; font.letterSpacing: 2 }
                Text { anchors { right: parent.right; rightMargin: 12; verticalCenter: parent.verticalCenter }; text: "SCROLL: LIVE"; color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10 }
            }
            Canvas {
                id: wfCanvas; anchors { fill: parent; topMargin: 26 }
                property var rows: []
                onPaint: drawFn.drawWaterfall(wfCanvas)
                Connections {
                    target: analyzer
                    onDataChanged: {
                        var row = analyzer.getWaterfallRow()
                        wfCanvas.rows.unshift(row)
                        if (wfCanvas.rows.length > Math.max(1, Math.floor(wfCanvas.height)))
                            wfCanvas.rows.length = Math.floor(wfCanvas.height)
                        wfCanvas.requestPaint()
                    }
                }
            }
        }

        Rectangle {
            color: root.cBg2; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1
            Layout.fillWidth: true; Layout.fillHeight: true; Layout.preferredHeight: 2; Layout.minimumWidth: 200
            Rectangle { anchors.fill: parent; color: Qt.rgba(0.1, 0.75, 0.69, 0.03) }
            Rectangle {
                anchors { left: parent.left; right: parent.right; top: parent.top }; height: 26; color: Qt.rgba(0, 0, 0, 0.3)
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: Qt.rgba(0.79, 0.66, 0.30, 0.18) }
                Text { x: 12; anchors.verticalCenter: parent.verticalCenter; text: "\u25C8 MODE INFO"; color: root.cGold; font.family: "Segoe UI"; font.pixelSize: 10; font.bold: true; font.letterSpacing: 2 }
                Text { anchors { right: parent.right; rightMargin: 12; verticalCenter: parent.verticalCenter }; text: root.currentMode; color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10 }
            }
            Canvas {
                id: modeCanvas; anchors { fill: parent; topMargin: 26 }
                onPaint: drawFn.drawModeInfo(modeCanvas)
                Connections { target: analyzer; onSettingsChanged: modeCanvas.requestPaint() }
                Component.onCompleted: requestPaint()
            }
        }

        // ═══ Row 2: Waveform (wide) + Timing ═══
        Rectangle {
            color: root.cBg2; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1
            Layout.columnSpan: 2; Layout.fillWidth: true; Layout.fillHeight: true; Layout.preferredHeight: 2
            Rectangle { anchors.fill: parent; color: Qt.rgba(0.1, 0.75, 0.69, 0.03) }
            Rectangle {
                anchors { left: parent.left; right: parent.right; top: parent.top }; height: 26; color: Qt.rgba(0, 0, 0, 0.3)
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: Qt.rgba(0.79, 0.66, 0.30, 0.18) }
                Text { x: 12; anchors.verticalCenter: parent.verticalCenter; text: "\u25C8 WAVEFORM + RAMP TX"; color: root.cGold; font.family: "Segoe UI"; font.pixelSize: 10; font.bold: true; font.letterSpacing: 2 }
                Text { anchors { right: parent.right; rightMargin: 12; verticalCenter: parent.verticalCenter }
                    text: analyzer && analyzer.zeroCrossRate > 0 ? analyzer.zeroCrossRate + " Hz" : "-- Hz"
                    color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10 }
            }
            Canvas {
                id: waveCanvas; anchors { fill: parent; topMargin: 26 }
                onPaint: drawFn.drawWaveform(waveCanvas)
                Connections { target: analyzer; onDataChanged: waveCanvas.requestPaint() }
            }
        }

        Rectangle {
            color: root.cBg2; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1
            Layout.fillWidth: true; Layout.fillHeight: true; Layout.preferredHeight: 2; Layout.minimumWidth: 200
            Rectangle { anchors.fill: parent; color: Qt.rgba(0.1, 0.75, 0.69, 0.03) }
            Rectangle {
                anchors { left: parent.left; right: parent.right; top: parent.top }; height: 26; color: Qt.rgba(0, 0, 0, 0.3)
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: Qt.rgba(0.79, 0.66, 0.30, 0.18) }
                Text { x: 12; anchors.verticalCenter: parent.verticalCenter; text: "\u25C8 TIMING / PERIODS"; color: root.cGold; font.family: "Segoe UI"; font.pixelSize: 10; font.bold: true; font.letterSpacing: 2 }
                Text { anchors { right: parent.right; rightMargin: 12; verticalCenter: parent.verticalCenter }
                    text: analyzer && analyzer.trPeriod > 0 ? "T/R " + (analyzer.trPeriod/1000).toFixed(1) + "s" : "T/R --s"
                    color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10 }
            }
            Canvas {
                id: timingCanvas; anchors { fill: parent; topMargin: 26 }
                onPaint: drawFn.drawTiming(timingCanvas)
                Connections { target: analyzer; onDataChanged: timingCanvas.requestPaint() }
            }
        }

        // ═══ Row 3: Tone Curve (wide) + ATT/Loss ═══
        Rectangle {
            color: root.cBg2; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1
            Layout.columnSpan: 2; Layout.fillWidth: true; Layout.fillHeight: true; Layout.preferredHeight: 2
            Rectangle { anchors.fill: parent; color: Qt.rgba(0.1, 0.75, 0.69, 0.03) }
            Rectangle {
                anchors { left: parent.left; right: parent.right; top: parent.top }; height: 26; color: Qt.rgba(0, 0, 0, 0.3)
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: Qt.rgba(0.79, 0.66, 0.30, 0.18) }
                Text { x: 12; anchors.verticalCenter: parent.verticalCenter; text: "\u25C8 TONE CURVE + ATT"; color: root.cGold; font.family: "Segoe UI"; font.pixelSize: 10; font.bold: true; font.letterSpacing: 2 }
                Text { anchors { right: parent.right; rightMargin: 12; verticalCenter: parent.verticalCenter }
                    text: analyzer ? "Fund: " + analyzer.peakFreq.toFixed(1) + " Hz" : ""; color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10 }
            }
            Canvas {
                id: toneCanvas; anchors { fill: parent; topMargin: 26 }
                onPaint: drawFn.drawToneCurve(toneCanvas)
                Connections { target: analyzer; onDataChanged: toneCanvas.requestPaint() }
            }
        }

        Rectangle {
            color: root.cBg2; border.color: Qt.rgba(0.79, 0.66, 0.30, 0.18); border.width: 1
            Layout.fillWidth: true; Layout.fillHeight: true; Layout.preferredHeight: 2; Layout.minimumWidth: 200
            Rectangle { anchors.fill: parent; color: Qt.rgba(0.1, 0.75, 0.69, 0.03) }
            Rectangle {
                anchors { left: parent.left; right: parent.right; top: parent.top }; height: 26; color: Qt.rgba(0, 0, 0, 0.3)
                Rectangle { anchors.bottom: parent.bottom; width: parent.width; height: 1; color: Qt.rgba(0.79, 0.66, 0.30, 0.18) }
                Text { x: 12; anchors.verticalCenter: parent.verticalCenter; text: "\u25C8 ATT / LOSS / DISTURBI"; color: root.cGold; font.family: "Segoe UI"; font.pixelSize: 10; font.bold: true; font.letterSpacing: 2 }
                Text { anchors { right: parent.right; rightMargin: 12; verticalCenter: parent.verticalCenter }
                    text: analyzer ? "\u03A3 " + Math.max(0, -analyzer.maxDB - 30).toFixed(1) + " dB" : ""; color: root.cTeal; font.family: "Consolas"; font.pixelSize: 10 }
            }
            Canvas {
                id: attCanvas; anchors { fill: parent; topMargin: 26 }
                onPaint: drawFn.drawAttLoss(attCanvas)
                Connections { target: analyzer; onDataChanged: attCanvas.requestPaint() }
            }
        }
    }

    // ── Drawing functions ──
    QtObject {
        id: drawFn

        function dbToY(db, h, ref, range) { return h * (1.0 - (db - (ref - range)) / range) }

        function drawSpectrum(cv) {
            var ctx = cv.getContext("2d")
            var W = cv.width, H = cv.height
            if (W < 10 || H < 10 || !analyzer) return
            ctx.clearRect(0, 0, W, H)
            var data = analyzer.spectrumData, N = data.length
            if (N < 2) return
            var ref = analyzer.refDB, range = analyzer.rangeDB, maxFreq = analyzer.spectrumSize * analyzer.df
            // Grid dB
            ctx.font = "9px Consolas"; ctx.strokeStyle = "rgba(58,80,96,0.4)"; ctx.lineWidth = 1
            for (var dB = 0; dB >= -120; dB -= 10) {
                if (dB < ref - range || dB > ref) continue
                var y = dbToY(dB, H, ref, range)
                ctx.beginPath(); ctx.moveTo(0, y); ctx.lineTo(W, y); ctx.stroke()
                ctx.fillStyle = "rgba(84,110,122,0.7)"; ctx.fillText(dB + "dB", 4, y - 2)
            }
            // Grid freq
            var fmarks = [500, 1000, 2000, 3000, 4000, 5000]
            for (var fi = 0; fi < fmarks.length; fi++) {
                var f = fmarks[fi]; if (f > maxFreq) break
                var x = (f / maxFreq) * W
                ctx.beginPath(); ctx.moveTo(x, 0); ctx.lineTo(x, H); ctx.stroke()
                ctx.fillStyle = "rgba(84,110,122,0.7)"; ctx.fillText(f >= 1000 ? (f/1000) + "k" : f, x + 3, H - 4)
            }
            // Noise floor
            var nfY = dbToY(analyzer.noiseFloor, H, ref, range)
            ctx.strokeStyle = "rgba(212,70,50,0.5)"; ctx.setLineDash([6, 4])
            ctx.beginPath(); ctx.moveTo(0, nfY); ctx.lineTo(W, nfY); ctx.stroke(); ctx.setLineDash([])
            ctx.fillStyle = "rgba(212,70,50,0.8)"; ctx.fillText("NF " + analyzer.noiseFloor.toFixed(1) + "dB", W - 110, nfY - 3)
            // Peak hold
            var pkY = dbToY(analyzer.peakDB, H, ref, range)
            ctx.strokeStyle = "rgba(201,168,76,0.6)"; ctx.setLineDash([3, 6])
            ctx.beginPath(); ctx.moveTo(0, pkY); ctx.lineTo(W, pkY); ctx.stroke(); ctx.setLineDash([])
            // Mode BW
            var md = root.modes[root.currentMode]
            if (md && md.bw > 0 && maxFreq > 0) {
                var fc = 1000, bw = md.bw
                var x1 = ((fc - bw/2) / maxFreq) * W, x2 = ((fc + bw/2) / maxFreq) * W
                ctx.fillStyle = "rgba(201,168,76,0.08)"; ctx.fillRect(x1, 0, x2 - x1, H)
                ctx.strokeStyle = "rgba(201,168,76,0.4)"; ctx.lineWidth = 1; ctx.strokeRect(x1, 0, x2 - x1, H)
                ctx.fillStyle = "rgba(201,168,76,0.7)"; ctx.fillText(root.currentMode + " " + bw + "Hz", x1 + 4, 14)
            }
            // Fill under curve
            var grad = ctx.createLinearGradient(0, 0, 0, H)
            grad.addColorStop(0, "rgba(27,191,176,0.35)"); grad.addColorStop(0.5, "rgba(27,191,176,0.12)"); grad.addColorStop(1, "rgba(27,191,176,0.02)")
            ctx.beginPath()
            for (var i = 0; i < N; i++) {
                var sx = (i / N) * W, sy = Math.max(0, Math.min(H, dbToY(data[i], H, ref, range)))
                i === 0 ? ctx.moveTo(sx, sy) : ctx.lineTo(sx, sy)
            }
            ctx.lineTo(W, H); ctx.lineTo(0, H); ctx.closePath(); ctx.fillStyle = grad; ctx.fill()
            // Spectrum line
            ctx.beginPath()
            for (i = 0; i < N; i++) {
                sx = (i / N) * W; sy = Math.max(0, Math.min(H, dbToY(data[i], H, ref, range)))
                i === 0 ? ctx.moveTo(sx, sy) : ctx.lineTo(sx, sy)
            }
            ctx.strokeStyle = "rgba(27,191,176,0.9)"; ctx.lineWidth = 1.5; ctx.stroke()
            // Peak marker
            var mIdx = 0
            for (i = 1; i < N; i++) if (data[i] > data[mIdx]) mIdx = i
            var px = (mIdx / N) * W, py = Math.max(0, Math.min(H, dbToY(data[mIdx], H, ref, range)))
            var rg = ctx.createRadialGradient(px, py, 0, px, py, 12)
            rg.addColorStop(0, "rgba(232,201,122,0.5)"); rg.addColorStop(1, "rgba(232,201,122,0)")
            ctx.fillStyle = rg; ctx.beginPath(); ctx.arc(px, py, 12, 0, Math.PI * 2); ctx.fill()
            ctx.fillStyle = "#E8C97A"; ctx.beginPath(); ctx.arc(px, py, 4, 0, Math.PI * 2); ctx.fill()
            ctx.fillStyle = "rgba(232,201,122,0.9)"; ctx.font = "9px Consolas"
            var lbl = (mIdx * analyzer.df * (analyzer.spectrumSize / N)).toFixed(1) + "Hz " + data[mIdx].toFixed(1) + "dBFS"
            ctx.fillText(lbl, Math.min(px + 8, W - lbl.length * 6), Math.max(py - 8, 16))
        }

        function drawWaterfall(cv) {
            var ctx = cv.getContext("2d")
            var W = cv.width, H = cv.height
            if (W < 10 || H < 10 || !analyzer) return
            ctx.clearRect(0, 0, W, H)
            var rows = cv.rows
            var maxFreq = analyzer.spectrumSize * analyzer.df
            for (var ry = 0; ry < Math.min(rows.length, H); ry++) {
                var row = rows[ry], N = row.length / 3
                if (N < 1) continue
                // Draw in chunks for performance
                var lastR = -1, lastG = -1, lastB = -1, runStart = 0
                for (var x = 0; x <= W; x++) {
                    var idx = Math.floor((Math.min(x, W-1) / W) * N) * 3
                    var cr = row[idx], cg = row[idx+1], cb = row[idx+2]
                    if (x < W && cr === lastR && cg === lastG && cb === lastB) continue
                    if (lastR >= 0 && x > runStart) {
                        ctx.fillStyle = "rgb(" + lastR + "," + lastG + "," + lastB + ")"
                        ctx.fillRect(runStart, ry, x - runStart, 1)
                    }
                    lastR = cr; lastG = cg; lastB = cb; runStart = x
                }
            }
            // Freq labels
            ctx.fillStyle = "rgba(84,110,122,0.7)"; ctx.font = "9px Consolas"
            var fl = [500, 1000, 2000, 3000, 4000]
            for (var fi = 0; fi < fl.length; fi++) {
                if (fl[fi] > maxFreq) break
                ctx.fillText(fl[fi] >= 1000 ? (fl[fi]/1000) + "k" : fl[fi], (fl[fi]/maxFreq)*W + 2, H - 2)
            }
        }

        function drawWaveform(cv) {
            var ctx = cv.getContext("2d")
            var W = cv.width, H = cv.height
            if (W < 10 || H < 10 || !analyzer) return
            ctx.clearRect(0, 0, W, H)
            var data = analyzer.waveformData, N = data.length
            if (N < 2) return
            // Center line
            ctx.strokeStyle = "rgba(58,80,96,0.5)"; ctx.setLineDash([4, 4]); ctx.lineWidth = 1
            ctx.beginPath(); ctx.moveTo(0, H/2); ctx.lineTo(W, H/2); ctx.stroke(); ctx.setLineDash([])
            // Waveform fill
            var grad = ctx.createLinearGradient(0, 0, 0, H)
            grad.addColorStop(0, "rgba(201,168,76,0.3)"); grad.addColorStop(0.5, "rgba(201,168,76,0)"); grad.addColorStop(1, "rgba(201,168,76,0.3)")
            ctx.beginPath(); ctx.moveTo(0, H/2)
            for (var i = 0; i < N; i++) ctx.lineTo((i/N)*W, H/2 - data[i]*(H/2*0.9))
            ctx.lineTo(W, H/2); ctx.closePath(); ctx.fillStyle = grad; ctx.fill()
            // Trace
            ctx.beginPath()
            for (i = 0; i < N; i++) {
                var x = (i/N)*W, y = H/2 - data[i]*(H/2*0.9)
                i === 0 ? ctx.moveTo(x, y) : ctx.lineTo(x, y)
            }
            ctx.strokeStyle = "rgba(232,201,122,0.9)"; ctx.lineWidth = 1.5; ctx.stroke()
            // RMS
            var rmsY = analyzer.waveRms * (H/2*0.9)
            ctx.strokeStyle = "rgba(212,70,50,0.5)"; ctx.setLineDash([2, 4])
            ctx.beginPath(); ctx.moveTo(0, H/2-rmsY); ctx.lineTo(W, H/2-rmsY)
            ctx.moveTo(0, H/2+rmsY); ctx.lineTo(W, H/2+rmsY); ctx.stroke(); ctx.setLineDash([])
            // T/R ramp
            if (analyzer.trPeriod > 0) {
                var periodMs = analyzer.trPeriod
                var frac = (analyzer.elapsed % periodMs) / periodMs
                var rampX = frac * W
                ctx.fillStyle = "rgba(27,191,176,0.15)"; ctx.fillRect(0, H-12, rampX, 12)
                ctx.strokeStyle = "rgba(27,191,176,0.6)"; ctx.lineWidth = 1; ctx.strokeRect(0, H-12, W, 12)
                ctx.strokeStyle = "rgba(27,191,176,0.8)"; ctx.lineWidth = 2
                ctx.beginPath(); ctx.moveTo(rampX, 0); ctx.lineTo(rampX, H); ctx.stroke()
                ctx.fillStyle = "rgba(27,191,176,0.8)"; ctx.font = "9px Consolas"
                ctx.fillText("T/R " + Math.floor(frac*periodMs) + "/" + Math.floor(periodMs) + "ms", rampX + 6, 14)
            }
            // Labels
            ctx.fillStyle = "rgba(84,110,122,0.7)"; ctx.font = "9px Consolas"
            ctx.fillText("+1.0", 4, 12); ctx.fillText(" 0.0", 4, H/2+4); ctx.fillText("-1.0", 4, H-4)
        }

        function drawMeters(cv) {
            var ctx = cv.getContext("2d"); var W = cv.width, H = cv.height
            if (W < 10 || H < 10 || !analyzer) return; ctx.clearRect(0, 0, W, H)
            var meters = [
                {label: "RX dBFS", val: analyzer.maxDB, unit: "dBFS", col: "#1BBFB0", mn: -120, mx: 0},
                {label: "PEAK",    val: analyzer.peakDB, unit: "dBFS", col: "#C9A84C", mn: -120, mx: 0},
                {label: "SNR",     val: analyzer.snr,    unit: "dB",   col: analyzer.snr>20?"#2ECC71":analyzer.snr>5?"#C9A84C":"#D44632", mn: -10, mx: 60},
                {label: "NOISE",   val: analyzer.noiseFloor, unit: "dBFS", col: "#D44632", mn: -120, mx: -40}
            ]
            var colW = W / 4
            for (var i = 0; i < 4; i++) {
                var cx = i * colW + colW / 2, m = meters[i]
                if (i > 0) { ctx.strokeStyle = "rgba(46,201,168,0.18)"; ctx.beginPath(); ctx.moveTo(i*colW, 4); ctx.lineTo(i*colW, H-4); ctx.stroke() }
                ctx.font = "8px Consolas"; ctx.fillStyle = "#3A5060"; ctx.textAlign = "center"
                ctx.fillText(m.label, cx, 16)
                ctx.font = "bold 18px Segoe UI"; ctx.fillStyle = m.col
                ctx.fillText(m.val > -199 ? m.val.toFixed(1) : "---", cx, H/2 + 6)
                ctx.font = "8px Consolas"; ctx.fillStyle = "#3A5060"
                ctx.fillText(m.unit, cx, H/2 + 20)
                var pct = Math.max(0, Math.min(1, (m.val - m.mn) / (m.mx - m.mn)))
                var bx = i*colW + 10, bw = colW - 20, by = H - 16
                ctx.fillStyle = "#0E1630"; ctx.fillRect(bx, by, bw, 6)
                var bg = ctx.createLinearGradient(bx, 0, bx + bw*pct, 0)
                bg.addColorStop(0, "#1BBFB0"); bg.addColorStop(1, m.col)
                ctx.fillStyle = bg; ctx.fillRect(bx, by, bw * pct, 6)
            }
            ctx.textAlign = "left"
        }

        function drawModeInfo(cv) {
            var ctx = cv.getContext("2d"); var W = cv.width, H = cv.height
            if (W < 10 || H < 10) return; ctx.clearRect(0, 0, W, H)
            var md = root.modes[root.currentMode]; if (!md) return
            var rows = [
                ["Modo", root.currentMode], ["Modulazione", md.mod], ["Banda", md.bw + " Hz"],
                ["T/R Cycle", md.tr > 0 ? md.tr + " s" : "\u2014"], ["Simboli", md.sym > 0 ? md.sym : "\u2014"],
                ["Spaziatura", md.sp], ["SNR ref", md.snr], ["ADIF", root.currentMode], ["Freq tipica", md.freq]
            ]
            ctx.font = "9px Consolas"
            var rowH = Math.max(16, H / 10)
            for (var i = 0; i < rows.length; i++) {
                var y = 8 + i * rowH
                ctx.strokeStyle = "rgba(201,168,76,0.07)"; ctx.beginPath(); ctx.moveTo(10, y + rowH - 1); ctx.lineTo(W - 10, y + rowH - 1); ctx.stroke()
                ctx.fillStyle = "#3A5060"; ctx.textAlign = "left"; ctx.fillText(rows[i][0], 10, y + 12)
                ctx.fillStyle = i === 6 ? "#C9A84C" : "#1BBFB0"; ctx.textAlign = "right"; ctx.fillText(rows[i][1], W - 10, y + 12)
            }
            ctx.textAlign = "left"
        }

        function drawTiming(cv) {
            var ctx = cv.getContext("2d"); var W = cv.width, H = cv.height
            if (W < 10 || H < 10 || !analyzer) return; ctx.clearRect(0, 0, W, H)
            var hw = W / 2, hh = H / 2
            var cells = [
                {val: analyzer.trPeriod > 0 ? Math.floor(analyzer.trPeriod).toString() : "--", lbl: "T/R PERIOD ms", col: "#C9A84C"},
                {val: Math.floor(analyzer.elapsed % 10000).toString(), lbl: "ELAPSED ms", col: "#1BBFB0"},
                {val: analyzer.zeroCrossRate.toString(), lbl: "ZERO CROSS/s", col: "#2ECC71"},
                {val: analyzer.rmsDB > -199 ? analyzer.rmsDB.toFixed(1) : "--", lbl: "RMS LEVEL", col: "#C9A84C"}
            ]
            ctx.strokeStyle = "rgba(46,201,168,0.18)"
            ctx.beginPath(); ctx.moveTo(hw, 4); ctx.lineTo(hw, H-4); ctx.stroke()
            ctx.beginPath(); ctx.moveTo(4, hh); ctx.lineTo(W-4, hh); ctx.stroke()
            for (var i = 0; i < 4; i++) {
                var cx = (i%2) * hw + hw/2, cy = Math.floor(i/2) * hh + hh/2
                ctx.font = "bold 22px Segoe UI"; ctx.fillStyle = cells[i].col; ctx.textAlign = "center"
                ctx.fillText(cells[i].val, cx, cy)
                ctx.font = "8px Consolas"; ctx.fillStyle = "#3A5060"
                ctx.fillText(cells[i].lbl, cx, cy + 18)
            }
            ctx.textAlign = "left"
        }

        function drawToneCurve(cv) {
            var ctx = cv.getContext("2d"); var W = cv.width, H = cv.height
            if (W < 10 || H < 10 || !analyzer) return; ctx.clearRect(0, 0, W, H)
            var data = analyzer.spectrumData; var N = data.length; if (N < 4) return
            var ref = analyzer.refDB, range = analyzer.rangeDB
            // Grid
            ctx.strokeStyle = "rgba(58,80,96,0.3)"; ctx.lineWidth = 1
            for (var i = 0; i <= 8; i++) { var x = (i/8)*W; ctx.beginPath(); ctx.moveTo(x,0); ctx.lineTo(x,H); ctx.stroke() }
            for (i = 0; i <= 4; i++) { var y = (i/4)*H; ctx.beginPath(); ctx.moveTo(0,y); ctx.lineTo(W,y); ctx.stroke() }
            // Envelope
            ctx.strokeStyle = "rgba(27,191,176,0.5)"; ctx.beginPath()
            for (i = 0; i < N; i++) {
                x = (i/N)*W; y = Math.max(0, Math.min(H, dbToY(data[i], H, ref, range)))
                i === 0 ? ctx.moveTo(x, y) : ctx.lineTo(x, y)
            }
            ctx.stroke()
            // Peaks
            var peaks = []
            for (i = 2; i < N - 2; i++)
                if (data[i]>data[i-1] && data[i]>data[i+1] && data[i]>data[i-2] && data[i]>data[i+2] && data[i]>-90)
                    peaks.push({i: i, db: data[i], hz: i * analyzer.df * (analyzer.spectrumSize / N)})
            peaks.sort(function(a,b){return b.db-a.db}); if (peaks.length > 12) peaks.length = 12
            for (var pi = 0; pi < peaks.length; pi++) {
                var pk = peaks[pi]
                x = (pk.i/N)*W; y = Math.max(0, Math.min(H, dbToY(pk.db, H, ref, range)))
                var col = pi === 0 ? "#E8C97A" : "rgba(27,191,176,0.8)"
                ctx.strokeStyle = col; ctx.lineWidth = pi===0 ? 2.5 : 1.5
                ctx.beginPath(); ctx.moveTo(x, H); ctx.lineTo(x, y); ctx.stroke()
                if (pi === 0) { var rg = ctx.createRadialGradient(x,y,0,x,y,10); rg.addColorStop(0,"rgba(232,201,122,0.5)"); rg.addColorStop(1,"rgba(232,201,122,0)"); ctx.fillStyle = rg; ctx.beginPath(); ctx.arc(x,y,10,0,Math.PI*2); ctx.fill() }
                ctx.fillStyle = col; ctx.beginPath(); ctx.arc(x, y, pi===0?5:3, 0, Math.PI*2); ctx.fill()
                if (pi < 3) { ctx.fillStyle = "rgba(232,201,122,0.9)"; ctx.font = "9px Consolas"; ctx.fillText(pk.hz >= 1000 ? (pk.hz/1000).toFixed(2)+"k" : Math.floor(pk.hz)+"Hz", Math.min(x+4, W-50), Math.max(y-6, 12)) }
            }
            // rolloff
            if (peaks.length > 0) {
                var f0 = peaks[0].hz, db0 = peaks[0].db
                ctx.strokeStyle = "rgba(212,70,50,0.4)"; ctx.setLineDash([4,4]); ctx.lineWidth = 1.5; ctx.beginPath()
                var started = false
                for (i = 0; i < N; i++) {
                    var hz = i * analyzer.df * (analyzer.spectrumSize / N); if (hz < 10) continue
                    var att = hz > f0 ? db0 - 20 * Math.log(hz/f0) / Math.LN10 : db0
                    x = (i/N)*W; y = Math.max(0, Math.min(H, dbToY(att, H, ref, range)))
                    !started ? (ctx.moveTo(x,y), started=true) : ctx.lineTo(x,y)
                }
                ctx.stroke(); ctx.setLineDash([]); ctx.fillStyle = "rgba(212,70,50,0.7)"; ctx.font = "9px Consolas"; ctx.fillText("20dB/dec rolloff", W-130, 14)
            }
        }

        function drawAttLoss(cv) {
            var ctx = cv.getContext("2d"); var W = cv.width, H = cv.height
            if (W < 10 || H < 10 || !analyzer) return; ctx.clearRect(0, 0, W, H)
            var att = Math.max(0, -analyzer.maxDB - 30), fspl = analyzer.maxDB + 120
            var disturbi = analyzer.noiseFloor + 10 <= analyzer.maxDB
            var rows = [
                ["Attenuazione", att.toFixed(1) + " dB", "#1BBFB0"],
                ["Path Loss", fspl.toFixed(1) + " dB", "#1BBFB0"],
                ["Noise Floor", analyzer.noiseFloor.toFixed(1) + " dBFS", "#1BBFB0"],
                ["Noise Power", (Math.pow(10,(analyzer.noiseFloor+30)/10)*1.38e-23*290).toExponential(2) + " W", "#1BBFB0"],
                ["SNR", analyzer.snr.toFixed(2) + " dB", analyzer.snr>15?"#2ECC71":analyzer.snr>5?"#C9A84C":"#D44632"],
                ["RMS Level", analyzer.rmsDB.toFixed(1) + " dBFS", "#1BBFB0"],
                ["Disturbi >NF+10", disturbi ? "DETECTED" : "OK", disturbi ? "#D44632" : "#2ECC71"],
                ["Dynamic Range", (analyzer.maxDB - analyzer.noiseFloor).toFixed(1) + " dB", "#1BBFB0"]
            ]
            ctx.font = "9px Consolas"
            var rowH = Math.max(16, H / 9)
            for (var i = 0; i < rows.length; i++) {
                var y = 8 + i * rowH
                ctx.strokeStyle = "rgba(201,168,76,0.07)"; ctx.beginPath(); ctx.moveTo(10, y+rowH-1); ctx.lineTo(W-10, y+rowH-1); ctx.stroke()
                ctx.fillStyle = "#3A5060"; ctx.textAlign = "left"; ctx.fillText(rows[i][0], 10, y + 12)
                ctx.fillStyle = rows[i][2]; ctx.textAlign = "right"; ctx.fillText(rows[i][1], W - 10, y + 12)
            }
            ctx.textAlign = "left"
        }
    }
}
