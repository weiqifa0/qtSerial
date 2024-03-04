#ifndef PORTCONFIG_H
#define PORTCONFIG_H

#include <QWidget>
#include <QIcon>
#include <QGroupBox>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
class PortConfig : public QWidget
{
    Q_OBJECT
public:
    explicit PortConfig(QWidget *parent = nullptr);
    QIcon getIcon();
signals:
private:

    void createUIItems();
    void doLayout();

    QGridLayout *m_layout;
    QGroupBox *m_portConfBox;

//    QHBoxLayout *m_portNameLayout;
    QVBoxLayout *m_mainLayout;

    QLabel *m_portNameLabel;
    QLabel *m_baudRateLabel;
    QLabel *m_dataBitsLabel;
    QLabel *m_stopBitsLabel;
    QLabel *m_parityBitsLabel;
    QLabel *m_flowControlLabel;

    QLabel *m_info;

    QComboBox *m_portNameBox;
    QComboBox *m_baudRate;
    QComboBox *m_dataBits;
    QComboBox *m_stopBits;
    QComboBox *m_parityBits;
    QComboBox *m_flowControl;
    QPushButton *m_openClose;
};

#endif // PORTCONFIG_H
