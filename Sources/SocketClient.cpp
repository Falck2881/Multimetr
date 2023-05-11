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

    if(technicalSupport.exists(socket_fd)){
        memset(&domain,0,sizeof(domain));
        domain.sun_family = AF_UNIX;
        strncpy(domain.sun_path, pathToAddress.data(), sizeof(domain.sun_path) - 1);
    }
}

bool Socket::connect()
{
    const int result{Sys::connectWithServer(socket_fd, domain)};

    if(technicalSupport.successfullyConnection(result))
        return true;
    else{
        close();
        return false;
    }
}

std::string Socket::status()
{
    std::string message{technicalSupport.errorInConnection()};
    std::cout << message << std::endl;
    return message;
}

void Socket::restart()
{
    close();
    create();
    if(connect())
        emit running();
    else
        emit loading();
}

int Socket::get() const
{
    return socket_fd;
}

void Socket::close()
{
    Sys::closeSocket(socket_fd);
}
