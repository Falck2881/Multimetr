#ifndef TYPEAPPLICATION_H
#define TYPEAPPLICATION_H

#include <QObject>
#include <QtGlobal>

namespace Type
{
    class Application: public QObject
    {
        Q_OBJECT

        public:
            virtual ~Application() = default;
            virtual void run() = 0;
        protected:
            Application() = default;
    };
}

#endif // TYPEAPPLICATION_H
