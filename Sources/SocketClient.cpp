#include "SocketClient.h"
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

Socket::Socket():
    socket_fd(0),
    pathToAddress("/tmp/socketForMultimetr")
{
    initialize();
}

void Socket::initialize()
{
    while(true){
        create();
        if(connect())break;
    }
}

void Socket::create()
{
    socket_fd = Sys::createSocket(AF_UNIX,SOCK_STREAM,0);

    if(technicalSupport.isOpeartionSuccessfully(socket_fd, "Client: Socket successufully create.\n")){
        memset(&domain,0,sizeof(domain));
        domain.sun_family = AF_UNIX;
        strncpy(domain.sun_path, pathToAddress.data(), sizeof(domain.sun_path) - 1);
    }
}

bool Socket::connect()
{
    const int result{Sys::connectWithServer(socket_fd, domain)};

    if(technicalSupport.isConnect(result))
        return true;
    else{
        close();
        return false;
    }
}

void Socket::restart()
{
    close();
    create();
    if(connect())
        emit successConnect();
    else
        emit failedConnect();
}

int Socket::get() const
{
    return socket_fd;
}

void Socket::close()
{
    Sys::closeSocket(socket_fd);
}
