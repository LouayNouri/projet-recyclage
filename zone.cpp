#include "zone.h"
#include "QSqlQuery"
#include "QSqlQueryModel"

Zone::Zone()
{
    this->idz=0;
    this->localisation="";
    this->prix=0;
    this->type="";
    this->nbmax=0;

}
Zone::Zone(int id ,QString type, QString localisation ,int nb ,float prix)
{
    this->idz=id;
    this->localisation=localisation;
    this->prix=prix;
    this->type=type;
    this->nbmax=nb;

}

bool Zone::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(idz);
QString res1=QString::number(nbmax);
QString res2=QString::number(prix);

    query.prepare("insert into zonedecollection (IDZ,TYPE,LOCALISATION,NBMAX,PRIX )""values(:id,:type,:localisation,:nbmax,:prix)");
    query.bindValue(":id", res);
    query.bindValue(":type", type);
    query.bindValue(":localisation", localisation);
    query.bindValue(":nbmax", res1);
    query.bindValue(":prix", res2);
return query.exec();
}


QSqlQueryModel *Zone::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from zonedecollection");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("LOCALISATION"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE_MAX"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));
return model;
}

bool Zone::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);
query.prepare("Delete from zonedecollection where IDZ=:id");
query.bindValue(":id",res);
return query.exec();
}
bool Zone::modifier(int id){

    QSqlQuery query;
        QString res=QString::number(id);
 QString res1=QString::number(prix);
 QString res2=QString::number(nbmax);

          query.prepare("UPDATE zonedecollection "" SET IDZ=:id, TYPE=:type, LOCALISATION=:localisation , NBMAX=:nbmax, PRIX=:prix where IDZ='"+res+"' ");


                query.bindValue(":id", res);
                query.bindValue(":type", type);
                query.bindValue(":localisation", localisation);
                query.bindValue(":nbmax", res1);
                query.bindValue(":prix", res2);


            return query.exec();

}


QSqlQueryModel* Zone::RechercheZone(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM zonedecollection WHERE idz LIKE '"+recherche+"%' OR type LIKE '"+recherche+"%' OR localisation LIKE '"+recherche+"%'");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("LOCALISATION"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE_MAX"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));
     return model;return model;
}


/***********************************************************************************************/


QSqlQueryModel * Zone::trierZoneparidz()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM zonedecollection order by idz ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


QSqlQueryModel * Zone::trierZoneparprix()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM zonedecollection order by prix ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


QSqlQueryModel * Zone::trierZoneparnbmax()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM zonedecollection order by nbmax ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


