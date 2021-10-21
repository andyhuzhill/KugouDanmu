import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 640
    height: 480
    color: "transparent"
    title: qsTr("酷狗弹幕姬")

    property int roomid: 5047532

    Component.onCompleted: {
        kugou.newMessage.connect(function (name, message){
            if (name === "SYS") {
                name = "系统"
            }

            msgModel.append({
                                "name": name,
                                "message": message
                            })

            danmuView.positionViewAtEnd()
        })
    }

    ListModel {
        id: msgModel
    }

    ListView {
        id: danmuView

        spacing: 5

        anchors.fill: parent

        model: msgModel

        delegate: Rectangle {

            width: danmuView.width
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
