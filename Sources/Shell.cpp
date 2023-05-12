#include "Shell.h"
#include <iostream>
#include <QFile>
#include <regex>

Shell::Shell(const qint32 numberChannel):
    numberChannel(numberChannel),
    messageHelp("You entered invalid input a command. \n"
                "Use command 'help'. \n"),
    client{std::make_unique<Client>()}
{

}

void Shell::run()
{
    std::string name;

    while(true)
    {
        std::cout << "Shell Multimetr: Number channels: " << numberChannel << std::endl;
        std::cout << "Client >>> ";

        name = inputOfCommand();

        if(name == "help")
            showHelp();
        else if(name == "close"){
            client->disconnect();
            exit(0);
        }else if(name != ""){
            client->sendRequest(name);
            std::cout << client->receiveAnswer() << "\n" <<std::endl;
        }
    }

}

std::string Shell::inputOfCommand()
{
    std::string name;
    std::getline(std::cin,name);
    std::endl(std::cout);

    if(name != "help" && name != "close")
        name = checkInput(name);

    return name;
}

std::string Shell::checkInput(std::string nameCommand)
{
    std::string _template{"(start_measure|set_range|stop_measure|get_status|get_result)"
                            "\\s(channel[0-%],+\\s+range[0-4]|channel[0-%])"};
    _template.replace(_template.find("%"),1,std::to_string(numberChannel-1));
    _template.replace(_template.find("%"),1,std::to_string(numberChannel-1));

    std::regex regExp(_template.data());
    std::smatch match;

    if(!std::regex_match(nameCommand,match,regExp)){
        std::cout << messageHelp << std::endl;
        nameCommand = "";
    }

    return nameCommand;
}

std::string readHelp()
{
    QFile file(":/HelpShell.txt");
    std::string message;

    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray array{file.readAll()};
        for(int i{0}; i < array.size(); ++i)
            message += array.at(i);
    }

    file.flush();
    file.close();

    return message;
}

void Shell::showHelp()
{
    const std::string message{readHelp()};
    std::cout << ">>> " << message << std::endl;
}
