#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include <QString>
#include<QSqlQueryModel>


class Entreprise
{
public:
    Entreprise();
    Entreprise(QString,QString,QString,QString);


    QString getID();

    QString getNOM();
    QString getDESTINATION();

     QString getMATRICULE();

     void setID(QString );

     void setNOM(QString );
     void setDESTINATION(QString );

     void setMATRICULE(QString );

     QString destinationPlusVisite();
     QString exportChauffeursByDestination(const QString& destination);
     QString findNearestCollectionZone(const QPointF& userLocation);


     bool ajouter();


 QSqlQueryModel* afficher();
 bool supprimer(QString);
 bool modifier();
//QSqlQueryModel* rechercher(QString);
//QSqlQueryModel* trierReglement(QString);
QSqlQueryModel* triernom();
QSqlQueryModel* rechercheParNom(const QString& ID);







private:

double haversineDistance(const QPointF& p1, const QPointF& p2);

    QString ID,MATRICULE,NOM,DESTINATION;

};

#endif // ENTREPRISE_H
