#ifndef COMMUNICATIONCENTER_H
#define COMMUNICATIONCENTER_H

#include <string>

class CommunicationCenter
{
    public:
        CommunicationCenter();
        std::string errorInConnection();
        bool exists(const int socket);
        bool successfullyConnection(const int result);
    private:
        int attemptsToConnection;
};

#endif // COMMUNICATIONCENTER_H
