import QtQml 2.3
import QtQuick 2.9

Item {
    width: 100; height: 100
    Component {
         id:selectbutton
        Rectangle{

                Text: qsTr("Select a File")
            width:20
            height:10
            onEnabledChanged: {playBackCls.fileSelectionDialog();}
        }
    }

    Component {
        id: redSquare
        Image {
            id: imgId
            source: "play.png"
        }
        Rectangle {
            color: "red"
            width: 10
            height: 10
        onEnabledChanged:  {playBackCls.onPlay();}
        }

    }
    Component {
        id: greenSquare
        Image {
            id: imgPauseId
            source: "pause.png"
        }
        Rectangle {
            color: "green"
            width: 10
            height: 10
        onEnabledChanged: {playBackCls.onPause();}
        }

    }
    Component{
        id: slider

        }


    Loader {sourceComponent: selectbutton;}
    Loader { sourceComponent: redSquare ;x:5;y:15}
    Loader { sourceComponent: greenSquare; x: 20 ;y:15}


}
