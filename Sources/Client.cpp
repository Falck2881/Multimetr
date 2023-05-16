#include "Client.h"
#include <iostream>

Client::Client():threadSocket(new QThread)
{
    socket.moveToThread(threadSocket);
    connectToSocket();
    threadSocket->start();
}

void Client::connectToSocket()
{
   QObject::connect(this, &Client::reboot, &socket, &Socket::restart);
   QObject::connect(&socket, &Socket::failedConnect, this, &Client::onRepeatConnect);
   QObject::connect(&socket, &Socket::successConnect, this, &Client::onRunning);
}

void Client::sendRequest(const std::string &nameCommand)
{
    Sys::sendRequest(socket.get(),nameCommand.data(),nameCommand.length(), MSG_NOSIGNAL);
}

std::string Client::receiveAnswer()
{
    char buffer[256];
    memset(buffer,'\0',sizeof(buffer));
    const qint32 result = Sys::reciveAnswer(socket.get(), buffer, sizeof(buffer));

    if(Sys::errorToRead(result)){
        onRepeatConnect();
    }else{
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

void Client::restart()
{
    emit reboot();
}

void Client::onRepeatConnect()
{
    emit repeatConnect();
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
