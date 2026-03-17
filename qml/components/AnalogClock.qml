import QtQuick
import Decodium

Canvas {
    id: clockCanvas
    width: 60
    height: 60

    property int hours: 0
    property int minutes: 0
    property int seconds: 0

    Timer {
        interval: 1000
        running: true
        repeat: true
        triggeredOnStart: true
        onTriggered: {
            var now = new Date();
            clockCanvas.hours = now.getUTCHours();
            clockCanvas.minutes = now.getUTCMinutes();
            clockCanvas.seconds = now.getUTCSeconds();
            clockCanvas.requestPaint();
        }
    }

    onPaint: {
        var ctx = getContext("2d");
        var w = width;
        var h = height;
        var cx = w / 2;
        var cy = h / 2;
        var r = Math.min(cx, cy) - 2;

        ctx.clearRect(0, 0, w, h);

        // Face
        ctx.beginPath();
        ctx.arc(cx, cy, r, 0, 2 * Math.PI);
        ctx.fillStyle = Theme.surface;
        ctx.fill();
        ctx.strokeStyle = Theme.accentDim;
        ctx.lineWidth = 1.5;
        ctx.stroke();

        // Hour marks
        for (var i = 0; i < 12; i++) {
            var angle = (i * 30 - 90) * Math.PI / 180;
            var inner = i % 3 === 0 ? r * 0.7 : r * 0.8;
            ctx.beginPath();
            ctx.moveTo(cx + inner * Math.cos(angle), cy + inner * Math.sin(angle));
            ctx.lineTo(cx + r * 0.9 * Math.cos(angle), cy + r * 0.9 * Math.sin(angle));
            ctx.strokeStyle = i % 3 === 0 ? Theme.textPrimary : Theme.textDim;
            ctx.lineWidth = i % 3 === 0 ? 1.5 : 0.8;
            ctx.stroke();
        }

        // Hour hand
        var hAngle = ((hours % 12) * 30 + minutes * 0.5 - 90) * Math.PI / 180;
        ctx.beginPath();
        ctx.moveTo(cx, cy);
        ctx.lineTo(cx + r * 0.5 * Math.cos(hAngle), cy + r * 0.5 * Math.sin(hAngle));
        ctx.strokeStyle = Theme.textPrimary;
        ctx.lineWidth = 2;
        ctx.stroke();

        // Minute hand
        var mAngle = (minutes * 6 + seconds * 0.1 - 90) * Math.PI / 180;
        ctx.beginPath();
        ctx.moveTo(cx, cy);
        ctx.lineTo(cx + r * 0.7 * Math.cos(mAngle), cy + r * 0.7 * Math.sin(mAngle));
        ctx.strokeStyle = Theme.textPrimary;
        ctx.lineWidth = 1.5;
        ctx.stroke();

        // Second hand
        var sAngle = (seconds * 6 - 90) * Math.PI / 180;
        ctx.beginPath();
        ctx.moveTo(cx, cy);
        ctx.lineTo(cx + r * 0.8 * Math.cos(sAngle), cy + r * 0.8 * Math.sin(sAngle));
        ctx.strokeStyle = Theme.accent;
        ctx.lineWidth = 0.8;
        ctx.stroke();

        // Center dot
        ctx.beginPath();
        ctx.arc(cx, cy, 2, 0, 2 * Math.PI);
        ctx.fillStyle = Theme.accent;
        ctx.fill();
    }
}
