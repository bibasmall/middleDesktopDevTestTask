import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Controls.Basic

Button {
    id: custombutton;
    
    required property bool isChecked;
    required property bool isEnabled;
    required property var iconPath;
    
    property bool isCheckable : true;
    property bool isUncheckable : false;
    
    enabled: isEnabled;
    checked: isChecked;
    
    signal justClicked();
    signal buttonHovered(bool isHovered);
    signal buttonChecked();
    signal buttonUnchecked();
    
    onClicked: {       
        if(!isCheckable || (isUncheckable && isChecked))
        {
            justClicked();
            return;
        }
        
        if(isChecked)
            custombutton.buttonUnchecked();
        else
            custombutton.buttonChecked();
        
        isChecked = !isChecked;
    }
    onHoveredChanged: {
            custombutton.buttonHovered(hovered);
    }
           
    anchors.centerIn: parent;
    flat: true;
    icon.width: 400;
    icon.height: 400;
    icon.color: "transparent";
    icon.source: iconPath;
    
    background: Rectangle {
        color: "transparent";
    }
}
