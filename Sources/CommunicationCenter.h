#ifndef COMMUNICATIONCENTER_H
#define COMMUNICATIONCENTER_H

#include <string>

class CommunicationCenter
{
    public:
        CommunicationCenter();
        bool isConnect(const int result);
        std::string errorInConnection();
        bool isOpeartionSuccessfully(const int result, const std::string message);
    private:
        int attemptsToConnection;
};

#endif // COMMUNICATIONCENTER_H
