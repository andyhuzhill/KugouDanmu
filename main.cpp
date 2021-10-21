//
//      File  : %{Cpp:License:FileName}
//
// Description:
//
//      Author: andy
//     Created: 2021-10-20
//
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFont>

#include "kugouproto.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QFont font;
    font.setFamily("Microsoft YaHei");
    app.setFont(font);

    KugouProto kugouProto;

    engine.rootContext()->setContextProperty("kugou", &kugouProto);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
