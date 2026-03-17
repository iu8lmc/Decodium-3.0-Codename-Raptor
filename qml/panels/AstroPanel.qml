import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Decodium

Rectangle {
    id: astroPanel
    color: Theme.surface
    radius: Theme.radius
    border.color: Theme.border
    border.width: 1
    visible: false

    property real myLat: 0.0
    property real myLon: 0.0

    // Moon position calculation (simplified)
    // Reference: new moon Jan 11, 2024 11:57 UTC
    readonly property real synodicMonth: 29.53059
    readonly property real refNewMoon: 19733.498  // days since epoch (Jan 11 2024)

    property real moonPhase: 0.0
    property real moonAzimuth: 0.0
    property real moonElevation: 0.0
    property real moonDopplerHz: 0.0
    property string moonRise: "--:--"
    property string moonSet: "--:--"
    property real sunElevation: 0.0

    Timer {
        id: astroTimer
        interval: 10000
        running: astroPanel.visible
        repeat: true
        triggeredOnStart: true
        onTriggered: updateAstro()
    }

    function updateAstro() {
        var now = new Date();
        var utcHours = now.getUTCHours() + now.getUTCMinutes() / 60.0 + now.getUTCSeconds() / 3600.0;

        // Julian Date
        var y = now.getUTCFullYear();
        var m = now.getUTCMonth() + 1;
        var d = now.getUTCDate();
        if (m <= 2) { y--; m += 12; }
        var A = Math.floor(y / 100);
        var B = 2 - A + Math.floor(A / 4);
        var jd = Math.floor(365.25 * (y + 4716)) + Math.floor(30.6001 * (m + 1)) + d + utcHours / 24.0 + B - 1524.5;

        // Moon phase (synodic)
        var daysSinceNew = jd - 2460320.998; // JD of ref new moon
        var phase = ((daysSinceNew % synodicMonth) + synodicMonth) % synodicMonth;
        moonPhase = phase / synodicMonth;

        // Simplified moon position (low-precision formula)
        var T = (jd - 2451545.0) / 36525.0;

        // Moon ecliptic longitude (degrees)
        var L0 = 218.3164477 + 481267.88123421 * T;
        var M_moon = 134.9633964 + 477198.8675055 * T;
        var M_sun = 357.5291092 + 35999.0502909 * T;
        var D = 297.8501921 + 445267.1114034 * T;
        var F = 93.2720950 + 483202.0175233 * T;

        // Normalize to 0-360
        L0 = ((L0 % 360) + 360) % 360;
        M_moon = ((M_moon % 360) + 360) % 360 * Math.PI / 180;
        M_sun = ((M_sun % 360) + 360) % 360 * Math.PI / 180;
        D = ((D % 360) + 360) % 360 * Math.PI / 180;
        F = ((F % 360) + 360) % 360 * Math.PI / 180;

        // Major perturbations
        var moonLon = L0
            + 6.289 * Math.sin(M_moon)
            - 1.274 * Math.sin(2 * D - M_moon)
            + 0.658 * Math.sin(2 * D)
            + 0.214 * Math.sin(2 * M_moon)
            - 0.186 * Math.sin(M_sun);

        var moonLat = 5.128 * Math.sin(F)
            + 0.281 * Math.sin(M_moon + F)
            + 0.078 * Math.sin(2 * D - F);

        // Ecliptic to equatorial
        var eps = 23.4393 * Math.PI / 180; // obliquity
        var lonRad = moonLon * Math.PI / 180;
        var latRad = moonLat * Math.PI / 180;

        var ra = Math.atan2(Math.sin(lonRad) * Math.cos(eps) - Math.tan(latRad) * Math.sin(eps),
                            Math.cos(lonRad));
        var dec = Math.asin(Math.sin(latRad) * Math.cos(eps) + Math.cos(latRad) * Math.sin(eps) * Math.sin(lonRad));

        // Hour angle
        var gmst = 280.46061837 + 360.98564736629 * (jd - 2451545.0);
        gmst = ((gmst % 360) + 360) % 360;
        var ha = (gmst + myLon - ra * 180 / Math.PI) * Math.PI / 180;

        var latRad2 = myLat * Math.PI / 180;
        // Altitude
        var sinAlt = Math.sin(latRad2) * Math.sin(dec) + Math.cos(latRad2) * Math.cos(dec) * Math.cos(ha);
        moonElevation = Math.asin(sinAlt) * 180 / Math.PI;

        // Azimuth
        var cosAz = (Math.sin(dec) - Math.sin(latRad2) * sinAlt) / (Math.cos(latRad2) * Math.cos(Math.asin(sinAlt)));
        cosAz = Math.max(-1, Math.min(1, cosAz));
        moonAzimuth = Math.acos(cosAz) * 180 / Math.PI;
        if (Math.sin(ha) > 0) moonAzimuth = 360 - moonAzimuth;

        // EME Doppler (simplified: ~1 Hz per Hz shift at 144 MHz ≈ ±300 Hz max)
        // Radial velocity ≈ rotation + orbital components
        var vRot = 0.464 * Math.cos(latRad2) * Math.sin(ha) * Math.cos(dec); // km/s from rotation
        moonDopplerHz = -(2 * vRot / 299792.458) * 144100000; // round-trip at 144.1 MHz

        // Sun elevation (simplified)
        var sunLon = (280.46646 + 36000.76983 * T) * Math.PI / 180;
        var sunRa = Math.atan2(Math.sin(sunLon) * Math.cos(eps), Math.cos(sunLon));
        var sunDec = Math.asin(Math.sin(eps) * Math.sin(sunLon));
        var sunHa = (gmst + myLon - sunRa * 180 / Math.PI) * Math.PI / 180;
        var sinSunAlt = Math.sin(latRad2) * Math.sin(sunDec) + Math.cos(latRad2) * Math.cos(sunDec) * Math.cos(sunHa);
        sunElevation = Math.asin(sinSunAlt) * 180 / Math.PI;
    }

    function phaseText() {
        if (moonPhase < 0.03 || moonPhase > 0.97) return "New Moon";
        if (moonPhase < 0.22) return "Waxing Crescent";
        if (moonPhase < 0.28) return "First Quarter";
        if (moonPhase < 0.47) return "Waxing Gibbous";
        if (moonPhase < 0.53) return "Full Moon";
        if (moonPhase < 0.72) return "Waning Gibbous";
        if (moonPhase < 0.78) return "Last Quarter";
        return "Waning Crescent";
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Theme.margin
        spacing: Theme.spacing

        // Header
        RowLayout {
            Layout.fillWidth: true
            Text {
                text: "ASTRO / EME"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.letterSpacing: 2
                font.bold: true
                color: Theme.accent
            }
            Item { Layout.fillWidth: true }
            Text {
                text: phaseText()
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                color: Theme.textSecondary
            }
        }

        Rectangle { Layout.fillWidth: true; height: 1; color: Theme.border }

        // Moon info grid
        GridLayout {
            Layout.fillWidth: true
            columns: 4
            columnSpacing: Theme.spacing
            rowSpacing: Theme.spacingSmall

            Text { text: "Az"; font.family: Theme.fontFamily; font.pixelSize: Theme.fontTiny; color: Theme.textSecondary }
            Text { text: moonAzimuth.toFixed(1) + "\u00B0"; font.family: Theme.digitalFont; font.pixelSize: Theme.fontSmall; color: Theme.textPrimary }
            Text { text: "El"; font.family: Theme.fontFamily; font.pixelSize: Theme.fontTiny; color: Theme.textSecondary }
            Text {
                text: moonElevation.toFixed(1) + "\u00B0"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: moonElevation > 0 ? Theme.activeGreen : Theme.alertRed
            }

            Text { text: "Doppler"; font.family: Theme.fontFamily; font.pixelSize: Theme.fontTiny; color: Theme.textSecondary }
            Text { text: (moonDopplerHz >= 0 ? "+" : "") + moonDopplerHz.toFixed(0) + " Hz"; font.family: Theme.digitalFont; font.pixelSize: Theme.fontSmall; color: Theme.accent }
            Text { text: "Sun El"; font.family: Theme.fontFamily; font.pixelSize: Theme.fontTiny; color: Theme.textSecondary }
            Text {
                text: sunElevation.toFixed(1) + "\u00B0"
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: sunElevation > 0 ? Theme.warning : Theme.textSecondary
            }

            Text { text: "Phase"; font.family: Theme.fontFamily; font.pixelSize: Theme.fontTiny; color: Theme.textSecondary }
            Text { text: (moonPhase * 100).toFixed(0) + "%"; font.family: Theme.digitalFont; font.pixelSize: Theme.fontSmall; color: Theme.textPrimary }
            Text { text: "Illum"; font.family: Theme.fontFamily; font.pixelSize: Theme.fontTiny; color: Theme.textSecondary }
            Text {
                text: {
                    // Illumination fraction
                    var illum = (1 - Math.cos(moonPhase * 2 * Math.PI)) / 2;
                    return (illum * 100).toFixed(0) + "%";
                }
                font.family: Theme.digitalFont
                font.pixelSize: Theme.fontSmall
                color: Theme.textPrimary
            }
        }

        // EME window indicator
        Rectangle {
            Layout.fillWidth: true
            height: 24
            radius: Theme.radius
            color: moonElevation > 5 ? Qt.rgba(0, 1, 0, 0.1) : Qt.rgba(1, 0.2, 0.2, 0.1)
            border.color: moonElevation > 5 ? Theme.activeGreen : Theme.alertRed
            border.width: 1

            Text {
                anchors.centerIn: parent
                text: moonElevation > 5 ? "EME WINDOW OPEN" : "EME WINDOW CLOSED"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontTiny
                font.bold: true
                font.letterSpacing: 1
                color: moonElevation > 5 ? Theme.activeGreen : Theme.alertRed
            }
        }
    }
}
