#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entreprise.h"

#include"QIntValidator"
#include"QObject"
#include<QSqlQueryModel>
#include"QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /*ui->le_id->setValidator( new QIntValidator(100, 9999999, this));*/
    ui->tab_entre->setModel(E.afficher());

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{   /*int ID=ui->le_id->text().toInt();
    int NOMBRE_DAUDIT_EFFECTUE=ui->le_nb->text().toInt();*/
    QString ID=ui->le_id->text();


    QString NOM=ui->le_nom->text();
    QString DOMAINE=ui->le_domaine->text();

      QString NOMBRE_DAUDIT_EFFECTUE=ui->le_nb->text();

    Entreprise E(ID,NOM,DOMAINE,NOMBRE_DAUDIT_EFFECTUE);
    bool test=E.ajouter();



    QMessageBox msgBox;
    if (test) {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue\n" "clicke cancel to exit." ),QMessageBox::Cancel);
        msgBox.setText("ajout avec succes");
        msgBox.exec();
    } else {
        msgBox.setText("echec");
        msgBox.exec();
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("ajout non effectue.\n" "clicke cancel to exit."),QMessageBox::Cancel);
    }




}

void MainWindow::on_pb_supp_clicked()
{
    Entreprise E1;E1.setID(ui->le_id_supp->text());
    bool test=E1.supprimer(E1.getID());
    QMessageBox msgBox;

    if (test) {
        msgBox.setText("suppression avec succes");
        msgBox.exec();
    } else {
        msgBox.setText("echec de suppression");
        msgBox.exec(); }

}

/*void MainWindow::on_pb_modifier_clicked()
{
    QString idd = ui->le_idmodif->text();
            Entreprise C;
            C.setID(idd);
            QString newNom = ui->le_nom->text();
            QString newdomaine = ui->le_domaine->text();
            QString newemaile = ui->le_email->text();
            QString newnb = ui->le_nb->text();
            QString newetat= ui->le_etat->text();
            // Check if the newId already exists in the database.
                                if (idd==C.getID)) {
                                    QMessageBox::critical(nullptr, QObject::tr("Error"),
                                        QObject::tr("ID not exists in the database. Please choose a unique ID."), QMessageBox::Ok);
                                    return; // ID already exists, so don't proceed with modification.
                                }
                                // If the ID is unique and changes are made, update the clients's information.
                                                   C.setID(idd);
                                                   C.setNOM(newNom);
                                                   C.setDOMAINE( newdomaine);
                                                   C.setEMAIL(newemaile);
                                                   C.setnb(newnb);
                                                   C.setETAT(newetat);

                                                   bool test = C.modifier();

                                                   if (test) {
                                                   QMessageBox::information(nullptr, QObject::tr("OK"),
                                                   QObject::tr("Modification successful.\nClick Cancel to exit."), QMessageBox::Cancel);
                                                                   ui->tab_entre->setModel(C.afficher()); // Mise à jour
                                                               } else {
                                                                   QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                                                       QObject::tr("Modification failed.\nClick Cancel to exit."), QMessageBox::Cancel);
                                                               }

                               }*/


/*void MainWindow::on_pb_modifier_clicked()
{
    // Get the data that you want to modify from your UI elements (e.g., QLineEdit, QComboBox, etc.)
    QString newNom = ui->le_nom_2->text(); // Replace with the actual name of your UI element
    QString newDomaine = ui->le_domaine_2->text(); // Replace with the actual name of your UI element
    QString newEmail = ui->le_email_2->text(); // Replace with the actual name of your UI element
    QString newNbaudit = ui->le_nb->text(); // Replace with the actual name of your UI element
    QString newEtat = ui->le_etat_2->text(); // Replace with the actual name of your UI element
    QString entrepriseID = ui->le_idmodif->text(); // Replace with the actual name of your UI element

    // Create an instance of the Entreprise class and set the new values
    Entreprise entreprise;
    entreprise.setID(entrepriseID);
    entreprise.setNOM(newNom);
    entreprise.setDOMAINE(newDomaine);
    entreprise.setEMAIL(newEmail);
    entreprise.setnb(newNbaudit);
    entreprise.setETAT(newEtat);

     QMessageBox msgBox;
    // Call the modifier function to update the database
    if (entreprise.modifier())
    {
        msgBox.setText("modifier avec succes");
        msgBox.exec();
    }
    else
    {
        msgBox.setText("echec de modification ");
        msgBox.exec();
    }
}*/
void MainWindow::on_pb_modifier_clicked()
{
    QString newID = ui->le_idmodif->text();
    QString newNom = ui->le_nom_2->text();
    QString newDomaine = ui->le_domaine_2->text();

    QString newNbAudit = ui->le_nb_2->text();



    Entreprise entreprise;
    entreprise.setID(newID);
    entreprise.setNOM(newNom);
    entreprise.setDESTINATION(newDomaine);

    entreprise.setMATRICULE(newNbAudit);



    bool test = entreprise.modifier();

    QMessageBox msgBox;

    if (test) {
        msgBox.setText("Modification avec succès");
        msgBox.exec();
    } else {
        msgBox.setText("Échec de la modification");
        msgBox.exec();
    }
}
/*void MainWindow::on_TricomboBoxReglement_currentTextChanged(const QString)
{
    QString trieOption=ui->comboBox_2->currentText();
     ui->tab_entre->setModel(E.trierReglement(trieOption));
}*/

/*void MainWindow::on_input_Rechercher_textChanged(const QString )
{
    QString chaine_c=ui->lineEdit_2->text();


       if(chaine_c !="")
       {
       ui->tab_entre->setModel(E.rechercher(chaine_c));
       }
       else
       {
           QString trieOption=ui->comboBox_2->currentText();
            //ui->tab_entre->setModel(E.trierReglement(trieOption));

       }
}*/

void MainWindow::on_tier_clicked()
{
    ui->tab_trier->setModel(E.triernom());

}

void MainWindow::on_chercher_clicked()
{
    QString searchName = ui->searchLineEdit->text();
        QSqlQueryModel* searchResults = E.rechercheParNom(searchName);

        if (searchResults->rowCount() > 0) {
            ui->tab_cherche->setModel(searchResults);
            QMessageBox::information(this, "Search Result", "Search successful. Results found.");
        } else {
            // Optionally display all entries if no results found
            // ui->tab_entre_3->setModel(E.afficher());
            QMessageBox::information(this, "Search Result", "No results found for the specified ID.");
        }

}
void MainWindow::on_pb_stats_clicked()
{
    QString mostVisitedDestination = E.destinationPlusVisite();
    QMessageBox::information(this, "Statistics", "Most visited destination: " + mostVisitedDestination);
}
void MainWindow::on_exportButton_clicked()
{
    QString destination = ui->destinationLineEdit->text();
    QString exportResult = E.exportChauffeursByDestination(destination);

    QMessageBox::information(this, "Export Result", exportResult);
}
void MainWindow::on_findNearestZoneButton_clicked()
{
    double userLatitude = ui->userLatitudeLineEdit->text().toDouble();
    double userLongitude = ui->userLongitudeLineEdit->text().toDouble();

    QPointF userLocation(userLatitude, userLongitude);

    QString result = E.findNearestCollectionZone(userLocation);

    QMessageBox::information(this, "Nearest Collection Zone", result);
}
