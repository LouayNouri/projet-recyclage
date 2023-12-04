#include "entreprise.h"
#include <QSqlQuery>
#include <QSqlQueryModel >
#include<QtDebug>
#include<QObject>

Entreprise::Entreprise()
{

    ID  ="";
    NOM="";
    DOMAINE="";
    EMAIL="";
    NOMBRE_DAUDIT_EFFECTUE="";
    ETAT="";

}

 Entreprise::Entreprise(QString ID  ,QString NOM,QString DOMAINE,QString EMAIL,QString NOMBRE_DAUDIT_EFFECTUE,QString ETAT)
 {
     this->ID  =ID  ;

     this->NOM=NOM;
     this->DOMAINE=DOMAINE;
     this->EMAIL=EMAIL;
      this->NOMBRE_DAUDIT_EFFECTUE=NOMBRE_DAUDIT_EFFECTUE;
     this->ETAT=ETAT;


 }
 QString Entreprise::getID  (){return ID  ;}

 QString Entreprise::getDOMAINE(){return DOMAINE;}
 QString Entreprise::getNOM(){return NOM;}
 QString Entreprise::getEMAIL(){return EMAIL;}
 QString Entreprise::getnb(){return NOMBRE_DAUDIT_EFFECTUE;}
 QString Entreprise::getETAT(){return ETAT;}
    void Entreprise::setID(QString ID   ){this->ID   =ID   ;}

 void Entreprise::setNOM(QString NOM){this->NOM=NOM;}
 void Entreprise::setDOMAINE(QString DOMAINE){this->DOMAINE=DOMAINE;}
 void Entreprise::setEMAIL(QString EMAIL){this->EMAIL=EMAIL;}
 void Entreprise::setnb(QString NOMBRE_DAUDIT_EFFECTUE){this->NOMBRE_DAUDIT_EFFECTUE=NOMBRE_DAUDIT_EFFECTUE;}
 void Entreprise::setETAT(QString ETAT){this->ETAT=ETAT;}

 bool Entreprise::ajouter()
 {

     QSqlQuery query;
     /*QString res=QString::number(ID);
     QString re=QString::number(NOMBRE_DAUDIT_EFFECTUE);*/

          /*query.prepare("INSERT INTO  ENTITE_AUDITEE  (ID  , NOM, DOMAINE,EMAIL,NOMBRE_DAUDIT_EFFECTUE,ETAT) "
                        "values (:ID  ,:NOM,:DOMAINE, :EMAIL,:NOMBRE_DAUDIT_EFFECTUE,:ETAT)");
          query.bindValue(":ID  ", ID);


          query.bindValue(":NOM", NOM);
            query.bindValue(":DOMAINE",DOMAINE );
          query.bindValue(":EMAIL", EMAIL);
          query.bindValue(":NOMBRE_DAUDIT_EFFECTUE",NOMBRE_DAUDIT_EFFECTUE);
          query.bindValue(":ETAT", ETAT);*/
     query.prepare("INSERT INTO ENTITE_AUDITEE (ID, NOM, DOMAINE, EMAIL, NOMBRE_DAUDIT_EFFECTUE, ETAT) "
                   "values (:ID, :NOM, :DOMAINE, :EMAIL, :NOMBRE_DAUDIT_EFFECTUE, :ETAT)");

     query.bindValue(":ID", ID);
     query.bindValue(":NOM", NOM);
     query.bindValue(":DOMAINE", DOMAINE);
     query.bindValue(":EMAIL", EMAIL);
     query.bindValue(":NOMBRE_DAUDIT_EFFECTUE", NOMBRE_DAUDIT_EFFECTUE);
     query.bindValue(":ETAT", ETAT);









     return query.exec();
 }

 QSqlQueryModel* Entreprise::afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM ENTITE_AUDITEE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID  "));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("DOMAINE"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("EMAIL"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_DAUDIT_EFFECTUE"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("ETAT"));


           return model;
 }
 bool Entreprise::supprimer(QString ID)
 {
     QSqlQuery query;
     query.prepare("DELETE FROM ENTITE_AUDITEE WHERE ID = :ID");
     query.bindValue(":ID", ID);

     return query.exec();
 }

 /* bool Entreprise::supprimer(QString ID)
 {   QSqlQuery query;
     query.prepare(" DELET FROM ENTITE_AUDITEE WHERE ID=:ID");
     query.bindValue(":ID  ", ID);










return query.exec();
 }*/

 /*bool Entreprise::modifier()
 {
     QSqlQuery checkQuery;
           checkQuery.prepare("SELECT ID FROM ENTITE_AUDITEE WHERE ID = :ID");
                   checkQuery.bindValue(":ID", ID);
                         checkQuery.exec();
                         if (checkQuery.next())
                                {
                                    QSqlQuery query;
                                    query.prepare("UPDATE ENTITE_AUDITEE SET ID = :ID, nom = :NOM, DOMAINE = :DOMAINE, EMAIL = :EMAIL, NOMBRE_DAUDIT_EFFECTUE = :NOMBRE_DAUDIT_EFFECTUE, ETAT = :ETAT WHERE ID = :ID");
                                    query.bindValue(":ID  ", ID);


                                    query.bindValue(":NOM", NOM);
                                      query.bindValue(":DOMAINE",DOMAINE );
                                    query.bindValue(":EMAIL", EMAIL);
                                    query.bindValue(":NOMBRE_DAUDIT_EFFECTUE",NOMBRE_DAUDIT_EFFECTUE);
                                    query.bindValue(":ETAT", ETAT);

                                               return query.exec();
                                           }
 }*/
 bool Entreprise::modifier()
 {
     QSqlQuery checkQuery;
     checkQuery.prepare("SELECT ID FROM ENTITE_AUDITEE WHERE ID = :ID");
     checkQuery.bindValue(":ID", ID);
     checkQuery.exec();

     if (checkQuery.next()) // The ID exists
     {
         QSqlQuery query;
         query.prepare("UPDATE ENTITE_AUDITEE SET NOM = :NOM, DOMAINE = :DOMAINE, EMAIL = :EMAIL, NOMBRE_DAUDIT_EFFECTUE = :NOMBRE_DAUDIT_EFFECTUE, ETAT = :ETAT WHERE ID = :ID");
         query.bindValue(":NOM", NOM);
         query.bindValue(":DOMAINE", DOMAINE);
         query.bindValue(":EMAIL", EMAIL);
         query.bindValue(":NOMBRE_DAUDIT_EFFECTUE", NOMBRE_DAUDIT_EFFECTUE);
         query.bindValue(":ETAT", ETAT);
         query.bindValue(":ID", ID);

         if (query.exec())
         {
             // Modification successful
             return true;
         }
     }

     // ID does not exist or modification failed
     return false;
 }

