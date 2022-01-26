#ifndef SERIAL_H
#define SERIAL_H

#include <QMainWindow>
#include "uartcore.h"

namespace Ui {
class serial;
}

class serial : public QMainWindow
{
    Q_OBJECT

public:
    explicit serial(QWidget *parent = 0);
    ~serial();

private slots:
    void on_refreshButton_clicked();
    void on_openPortButton_clicked();
    void on_sendButton_clicked();
    void readSerialData();

    void on_clearTextButton_clicked();

private:
    Ui::serial *ui;
    Uartcore *m_serial; // 自定义串口类对象指针
    QLabel* rx_label;
    QLabel* tx_label;
    QLabel* connect_label;
    qint64 rx_count = 0;
    qint64 tx_count = 0;
};

#endif // SERIAL_H
