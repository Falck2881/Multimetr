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


void GuiApp::run()
{
    char* buffer[]{argv.data()};
    QApplication app(argc,buffer);

    qmlRegisterType<Client>("Client", 1, 0, "Client");
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/Windows/Sources/MainWindow.qml"));

    int result{app.exec()};

    if(result != -1)
        exit(0);
    else
        exit(1);
}


