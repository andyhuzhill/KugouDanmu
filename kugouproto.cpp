//
//      File  : kugouproto.cpp
//
// Description:
//
//      Author: andy
//     Created: 2021-10-20
//


#include <algorithm>

#include "kugouproto.hpp"

#include "kugou.pb.h"

#include <QDebug>
#include <QBuffer>
#include <QByteArray>
#include <QDataStream>


KugouProto::KugouProto(QObject *parent)
    : QObject(parent)
{

}

QString KugouProto::loginRequest(int roomid, QString socToken)
{
    KuGouPack::LoginRequest *loginRequest = new KuGouPack::LoginRequest();

    loginRequest->set_appid(1010);
    loginRequest->set_clientid(105);
    loginRequest->set_cmd(201);
    loginRequest->set_deviceno("4edc0e89-ccaf-452c-bce4-00f4cb6bb5bb");
    loginRequest->set_kugouid(0);
    loginRequest->set_platid(18);
    loginRequest->set_referer(0);
    loginRequest->set_roomid(roomid);
    loginRequest->set_sid("8b9b79a7-a742-4397-fcc0-94efa3a1c920");
    loginRequest->set_v(20191231);
    loginRequest->set_soctoken(socToken.toStdString());

    std::string serializedRequest;
    loginRequest->SerializeToString(&serializedRequest);

    auto msg = new KuGouPack::Message();
    msg->set_content(serializedRequest);

    std::string serializedMessage;
    msg->SerializeToString(&serializedMessage);

    std::string encodedMsg = encode(serializedMessage, 201);

    return QString::fromStdString(encodedMsg);
}

QString KugouProto::decode(QByteArray binaryMessage)
{
    QString result;

    qDebug() << "binaryMessage = " << binaryMessage;

    return result;
}

std::string KugouProto::encode(std::string msg, int cmd)
{
    int n = f.size();
    int i = msg.length();

    f.at(PAYLOAD).value = i;
    f.at(CMD).value = cmd;

    QByteArray res;
    QBuffer buffer(&res);
    buffer.open(QIODevice::WriteOnly);
    QDataStream data(&buffer);
    data.setByteOrder(QDataStream::BigEndian);

    for (int j = 0; j < f.size(); ++j) {
        data << f.at(j).value;
    }

    data << i;

//    std::copy(msg.begin(), msg.end(), std::)

    data << msg.c_str();

    return res.toStdString();
}

int KugouProto::g(int a)
{
    int t = 12;
    int n = 0;
    int i = 0;
    int e = a;

    while ((i < e) && (i < f.size())) {
        n += f.at(i).length;
        i += 1;
    }

    if (e == f.size()) {
        return n + t - 12;
    } else {
        return n;
    }
}

int KugouProto::g(int a, int b)
{
    int t = b;
    int n = 0;
    int i = 0;
    int e = a;

    while ((i < e) && (i < f.size())) {
        n += f.at(i).length;
        i += 1;
    }

    if (e == f.size()) {
        return n + t - 12;
    } else {
        return n;
    }
}

