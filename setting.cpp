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
}

setting::~setting()
{
    delete ui;
}
