#include "uart_core.h"

Uartcore::Uartcore()
{
    // 初始化串口
    serial_port_ = new QSerialPort;
    qDebug()<<"Uartcore()";
}

// 扫描可用串口
QStringList Uartcore::serial_port_scanning()
{
    QStringList serialStrList;
    // 读取串口信息
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        serial_port_->setPort(info);
        // 判断端口能否以读写方式打开
        if(serial_port_->open(QIODevice::ReadWrite))
        {
            serialStrList.append(serial_port_->portName());
            serial_port_->close(); // 然后自动关闭等待人为开启（通过"打开串口按钮"）
        }
    }
    return serialStrList;
}

// 打开串口
bool Uartcore::open(QString serialName, int baudRate, int data_bit, int parity_bit, int stop_bit, int flow_control)
{
    // 设置串口名
    serial_port_->setPortName(serialName);
    // 打开串口(以读写方式)
    if(serial_port_->open(QIODevice::ReadWrite))
    {
        serial_port_->setBaudRate(baudRate); // 设置波特率(默认为115200)
        serial_port_->setDataBits( /*QSerialPort::Data8*/(QSerialPort::DataBits)data_bit ); // 设置数据位(数据位为8位)
        serial_port_->setParity( /*QSerialPort::NoParity*/(QSerialPort::Parity)parity_bit ); // 设置校验位(无校验位)
        serial_port_->setStopBits( /*QSerialPort::OneStop*/(QSerialPort::StopBits)stop_bit ); // 设置停止位(停止位为1)
        serial_port_->setFlowControl( /*QSerialPort::NoFlowControl*/(QSerialPort::FlowControl)flow_control ); // 设置流控制(无数据流控制)

        // 当下位机中有数据发送过来时就会响应这个槽函数
        connect(serial_port_, SIGNAL(readyRead()), this, SLOT(read_lower_computer_dataer_computer_dataer_computer_data()));
        // 当下位机中有数据发送过来时就会触发这个信号，以提示其它类对象
        connect(serial_port_, SIGNAL(readyRead()), this, SIGNAL(read_signal()));

        return true;
    }

    return false;
}

// 关闭串口
void Uartcore::close()
{
    serial_port_->clear();
    serial_port_->close();
}

// 发送数据给下位机
void Uartcore::send_data(QByteArray &data)
{
    // 发送数据帧
    serial_port_->write(data);
}

// 读取下位机发来数据
void Uartcore::read_lower_computer_dataer_computer_dataer_computer_data()
{
    // 将下位机发来数据存储在数据缓冲区
    serial_buff_ = serial_port_->readAll();
}

// 获得读取数据缓冲区
QByteArray Uartcore::get_data_buffer_content()
{
    return serial_buff_;
}

// 清除读取数据缓冲区
void Uartcore::clear_data_buffer_content()
{
    serial_buff_.clear();
}

// 将16进制字符串转换为对应的字节序列
QByteArray Uartcore::hex_string_to_bytearray(QString HexString)
{
    bool ok;
    QByteArray data;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    QStringList sl = HexString.split(" ");

    foreach (QString s, sl)
    {
        if(!s.isEmpty())
        {
            char c = static_cast<char>(s.toInt(&ok, 16) & 0xFF);
            if(ok)
            {
                data.append(c);
            }
            else
            {
                qDebug()<<"非法的16进制字符："<<s;
                QMessageBox::warning(nullptr, tr("错误："), QString("非法的16进制字符: \"%1\"").arg(s));
            }
        }
    }

    return data;
}

