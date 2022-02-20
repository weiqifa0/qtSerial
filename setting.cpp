#include "setting.h"
#include "ui_setting.h"
#include "serial.h"

setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);

}

void setting::set_serial_core_obj(Uartcore* m_serial_)
{
    m_serial = m_serial_;

    // 寻找可用串口
    QStringList serialStrList;
    serialStrList = m_serial->scanSerial();
    for (int i=0; i<serialStrList.size(); i++)
    {
        ui->comComboBox->addItem(serialStrList[i]); // 在comboBox那添加串口号
    }
}

setting::~setting()
{
    delete ui;
}

void setting::on_buttonBox_accepted()
{
    m_serial->serial_name_ = ui->comComboBox->currentText();
    m_serial->baud_rate_ = ui->baudComboBox->currentText().toInt();
    m_serial->data_bits_ = ui->bitComboBox->currentText().toInt();
    m_serial->parity_bits_ = ui->parityComboBox->currentText().toInt();
    m_serial->stop_bits_ = ui->stopComboBox->currentText().toInt();
    m_serial->flow_control_ = ui->flowctrComboBox->currentText().toInt();
    qDebug()<< "serial_name_:" <<m_serial->serial_name_;
    qDebug()<< "baud_rate_:" <<m_serial->baud_rate_;
    qDebug()<< "data_bits_:" <<m_serial->data_bits_;
    qDebug()<< "parity_bits_:" <<m_serial->parity_bits_;
    qDebug()<< "stop_bits_:" <<m_serial->stop_bits_;
    qDebug()<< "flow_control_:" <<m_serial->flow_control_;
}

