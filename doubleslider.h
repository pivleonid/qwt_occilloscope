#ifndef DOUBLESLIDER_H
#define DOUBLESLIDER_H


#include <QSlider>
#include <QScrollBar>

//class doubleSlider : public QSlider
class doubleSlider : public QScrollBar
{
    Q_OBJECT
public:
    //Конструктор
    doubleSlider(QWidget *parent = 0);
    ~doubleSlider();
signals:
    void doubleValueChanged(double );

private slots:
    void notifyValueChanged(int);
};

#endif // DOUBLESLIDER_H

