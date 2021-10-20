import QtQuick 2.9
import QtQuick.Window 2.2

import QtWebSockets 1.1

Window {
    visible: true
    width: 640
    height: 480
    color: "transparent"
    title: qsTr("酷狗弹幕姬")

    property int roomid: 5047532

    property var heartbeatdata: '\x64\x00\x01\x00'

    function getSocToken(roomid) {
        var xhr = new XMLHttpRequest()
        var url = 'https://fx2.service.kugou.com/socket_scheduler/pc/v2/address.jsonp?'
        url += '_v=7.0.0&_p=0&pv=20191231&at=102&cid=105&rid=' + roomid

        xhr.open("GET", url, false)

        xhr.send(null)
        return JSON.parse(xhr.responseText).data.soctoken
    }


    WebSocket {
        id: wssObj
        url: "wss://chat1wss.kugou.com/acksocket"

        active: true

        onBinaryMessageReceived: function (binaryMsg) {
            var msg = kugou.decode(binaryMsg)
        }

        onStatusChanged: function (status) {
            switch (status) {
            case WebSocket.Connecting:
                console.debug(qsTr("正在连接..."))
                break;
            case WebSocket.Open:
                console.debug(qsTr("已连接"))

                var socToken = getSocToken(roomid)

                var loginRequestMessage = kugou.loginRequest(roomid, socToken)
                wssObj.sendBinaryMessage(loginRequestMessage)

                timerHeartBeat.start()
                break;
            case WebSocket.Closing:
                console.debug(qsTr("正在关闭连接"))
                break;
            case WebSocket.Closed:
                console.debug(qsTr("连接已关闭"))
                timerHeartBeat.stop()
                break;
            case WebSocket.Error:
                console.debug(qsTr("连接错误: %1").arg(wssObj.errorString))
                break;
            default:
                break;
            }
        }
    }

    Timer {
        id: timerHeartBeat
        interval: 10000
        running: false
        repeat: true

        onTriggered: {
            wssObj.sendBinaryMessage(heartbeatdata)
        }
    }

    ListModel {
        id: msgModel

        ListElement {
            name: "[A]:"
            message: "[口水黄豆][口水黄豆][口水黄豆]"
        }

        ListElement {
            name: "[B]:"
            message: "\\扇宝/\\扇宝/\\扇宝/\\扇宝/\\扇宝/"
        }

        ListElement {
            name: "[A]:"
            message: "[口水黄豆][口水黄豆][口水黄豆]"
        }

        ListElement {
            name: "[B]:"
            message: "\\扇宝/\\扇宝/\\扇宝/\\扇宝/\\扇宝/"
        }

        ListElement {
            name: "[A]:"
            message: "[口水黄豆][口水黄豆][口水黄豆]"
        }

        ListElement {
            name: "[B]:"
            message: "\\扇宝/\\扇宝/\\扇宝/\\扇宝/\\扇宝/"
        }

        ListElement {
            name: "[A]:"
            message: "[口水黄豆][口水黄豆][口水黄豆]"
        }

        ListElement {
            name: "[B]:"
            message: "\\扇宝/\\扇宝/\\扇宝/\\扇宝/\\扇宝/"
        }
    }

    ListView {
        id: danmuView

        spacing: 5

        anchors.fill: parent

        model: msgModel

        delegate: Rectangle {

            width: parent.width
            height: 100

            radius: 15
            color: "#f2f2f2"

            border.color: "#3597f9"
            border.width: 3

            Column {
                anchors.fill: parent
                anchors.leftMargin: 20

                Text {
                    font.pointSize: 24
                    color: "#3f00ff"
                    text: name
                }

                Text {
                    font.pointSize: 26
                    color: "#000000"
                    text: message
                }
            }
        }
    }
}
