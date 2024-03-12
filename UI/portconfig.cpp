#include "portconfig.h"

PortConfig::PortConfig(QWidget *parent)
    : QWidget(parent)
{
    createUIItems();
    doLayout();
}

QIcon PortConfig::getIcon()
{
    return QIcon();
}

void PortConfig::createUIItems()
{
    m_layout = new QGridLayout();
    m_portConfBox = new QGroupBox();
    m_mainLayout = new QVBoxLayout(this);


    m_portNameLabel     = new QLabel();
    m_baudRateLabel     = new QLabel();
    m_dataBitsLabel     = new QLabel();
    m_stopBitsLabel     = new QLabel();
    m_parityBitsLabel   = new QLabel();
    m_flowControlLabel  = new QLabel();
    m_info              = new QLabel();

    m_portNameBox    = new QComboBox();
    m_baudRate       = new QComboBox();
    m_dataBits       = new QComboBox();
    m_stopBits       = new QComboBox();
    m_parityBits     = new QComboBox();
    m_flowControl    = new QComboBox();

    m_openClose =  new QPushButton();

    m_portConfBox->setTitle(tr("PortSetting"));


    m_portNameLabel->setText(tr("Port Name")+ tr(":"));
    m_baudRateLabel->setText(tr("Baud Rate")+ tr(":"));
    m_dataBitsLabel->setText(tr("Data Bits")+ tr(":"));
    m_stopBitsLabel->setText(tr("Stop Bits")+ tr(":"));
    m_parityBitsLabel->setText(tr("Parity Bits")+ tr(":"));
    m_flowControlLabel->setText(tr("Flow Control")+ tr(":"));

    m_openClose->setText(tr("Open"));

    m_portNameLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_baudRateLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_dataBitsLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_stopBitsLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_parityBitsLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_flowControlLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void PortConfig::doLayout()
{


    m_portNameLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_portNameBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_portNameBox->setFixedWidth(400);



    m_layout->addWidget(m_portNameLabel, 0, 0, 1, 1, Qt::AlignRight);
    m_layout->addWidget(m_baudRateLabel, 1, 0, 1, 1, Qt::AlignRight);
    m_layout->addWidget(m_dataBitsLabel, 2, 0, 1, 1, Qt::AlignRight);
    m_layout->addWidget(m_stopBitsLabel, 3, 0, 1, 1, Qt::AlignRight);
    m_layout->addWidget(m_parityBitsLabel, 4, 0, 1, 1, Qt::AlignRight);
    m_layout->addWidget(m_flowControlLabel, 5, 0, 1, 1, Qt::AlignRight);

    m_layout->addWidget(m_portNameBox, 0, 1, 1, 1, Qt::AlignLeft);
    m_layout->addWidget(m_baudRate, 1, 1, 1, 1, Qt::AlignLeft);
    m_layout->addWidget(m_dataBits, 2, 1, 1, 1, Qt::AlignLeft);
    m_layout->addWidget(m_stopBits, 3, 1, 1, 1, Qt::AlignLeft);
    m_layout->addWidget(m_parityBits, 4, 1, 1, 1, Qt::AlignLeft);
    m_layout->addWidget(m_flowControl, 5, 1, 1, 1, Qt::AlignLeft);

    m_layout->addWidget(m_openClose, 6, 0, 1, 1, Qt::AlignLeft);

    m_layout->setColumnStretch(0,0);
    m_layout->setColumnStretch(1,2);
    m_portConfBox->setLayout(m_layout);

    m_mainLayout->addWidget(m_portConfBox, 0, Qt::AlignTop);
    m_mainLayout->addWidget(m_info, 1, Qt::AlignTop);
    this->setLayout(m_mainLayout);
}
