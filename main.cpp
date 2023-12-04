#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"login.h"
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
          //  w.show();
            return a.exec();
        }
}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
