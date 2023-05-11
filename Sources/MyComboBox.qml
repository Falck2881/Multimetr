import QtQuick 2.12
import QtQuick.Controls 2.12

ComboBox {
    id: control
    width: 150
    height: 32
    property string currentSelect: model[0]
    model: []

    delegate: ItemDelegate {
        id: delegat
        width: control.width
        contentItem: Text {
            text: modelData
            color: control.pressed ? "#3FC1C9" : "#F5F5F5"
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
        }

        background: MouseArea {
            hoverEnabled: true

            Rectangle {
                anchors.fill: parent
                color: "#495866"
            }
        }

        onClicked: {

            currentSelect = control.textAt(index)
            console.log("MYcombobox: ", currentSelect)
        }
        highlighted: control.highlightedIndex === index
    }

    indicator: Canvas {
        id: canvas
        x: control.width - width - control.rightPadding
        y: control.topPadding + (control.availableHeight - height) / 2
        width: 12
        height: 8
        contextType: "2d"

        onPaint: {
            context.reset()
            context.moveTo(0, 0)
            context.lineTo(width, 0)
            context.lineTo(width / 2, height)
            context.closePath()
            context.fillStyle = control.pressed ? "#3FC1C9" : "#F5F5F5"
            context.fill()
        }
    }

    contentItem: Text {
        leftPadding: 0
        rightPadding: control.indicator.width + control.spacing

        font: control.font
        color: control.pressed ? "#3FC1C9" : "#F5F5F5"
        text: control.displayText
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignHCenter
    }

    background: Rectangle {
        color: "#364F6B"
        implicitWidth: control.width
        implicitHeight: control.height
        border.color: control.pressed ? "#3FC1C9" : "#F5F5F5"
        border.width: control.visualFocus ? 3 : 1
        radius: 3
    }

    popup: Popup {
        y: control.height - 1
        width: control.width
        implicitHeight: contentItem.implicitHeight
        padding: 2

        background: Rectangle {
            border.color: "#3FC1C9"
            radius: 2
        }
        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: control.popup.visible ? control.delegateModel : null
            currentIndex: control.highlightedIndex
            ScrollIndicator.vertical: ScrollIndicator {}
        }
    }
}

/*##^##
Designer {
    D{i:0;height:0;width:0}
}
##^##*/

