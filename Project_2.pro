QT += sql
QT += widgets
QT += charts
QT += printsupport
QT       += core gui widgets texttospeech sql charts quick quickcontrols2
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG+=console

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    DataExporter.cpp \
    Employee.cpp \
    Formation.cpp \
    Home.cpp \
    Main_Employee.cpp \
    TTP.cpp \
    connection.cpp \
    forget.cpp \
    main.cpp \
    donutbreakdownchart.cpp \
    mainslice.cpp\
    drilldownchart.cpp \
    drilldownseries.cpp \
    randomstringgenerator.cpp \
    recaptcha.cpp \
    stats.cpp \
    trash.cpp

HEADERS += \
    DataExporter.h \
    Employee.h \
    Formation.h \
    Home.h \
    Main_Employee.h \
    TTP.h \
    connection.h \
    donutbreakdownchart.h\
    forget.h \
    mainslice.h\
    randomstringgenerator.h \
    recaptcha.h \
    stats.h \
    trash.h\
    drilldownchart.h \
    drilldownseries.h

FORMS += \
    Formation.ui \
    Home.ui \
    Main_Employee.ui \
    TTP.ui \
    forget.ui \
    recaptcha.ui \
    stats.ui

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
