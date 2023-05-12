#ifndef GUIAPP_H
#define GUIAPP_H

#include "TypeApplication.h"
#include "Client.h"
#include <QString>
#include <string>
#include <memory>
#include <QQuickView>
#include <QQmlContext>

class GuiApp: public Type::Application
{
    Q_OBJECT

    public:
        GuiApp(qint32 argc, std::string argv);
    private:
        void run() override;
    private:
        QObject* buttonResult;
        qint32 argc;
        std::string argv;
};
#endif // MAINWINDOW_H
