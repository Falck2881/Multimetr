#ifndef COMMUNICATIONCENTER_H
#define COMMUNICATIONCENTER_H

#include <QtGlobal>
#include <string>

class CommunicationCenter
{
    public:
        CommunicationCenter();
        std::string errorInConnection();
        bool exists(const qint32 socket);
        bool successfullyConnection(const int result);
    private:
        quint32 attemptsToConnection;
};

#endif // COMMUNICATIONCENTER_H
