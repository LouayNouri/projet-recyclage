#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"login.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    double largeNumber = 544115000.0;

    QString formattedNumber = QString::number(largeNumber, 'f', 0); // 'f' pour spécifier le format décimal sans décimales
    qDebug() << formattedNumber;

    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    login l;

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        l.exec();

        if (l.result() == QDialog::Accepted) {
            return a.exec();
        }
    }
    else
        QQuickStyle::setStyle(settings.value("style").toString());

    QGuiApplication::setApplicationName("Gallery");
    QGuiApplication::setOrganizationName("QtProject");
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QSettings settings;
    QString style = QQuickStyle::name();
    if (!style.isEmpty())
        settings.setValue("style", style);
    else
        QQuickStyle::setStyle(settings.value("style").toString());

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("availableStyles", QQuickStyle::availableStyles());
    engine.load(QUrl("qrc:/gallery.qml"));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject *rootObject = engine.rootObjects().first();
    QObject::connect(rootObject, SIGNAL(openWindow()), &w, SLOT(show()));

    return a.exec();
}
