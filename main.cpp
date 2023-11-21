#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    bool test=c.createconnect();//etablir connection
    if(test)
    {w.show();
    }
    return a.exec();

}
