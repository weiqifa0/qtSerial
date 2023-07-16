#ifndef SERIAL_H
#define SERIAL_H

#include <QMainWindow>
#include "uart_core.h"
#include "qserialport.h"

namespace Ui {
class serial;
}

class serial : public QMainWindow
{
  Q_OBJECT

  #define NO_SERIAL_PORT tr("No Available Serial Port")

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
  void show_text(const QString &text);
  void status_bar_initialization();
private:
  Ui::serial *ui;
  Uartcore *uart_core_;
  QLabel* rx_display_;
  QLabel* tx_display_;
  QLabel* connect_display_;
  qint64 rx_quantity_ = 0;
  qint64 tx_quantity_ = 0;
  bool is_the_serial_port_open_ = false;
};

#endif // SERIAL_H
