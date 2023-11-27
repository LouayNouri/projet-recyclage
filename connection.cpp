#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("project");
db.setUserName("aymoun");//inserer nom de l'utilisateur
db.setPassword("aymoun");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
