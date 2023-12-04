#include "connection.h"
#include <QDebug>

Connection::Connection()
{

}
bool Connection::createconnect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet_2A");
    db.setUserName("nour");
    db.setPassword("123");

    if (db.open())
    {
        return true;
    }
    else
    {
        qDebug() << "Database connection error: " << db.lastError().text();
        return false;
    }
}

/*bool Connection::createconnect()
{   db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");
db.setUserName("med");//inserer nom de l'utilisateur
db.setPassword("azertyu221");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}*/
void Connection::closeconnect()
{
     db.close();
}
