#ifndef CUSTOMFORMAT_H
#define CUSTOMFORMAT_H

#include <QWidget>
#include <QIcon>

class CustomFormat : public QWidget
{
    Q_OBJECT
public:
    explicit CustomFormat(QWidget *parent = nullptr);
    QIcon getIcon();
signals:

};

#endif // CUSTOMFORMAT_H
