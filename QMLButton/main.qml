import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls.Basic

Window {
    id: wnd
    width: 640
    height: 480
    visible: true
    title: "QML Button"
    
    CustomButton { id: bigButton; isCheckable: true; isEnabled: true; iconPath: "file:///" + Qt.application.arguments[1]}
    
    Connections {
        target: bigButton
        function onB(p)
        {
            wnd.color = p ? "blue" : "white";
        }
        function onA()
        {
            wnd.color = "orange";
        }
    }
}

