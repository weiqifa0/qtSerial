#include "serialportassissant.h"

SerialPortAssissant::SerialPortAssissant(QWidget *parent)
    : QWidget(parent),
      m_mainWidget(new QTabWidget()),
      m_mainLayout(new QVBoxLayout(this)),
      m_portConfig(new PortConfig()),
      m_basicFunc(new BasicFunc()),
      m_customFormat(new CustomFormat()),
      m_chartAnalize(new ChartAnalize()),
      m_preference(new Preference())
{
    m_mainLayout->addWidget(m_mainWidget);
    m_mainWidget->setTabPosition(QTabWidget::West);
    m_mainWidget->addTab(m_portConfig, m_portConfig->getIcon(), tr("PortConfig"));
    m_mainWidget->addTab(m_basicFunc, m_basicFunc->getIcon(), tr("BasicFunc"));
    m_mainWidget->addTab(m_customFormat, m_customFormat->getIcon(), tr("Custom"));
    m_mainWidget->addTab(m_chartAnalize, m_chartAnalize->getIcon(), tr("ChartAnalize"));
    m_mainWidget->addTab(m_preference, m_preference->getIcon(), tr("Preference"));
    m_mainWidget->setCurrentIndex(1);

}

SerialPortAssissant::~SerialPortAssissant()
{
}

