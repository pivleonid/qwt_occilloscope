/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "doubleslider.h"
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QwtPlot *qwtPlot;
    QWidget *tab_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *set_trigger;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *delete_trigger;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QPushButton *continue_plot;
    QPushButton *save_plot_in_jpeg;
    QSpacerItem *horizontalSpacer_2;
    doubleSlider *verticalScrollBar;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QPushButton *button_pause;
    QPushButton *button_udate;
    QSpacerItem *verticalSpacer_6;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1144, 795);
        MainWindow->setMinimumSize(QSize(1142, 0));
        MainWindow->setMaximumSize(QSize(1496, 1053));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionQuit->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        qwtPlot = new QwtPlot(tab);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        qwtPlot->setGeometry(QRect(0, 0, 921, 681));
        qwtPlot->setMinimumSize(QSize(921, 0));
        qwtPlot->setMaximumSize(QSize(921, 681));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 20, 901, 661));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 899, 659));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab_2, QString());

        horizontalLayout_4->addWidget(tabWidget);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        set_trigger = new QPushButton(centralWidget);
        set_trigger->setObjectName(QStringLiteral("set_trigger"));

        verticalLayout_6->addWidget(set_trigger);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);

        horizontalLayout_2->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        horizontalLayout_2->addWidget(doubleSpinBox);


        verticalLayout_6->addLayout(horizontalLayout_2);

        delete_trigger = new QPushButton(centralWidget);
        delete_trigger->setObjectName(QStringLiteral("delete_trigger"));

        verticalLayout_6->addWidget(delete_trigger);

        verticalSpacer_4 = new QSpacerItem(38, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        verticalSpacer_3 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        continue_plot = new QPushButton(centralWidget);
        continue_plot->setObjectName(QStringLiteral("continue_plot"));

        verticalLayout_6->addWidget(continue_plot);

        save_plot_in_jpeg = new QPushButton(centralWidget);
        save_plot_in_jpeg->setObjectName(QStringLiteral("save_plot_in_jpeg"));
        save_plot_in_jpeg->setCheckable(false);
        save_plot_in_jpeg->setFlat(false);

        verticalLayout_6->addWidget(save_plot_in_jpeg);


        horizontalLayout_3->addLayout(verticalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        verticalScrollBar = new doubleSlider(centralWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout_3->addWidget(verticalScrollBar);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        horizontalLayout_3->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        button_pause = new QPushButton(centralWidget);
        button_pause->setObjectName(QStringLiteral("button_pause"));

        verticalLayout_7->addWidget(button_pause);

        button_udate = new QPushButton(centralWidget);
        button_udate->setObjectName(QStringLiteral("button_udate"));

        verticalLayout_7->addWidget(button_udate);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);


        horizontalLayout_4->addLayout(verticalLayout_7);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1144, 21));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QStringLiteral("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simple oscilloscope  ", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Alt+A", Q_NULLPTR));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to serial port", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from serial port", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure serial port", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Alt+C", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MainWindow", "C&lear", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("MainWindow", "Clear data", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionClear->setShortcut(QApplication::translate("MainWindow", "Alt+L", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", Q_NULLPTR));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\236\321\201\321\206\320\270\320\273\320\273\320\276\320\263\321\200\320\260\321\204", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", Q_NULLPTR));
        set_trigger->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\202\321\200\320\270\320\263\320\263\320\265\321\200", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \n"
"\321\202\321\200\320\270\320\263\320\265\321\200\320\260", Q_NULLPTR));
        delete_trigger->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\202\321\200\320\270\320\263\320\263\320\265\321\200", Q_NULLPTR));
        continue_plot->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", Q_NULLPTR));
        save_plot_in_jpeg->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272 ", Q_NULLPTR));
        button_pause->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\203\320\267\320\260", Q_NULLPTR));
        button_udate->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
        menuCalls->setTitle(QApplication::translate("MainWindow", "Calls", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
