

QT       += core gui widgets texttospeech sql charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG+=console

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    TTP.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    donutbreakdownchart.cpp \
    mainslice.cpp\
    drilldownchart.cpp \
    drilldownseries.cpp \
    trash.cpp

HEADERS += \
    TTP.h \
    connection.h \
    mainwindow.h \
    donutbreakdownchart.h\
    mainslice.h\
    trash.h\
    drilldownchart.h \
    drilldownseries.h

FORMS += \
    TTP.ui \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgs.qrc

# install
target.path = target.path = C:/Users/MEGA-PC/Desktop/QT-test/Project_2

INSTALLS += target

DISTFILES +=
