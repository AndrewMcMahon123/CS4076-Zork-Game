/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Particles 2.0
import "content"

Item {
    id: window

    property int activeSuns: 0
    property int centerOffset: 72

    height: 480; width: 320


    MouseArea {
        anchors.fill: parent
        onClicked: window.focus = false;
    }

    //This is the message box that pops up when there's an error


    Item {
        id: scene
        anchors { top: startRoom.top; bottom: ground.bottom; left: parent.left; right: parent.right}
        z: 10
    }

   // sky
    Rectangle {
        id: startRoom
        anchors { left: parent.left; top: toolbox.bottom; right: parent.right;  bottomMargin: -window.centerOffset; bottom: parent.verticalCenter }
        gradient: Gradient {
            GradientStop { id: gradientStopA; position: 0.0; color: "#0E1533" }
            GradientStop { id: gradientStopB; position: 1.0; color: "#437284" }
        }
    }

    // stars (when there's no sun)
    ParticleSystem {
        id: particlesystem
        anchors.fill: startRoom



        Emitter {
            id: starsemitter
            anchors.fill: parent
            emitRate: parent.width
            lifeSpan: 5000
            group: "startRoom"

            PaletteItem {
                anchors.verticalCenter: parent.verticalCenter

                source: "content/images/house.jpg"
                image: "images/house.jpg"
                height: 420
                width: 420
                anchors { top: startRoom.top; bottom: ground.bottom; left: parent.left; right: parent.right}
            }


        }
    }





    // top panel
    Rectangle {
        id: toolbox

        height: window.centerOffset * 2
        color: "white"
        anchors { right: parent.right; top: parent.top; left: parent.left}

        Column {
            anchors.centerIn: parent
            spacing: 8

            Text { text: "Timer :" }

            Rectangle {
                width: palette.width + 10; height: palette.height + 10
                border.color: "black"

                Row {
                    id: palette
                    anchors.centerIn: parent
                    spacing: 8

                    PaletteItem {
                        anchors.verticalCenter: parent.verticalCenter
                        source: "content/images/bar.jpg"
                        image: "images/bar.jpg"
                        //anchors { right: parent.right; top: parent.top; left: parent.left}
                    }



            }

            Text { text: "Active Suns: " + window.activeSuns }
        }
    }

    //Popup toolbox down the bottom
    Rectangle {
        id: popupToolbox
        z: 1000
        width: parent.width
        height: popupColumn.height + 16
        color: "white"

        property bool poppedUp: false
        property int downY: window.height - (createButton.height + 16)
        property int upY: window.height - (popupColumn.height + 16)
        y: poppedUp ? upY : downY
        Behavior on y { NumberAnimation {}}

        Column {
            id: popupColumn
            y: 8
            spacing: 8

            Row {
                height: createButton.height
                spacing: 8
                Text { text: "Custom QML:"; anchors.verticalCenter: parent.verticalCenter }
                Button {
                    id: popupButton
                    text: popupToolbox.poppedUp ? "Hide" : "SOUTH"
                    onClicked: popupToolbox.poppedUp = !popupToolbox.poppedUp
                }
                Button {
                    id: createButton
                    text: "ENTER"
                    property bool aBool: false
                    onClicked: {
                           something = Qt.createQmlObject(qmlText361.text, scene, 'CustomObject');
                           aBool = true

                    }
                }

                Button {
                    id: hitButton
                    text: "HIT"
                    onClicked:{
                        scene.destroy();
                        }



                }

            }

            Rectangle {
                width: 10; height: 10

                TextEdit {
                    width: 10
                    height: 10
                    id: qmlText361
                    anchors.fill: parent; anchors.margins: 5
                    readOnly: false
                    font.pixelSize: 14
                    selectByMouse: true
                    wrapMode: TextEdit.WordWrap

                    text: "import QtQuick 2.0\nImage {\n    id: smile\n    x: 120 \n    y: 80 \n    source: 'content/images/zombie.jpg'\n height: 200\n width: 100 }"
                }
            }
        }
    }

    //Day state, for when a sun is added to the sce}
}
}
