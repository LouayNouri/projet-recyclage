QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4):
 QT += widgets
QT += core
CONFIG += c++11
QT += core gui charts
QT += core gui widgets printsupport
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
    connection.cpp \
    employe.cpp \
    forget.cpp \
    main.cpp \
    mainwindow.cpp \
    randomstringgenerator.cpp \
    recaptcha.cpp \
    stats.cpp
    stats.cpp
HEADERS += \
    DataExporter.h \
    connection.h \
    employe.h \
    forget.h \
    mainwindow.h \
    randomstringgenerator.h \
    recaptcha.h \
    stats.h
    stats.h
FORMS += \
    forget.ui \
    mainwindow.ui \
    recaptcha.ui \
    stats.ui \
    stats.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
