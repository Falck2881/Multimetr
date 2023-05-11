#include "GuiApp.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QUrl>

GuiApp::GuiApp(qint32 argc, std::string argv):
    buttonResult(nullptr),
    argc(argc),
    argv(argv)
{

}


qint32 GuiApp::run()
{
    char* buffer[]{argv.data()};
    QApplication app(argc,buffer);

    qmlRegisterType<Client>("Client", 1, 0, "Client");
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/Windows/Sources/MainWindow.qml"));
    return app.exec();
}


