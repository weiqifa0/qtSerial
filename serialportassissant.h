#ifndef SERIALPORTASSISSANT_H
#define SERIALPORTASSISSANT_H

#include <QWidget>



#include <QTabWidget>

#include <QIcon>
#include <QVBoxLayout>

#include <UI/basicfunc.h>
#include <UI/portconfig.h>
#include <UI/customformat.h>
#include <UI/chartanalize.h>
#include <UI/preference.h>

class SerialPortAssissant : public QWidget
{
    Q_OBJECT

public:
    SerialPortAssissant(QWidget *parent = nullptr);
    ~SerialPortAssissant();

private:
    QTabWidget  *m_mainWidget;
    QVBoxLayout *m_mainLayout;
    PortConfig     *m_portConfig;
    BasicFunc     *m_basicFunc;
    CustomFormat     *m_customFormat;
    ChartAnalize     *m_chartAnalize;
    Preference     *m_preference;
};

#endif // SERIALPORTASSISSANT_H
