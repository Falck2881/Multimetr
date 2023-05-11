#ifndef SHELL_H
#define SHELL_H

#include "TypeApplication.h"
#include "Client.h"
#include <string>
#include <memory>


class Shell: public Type::Application
{
    public:
        Shell(const qint32 numberChannel);
    private:
        qint32 run() override;
        std::string inputOfCommand();
        std::string checkInput(std::string name);
        void showHelp();
    private:
        const qint32 numberChannel;
        const std::string messageHelp;
        std::unique_ptr<Client> client;
};

#endif // SHELL_H
