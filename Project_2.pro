QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG+=console
QT += sql
QT += charts


DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    donutbreakdownchart.cpp \
    mainslice.cpp\
    drilldownchart.cpp \
    drilldownseries.cpp \
    trash.cpp

HEADERS += \
    connection.h \
    mainwindow.h \
    donutbreakdownchart.h\
    mainslice.h\
    trash.h\
    drilldownchart.h \
    drilldownseries.h

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgs.qrc
