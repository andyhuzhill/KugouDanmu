# Resource object code (Python 3)
# Created by: object code
# Created by: The Resource Compiler for Qt version 5.15.2
# WARNING! All changes made in this file will be lost!

from PySide2 import QtCore

qt_resource_data = b"\
\x00\x00\x05>\
i\
mport QtQuick 2.\
15\x0aimport QtQuic\
k.Window 2.15\x0a\x0aW\
indow {\x0a    visi\
ble: true\x0a    wi\
dth: 640\x0a    hei\
ght: 480\x0a    col\
or: \x22transparent\
\x22\x0a    title: qsT\
r(\x22\xe9\x85\xb7\xe7\x8b\x97\xe5\xbc\xb9\xe5\xb9\x95\xe5\
\xa7\xac\x22)\x0a\x0a    proper\
ty int roomid: 5\
047532\x0a\x0a    Comp\
onent.onComplete\
d: {\x0a        kug\
ou.newMessage.co\
nnect(function (\
name, message){\x0a\
            if (\
name === \x22SYS\x22) \
{\x0a              \
  name = \x22\xe7\xb3\xbb\xe7\xbb\x9f\
\x22\x0a            }\x0a\
\x0a            msg\
Model.append({\x0a \
                \
               \x22\
name\x22: name,\x0a   \
                \
             \x22me\
ssage\x22: message\x0a\
                \
            })\x0a \
       })\x0a    }\x0a\
\x0a    ListModel {\
\x0a        id: msg\
Model\x0a    }\x0a\x0a   \
 ListView {\x0a    \
    id: danmuVie\
w\x0a\x0a        spaci\
ng: 5\x0a\x0a        a\
nchors.fill: par\
ent\x0a\x0a        mod\
el: msgModel\x0a\x0a  \
      delegate: \
Rectangle {\x0a\x0a   \
         width: \
danmuView.width\x0a\
            heig\
ht: 100\x0a\x0a       \
     radius: 15\x0a\
            colo\
r: \x22#f2f2f2\x22\x0a\x0a  \
          border\
.color: \x22#3597f9\
\x22\x0a            bo\
rder.width: 3\x0a\x0a \
           Colum\
n {\x0a            \
    anchors.fill\
: parent\x0a       \
         anchors\
.leftMargin: 20\x0a\
\x0a               \
 Text {\x0a        \
            font\
.pointSize: 24\x0a \
                \
   color: \x22#3f00\
ff\x22\x0a            \
        text: na\
me\x0a             \
   }\x0a\x0a          \
      Text {\x0a   \
                \
 font.pointSize:\
 26\x0a            \
        color: \x22\
#000000\x22\x0a       \
             tex\
t: message\x0a     \
           }\x0a   \
         }\x0a     \
   }\x0a    }\x0a}\x0a\
"

qt_resource_name = b"\
\x00\x08\
\x08\x01Z\x5c\
\x00m\
\x00a\x00i\x00n\x00.\x00q\x00m\x00l\
"

qt_resource_struct = b"\
\x00\x00\x00\x00\x00\x02\x00\x00\x00\x01\x00\x00\x00\x01\
\x00\x00\x00\x00\x00\x00\x00\x00\
\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x00\
\x00\x00\x01|\xa0\xe0\x019\
"

def qInitResources():
    QtCore.qRegisterResourceData(0x03, qt_resource_struct, qt_resource_name, qt_resource_data)

def qCleanupResources():
    QtCore.qUnregisterResourceData(0x03, qt_resource_struct, qt_resource_name, qt_resource_data)

qInitResources()
