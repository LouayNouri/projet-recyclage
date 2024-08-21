//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QQmlContext>
//#include <QSettings>
//#include <QQuickStyle>
//#include "mainwindow.h"

//int main(int argc, char *argv[])
//{
//    QGuiApplication::setApplicationName("Gallery");
//    QGuiApplication::setOrganizationName("QtProject");
//    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

//    QGuiApplication app(argc, argv);

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
//        return -1;

//    MainWindow w;

//    QObject *rootObject = engine.rootObjects().first();
//    QObject::connect(rootObject, SIGNAL(openWindow()), &w, SLOT(show()));

//    return app.exec();
//}
