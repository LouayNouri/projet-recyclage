#include "employe.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtDebug>
#include <QObject>
#include<QDate>
#include<QMessageBox>
#include <QSqlError>
#include <QDebug>
employe::employe()
{

}

employe::employe(QString id,QString poste,QString etat,QString mail,QString password,QDate date_naissance)
{this->id=id;
    this->poste = poste;
    this->etat = etat;
    this->mail = mail;
    this->password = password;
    this->date_naissance=date_naissance;

}

  QString employe::getid(){return id;}
  QString employe::getposte(){return poste;}
  QString employe::getEtat(){return etat;}
  QString employe::getmail(){return mail;}
  QString employe::getpassword(){return password;}
  QDate employe::getDate(){return date_naissance;}


  void employe::setID(QString id){this->id=id;}
  void employe::setposte(QString poste){this->poste=poste;}
  void employe::setEtat(QString etat){this->etat=etat;}
  void employe::setmail(QString mail){this->mail=mail;}
  void employe::setpassword(QString password ){this->password=password;}
  void employe::setDate(QDate date_naissance){this->date_naissance=date_naissance;}


bool employe::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO employe (id,poste,etat,mail,password,date_naissance)"
                  "values(:id,:poste,:etat,:mail,:password,:date_naissance)");
         query.bindValue(":id",id);
         query.bindValue(":poste",poste);
         query.bindValue(":etat",etat);
         query.bindValue(":mail",mail);
         query.bindValue(":password",password);
         query.bindValue(":date_naissance",date_naissance);


          return query.exec();

   };



QSqlQueryModel * employe::afficher(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY id + 0 ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("password"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_naissance"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat"));

    return model;
}



bool employe::supprimer(QString id)
{
    QSqlQuery query;
         query.prepare("Delete from employe where id=:id");
         query.bindValue(":id",id);
         return query.exec();
}



bool employe::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE employe SET poste = :poste, etat = :etat, mail = :mail, password = :password, date_naissance = :date_naissance WHERE id = :id");

    query.bindValue(":id", id);
    query.bindValue(":poste", poste);
    query.bindValue(":etat", etat);
    query.bindValue(":mail", mail);
    query.bindValue(":password", password);
    query.bindValue(":date_naissance", date_naissance);

    return query.exec();
}


bool employe::checkIfIdExists(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM employe WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // The ID exists in the database
        return true;
    } else {
        // The ID does not exist in the database
        return false;
    }
}
QSqlQueryModel* employe::rechercher(const QString& searchText)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QString queryString = "SELECT * FROM employe";

    // If there's a search text, add a WHERE clause to filter the results
    if (!searchText.isEmpty()) {
        // Check if the searchText is a valid integer
        bool isNumeric;
        searchText.toInt(&isNumeric);

        if (isNumeric) {
            // If it's a valid integer, search for an exact match on the ID
            queryString += " WHERE id = " + searchText;
        } else {
            // If it's not a valid integer, use the previous LIKE condition
            queryString += " WHERE id LIKE '%" + searchText + "%' OR poste LIKE '%" + searchText + "%' OR etat LIKE '%" + searchText + "%' OR mail LIKE '%" + searchText + "%' OR password LIKE '%" + searchText + "%' OR date_naissance LIKE '%" + searchText + "%'";
        }
    }

    queryString += " ORDER BY id ASC";

    model->setQuery(queryString);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("password"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_naissance"));

    return model;
}




