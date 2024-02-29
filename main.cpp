#include "serialportassissant.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialPortAssissant w;
    w.show();
    return a.exec();
}
