#ifndef CHARTANALIZE_H
#define CHARTANALIZE_H

#include <QWidget>
#include <QIcon>

class ChartAnalize : public QWidget
{
    Q_OBJECT
public:
    explicit ChartAnalize(QWidget *parent = nullptr);
    QIcon getIcon();
signals:

};

#endif // CHARTANALIZE_H
