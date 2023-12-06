

import QtQuick 2.6
import QtQuick.Controls 2.1

ScrollablePage {
    id: page

    Column {
        spacing: 40
        width: parent.width

        Label {
            width: parent.width
            wrapMode: Label.Wrap
            horizontalAlignment: Qt.AlignHCenter
            text: "CheckBox presents an option button that can be toggled on or off. "
                + "Check boxes are typically used to select one or more options from a set of options."
        }

        Column {
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter

            CheckBox {
                text: "First"
                checked: true
            }
            CheckBox {
                text: "Second"
            }
            CheckBox {
                text: "Third"
                checked: true
                enabled: false
            }
        }
    }
}
