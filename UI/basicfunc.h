#ifndef BASICFUNC_H
#define BASICFUNC_H

#include <QWidget>
#include <QIcon>
#include <QTextBrowser>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QToolButton>

class BasicFunc : public QWidget
{
    Q_OBJECT
public:
    explicit BasicFunc(QWidget *parent = nullptr);
    QIcon getIcon();


signals:
    void startCycleSend(QByteArray data, int len, int isHex, int cycle);
    void stopCycleSend();
    void SendData(QByteArray data, int len, int isHex);
public slots:
    void onDataReceive(QByteArray data);
private:
    void doLayout();
    void createUIItems();
private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_sendLayout;
    QHBoxLayout *m_showLayout;
    QGroupBox *m_displayGrp;
    QGroupBox *m_inputGrp;
    QTextBrowser *m_dispText;
    QPlainTextEdit *m_editText;
    QCheckBox *m_showHex;
    QCheckBox *m_sendCycle;
    QCheckBox *m_showTime;
    QCheckBox *m_sendHex;
    QLabel *m_cycleUint;
    QSpinBox *m_cycleInternal;
    QPushButton *m_send;
    QPushButton *m_clearShow;
    QPushButton *m_save2File;
};

#endif // BASICFUNC_H
