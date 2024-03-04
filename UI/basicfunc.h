#ifndef BASICFUNC_H
#define BASICFUNC_H

#include <QWidget>
#include <QIcon>
#include <QTextBrowser>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>

class BasicFunc : public QWidget
{
    Q_OBJECT
public:
    explicit BasicFunc(QWidget *parent = nullptr);
    QIcon getIcon();
signals:

private:
    QVBoxLayout *m_mainLayout;
    QGroupBox *m_displayGrp;
    QGroupBox *m_inputGrp;
    QTextBrowser *m_dispText;
    QPlainTextEdit *m_editText;



};

#endif // BASICFUNC_H
