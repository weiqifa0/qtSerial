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
class PortConfig : public QWidget
{
    Q_OBJECT
public:
    explicit PortConfig(QWidget *parent = nullptr);
    QIcon getIcon();
signals:
private:
    QGridLayout *m_layout;
    QGroupBox *m_portConfBox;
    QLabel *m_PortNameLabel;
    QComboBox *m_portNameBox;
    QHBoxLayout *m_portNameLayout;
    QVBoxLayout *m_mainLayout;

private:

};

#endif // PORTCONFIG_H
