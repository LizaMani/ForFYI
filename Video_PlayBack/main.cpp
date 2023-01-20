#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QCoreApplication>
#include "playbackcls.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

     QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("playBackCls", new PlayBackCls);
    engine.load(QUrl(QStringLiteral("qrc:///Video_PlayBack_UI.qml")));
       return a.exec();
}
