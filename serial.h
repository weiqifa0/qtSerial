#ifndef SERIAL_H
#define SERIAL_H

#include <QMainWindow>
#include "uartcore.h"
#include "qserialport.h"

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
    void on_actionExit_triggered();
    void on_openPortButton_3_clicked();

    void on_portComboBox_activated(const QString &arg1);

private:
    Ui::serial *ui;
    Uartcore *m_serial; // 自定义串口类对象指针
    QLabel* rx_label;
    QLabel* tx_label;
    QLabel* connect_label;
    qint64 rx_count = 0;
    qint64 tx_count = 0;
    bool serial_open = false;
    void show_text(const QString &text);

    #define NO_SERIAL_PORT tr("没有可以使用的串口")
};

#endif // SERIAL_H
