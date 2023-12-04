#include "connection.h"
#include <QSqlDatabase>
#include <QDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("ham");//inserer nom de l'utilisateur
    db.setPassword("6969");//inserer mot de passe de cet utilisateur

    if (!db.isOpen()) {
        bool ok = db.open();
        qDebug() << "Database open: " << ok;
    }
    if (db.open())
        test=true;
    return  test;
}
