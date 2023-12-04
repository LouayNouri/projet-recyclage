QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4):
 QT += widgets
QT += core
CONFIG += c++11
QT += core gui charts
QT += core gui widgets printsupport
 QT       += multimedia
QT       += multimediawidgets charts printsupport widgets axcontainer network
QT       +=network
QT += serialport
QT       += core gui widgets texttospeech sql charts quick quickcontrols2

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG+=console

SOURCES += \
    DataExporter.cpp \
    QrCode.cpp \
    arduino.cpp \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    entreprise.cpp \
    equipement.cpp \
    forget.cpp \
    fournisseur.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    randomstringgenerator.cpp \
    recaptcha.cpp \
    smtp.cpp \
    stats.cpp \
    zone.cpp \
    TTP.cpp \
    donutbreakdownchart.cpp \
    mainslice.cpp\
    drilldownchart.cpp \
    drilldownseries.cpp \
    trash.cpp \
    Main_trash.cpp \
    gallery.cpp
HEADERS += \
    TTP.h \
    Main_trash.h \
    trash.h\
    mainslice.h\
    drilldownchart.h \
    drilldownseries.h \
    DataExporter.h \
    QrCode.hpp \
    arduino.h \
    donutbreakdownchart.h\
    connection.h \
    dialog.h \
    employe.h \
    entreprise.h \
    equipement.h \
    forget.h \
    fournisseur.h \
    login.h \
    mainwindow.h \
    randomstringgenerator.h \
    recaptcha.h \
    smtp.h \
    stats.h \
    zone.h
FORMS += \
    dialog.ui \
    forget.ui \
    login.ui \
    mainwindow.ui \
    recaptcha.ui \
    stats.ui \
    TTP.ui \
    Trash.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

target.path = C:/Users/MEGA-PC/Desktop/QT-test/Project_2
INSTALLS += target

DISTFILES += \
    352885013_1349384105640096_903490800808895943_n.png \
    400894800_719427929737793_7893295807958843835_n.jpg \
    403646966_916590199884936_3478174815254528194_n.png \
    rech.png

RESOURCES += \
    imgs.qrc \
    gallery.qml \
    qtquickcontrols2.conf \
    $$files(images/*.png) \
    $$files(images/+material/*.png) \
    $$files(pages/*.qml) \
    img.qrc
