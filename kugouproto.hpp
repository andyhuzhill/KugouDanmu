//
//      File  : kugouproto.hpp
//
// Description:
//
//      Author: andy
//     Created: 2021-10-20
//
#ifndef KUGOUPROTO_HPP
#define KUGOUPROTO_HPP

#include <QObject>
#include <QString>
#include <QVariantMap>

#include <string>
#include <vector>

struct FieldInfo {
    int index;
    int length;
    int value;
};

class KugouProto : public QObject
{
    Q_OBJECT
public:
    KugouProto(QObject *parent = nullptr);

public slots:
    QString loginRequest(int roomid, QString socToken);

    QVariantMap decode(QByteArray binaryMessage);

private:
    std::string encode(std::string msg, int cmd);

    int g(int a);

    int g(int a, int b);

    enum FieldName {
        MAGIC = 0,
        VERSION = 1,
        TYPE = 2,
        HEADER = 3,
        CMD = 4,
        PAYLOAD = 5,
        ATTR = 6,
        CRC = 7,
        SKIP = 8,
    };

    std::vector<FieldInfo> f = {
        { 0, 1, 100}, // MAGIC
        { 1, 2, 1},   // VERSION
        { 2, 1, 1},   // TYPE
        { 3, 2, 12},  // HEADER
        { 4, 4, 0},   // CMD
        { 5, 4, 0},   // PAYLOAD
        { 6, 1, 0},   // ATTR
        { 7, 2, 0},   // CRC
        { 8, 1, 0},   // SKIP
    };
};

#endif // KUGOUPROTO_HPP
