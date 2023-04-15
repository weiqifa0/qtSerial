#include "uart_interaction.h"
#include "uart_setting.h"
#include "ui_uart_interface.h"

serial::serial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serial){
  ui->setupUi(this);
  ui->retranslateUi(this);

  // 初始化串口
  uart_core_ = new Uartcore;

  // 寻找可用串口
  QStringList serialStrList;
  serialStrList = uart_core_->serial_port_scanning();
  for (int i=0; i<serialStrList.size(); i++) {
     ui->portComboBox->addItem(serialStrList[i]); // 在comboBox那添加串口号
  }

  // 默认设置波特率为115200（第5项）
  ui->baudComboBox->setCurrentIndex(5);
  // 当下位机中有数据发送过来时就会响应这个槽函数
  connect(uart_core_, SIGNAL(read_signal()), this, SLOT(readSerialData()));

  status_bar_initialization();
}

serial::~serial(){
  delete ui;
}

void serial::status_bar_initialization(){
  QStatusBar* bar = ui->statusBar;
  rx_display_ = new QLabel;
  rx_display_->setMinimumSize(300,20);
  rx_display_->setFrameShape(QFrame::NoFrame);
  rx_display_->setFrameShadow(QFrame::Plain);
  rx_display_->setText(tr("RX")+": 0");
  rx_display_->setStyleSheet("QLabel { color : black; }");

  tx_display_ = new QLabel;
  tx_display_->setMinimumSize(300,20);
  tx_display_->setFrameShape(QFrame::NoFrame);
  tx_display_->setFrameShadow(QFrame::Plain);
  tx_display_->setText((tr("TX") + ": 0"));
  tx_display_->setStyleSheet("QLabel { color : black; }");

  connect_display_ = new QLabel;
  connect_display_->setMinimumSize(300,20);
  connect_display_->setFrameShape(QFrame::NoFrame);
  connect_display_->setFrameShadow(QFrame::Plain);
  connect_display_->setText(tr("Serial Port not connect"));
  connect_display_->setStyleSheet("QLabel { color : black; }");

  bar->addWidget(connect_display_);
  bar->addWidget(rx_display_);
  bar->addWidget(tx_display_);
}

void serial::on_refreshButton_clicked() {
  QStringList serialStrList;
  serialStrList = uart_core_->serial_port_scanning();
  ui->portComboBox->clear();
  for (int i=0; i<serialStrList.size(); i++){
    ui->portComboBox->addItem(serialStrList[i]);
  }
}

void serial::on_openPortButton_clicked() {
  if (ui->portComboBox->currentText().isEmpty()) {
    show_text(NO_SERIAL_PORT);
    return;
  }
  if(is_the_serial_port_open_ == false) {
    if(uart_core_->open(ui->portComboBox->currentText(),
                      ui->baudComboBox->currentText().toInt(),
                      uart_core_->data_bits_,
                      uart_core_->parity_bits_,
                      uart_core_->stop_bits_,
                      uart_core_->flow_control_)) {
      // 关闭下拉列表使能
      ui->portComboBox->setEnabled(false);
      ui->baudComboBox->setEnabled(false);
      ui->refreshButton->setEnabled(false);
      ui->openPortButton_3->setEnabled(false);
      // 修改按钮名称
      ui->openPortButton->setText(tr("Close Port"));
      connect_display_->setText(tr("Port already opended"));
      connect_display_->setStyleSheet("QLabel { color : green; }");

      is_the_serial_port_open_ = true;
    }
  } else {
    // 关闭串口
    uart_core_->close();
    // 重新开启下拉列表使能
    ui->portComboBox->setEnabled(true);
    ui->baudComboBox->setEnabled(true);
    ui->refreshButton->setEnabled(true);
    ui->openPortButton_3->setEnabled(true);
    // 恢复按钮名称
    ui->openPortButton->setText(tr("Open Port"));
    connect_display_->setText(tr("Port already Closed"));
    connect_display_->setStyleSheet("QLabel { color : black; }");

    is_the_serial_port_open_ = false;
  }
}

void serial::on_sendButton_clicked(){
  QByteArray send_data;
  if(ui->hexSendCheckBox->checkState() == false){
    send_data = ui->sendTextEdit->toPlainText().toLatin1();
  }else{
    send_data = uart_core_->hex_string_to_bytearray(ui->sendTextEdit->toPlainText());
  }

  if (send_data.length() <= 0) {
    ui->recvTextEdit->append(tr("No Input"));
    return;
  }

  tx_quantity_ += send_data.length();
  tx_display_->setText(tr("TX")+": "+QString::number(tx_quantity_,10));
  uart_core_->send_data(send_data);
}

void serial::show_text(const QString &text){
    ui->recvTextEdit->insertPlainText(text+"\n");
}

// 读取从自定义串口类获得的数据
void serial::readSerialData() {
  QString originStr = ui->recvTextEdit->toPlainText();
  ui->recvTextEdit->clear();
  ui->recvTextEdit->setText(originStr);
  ui->recvTextEdit->moveCursor(QTextCursor::End);

  if(ui->hexRecvCheckBox->checkState()){
    ui->recvTextEdit->insertPlainText(uart_core_->get_data_buffer_content().toHex()); //转换成HEX
  }else{
    ui->recvTextEdit->insertPlainText(uart_core_->get_data_buffer_content());
  }
  rx_quantity_ += uart_core_->get_data_buffer_content().length();
  rx_display_->setText(tr("RX")+": "+QString::number(tx_quantity_,10));
  //ui->recvTextEdit->moveCursor(QTextCursor::End); // 在末尾移动光标一格
  ui->recvTextEdit->insertPlainText("\n");

  uart_core_->clear_data_buffer_content();
}

void serial::on_clearTextButton_clicked(){
  ui->recvTextEdit->clear();
  ui->recvTextEdit->moveCursor(QTextCursor::Start);
  ui->sendTextEdit->clear();
}

void serial::on_actionExit_triggered(){
//  QApplication* app;
//  app->exit(0);
}

void serial::on_openPortButton_3_clicked(){
  setting param;
  param.find_available_serial_ports_and_add(uart_core_);
  param.exec();

  if(!uart_core_->serial_name_.isEmpty()){
      ui->portComboBox->setCurrentText(uart_core_->serial_name_);
  }

  if(uart_core_->baud_rate_ > 0){
      ui->baudComboBox->setCurrentText(QString::number(uart_core_->baud_rate_)) ;
  }
}

void serial::on_portComboBox_activated(const QString &arg1){
  uart_core_->serial_name_ = arg1;
}
