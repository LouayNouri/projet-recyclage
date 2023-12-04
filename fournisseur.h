#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include<QObject>
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class fournisseur
{
   QString nom,prenom,email,sexe,motp;
   int cin,nbrp;
public:
   fournisseur(){}
   fournisseur(QString,QString,QString,int,int,QString,QString);
   QString get_nom(){return nom;}
   QString get_prenom(){return prenom;}
   QString get_email(){return email;}
   int get_cin(){return cin;}
   int get_nbrp(){return nbrp;}
    QString get_sexe(){return sexe;}
    QString get_motp(){return motp;}
   void setnom (QString n){nom=n;}
   void setprenom (QString n){prenom=n;}
   void setemail (QString n){email=n;}
   void setcin (int n){cin =n;}
   void setnbrp (int n){nbrp =n;}
    void setsexe(int n){sexe =n;}
     void setmotp(int n){motp =n;}
   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer (int );
   bool modifier (int );
   QSqlQueryModel* tri();
    QSqlQueryModel* triprenom();
     QSqlQueryModel* trisexe();
QSqlQueryModel *chercher(QString critere ,QString rech);
bool Modifier(int , int );
   QString getnom() const {
             return nom;
         }

         QString getprenom() const {
             return prenom;
         }

         QString getemail() const {
             return email;
         }
         int getnbrp() const {
                   return nbrp;
               }
         QString getsexe() const {
                   return sexe;
               }



};


#endif // FOURNISSEUR_H


