#include "CommunicationCenter.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

CommunicationCenter::CommunicationCenter():attemptsToConnection(1)
{

}

bool CommunicationCenter::exists(const int socket)
{
    if(socket != -1)
        return true;
    else{
        std::cout << "Client: Failed to create socket of active." << std::endl;
        exit(1);
    }
}

bool CommunicationCenter::successfullyConnection(const int result)
{
    if(result != -1)
        return true;
    else{
        std::cout << errorInConnection();
        return false;
    }
}

std::string CommunicationCenter::errorInConnection()
{
    std::string message ("Attempt: " + std::to_string(attemptsToConnection) +
                         "|Failed connecting to server, check activity the server.\n");
    std::this_thread::sleep_for(2s);
    ++attemptsToConnection;

    return message;
}

