import QtQuick
import QtQuick.Layouts
import Decodium

Item {
    id: freqDisplay
    implicitWidth: freqColumn.implicitWidth
    implicitHeight: freqColumn.implicitHeight

    property double frequency: 14075500  // Hz

    function formatFrequency(hz) {
        var mhz = Math.floor(hz / 1000000);
        var khz = Math.floor((hz % 1000000) / 1000);
        var rest = Math.floor(hz % 1000);
        var khzStr = String(khz).padStart(3, '0');
        var restStr = String(rest).padStart(3, '0');
        return mhz + "." + khzStr + "." + restStr;
    }

    Column {
        id: freqColumn
        anchors.centerIn: parent
        spacing: 2

        Text {
            text: formatFrequency(frequency)
            font.family: Theme.digitalFont
            font.pixelSize: Theme.fontHuge
            font.bold: true
            color: Theme.activeGreen

            layer.enabled: true
            layer.effect: Item {
                // Glow simulation via slight opacity
            }
        }
        Text {
            text: "MHz"
            font.family: Theme.fontFamily
            font.pixelSize: Theme.fontTiny
            font.letterSpacing: 2
            color: Theme.textSecondary
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
