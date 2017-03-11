import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0

Rectangle {
    signal submitTextField(string text)

    // this function is our QML slot
    function setTextField(text){
        console.log("setTextField: " + text)
        textField1.text = text
    }

    visible: true
    width: 360
    height: 360



    TextField {
        id: textField1
        x: 24
        y: 156
        placeholderText: qsTr("Enter some text...")
    }

    Button {
        x: 24
        y: 102
        text: qsTr("Uppercase me!")

        onClicked:
            // emit the submitTextField signal
            submitTextField(textField1.text)
    }

    Button {
        id: button1
        x: 24
        y: 201
        text: qsTr("Button")
    }

    Button {
        id: button2
        x: 24
        y: 248
        text: qsTr("Button")
    }


//    GridLayout{
//        columns: 3  //每行3列
//        Button{text:"Button1"}
//        Button{text:"Button2"}
//        Button{text:"Button3"}
//        Button{text:"Button4"}
//        Button{text:"Button5"}
//        Button{text:"Button6"}
//        Button{text:"Button7"}
//        Button{text:"Button8"}
//        Button{text:"Button9"}
//    }
}
