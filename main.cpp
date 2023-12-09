#include "Home.h"
#include "Main_trash.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSqlDatabase>
#include "TTP.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Home h;
    h.show();

    return a.exec();
}


//    QGuiApplication::setApplicationName("Gallery");
//    QGuiApplication::setOrganizationName("QtProject");
//    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QSettings settings;
//    QString style = QQuickStyle::name();
//    if (!style.isEmpty())
//        settings.setValue("style", style);
//    else
//        QQuickStyle::setStyle(settings.value("style").toString());

//    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("availableStyles", QQuickStyle::availableStyles());
//    engine.load(QUrl("qrc:/gallery.qml"));
//    if (engine.rootObjects().isEmpty())
//       return -1;

//    QObject *rootObject = engine.rootObjects().first();
//    QObject::connect(rootObject, SIGNAL(openWindow()), &w, SLOT(show()));
