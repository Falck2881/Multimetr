import QtQuick 2.12
import QtQuick.Controls 2.12

Button {
    id: button
    width: 150
    height: 40
    signal execute(bool status)
    property bool status: false
    property alias currText: textButton.text

    background: Rectangle {
        id: rectButton
        anchors.fill: button
        color: "#364F6B"
        border.color: "#F5F5F5"
        border.width: 3
    }

    Rectangle {
        id: rectProg
        opacity: 1
        color: "#FC5185"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 3
        anchors.bottomMargin: 4
        anchors.topMargin: 4
        NumberAnimation on width {
            id: animProg
            running: false
            from: 0
            to: rectButton.width - 6
            duration: 2000
            easing.type: Easing.InOutCubic
            onFinished: {
                status = true
                execute(status)
            }
        }
    }

    Text {
        id: textButton
        anchors.top: button.top
        anchors.bottom: button.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Empty"
        color: "#F5F5F5"
    }

    MouseArea {
        id: mouseArea
        anchors.fill: button
        hoverEnabled: true

        onPressed: {
            animProg.start()
        }

        onReleased: {
            animProg.stop()
            rectProg.width = 0
        }

        onEntered: {
            rectButton.border.color = "#3FC1C9"
            rectButton.border.width = 5
        }

        onExited: {
            rectButton.border.color = "#F5F5F5"
            rectButton.border.width = 3
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:2}D{i:2}D{i:3}D{i:4}
}
##^##*/

