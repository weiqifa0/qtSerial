#include "basicfunc.h"

BasicFunc::BasicFunc(QWidget *parent) : QWidget(parent)
{
    createUIItems();
    doLayout();
}

QIcon BasicFunc::getIcon()
{
    return QIcon();
}

void BasicFunc::onDataReceive(QByteArray data)
{

}

void BasicFunc::createUIItems()
{
    m_mainLayout    = new QVBoxLayout(this);
    m_displayGrp    = new QGroupBox(tr("Display Settings"));
    m_inputGrp      = new QGroupBox(tr("Send Settings"));
    m_dispText      = new QTextBrowser();
    m_editText      = new QPlainTextEdit();
    m_showHex       = new QCheckBox(tr("Show Hex"));
    m_sendCycle     = new QCheckBox(tr("Send Cycle"));
    m_showTime      = new QCheckBox(tr("Show Time Stamp"));
    m_sendHex       = new QCheckBox(tr("Send Hex"));
    m_cycleUint     = new QLabel(tr("ms"));
    m_cycleInternal = new QSpinBox();
    m_send          = new QPushButton(tr("Send"));
    m_sendLayout    = new QHBoxLayout();
    m_showLayout    = new QHBoxLayout();
    m_clearShow     = new QPushButton(tr("Clear"));
    m_save2File     = new QPushButton(tr("Save to File"));

    m_send->setFixedWidth(100);
    m_cycleUint->setFixedWidth(50);
    m_cycleInternal->setFixedWidth(200);
}

void BasicFunc::doLayout()
{
    m_showLayout->addWidget(m_clearShow, 0);
    m_showLayout->addWidget(m_showHex, 0);
    m_showLayout->addWidget(m_showTime, 0);
    m_showLayout->addWidget(m_save2File, 0);
    m_showLayout->addStretch(1);

    m_displayGrp->setLayout(m_showLayout);


    m_sendLayout->addWidget(m_send, 0);
    m_sendLayout->addWidget(m_sendHex, 0);
    m_sendLayout->addWidget(m_sendCycle, 0);
    m_sendLayout->addWidget(m_cycleInternal, 0);
    m_sendLayout->addWidget(m_cycleUint, 0);
    m_sendLayout->addStretch(1);

    m_inputGrp->setLayout(m_sendLayout);

    m_mainLayout->addWidget(m_dispText, 1);
    m_mainLayout->addWidget(m_displayGrp, 0);
    m_mainLayout->addWidget(m_editText, 0);
    m_mainLayout->addWidget(m_inputGrp, 0);
}

