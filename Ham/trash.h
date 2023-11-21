#ifndef TRASH_H
#define TRASH_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlDatabase>
class trash
{
public:

    /// Les constructeurs / destructures


    trash();//constructeur
   trash(QString,QString,double,QString,QDate,int);// constructeur
   ~trash();

    /// Getters And setters

   QString gettype(){return type;}
   QString getunit(){return unit;}
   double getamount(){return amount;}
   QString getproperties(){return properties;}
   QDate getdate(){return date;}
   int getcode(){return code;}

   void setdate(QDate);
   void setamount(double);
   void setunit(QString);
   void settype(QString);
   void setproperties(QString);
   void setcode(int);

    /// Fonctions
   bool ajouter();
   QSqlQueryModel *afficher();
   bool supprimer(int code);
   bool modifier();

    /// Attributs
private:
   QString type;
   QString unit;
   double amount;
   QString properties;
   QDate date;
   int code;
};

#endif // TRASH_H
