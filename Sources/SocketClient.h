#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include "System.h"
#include "CommunicationCenter.h"
#include <string>
#include <QObject>


class Socket: public QObject
{
    Q_OBJECT

    public:
        Socket();
        int get() const;
        void close();
        std::string status();

    public slots:
        void restart();
    private:
        void initialize();
        void create();
        bool connect();
    protected:
        struct sockaddr_un domain;
        int socket_fd;
        const std::string pathToAddress;
        CommunicationCenter technicalSupport;
    signals:
        void running();
        void loading();
};

#endif // SOCKETCLIENT_H
