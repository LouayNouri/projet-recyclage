#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include <QString>
#include<QSqlQueryModel>


class Entreprise
{
public:
    Entreprise();
    Entreprise(QString,QString,QString,QString,QString,QString);


    QString getID();

    QString getNOM();
    QString getDOMAINE();
    QString getEMAIL();
     QString getnb();
    QString getETAT();
     void setID(QString );

     void setNOM(QString );
     void setDOMAINE(QString );
     void setEMAIL(QString );
     void setnb(QString );
     void setETAT(QString );

     bool ajouter();

 QSqlQueryModel* afficher();
 bool supprimer(QString);
 bool modifier();







private:

    QString ID,NOMBRE_DAUDIT_EFFECTUE,NOM,DOMAINE,EMAIL,ETAT;

};

#endif // ENTREPRISE_H
