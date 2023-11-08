#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QTextStream>
#include "iconValidator.h"

int main(int argc, char *argv[])
{
    if(argc != 2 || !IconValidator::Init(argv[1]))
    {
        QTextStream out(stdout);
        out << "Pls pass a valid icon path";
        return -1;
    }

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/QMLButton/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) { if (!obj && url == objUrl) QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
