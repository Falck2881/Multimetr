import QtQuick 2.12
import QtQuick.Controls 2.12

Button {
    id: button
    width: 150
    height: 40
    property alias mauseArea: area
    property alias textButton: textButton.text

    Text {
        id: textButton
        color: "#F5F5F5"
        text: "Empty"
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
        anchors.bottomMargin: 4
    }

    background: Rectangle {
        id: rectButton
        color: "#364F6B"
        border.color: "#F5F5F5"
        border.width: 3
        radius: 10
    }
    MouseArea {
        id: area
        anchors.fill: button
        hoverEnabled: true
        onEntered: {
            rectButton.color = "#FC5185"
            rectButton.border.color = "#3FC1C9"
        }
        onExited: {
            rectButton.color = "#364F6B"
            rectButton.border.color = "#F5F5F5"
        }
    }
}

/*##^##
Designer {
    D{i:0;height:40;width:150}D{i:1}D{i:3}
}
##^##*/

