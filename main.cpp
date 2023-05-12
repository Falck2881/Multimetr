#include <QApplication>
#include "Mode.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Mode mode(argc,argv[1]);
    mode.startApp();

    return app.exec();
}
