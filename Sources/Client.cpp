#include "Client.h"
#include <iostream>


Client::Client():threadSocket(new QThread(&socket))
{
    socket.moveToThread(threadSocket);
    connect();
    threadSocket->start();
}

void Client::connect()
{
   QObject::connect(this, &Client::reboot, &socket, &Socket::restart);
   QObject::connect(&socket, &Socket::loading, this, &Client::onLoading);
   QObject::connect(&socket, &Socket::running, this, &Client::onRunning);
}

void Client::sendRequest(const std::string &nameCommand)
{
    const qint32 result = Sys::sendRequest(socket.get(),nameCommand.data(),nameCommand.length(), MSG_NOSIGNAL);

    if(Sys::errorToSend(result))
        socket.status();
}

std::string Client::receiveAnswer()
{
    char buffer[256];
    memset(buffer,'\0',sizeof(buffer));
    const qint32 result = Sys::reciveAnswer(socket.get(), buffer, sizeof(buffer));

    if(Sys::errorToRead(result)){
        p_answer = socket.status().data();
        std::cout << p_answer.toStdString() << std::endl;
        onLoading();
    }
    else{
        p_answer = buffer;
        onRunning();
    }

    return p_answer.toStdString();
}

void Client::setRequest(QString request)
{
    if(request == p_answer)
        return;

    sendRequest(request.toStdString());
    p_answer = receiveAnswer().data();

    emit updateAnswer();
    emit showAnswer();
}

QString Client::answer() const
{
    return p_answer;
}

void Client::disconnect()
{
    socket.close();
}

void Client::onReboot()
{
    emit reboot();
}

void Client::onLoading()
{
    emit loading();
}

void Client::onRunning()
{
    emit running();
}

Client::~Client()
{
    threadSocket->quit();
    threadSocket->wait();
    delete threadSocket;
}
