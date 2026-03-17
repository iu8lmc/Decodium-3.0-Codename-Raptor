import QtQuick
import Decodium

Item {
    id: countdown
    width: 56
    height: 56

    property double period: typeof decoder !== "undefined" ? decoder.period : 15.0
    property double progress: typeof decoder !== "undefined" ? decoder.periodProgress : 0.0

    Canvas {
        id: arcCanvas
        anchors.fill: parent
        antialiasing: true

        onPaint: {
            var ctx = getContext("2d");
            var cx = width / 2;
            var cy = height / 2;
            var r = Math.min(cx, cy) - 4;

            ctx.clearRect(0, 0, width, height);

            // Background circle
            ctx.beginPath();
            ctx.arc(cx, cy, r, 0, 2 * Math.PI);
            ctx.lineWidth = 3;
            ctx.strokeStyle = Theme.surfaceLight;
            ctx.stroke();

            // Progress arc (starts from top, clockwise)
            var startAngle = -Math.PI / 2;
            var endAngle = startAngle + (2 * Math.PI * countdown.progress);

            ctx.beginPath();
            ctx.arc(cx, cy, r, startAngle, endAngle);
            ctx.lineWidth = 3;

            // Color transitions: green -> yellow -> red as time runs out
            if (countdown.progress < 0.6) {
                ctx.strokeStyle = Theme.accent;
            } else if (countdown.progress < 0.85) {
                ctx.strokeStyle = Theme.warning;
            } else {
                ctx.strokeStyle = Theme.alertRed;
            }
            ctx.stroke();

            // Center dot
            ctx.beginPath();
            ctx.arc(cx, cy, 2, 0, 2 * Math.PI);
            ctx.fillStyle = Theme.textSecondary;
            ctx.fill();
        }
    }

    // Remaining seconds text in center
    Text {
        anchors.centerIn: parent
        text: {
            var remaining = Math.ceil(countdown.period * (1.0 - countdown.progress));
            return String(remaining);
        }
        font.family: Theme.digitalFont
        font.pixelSize: Theme.fontSmall
        color: {
            if (countdown.progress < 0.6) return Theme.accent;
            if (countdown.progress < 0.85) return Theme.warning;
            return Theme.alertRed;
        }
    }

    // Repaint when progress changes from decoder
    onProgressChanged: arcCanvas.requestPaint()

    // Fallback timer for when decoder isn't providing updates
    Timer {
        interval: 200
        running: typeof decoder === "undefined"
        repeat: true
        onTriggered: {
            var now = new Date();
            var secs = now.getUTCSeconds() + now.getUTCMilliseconds() / 1000.0;
            var p = countdown.period > 0 ? countdown.period : 15.0;
            countdown.progress = (secs % p) / p;
            arcCanvas.requestPaint();
        }
    }
}
