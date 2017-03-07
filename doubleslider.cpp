
#include <QtGui>
#include "doubleslider.h"

doubleSlider::doubleSlider(QWidget *parent): QScrollBar(parent)
{
    setRange(0, 40);
    connect(this, SIGNAL(valueChanged(int)),
        this, SLOT(notifyValueChanged(int)));
}

doubleSlider::~doubleSlider(){
    //удалить всякое, если добавлю
    //по идее деструктор базового класса позаботитьс об этолм

}
void doubleSlider::notifyValueChanged(int value){
    double d_value = value/10.0;
    //этот сигнал привязать к doubleCheckbox
    // Max 3.3 V т.о. диспазон допустимых значений setRange(0, 40);
    //реализации сигнала нет, да она и не нужна
    emit doubleValueChanged(d_value);
}
