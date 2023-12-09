#include "connection.h"
#include <QDebug>

connection::connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

bool connection::createconnect()
{
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("ham");
    db.setPassword("6969");

    if (!db.isOpen()) {
        bool ok = db.open();
        qDebug() << "Database open: " << ok;
    }
    if (db.open())
        test=true;
    return  test;
}

void connection::closeconnection()
{
    db.close();
}
