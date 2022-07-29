#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include "uart_core.h"

namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    void find_available_serial_ports_and_add(Uartcore* m_serial_);
    ~setting();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::setting *ui;
    Uartcore *uart_core_;
};

#endif // SETTING_H
