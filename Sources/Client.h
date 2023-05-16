#ifndef CLIENT_H
#define CLIENT_H

#include "SocketClient.h"
#include "System.h"
#include <string>
#include <QtGlobal>
#include <QObject>
#include <QThread>
#include <QString>

class Client: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString request WRITE setRequest)
    Q_PROPERTY(QString answer READ answer NOTIFY updateAnswer)

    public:
        Client();
        ~Client();
        void setRequest(QString request);
        QString answer() const ;
        void sendRequest(const std::string& nameCommand);
        std::string receiveAnswer();

    public slots:
        void restart();
        void disconnect();

    private slots:
        void onRunning();
        void onRepeatConnect();

    private:
        void connectToSocket();

    private:
        Socket socket;
        QString p_answer;
        QThread* threadSocket;

    signals:
        void updateAnswer();
        void showAnswer();
        void running();
        void repeatConnect();
        void reboot();
};

#endif // CLIENT_H
