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
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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
    zone.cpp
    stats.cpp
HEADERS += \
    DataExporter.h \
    QrCode.hpp \
    arduino.h \
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
    stats.h
FORMS += \
    dialog.ui \
    forget.ui \
    login.ui \
    mainwindow.ui \
    recaptcha.ui \
    stats.ui \
    stats.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    352885013_1349384105640096_903490800808895943_n.png \
    400894800_719427929737793_7893295807958843835_n.jpg \
    403646966_916590199884936_3478174815254528194_n.png \
    rech.png

RESOURCES += \
    img.qrc

SUBDIRS += \
    ../../Documents/GitHub/projet-recyclage/Gestion_employe.pro
