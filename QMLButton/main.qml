import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls.Basic

Window {
    id: wnd;
    width: 640;
    height: 480;
    visible: true;
    title: "QML Button";
    
    CustomButton {  id: button; isChecked: true; isEnabled: true; iconPath: "file:///" + Qt.application.arguments[1];   }
    
    Connections {
        target: button;
        function onButtonHovered(isHovered)
        {
            wnd.color = isHovered ? "cyan" : "white";
        }
        function onJustClicked()
        {
            wnd.color = "orange";
        }
        function onButtonChecked()
        {
            wnd.color = "red";
        }
        function onButtonUnchecked()
        {
            wnd.color = "magenta";
        }
    }
}

