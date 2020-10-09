import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Image Provider")

    Connections {
        target: imageProvider
        function onImageUpdated() { image.reload() }
    }

    Image {
        id: image

        readonly property string providerSource: "image://stream/";

        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        asynchronous: false
        cache: false

        function reload() {
            var oldSource = providerSource;
            source = "";
            source = oldSource;
        }
    }

}
