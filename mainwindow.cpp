/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console.h"
#include "settingsdialog.h"
//

//

#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QDebug>
#include <QVector>

//!         Конструктор базового класса
//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //! [0]
    ui->setupUi(this);
    console = new Console;
    console->setEnabled(false);

        for (int i = 0; i < 200 ; i++){
           x.append(i);
           x[i] *= 1.4;
        }
/*
 *     QVector<int>::iterator i = 0;
        for (int i = 0; i < 200 ; i++)
           x.append(i);

 */
    //! [1]
    serial = new QSerialPort(this);
    //! [1]
    settings = new SettingsDialog;

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);

    initActionsConnections();

    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);

//! [2]
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
//! [2]
    connect(console, &Console::getData, this, &MainWindow::writeData);
//! [3]
    //!
    my_connect_begin();
    my_connect_end();

}
//! [3]
//!         Настройка отображения
//!
void MainWindow::my_connect_begin(){

    ui->qwtPlot->setTitle("Частоты до 200 КГц");
    ui->qwtPlot->setCanvasBackground( Qt::black );
    // Параметры осей координат
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft, "U, мВ");
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, "time, us");


    //мин и макс осей
    ui->qwtPlot->setAxisScale(QwtPlot::yLeft, 0, 4, 0.5);
    ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,280, 20);
    ui->qwtPlot->insertLegend( new QwtLegend() );


    // Включить сетку
    // #include <qwt_plot_grid.h>
    QwtPlotGrid *grid = new QwtPlotGrid(); //
    grid->setMajorPen(QPen( Qt::white, 2,Qt::DotLine)); // цвет линий и толщина
    grid->attach( ui->qwtPlot ); // добавить сетку к полю графика

    //-- Кривая АЦП --//

    //#include <qwt_plot_curve.h>
    curve = new QwtPlotCurve();
    curve->setTitle( "Канал 1" );
    curve->setPen( Qt::blue, 6 ); // цвет и толщина кривой
    curve->setRenderHint
            ( QwtPlotItem::RenderAntialiased, true ); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Hexagon,
                                       QBrush( Qt::blue ), QPen( Qt::red, 2 ), QSize( 1, 1 ) );
    curve->setSymbol( symbol );

    //--График триггера--//

    //#include <qwt_plot_curve.h>
    curve_trig = new QwtPlotCurve();
    curve_trig->setTitle( "Триггер" );
    curve_trig->setPen( Qt::yellow, 6 ); // цвет и толщина кривой
    curve_trig->setRenderHint
            ( QwtPlotItem::RenderAntialiased, true ); // сглаживание

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *symbol_trig = new QwtSymbol( QwtSymbol::Hexagon,
                                            QBrush( Qt::yellow ), QPen( Qt::yellow, 0 ), QSize( 0,0  ) );
    curve_trig->setSymbol( symbol_trig );

    //--Остальная Настройка--

    // Включить возможность приближения/удаления графика
    // #include <qwt_plot_magnifier.h>
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(ui->qwtPlot->canvas());
    // клавиша, активирующая приближение/удаление
    magnifier->setMouseButton(Qt::MidButton);


    // Включить возможность перемещения по графику
    // #include <qwt_plot_panner.h>
    QwtPlotPanner *d_panner = new QwtPlotPanner( ui->qwtPlot->canvas() );
    // клавиша, активирующая перемещение
    d_panner->setMouseButton( Qt::RightButton );

    // Включить отображение координат курсора и двух перпендикулярных
    // линий в месте его отображения
    // #include <qwt_plot_picker.h>

    // настройка функций
    QwtPlotPicker *d_picker =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
                QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
                QwtPicker::ActiveOnly, // включение/выключение
                ui->qwtPlot->canvas() ); // ассоциация с полем

    // Цвет перпендикулярных линий
    d_picker->setRubberBandPen( QColor( Qt::red ) );

    // цвет координат положения указателя
    d_picker->setTrackerPen( QColor( Qt::black ) );

    // непосредственное включение вышеописанных функций
    d_picker->setStateMachine( new QwtPickerDragPointMachine() );

    ui->qwtPlot->replot();
}

//!         Настройка коннектов и кнопочек
//!
void MainWindow::my_connect_end(){
    ui->save_plot_in_jpeg->setEnabled(false);
    ui->doubleSpinBox->setEnabled(false); //спинбокс неактивен
    ui->continue_plot->setEnabled(false);
    ui->doubleSpinBox->setRange(0,4);
    ui->doubleSpinBox->setSingleStep(0.1);
    ui->doubleSpinBox->setValue(0);
    ui->verticalScrollBar->setRange(0,4);
    ui->verticalScrollBar->setValue(0);
    connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)),this,SLOT(activate_curve_trigger(double)));
    connect(ui->set_trigger,SIGNAL(clicked()), this, SLOT(doubleSpinBox_active()));
    connect(ui->delete_trigger,SIGNAL(clicked()), this, SLOT(doubleSpinBox_deactive()));
    connect(ui->continue_plot,SIGNAL(clicked(bool)),this,SLOT(continue_Trigger_mode()));

    tmr = new QTimer;
    connect(tmr, SIGNAL(timeout()), this, SLOT(plot_time_update()));
}

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        console->setEnabled(true);
        console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }

}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{
    tmr->stop();
    serial->close();
    console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));

}
//! [5]

