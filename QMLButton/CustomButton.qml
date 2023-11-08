import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls.Basic

Button {   
    property bool isCheckable
    property bool isEnabled
    property var iconPath 
    
    signal a()
    signal b(bool underCursor)
    signal c()
    
    onClicked: {
        if(isCheckable)
        {
            checked = !checked
            custombutton.a()
        }                
    }
    onHoveredChanged: {
        custombutton.b(hovered)
    }
    
    id: custombutton
    anchors.centerIn: parent
    flat: true
    icon.width: 400
    icon.height: 400
    icon.color: "transparent"
    icon.source: iconPath
    
    enabled: isEnabled
    checked: true
    
    background: Rectangle {
        color: "transparent"
    }
}
