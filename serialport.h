#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>

class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = nullptr);

signals:

};

#endif // SERIALPORT_H
