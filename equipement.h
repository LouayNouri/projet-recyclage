#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
//mail
#include <QByteArray>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSslSocket>

#include <QtCore/QTextStream>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>

class Equipement
{
public:
    Equipement();

    Equipement(QString,QString,QString,int,int,QDate,QString);
    QString getID();
    QString getType();
    QString getEtat();
    int getPrix();
    int getNiveau();
    QDate getDate();
    QString getidZ();

    void setID(QString);
    void setType(QString);
    void setEtat(QString );
    void setPrix(int);
    void setNiveau(int );
    void setDate(QDate);
    void setidZ(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();

    bool checkIfIdExists(QString);
    QSqlQueryModel *rechercher(QString);
    QSqlQueryModel *trier(QString);
    bool isValidEmail(QString email);


private:
    QString id_equipement,type,etat,idZ;
    int prix;
    int niveau_remplissage;
    QDate date_acquisation;


};

#endif // EQUIPEMENT_H
