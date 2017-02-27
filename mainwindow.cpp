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

//
//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//! [0]
    ui->setupUi(this);
    console = new Console;
    console->setEnabled(false);
  //  setCentralWidget(console);
    /*HELLO QWT*/
    //ui->qwtPlot = new QwtPlot(this);

    //setCentralWidget(ui->qwtPlot);
    ui->qwtPlot->setTitle("Частоты до 1 КГц");
    ui->qwtPlot->setCanvasBackground( Qt::white );
    // Параметры осей координат
      ui->qwtPlot->setAxisTitle(QwtPlot::yLeft, "Y");
      ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, "X");
      //мин и макс осей
      ui->qwtPlot->setAxisScale(QwtPlot::yLeft, 0, 70);
      ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,200);
      ui->qwtPlot->insertLegend( new QwtLegend() );


      // Включить сетку
      // #include <qwt_plot_grid.h>
      QwtPlotGrid *grid = new QwtPlotGrid(); //
      grid->setMajorPen(QPen( Qt::gray, 2,Qt::DotLine)); // цвет линий и толщина
      grid->attach( ui->qwtPlot ); // добавить сетку к полю графика

      // Кривая
       //#include <qwt_plot_curve.h>
       curve = new QwtPlotCurve();
       curve->setTitle( "Канал 1" );
       curve->setPen( Qt::blue, 6 ); // цвет и толщина кривой
       curve->setRenderHint
               ( QwtPlotItem::RenderAntialiased, true ); // сглаживание

       // Маркеры кривой
       // #include <qwt_symbol.h>
       QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Hexagon,
           QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 16, 16 ) );
       curve->setSymbol( symbol );

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

         tmr = new QTimer;
//         tmr->setInterval(1000);
//         connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
//         tmr->start();
          connect(tmr, SIGNAL(timeout()), this, SLOT(plot_time_update()));
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
ui->lineEdit->setEnabled(false);
ui->save_plot_in_jpeg->setEnabled(false);

}
//! [3]

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

    //if (serial->isOpen())
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
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
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
    data = serial->readAll();
//    for (int i = 0; i < 200 ; i++)
//    x[i] = i;

//    for(int i = 0; i < 200; i++){
//     points << QPointF(x[i], data[i]);
//    }
    serial->close();
    tmr->start(10);



//     points.append(points);
//     curve->setSamples( points ); // ассоциировать набор точек с кривой
//     curve->attach( ui->qwtPlot ); // отобразить кривую на графике
//     ui->qwtPlot->replot();
//     points.clear();

}
void MainWindow::plot_time_update(){
    points.clear();
    static int count = 0;
    //
    QVector<int> x(200);
    for (int i = 0; i < 200 ; i++)
        x[i] = i;
//
    for(int i = 0; i <= count; i++){
        points << QPointF(x[i], data[i]);
    }

    count++;
    if(count >= 200){
        count = 0;
        tmr->stop();
        serial->open(QIODevice::ReadWrite); //посмотреть как правильно открывать

    }
    curve->setSamples( points ); // ассоциировать набор точек с кривой
    curve->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
    //
    //tmr->stop();
    //serial->open(QIODevice::ReadWrite); //посмотреть как правильно открывать
}
//! [7]

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




void MainWindow::updateTime(){

    points.clear();
    static int i = 0;
    if (i == 0){
        points << QPointF( 1.0, 1.0 );

    }
    if (i == 1){
        points << QPointF( 1.0, 1.0 ) // координаты x, y
     << QPointF( 1.5, 2.0 );
    }
    if (i == 2){
        points << QPointF( 1.0, 1.0 ) // координаты x, y
     << QPointF( 1.5, 2.0 ) << QPointF( 3.0, 2.0 )
     << QPointF( 3.5, 3.0 ) ;
    }
    if (i == 3){
        points << QPointF( 1.0, 1.0 ) // координаты x, y
     << QPointF( 1.5, 2.0 ) << QPointF( 3.0, 2.0 )
     << QPointF( 3.5, 3.0 ) << QPointF( 5.0, 3.0 );
        tmr->stop();
    }

    curve->setSamples( points ); // ассоциировать набор точек с кривой
    curve->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
    i++;


}
