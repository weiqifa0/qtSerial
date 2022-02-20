#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include "uartcore.h"

namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    void set_serial_core_obj(Uartcore* m_serial_);
    ~setting();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::setting *ui;
    Uartcore *m_serial; // 自定义串口类对象指针, 这个指针需要从serial类传入
};

#endif // SETTING_H
