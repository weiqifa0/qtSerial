#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QWidget>
#include <QIcon>

class Preference : public QWidget
{
    Q_OBJECT
public:
    explicit Preference(QWidget *parent = nullptr);
    QIcon getIcon();

signals:

};

#endif // PREFERENCE_H
