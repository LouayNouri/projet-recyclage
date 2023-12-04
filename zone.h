#ifndef ZONE_H
#define ZONE_H
#include "iostream"
#include <QDialog>
#include "QString"
#include <QSqlDatabase>
#include <QSqlQueryModel>


class Zone
{
    QString type,localisation;
    int idz,nbmax;
    float prix;
public:
    Zone();
    Zone(int ,QString,QString ,int,float);
    bool ajouter();
    QSqlQueryModel  * afficher();
    bool supprimer(int id);
    bool modifier(int id);
    QSqlQueryModel* RechercheZone(QString);
    QSqlQueryModel * trierZoneparidz();
    QSqlQueryModel * trierZoneparnbmax();
    QSqlQueryModel * trierZoneparprix();
};

#endif // ZONE_H
