import QtQuick 2.3
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Item {
    width: 360; height: 360

    anchors.fill: parent;

    Rectangle {
        id: container
        anchors.fill: parent
        color: "lightblue"

        Component.onCompleted: state = "toRight"

        Rectangle {
            id: redRect
            width: 50; height: 50
            anchors.centerIn: parent
            color: "red"
        }

        Rectangle {
            id: yellowRect
            width: 50; height: 50
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            color: "yellow"
        }

        Rectangle {
            id: greenRect
            width: 50; height: 50
            color: "green"
        }

        states: State {
            name: "toRight"
            AnchorChanges {
                target: greenRect
                anchors.right: parent.right
            }
        }

        transitions: Transition {
            AnchorAnimation { duration: 1000 }
        }
    }
}
