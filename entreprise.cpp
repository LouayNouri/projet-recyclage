#include "entreprise.h"
#include <QSqlQuery>
#include <QSqlQueryModel >
#include<QtDebug>
#include<QObject>
#include <QSqlRecord>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QTextCursor>
#include <QSqlRecord>
#include <QPointF>
#include <QtMath>
#include <limits>


Entreprise::Entreprise()
{

    ID  ="";
    NOM="";
    DESTINATION="";

    MATRICULE="";


}

 Entreprise::Entreprise(QString ID  ,QString NOM,QString DESTINATION,QString MATRICULE)
 {
     this->ID  =ID  ;

     this->NOM=NOM;
     this->DESTINATION=DESTINATION;

      this->MATRICULE=MATRICULE;



 }
 QString Entreprise::getID  (){return ID  ;}

 QString Entreprise::getDESTINATION(){return DESTINATION;}
 QString Entreprise::getNOM(){return NOM;}

 QString Entreprise::getMATRICULE(){return MATRICULE;}

    void Entreprise::setID(QString ID   ){this->ID   =ID   ;}

 void Entreprise::setNOM(QString NOM){this->NOM=NOM;}
 void Entreprise::setDESTINATION(QString DESTINATION){this->DESTINATION=DESTINATION;}

 void Entreprise::setMATRICULE(QString MATRICULE){this->MATRICULE=MATRICULE;}

 bool Entreprise::ajouter()
 {

     QSqlQuery query;
     /*QString res=QString::number(ID);
     QString re=QString::number(NOMBRE_DAUDIT_EFFECTUE);*/

          /*query.prepare("INSERT INTO  NOUR.TRANSPORT  (ID  , NOM, DOMAINE,EMAIL,NOMBRE_DAUDIT_EFFECTUE,ETAT) "
                        "values (:ID  ,:NOM,:DOMAINE, :EMAIL,:NOMBRE_DAUDIT_EFFECTUE,:ETAT)");
          query.bindValue(":ID  ", ID);


          query.bindValue(":NOM", NOM);
            query.bindValue(":DOMAINE",DOMAINE );
          query.bindValue(":EMAIL", EMAIL);
          query.bindValue(":NOMBRE_DAUDIT_EFFECTUE",NOMBRE_DAUDIT_EFFECTUE);
          query.bindValue(":ETAT", ETAT);*/
     query.prepare("INSERT INTO NOUR.TRANSPORT (ID, NOM, DESTINATION,  MATRICULE) "
                   "values (:ID, :NOM, :DESTINATION, :MATRICULE)");

     query.bindValue(":ID", ID);
     query.bindValue(":NOM", NOM);
     query.bindValue(":DESTINATION", DESTINATION);

     query.bindValue(":MATRICULE", MATRICULE);









     return query.exec();
 }

 QSqlQueryModel* Entreprise::afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM NOUR.TRANSPORT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID  "));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));

           model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));



           return model;
 }
 bool Entreprise::supprimer(QString ID)
 {
     QSqlQuery query;
     query.prepare("DELETE FROM NOUR.TRANSPORT WHERE ID = :ID");
     query.bindValue(":ID", ID);

     return query.exec();
 }


 bool Entreprise::modifier()
 {
     QSqlQuery checkQuery;
     checkQuery.prepare("SELECT ID FROM NOUR.TRANSPORT WHERE ID = :ID");
     checkQuery.bindValue(":ID", ID);
     checkQuery.exec();

     if (checkQuery.next()) // The ID exists
     {
         QSqlQuery query;
         query.prepare("UPDATE NOUR.TRANSPORT SET NOM = :NOM, DESTINATION = :DESTINATION, MATRICULE = :MATRICULE, WHERE ID = :ID");
         query.bindValue(":NOM", NOM);
         query.bindValue(":DESTINATION", DESTINATION);

         query.bindValue(":MATRICULE", MATRICULE);

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
 /*QSqlQueryModel* Entreprise::rechercher(QString a)
 {
     QSqlQueryModel * query=new QSqlQueryModel();
     query->setQuery("select * from NOUR.TRANSPORT where (nom like '%"+a+"%' or nom like '"+a+"%' or  nom like '%"+a+"' or matricule like '%"+a+"%' or matricule like '"+a+"%' or  matricule like '%"+a+"'or id '%"+a+"%' or id like '"+a+"%' or  id like '%"+a+"') ");



     query->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     query->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     query->setHeaderData(2, Qt::Horizontal, QObject::tr("destination"));
     query->setHeaderData(3, Qt::Horizontal, QObject::tr("matricule"));

     return    query;
 }*/
/* QSqlQueryModel * Entreprise::trierReglement(QString test)
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     if(test == "default"){
         model->setQuery("SELECT * from NOUR.TRANSPORT");
     }
     else if(test =="id")
     {
         model->setQuery("SELECT * from NOUR.TRANSPORT order by ID asc ");
     }
     else if(test =="nom")
     {
         model->setQuery("SELECT * from NOUR.TRANSPORT order by NOM asc ");
     }
     else if(test =="destination")
     {
         model->setQuery("SELECT * from NOUR.TRANSPORT order by DESTINATION asc ");
     }
     else if(test =="matricule")
     {
         model->setQuery("SELECT * from NOUR.TRANSPORT order by MATRICULE asc ");
     }



     return model;
 }*/
     QSqlQueryModel* Entreprise::triernom()
     {
         QSqlQueryModel* model = new QSqlQueryModel();

         // Assuming the table name is "TRANSPORT" and the column for sorting is "NOM"
         model->setQuery("SELECT * FROM NOUR.TRANSPORT ORDER BY NOM ASC");

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("MATRICULE"));

         return model;
     }
     QSqlQueryModel* Entreprise::rechercheParNom(const QString& ID)
     {
         QSqlQueryModel* model = new QSqlQueryModel();

         QSqlQuery query;
         query.prepare("SELECT * FROM NOUR.TRANSPORT WHERE ID LIKE :ID");
         query.bindValue(":ID", "%" + ID + "%"); // Search for IDs containing the specified substring
         query.exec();

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESTINATION"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("MATRICULE"));

         model->setQuery(query);

         return model;
     }
     QString Entreprise::destinationPlusVisite()
     {
         QSqlQuery query;
         query.prepare("SELECT DESTINATION, COUNT(DESTINATION) AS VisitsCount "
                       "FROM NOUR.TRANSPORT "
                       "GROUP BY DESTINATION "
                       "ORDER BY VisitsCount DESC "
                       "LIMIT 1");

         if (query.exec() && query.next()) {
             return query.value("DESTINATION").toString();
         } else {
             return "No data available";
         }
     }
     QString Entreprise::exportChauffeursByDestination(const QString& destination)
     {
         QSqlQuery query;
         query.prepare("SELECT * FROM NOUR.TRANSPORT WHERE DESTINATION = :destination");
         query.bindValue(":destination", destination);
         query.exec();

         if (query.size() == 0) {
             return "No chauffeurs found for the specified destination.";
         }

         QString transport = "Chauffeurs_" + destination + ".docx";
         QPrinter printer(QPrinter::HighResolution);
         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setOutputFileName(transport);

         QPainter painter;
         if (painter.begin(&printer)) {
             // Set up painter for PDF
             painter.setRenderHint(QPainter::Antialiasing, true);
             painter.setRenderHint(QPainter::TextAntialiasing, true);

             // Create a table for the PDF
             int rowHeight = 20;
             int columnWidth = 150;
             int x = 50;
             int y = 50;

             // Draw table header
             painter.drawText(x, y, "ID");
             painter.drawText(x + columnWidth, y, "NOM");
             painter.drawText(x + 2 * columnWidth, y, "DESTINATION");
             painter.drawText(x + 3 * columnWidth, y, "MATRICULE");

             // Draw table data
             y += 20; // Move to the next row
             while (query.next()) {
                 painter.drawText(x, y, query.value("ID").toString());
                 painter.drawText(x + columnWidth, y, query.value("NOM").toString());
                 painter.drawText(x + 2 * columnWidth, y, query.value("DESTINATION").toString());
                 painter.drawText(x + 3 * columnWidth, y, query.value("MATRICULE").toString());

                 y += rowHeight;
             }

             painter.end();
             return "Export successful. File saved as " + transport;
         } else {
             return "Error creating the file for export.";
         }
     }
     QString Entreprise::findNearestCollectionZone(const QPointF& userLocation)
     {
         QSqlQuery query;
         query.prepare("SELECT ID, LATITUDE, LONGITUDE FROM COLLECTION_ZONES");

         if (!query.exec()) {
             return "Error retrieving collection zones.";
         }

         double minDistance = std::numeric_limits<double>::max();
         QString nearestZone;

         while (query.next()) {
             QString zoneID = query.value("ID").toString();
             double zoneLatitude = query.value("LATITUDE").toDouble();
             double zoneLongitude = query.value("LONGITUDE").toDouble();

             QPointF zoneLocation(zoneLatitude, zoneLongitude);
             double distance = haversineDistance(userLocation, zoneLocation);

             if (distance < minDistance) {
                 minDistance = distance;
                 nearestZone = zoneID;
             }
         }

         if (nearestZone.isEmpty()) {
             return "No collection zones found.";
         }

         return "Nearest collection zone: " + nearestZone + ", Distance: " + QString::number(minDistance) + " km";
     }

     double Entreprise::haversineDistance(const QPointF& p1, const QPointF& p2)
     {
         const double R = 6371.0; // Earth radius in kilometers

         double lat1 = qDegreesToRadians(p1.x());
         double lon1 = qDegreesToRadians(p1.y());
         double lat2 = qDegreesToRadians(p2.x());
         double lon2 = qDegreesToRadians(p2.y());

         double dlat = lat2 - lat1;
         double dlon = lon2 - lon1;

         double a = qSin(dlat / 2) * qSin(dlat / 2) +
                    qCos(lat1) * qCos(lat2) * qSin(dlon / 2) * qSin(dlon / 2);

         double c = 2 * qAtan2(qSqrt(a), qSqrt(1 - a));

         return R * c;
     }
