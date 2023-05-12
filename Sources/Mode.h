#ifndef MODE_H
#define MODE_H

#include <memory>
#include <QtGlobal>
#include <string>
#include "TypeApplication.h"

class Mode
{
    public:
        Mode(const qint32 numberArguments, const char*arguments);
        void startApp();
    private:
        bool isExistsOfArguments() const;
        void createMode(const std::string typeMode);
        void showHelp();
        void warning();
        std::string readHelp() const;
    private:
        std::unique_ptr<Type::Application> app;
        qint32 numberArguments;
};

#endif // MODE_H
