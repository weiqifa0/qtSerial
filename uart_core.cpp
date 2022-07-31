#include "uart_core.h"

Uartcore::Uartcore(){
  serial_port_ = new QSerialPort;
}

// 扫描可用串口
QStringList Uartcore::serial_port_scanning() {
  QStringList serialStrList;
  foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
    serial_port_->setPort(info);
    // 判断端口能否以读写方式打开
    if(serial_port_->open(QIODevice::ReadWrite)){
      serialStrList.append(serial_port_->portName());
      // 然后自动关闭等待人为开启（通过"打开串口按钮"）
      serial_port_->close();
    }
  }
  return serialStrList;
}

// 打开串口
bool Uartcore::open(QString serialName, int baudRate, int data_bit, int parity_bit, int stop_bit, int flow_control) {
  serial_port_->setPortName(serialName);
  if (serial_port_->open(QIODevice::ReadWrite)) {
    serial_port_->setBaudRate(baudRate);
    serial_port_->setDataBits((QSerialPort::DataBits)data_bit );
    serial_port_->setParity((QSerialPort::Parity)parity_bit );
    serial_port_->setStopBits((QSerialPort::StopBits)stop_bit );
    serial_port_->setFlowControl((QSerialPort::FlowControl)flow_control );
    connect(serial_port_, SIGNAL(readyRead()), this, SLOT(read_lower_computer_dataer_computer_dataer_computer_data()));
    connect(serial_port_, SIGNAL(readyRead()), this, SIGNAL(read_signal()));
    return true;
  }

  return false;
}

// 关闭串口
void Uartcore::close() {
  serial_port_->clear();
  serial_port_->close();
}

// 发送数据给下位机
void Uartcore::send_data(QByteArray &data){
  serial_port_->write(data);
}

// 读取下位机发来数据
void Uartcore::read_lower_computer_dataer_computer_dataer_computer_data() {
  serial_buff_ = serial_port_->readAll();
}

// 获得读取数据缓冲区
QByteArray Uartcore::get_data_buffer_content() {
  return serial_buff_;
}

void Uartcore::clear_data_buffer_content(){
  serial_buff_.clear();
}

QByteArray Uartcore::hex_string_to_bytearray(QString HexString)
{
  bool ok;
  QByteArray data;
  HexString = HexString.trimmed();
  HexString = HexString.simplified();
  QStringList sl = HexString.split(" ");

  foreach (QString s, sl){
    if(!s.isEmpty()){
      char c = static_cast<char>(s.toInt(&ok, 16) & 0xFF);
      if(ok){
        data.append(c);
      } else {
        QMessageBox::warning(nullptr, tr("Error："),
                             QString("非法的16进制字符: \"%1\"").arg(s));
      }
    }
  }
  return data;
}

