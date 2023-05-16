#include "Shell.h"
#include "GuiApp.h"
#include "Mode.h"
#include <QFile>
#include <QByteArray>
#include <iostream>

Mode::Mode(const qint32 numberArguments, const char* arguments):
    app(nullptr),numberArguments{numberArguments}
{
    if(isExistsOfArguments())
        createMode("GUI");
    else{
        warning();
        exit(1);
    }
}

bool Mode::isExistsOfArguments() const
{
    return 2 == 2;
}

void Mode::createMode(const std::string typeMode)
{
    if(typeMode == "shell")
        app = std::make_unique<Shell>(5);
    else if(typeMode == "GUI")
        app = std::make_unique<GuiApp>(1,typeMode);
    else if(typeMode == "help"){
        showHelp();
        exit(0);
    }
    else{
        warning();
        exit(1);
    }
}

void Mode::showHelp()
{
    const std::string message = readHelp();
    std::cout << message << std::endl;
}

std::string Mode::readHelp() const
{
    QFile file(":/HelpStart.txt");
    std::string message;

    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray array{file.readAll()};
        for(qint32 i{0}; i < array.size(); ++i)
            message += array.at(i);
    }

    file.flush();
    file.close();

    return message;
}

void Mode::warning()
{
    std::cout << "You entered invalid input a parameter. \n"
                 "Use parameter 'help'. \n" << std::endl;
}

void Mode::startApp()
{
    app->run();
}
