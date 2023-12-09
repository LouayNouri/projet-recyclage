QT       += core gui widgets texttospeech sql charts quick quickcontrols2
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG+=console

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Home.cpp \
    Main_trash.cpp \
    TTP.cpp \
    connection.cpp \
    gallery.cpp \
    main.cpp \
    donutbreakdownchart.cpp \
    mainslice.cpp\
    drilldownchart.cpp \
    drilldownseries.cpp \
    trash.cpp \
    gallery.cpp

HEADERS += \
    Home.h \
    Main_trash.h \
    TTP.h \
    connection.h \
    donutbreakdownchart.h\
    mainslice.h\
    trash.h\
    drilldownchart.h \
    drilldownseries.h

FORMS += \
    Home.ui \
    Main_trash.ui \
    TTP.ui

RESOURCES += \
    imgs.qrc \
    gallery.qml \
    qtquickcontrols2.conf \
    $$files(images/*.png) \
    $$files(images/+material/*.png) \
    $$files(pages/*.qml)

# install
target.path = C:/Users/MEGA-PC/Desktop/QT-test/Project_2
INSTALLS += target

DISTFILES +=
