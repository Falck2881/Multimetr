import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import "../JsScripts/Range.js" as Multimetr
import Client

Window {
    id: window
    width: 800
    height: 500
    visible: true
    color: "#364f6b"
    minimumWidth: 400
    minimumHeight: 250
    maximumWidth: 800
    maximumHeight: 500
    title: "Window"

    ToolSeparator {
        id: toolSeparator
        x: 422
        y: 101
        width: 13
        height: 314
    }

    Rectangle {
        id: frame
        x: 13
        width: 349
        height: 314
        color: "#364f6b"
        radius: 5
        border.color: "#3fc1c9"
        border.width: 3
        anchors.top: parent.top
        anchors.topMargin: 101

        MyComboBox {
            id: listChannel
            x: 176
            y: 67
            width: 165
            height: 32
            font.pointSize: 12
            model: Multimetr.getChannels()
        }

        Text {
            id: labelName
            x: 21
            y: 69
            width: 80
            height: 27
            color: "#f5f5f5"
            text: qsTr("Name")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.family: "Ubuntu"
        }

        Text {
            id: labelRange
            x: 21
            y: 144
            width: 80
            height: 26
            color: "#f5f5f5"
            text: qsTr("Range")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
        }

        MyButton {
            id: buttonSetRange
            x: 21
            y: 249
            width: 126
            height: 40
            textButton: "Set Range"
            mauseArea.onClicked: {
                let channel = listChannel.currentSelect
                console.log("Channel: ", channel)
                let range = Multimetr.findVoltages(listRange.currentSelect)
                console.log("Range: ", range)
                _client.request = "set_range " + channel + ", " + range
            }
        }

        MyDelayButton {
            id: buttonReset
            x: 186
            y: 249
            width: 150
            height: 40
            rotation: 0
            currText: "Reset"
            onExecute: {
                if (buttonReset.status) {
                    listChannel.currentIndex = 0
                    listRange.currentIndex = 0
                    answerServer.text = " "
                }
            }
        }

        MyComboBox {
            id: listRange
            x: 176
            y: 141
            width: 165
            height: 32
            model: Multimetr.rangesVoltages()
        }
    }

    Rectangle {
        id: rectangle
        x: 12
        y: 9
        width: 218
        height: 78
        color: "#364f6b"
        radius: 5
        border.color: "#3fc1c9"
        border.width: 3

        Column {
            id: column
            x: 8
            y: 10
            width: 178
            height: 60
            spacing: 5

            Text {
                id: labelMultimetr
                width: 184
                height: 20
                color: "#f5f5f5"
                text: qsTr("GUI Multimetr")
                anchors.left: parent.left
                font.pixelSize: 16
                minimumPointSize: 12
                anchors.topMargin: 0
                anchors.leftMargin: 10
                font.family: "Arial"
            }

            Text {
                id: textMaxChannel
                width: 160
                height: 28
                color: "#f5f5f5"
                text: qsTr("Max number channel: ")
                anchors.left: parent.left
                font.pixelSize: 16
                anchors.leftMargin: 10
                anchors.bottomMargin: 0
            }
        }

        Text {
            id: text1
            x: 192
            y: 36
            width: 18
            height: 19
            color: "#fc5185"
            text: Multimetr.maxNumberChannel
            anchors.right: parent.right
            font.pixelSize: 16
            anchors.topMargin: 30
            anchors.rightMargin: 8
            anchors.bottomMargin: 10
        }
    }

    Rectangle {
        id: rectangle1
        x: 495
        y: 101
        width: 290
        height: 314
        color: "#364f6b"
        radius: 5
        border.color: "#3fc1c9"
        border.width: 3

        Column {
            id: column1
            anchors.fill: parent
            anchors.rightMargin: 8
            anchors.bottomMargin: 14
            anchors.leftMargin: 8
            anchors.topMargin: 31
            spacing: 30

            MyButton {
                id: buttonStartMeasure
                width: 150
                height: 40
                anchors.left: parent.left
                textButton: "Start Measure"
                anchors.leftMargin: 70
                anchors.topMargin: 23
                mauseArea.onClicked: {
                    let request = "start_measure " + listChannel.currentSelect
                    console.log("Request on start measure: ", request)
                    _client.request = request
                }
            }

            MyButton {
                id: buttonStopMeasure
                anchors.left: parent.left
                textButton: "Stop Measure"
                anchors.leftMargin: 70
                anchors.topMargin: 30
                mauseArea.onClicked: {
                    let request = "stop_measure " + listChannel.currentSelect
                    console.log("Request on stop measure: ", request)
                    _client.request = request
                }
            }

            MyButton {
                id: buttonGetStatus
                width: 150
                height: 40
                anchors.left: parent.left
                textButton: "Status"
                anchors.leftMargin: 70
                anchors.topMargin: 30
                mauseArea.onClicked: {
                    let request = "get_status " + listChannel.currentSelect
                    console.log("Request on get a status: ", request)
                    _client.request = request
                }
            }

            MyButton {
                id: myButton
                width: 150
                height: 40
                anchors.left: parent.left
                textButton: "Result"
                anchors.leftMargin: 70
                anchors.topMargin: 30
                mauseArea.onClicked: {
                    let request = "get_result " + listChannel.currentSelect
                    console.log("Request on get a result: ", request)
                    _client.request = request
                }
            }
        }
    }

    Rectangle {
        id: rectangle2
        y: 469
        width: 800
        height: 31
        opacity: 1
        color: "#273c54"
        radius: 0
        border.color: "#fc5185"
        border.width: 0
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.bottomMargin: 0

        Text {
            id: answerServer
            x: 8
            width: 600
            height: 22
            color: "#f5f5f5"
            text: qsTr("")
            styleColor: "#e7e7e7"
            font.capitalization: Font.MixedCase
            style: Text.Normal
            font.family: "Times New Roman"
            font.pointSize: 16
            anchors.topMargin: 4
            anchors.leftMargin: 5
        }
    }

    AnimatedImage {
        id: serverStatus
        x: 753
        y: 12
        width: 32
        height: 32
        source: "qrc:/online.png"
        clip: false
    }

    Text {
        id: labelServer
        x: 667
        y: 12
        width: 80
        height: 29
        color: "#f5f5f5"
        text: qsTr("Server")
        font.pixelSize: 22
        verticalAlignment: Text.AlignVCenter
        font.family: "Times New Roman"
    }

    Client {
        id: _client
        onShowAnswer: {
            answerServer.text = _client.answer
            console.log("Answer: ", _client.answer)
        }
        onLoading: {
            serverStatus.playing = true
            serverStatus.source = "qrc:/load.gif"
            _client.onReboot()
        }

        onRunning: {
            serverStatus.playing = false
            serverStatus.source = "qrc:/online.png"
        }
    }

    onClosing: {
        console.log("Closing application")
        _client.disconnect()
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:1}D{i:2}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}D{i:9}D{i:3}D{i:12}
D{i:13}D{i:11}D{i:14}D{i:10}D{i:17}D{i:18}D{i:19}D{i:20}D{i:16}D{i:15}D{i:22}D{i:21}
D{i:23}D{i:24}
}
##^##*/

