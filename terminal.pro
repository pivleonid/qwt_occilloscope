QT += widgets serialport

TARGET = terminal
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    console.h\


FORMS += \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
CONFIG += qwt
#INCLUDEPATH += C:\qwt-6.1.3\include
INCLUDEPATH += C:\qwt-6.1.3\src
#LIBS += C:\qwt-6.1.3\lib



include( C:\qwt-6.1.3\qwt.prf )
