#include "trash.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "mainwindow.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QtSql>
#include <QTableView>
#include <QSqlDatabase>
using namespace std;

trash::trash()
{

}

///constructeurs

trash::~trash()
{
    //destructeur
}

trash::trash( QString type, QString unit, double amount, QString properties, QDate date, int code)
{
    this->amount=amount;
    this->properties=properties;
    this->date=date;
    this->unit=unit;
    this->type=type;
    this->code=code;
}

///////////////Les fonctions////////////////////




bool trash::ajouter()
{
    QSqlQuery q;
    q.prepare("INSERT INTO trash (MATERIAL_TYPE, UNIT, AMOUNT, PROPERTIES, DATE_ADDED, CODE) "
              "VALUES (:ty, :un, :am, :pr, :da, :co)");
    q.bindValue(":ty", type);
    q.bindValue(":un", unit);
    q.bindValue(":am", amount);
    q.bindValue(":pr", properties); // properties now holds the text of the checked checkboxes
    q.bindValue(":da", date);
    q.bindValue(":co", code);
    return q.exec();
}



QSqlQueryModel * trash::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM trash");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("MATERIAL_TYPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("UNIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AMOUNT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PROPERTIES"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_ADDED"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CODE"));
    return model;
}

bool trash::supprimer(int code)
{
    QSqlQuery q;
    q.prepare("DELETE FROM trash WHERE CODE = :co");
    q.bindValue(":co",code);
    //return q.exec();
    if (q.exec() && q.numRowsAffected() > 0) {
            return true;  // Deletion was successful (at least one row affected).
        } else {
            return false; // Deletion didn't affect any rows (record not found or other issue).
        }
}

bool trash::modifier()
{
    QSqlQuery update_query;
    update_query.prepare("UPDATE trash SET MATERIAL_TYPE = :ty, UNIT = :un, AMOUNT = TO_BINARY_DOUBLE(:am), PROPERTIES = :pr, DATE_ADDED = :da WHERE CODE = :co");
    update_query.bindValue(":ty", type);
    update_query.bindValue(":un", unit);
    update_query.bindValue(":am", amount);
    update_query.bindValue(":pr", properties);
    update_query.bindValue(":da", date);
    update_query.bindValue(":co", code); // Add this line

    return update_query.exec();
}


