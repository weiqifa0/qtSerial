#include "portconfig.h"

PortConfig::PortConfig(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QGridLayout(this);
    m_portConfBox = new QGroupBox();
    m_PortNameLabel = new QLabel();
    m_portNameBox = new QComboBox();
    m_portNameLayout = new QHBoxLayout();
    m_mainLayout = new QVBoxLayout();



    m_portConfBox->setTitle(tr("PortSetting"));
    m_PortNameLabel->setText(tr("PortName"));
    m_portNameBox->setCurrentText(tr("Please Choose a Port Name"));

    m_layout->addWidget(m_portConfBox);

    m_portConfBox->setLayout(m_mainLayout);

    m_portNameLayout->addWidget(m_PortNameLabel,0, Qt::AlignRight);
    m_portNameLayout->addWidget(m_portNameBox, 1, Qt::AlignLeft);

    m_mainLayout->addLayout(m_portNameLayout, 0);


}

QIcon PortConfig::getIcon()
{
    return QIcon();
}
