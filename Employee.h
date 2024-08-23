#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class employe
{
public:
    employe();

    employe(QString,QString,QString,QString,QString,QDate);
    QString getid();
    QString getposte();
    QString getEtat();
    QString getmail();
    QString getpassword();
    QDate getDate();


    void setID(QString);
    void setposte(QString);
    void setEtat(QString );
    void setmail(QString);
    void setpassword(QString );
    void setDate(QDate);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
    bool checkIfIdExists(QString);
    QSqlQueryModel* rechercher(const QString& searchText);

private:
    QString id,poste,etat,mail,password;


    QDate date_naissance;


};

#endif // EMPLOYE_H
