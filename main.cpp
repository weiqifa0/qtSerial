#include "uart_interaction.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QTranslator translator;
  translator.load("./MySerial_zh_CN.qm");
  a.installTranslator(&translator);

  serial w;
  w.show();

  return a.exec();
}
