#ifndef UARTCORE_H
#define UARTCORE_H
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

#include <iostream>
#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


class Uartcore:public QObject
{
    Q_OBJECT

public:
    Uartcore();
    QStringList serial_port_scanning();
    bool open(QString serialName, int baudRate, int data_bit, int parity_bit, int stop_bit, int flow_control);
    void close();
    void send_data(QByteArray &data);
    QByteArray get_data_buffer_content();
    void clear_data_buffer_content();
    QByteArray hex_string_to_bytearray(QString HexString);

public:
    QString serial_name_;
    int baud_rate_      = 115200;
    int data_bits_      = 8;
    int parity_bits_    = 0;
    int stop_bits_      = 1;
    int flow_control_   = 0;

signals:
    void read_signal();

public slots:
    void read_lower_computer_dataer_computer_dataer_computer_data();

private:
    QSerialPort *serial_port_ = nullptr;
    QByteArray serial_buff_;
};
#endif // UARTCORE_H

