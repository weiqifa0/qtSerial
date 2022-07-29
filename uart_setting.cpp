#include "uart_setting.h"
#include "uart_interaction.h"
#include "ui_uart_setting.h"

setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting){
    ui->setupUi(this);

}

void setting::find_available_serial_ports_and_add(Uartcore* serial_core) {
    uart_core_ = serial_core;
    QStringList serialStrList;
    serialStrList = uart_core_->serial_port_scanning();
    for (int i=0; i<serialStrList.size(); i++){
        ui->comComboBox->addItem(serialStrList[i]); // 在comboBox那添加串口号
    }
}

setting::~setting(){
    delete ui;
}

void setting::on_buttonBox_accepted(){
    uart_core_->serial_name_ = ui->comComboBox->currentText();
    uart_core_->baud_rate_ = ui->baudComboBox->currentText().toInt();
    uart_core_->data_bits_ = ui->bitComboBox->currentText().toInt();
    uart_core_->parity_bits_ = ui->parityComboBox->currentText().toInt();
    uart_core_->stop_bits_ = ui->stopComboBox->currentText().toInt();
    uart_core_->flow_control_ = ui->flowctrComboBox->currentText().toInt();
    qDebug()<< "serial_name_:" <<uart_core_->serial_name_;
    qDebug()<< "baud_rate_:" <<uart_core_->baud_rate_;
    qDebug()<< "data_bits_:" <<uart_core_->data_bits_;
    qDebug()<< "parity_bits_:" <<uart_core_->parity_bits_;
    qDebug()<< "stop_bits_:" <<uart_core_->stop_bits_;
    qDebug()<< "flow_control_:" <<uart_core_->flow_control_;
}

