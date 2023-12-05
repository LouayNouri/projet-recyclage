#include "fournisseur.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QSqlQueryModel>
#include <QMessageBox>
#include"dialog.h"
#include<QDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ui_dialog.h"

fournisseur::fournisseur(QString nom,QString prenom,QString email,int cin,int nbrp,QString sexe,QString motp) {
this->nom=nom;this->prenom=prenom;this->email=email;this->cin=cin;this->nbrp=nbrp;this->sexe=sexe;this->motp=motp;}

bool fournisseur::ajouter()
{
    QSqlQuery query;
       query.prepare("INSERT INTO FOURNISSEUR(NOM, PRENOM, EMAIL, CIN,NBRP,SEXE,MOTP) VALUES (:NOM, :PRENOM, :EMAIL, :CIN, :NBRP , :SEXE, :MOTP)");
       query.bindValue(":NOM", nom);
       query.bindValue(":PRENOM",prenom);
       query.bindValue(":EMAIL",email);
       query.bindValue(":CIN", cin);
       query.bindValue(":NBRP", nbrp);
        query.bindValue(":SEXE", sexe);
         query.bindValue(":MOTP", motp);
       return query.exec();
}
bool fournisseur::supprimer(int cin) {
    QSqlQuery query;
    query.prepare("DELETE FROM FOURNISSEUR WHERE CIN=:CIN");
    query.bindValue(":CIN", cin);

    if (query.exec() && query.numRowsAffected() > 0) {
        return true;
    } else {
        return false;
    }
}


QSqlQueryModel* fournisseur:: afficher(){
 QSqlQueryModel* model=new QSqlQueryModel();
       model->setQuery("SELECT* FROM  FOURNISSEUR");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRP"));
                      model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("MOTP"));
    return model;
}


bool fournisseur::modifier(int cin){
    QSqlQuery query;

   QString cin_string= QString::number(cin);

   query.prepare("UPDATE FOURNISSEUR SET NOM = :NOM, PRENOM = :PRENOM, EMAIL = :EMAIL, NBRP = :NBRP,SEXE = :SEXE,MOTP = :MOTP) WHERE CIN = :CIN");

       query.bindValue(":NOM", nom);
       query.bindValue(":PRENOM", prenom);
       query.bindValue(":EMAIL", email);
       query.bindValue(":CIN", cin);
       query.bindValue(":NBRP", nbrp);
   query.bindValue(":SEXE", sexe);
   query.bindValue(":MOTP", motp);
       return query.exec();




}
QSqlQueryModel* fournisseur::tri()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY NOM ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRP"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("MOTP"));
   return  model;

}



QSqlQueryModel* fournisseur::triprenom()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY PRENOM ");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRP"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("MOTP"));
   return  model;

}



QSqlQueryModel* fournisseur::trisexe()
{
   QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY SEXE ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRP"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("MOTP"));
   return  model;

}

QSqlQueryModel* fournisseur::chercher(QString critere, QString rech) {
    QSqlQueryModel *model = new QSqlQueryModel();

    QString querystr = "SELECT * FROM FOURNISSEUR WHERE " + critere + " LIKE :rech";

    QSqlQuery query;
    query.prepare(querystr);
    query.bindValue(":rech", "%" + rech + "%"); // Recherche partielle avec %

    if (query.exec()) {
        model->setQuery(query);
    }

    // Définissez les en-têtes ici...

    return model;
}




    // Définissez les en-têtes ici...


bool fournisseur::Modifier(int cin, int nbrp) {
    QSqlQuery query;

    query.prepare("UPDATE FOURNISSEUR SET NBRP = :NBRP WHERE CIN = :CIN");
    query.bindValue(":NBRP", nbrp);
    query.bindValue(":CIN", cin);

    return query.exec();
}