void MainWindow::about()
{
    QMessageBox::about(this, tr("Программа выполнена с использованием Simple Terminal"),
                       tr("В приложении использована библиотека QWT   \n"
                          "       http://qwt.sourceforge.net/         \n"
                          "       Микроконтроллер STM32F407           \n"
                          "Особую благодарность за идею и вдохносление\n"
                          "выражаю к.т.н. Михаилу Рощупкину         "));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}
//! [6]

//! [7]
void MainWindow::readData()
{
    //data имеет тип QByteArray
    data = serial->readAll();
    serial->close();
    //Заполнение контейнера Qvector'a знчениями типа float
    data_f.clear();// очистка контейнера
    //QbyteArray перевожу в Qvector <float>
    for (int i = 0; i < 200; i++) {
        data_f.append(data.at(i));
        data_f[i] *= 0.0515;
    }
    //Приняли значения, закрыли порт, включили таймер
    tmr->start(10);
}

//Вывод графика по таймеру для красоты
void MainWindow::plot_time_update(){
    tmr->stop();//остановка таймера
    points.clear();
    //Счетчик времени. Эта переменная видна и сохраняется
    // только в этой функции
    static int count = 0;
     //вывод без триггера
    if ( trigger_active == false){
        curve->setPen( Qt::blue, 6 ); // цвет и толщина кривой
    for(int i = 0; i <= count; i++){
        points << QPointF(x[i], data_f[i]);
    }
    count++;
        if(count >= 200){
            count = 0;
            serial->open(QIODevice::ReadWrite);
            return;
        }
    }
    //вывод с триггером
    if ( trigger_active == true){

        for(int i = 0; i <= count; i++){
             curve->setPen( Qt::red, 6 ); // цвет и толщина кривой
            //вернуть размер точек
             if (data_f[i] > trigger){
                 points << QPointF(x[i], data_f[i]);
                 curve_trigger = true;
             }
             if (data_f[i] < trigger && curve_trigger == true)
                 points << QPointF(x[i], data_f[i]);
             if (data_f[i] < trigger && curve_trigger == false){
                 data_f[i] = 0;
                 points << QPointF(x[i], data_f[i]);
             }
        }
        count++;
        if(count >= 200){
            count = 0;
            //Ежели произошел "захват сигнала" (Сигнал выше уровня триггера)
            if (curve_trigger == true){
                curve_trigger = false;
                //придумать ожидание нажатия кнопки
                serial->close();
                // ассоциировать набор точек с кривой
                curve->setSamples( points );
                //добавить кривую на график
                curve->attach(ui->qwtPlot);
                //перерисовать график
                ui->qwtPlot->replot();
                //активирую кнопочку "Продолжить"
                ui->continue_plot->setEnabled(true);
                return;
            }
            //Если сигнала выше уровня триггера не было- продолжаем поиск
            else{
                serial->open(QIODevice::ReadWrite);
                return;
            }
        }
    }

    // ассоциировать набор точек с кривой
    curve->setSamples( points );
    //добавить кривую на график
    curve->attach(ui->qwtPlot);
    //перерисовать график
    ui->qwtPlot->replot();
    tmr->start(10);

}
//! [7]
void MainWindow::continue_Trigger_mode(){
    serial->open(QIODevice::ReadWrite);
}

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//! [8]

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionConfigure, &QAction::triggered, settings, &MainWindow::show);
    connect(ui->actionClear, &QAction::triggered, console, &Console::clear);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}





//перемещает уровень триггера на графике
void MainWindow::activate_curve_trigger(double trig){
    trigger = trig; //иначе переменную не видно в обработчике прерывания по таймеру
    points.clear();
    points << QPointF(   0, trigger ) // координаты x, y
           << QPointF( 280, trigger );
    curve_trig->setSamples( points ); // ассоциировать набор точек с кривой
    curve_trig->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
}
//функция выключения картинки с экрана и ожидание данных, выше порогового значения
void MainWindow::doubleSpinBox_active(){
    ui->doubleSpinBox->setEnabled(true);
    trigger_active = true;

}

void MainWindow::doubleSpinBox_deactive(){
    ui->doubleSpinBox->setEnabled(false);
    trigger_active = false;
    points.clear();
    //функция включения нормального режима
    curve_trig->setSamples( points ); // ассоциировать набор точек с кривой
    curve_trig->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
}






