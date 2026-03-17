import QtQuick
import Decodium

Item {
    id: moonClock
    width: 80
    height: 100

    // Approximate lunar phase: 0 = new moon, 0.5 = full moon, 1 = new moon
    property real lunarPhase: {
        // Simple synodic month calculation
        var now = new Date();
        var refNew = new Date(2024, 0, 11);   // Known new moon: Jan 11, 2024
        var daysSince = (now.getTime() - refNew.getTime()) / (1000 * 60 * 60 * 24);
        var synodicMonth = 29.53059;
        var phase = (daysSince % synodicMonth) / synodicMonth;
        return phase;
    }

    Column {
        anchors.centerIn: parent
        spacing: 6

        // Moon circle
        Canvas {
            id: moonCanvas
            width: 48
            height: 48
            anchors.horizontalCenter: parent.horizontalCenter
            antialiasing: true

            onPaint: {
                var ctx = getContext("2d");
                var cx = width / 2;
                var cy = height / 2;
                var r = 20;

                ctx.clearRect(0, 0, width, height);

                // Outer glow
                var glowGrad = ctx.createRadialGradient(cx, cy, r - 2, cx, cy, r + 8);
                glowGrad.addColorStop(0, Qt.rgba(0.5, 0.55, 0.65, 0.08));
                glowGrad.addColorStop(1, "transparent");
                ctx.beginPath();
                ctx.arc(cx, cy, r + 8, 0, 2 * Math.PI);
                ctx.fillStyle = glowGrad;
                ctx.fill();

                // Dark side of the moon (base)
                ctx.beginPath();
                ctx.arc(cx, cy, r, 0, 2 * Math.PI);
                ctx.fillStyle = "#1a1f2a";
                ctx.fill();

                // Illuminated side
                ctx.save();
                ctx.beginPath();
                ctx.arc(cx, cy, r, 0, 2 * Math.PI);
                ctx.clip();

                // Phase determines illumination shape
                var phase = moonClock.lunarPhase;
                var illumination;

                ctx.beginPath();
                if (phase <= 0.5) {
                    // Waxing: light comes from the right
                    illumination = phase * 2;  // 0 -> 1
                    ctx.arc(cx, cy, r, -Math.PI / 2, Math.PI / 2, false);
                    var cp = r * (1 - 2 * illumination);
                    ctx.bezierCurveTo(cx + cp, cy + r * 0.6, cx + cp, cy - r * 0.6, cx, cy - r);
                } else {
                    // Waning: light recedes from the left
                    illumination = (1 - phase) * 2;  // 1 -> 0
                    ctx.arc(cx, cy, r, Math.PI / 2, -Math.PI / 2, false);
                    var cp2 = r * (1 - 2 * illumination);
                    ctx.bezierCurveTo(cx - cp2, cy - r * 0.6, cx - cp2, cy + r * 0.6, cx, cy + r);
                }
                ctx.closePath();

                var moonGrad = ctx.createRadialGradient(cx - 4, cy - 4, 0, cx, cy, r);
                moonGrad.addColorStop(0, "#d4d8e0");
                moonGrad.addColorStop(0.7, "#a8adb8");
                moonGrad.addColorStop(1, "#808890");
                ctx.fillStyle = moonGrad;
                ctx.fill();

                ctx.restore();

                // Subtle border
                ctx.beginPath();
                ctx.arc(cx, cy, r, 0, 2 * Math.PI);
                ctx.lineWidth = 0.5;
                ctx.strokeStyle = Qt.rgba(1, 1, 1, 0.1);
                ctx.stroke();
            }

            Component.onCompleted: requestPaint()
        }

        // UTC time below moon
        Text {
            id: moonUtcText
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: Theme.digitalFont
            font.pixelSize: Theme.fontSmall
            color: Theme.textSecondary

            function update() {
                var now = new Date();
                var h = String(now.getUTCHours()).padStart(2, '0');
                var m = String(now.getUTCMinutes()).padStart(2, '0');
                text = h + ":" + m + " UTC";
            }

            Timer {
                interval: 10000
                running: true
                repeat: true
                triggeredOnStart: true
                onTriggered: moonUtcText.update()
            }
        }
    }
}
