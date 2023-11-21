#include "connection.h"
#include <QSqlDatabase>
connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("ham");//inserer nom de l'utilisateur
db.setPassword("6969");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}

void connection::closeconnection(){db.close();}
