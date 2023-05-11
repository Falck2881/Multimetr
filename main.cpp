#include <QCoreApplication>
#include "Mode.h"

int main(int argc, char *argv[])
{

    Mode mode(argc,const_cast<const char**>(argv));
    mode.startApp();

    return 0;
}
