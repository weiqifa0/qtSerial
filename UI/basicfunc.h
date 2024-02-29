#ifndef BASICFUNC_H
#define BASICFUNC_H

#include <QWidget>
#include <QIcon>

class BasicFunc : public QWidget
{
    Q_OBJECT
public:
    explicit BasicFunc(QWidget *parent = nullptr);
    QIcon getIcon();
signals:

};

#endif // BASICFUNC_H
