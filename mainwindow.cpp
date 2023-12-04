#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "forget.h"
#include "stats.h"
#include "recaptcha.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlRecord>
#include "randomstringgenerator.h"
#include <QFileDialog>
#include <QPainter>
#include <QPrinter>
#include"connection.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include "QrCode.hpp"
#include "smtp.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QApplication>
#include <QSound>
#include <QDebug>
#include <QMediaPlayer>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QDataStream>
#include <QPrintDialog>
#include <QSqlQuery>
#include <QComboBox>
#include <QSaveFile>
#include <QBuffer>
#include <QFileDialog>
#include <QFile>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QDesktopServices>
#include <QUrl>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include <QGraphicsView>
#include <QPdfWriter>
#include <QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDate>
#include <QTime>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include <QPixmap>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>
#include <QString>
#include <QStatusBar>
#include <QTimer>
#include <QDateTime>
using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_equipement->setModel(e.afficher());//refresh
    ui->tab_equipement_2->setModel(e.afficher());//refresh
    ui->tab_equipement_5->setModel(e.afficher());//refresh
    connect(ui->exporter, &QPushButton::clicked, this, &MainWindow::on_exporter_clicked);
    ui->tab_equipement_3->setModel(E.afficher());//refresh

    int ret=Ar.connect_arduino(); // lancer la connexion à arduino

    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< Ar.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<Ar.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(Ar.getserial(),SIGNAL(readyRead()),this,SLOT(update_label_equipement())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}



MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{

    // Réinitialisez les étiquettes d'erreur à vide
    ui->lblErreurId->setText("");
    ui->lblErreurType->setText("");
    ui->lblErreurEtat->setText("");
    ui->lblErreurPrix->setText("");
    ui->lblErreurNiveauremplissage->setText("");
    ui->lblErreurDate_acquisation->setText("");  // Correction du nom de la variable
    ui->lblErreuridZ->setText("");  // Correction du nom de la variable

    // Récupérez les valeurs d'entrée
    QString id = ui->le_idequipement->text();
    QString poste = ui->type->currentText();
    QString etat = ui->etat->currentText();
    QString mail = ui->prix->text();
    QString password = ui->niveauremplissage->text();
    QDate date_naissance = ui->date->date();  // Correction du nom de la variable

    // Validez les champs d'entrée
    bool isValid = true;

    if (id.isEmpty()) {
        ui->lblErreurId->setText("<font color='red'>ID ne peut pas être vide!!!!</font>");
        isValid = false;
    }

    // Validation pour le titre (exemplaire, assurez-vous qu'il n'est pas vide)
    if (poste.isEmpty()) {
        ui->lblErreurType->setText("<font color='red'>Choisir une poste!!!</font>");
        isValid = false;
    }

    if (etat.isEmpty()) {
        ui->lblErreurEtat->setText("<font color='red'>Choisir un état!!!</font>");
        isValid = false;
    }
    // Ajouter une vérification de l'existence de l'ID dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id from employe  WHERE id = :id");
    checkQuery.bindValue(":id", id);
    if (checkQuery.exec() && checkQuery.next()) {
        ui->lblErreurId->setText("<font color='red'>ID existe déjà!!!!</font>");
        isValid = false;
    }

    if (isValid) {
        // Si l'entrée est valide and que l'ID n'existe pas, procédez à l'ajout de l'employé
        employe e(id, poste, etat, mail, password, date_naissance);

        QSqlQuery query;
        bool test = e.ajouter();
        if (test) {
            QMessageBox::information(nullptr, QObject::tr("Ajout employe"),
                QObject::tr("employe ajouté avec succès.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Ajout employe"),
                QObject::tr("Erreur lors de l'ajout de l'employe.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    } else {
        // Gérez l'erreur d'entrée invalide ou d'ID existant
    }
}

void MainWindow::on_pb_afficher_clicked()
{
    ui->tab_equipement->setModel(e.afficher());//refresh
    ui->tab_equipement_2->setModel(e.afficher());//refresh
    ui->tab_equipement_5->setModel(e.afficher());//refresh


}

void MainWindow::on_pb_supprimer_2_clicked()
{
    ui->comboSupp->setModel(e.afficher());
    ui->ComboModif->setModel(e.afficher());
    QString id=ui->comboSupp->currentText();

    bool test=e.supprimer(id);
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Supprimer employe"),
                    QObject::tr("employe supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer employe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier_2_clicked()
{
    // Retrieve values from UI elements
    QString id = ui->ComboModif->currentText();
    QString poste = ui->type2->currentText();
    QString etat = ui->etat2->currentText();
    QString mail = ui->prix2->text(); // Assuming this is the input field for email
    QString password = ui->niveauremplissage2->text(); // Assuming this is the input field for password
    QDate date_naissance = ui->date2->date();

    // Create an employe object with the updated information
    employe e(id, poste, etat, mail, password, date_naissance);

    // Attempt to modify the employee information
    bool test = e.modifier();

    if (test) {
        // Update ComboBoxes after modification
        ui->comboSupp->setModel(e.afficher());
        ui->ComboModif->setModel(e.afficher());

    } else {
        // Show an error message in case of failure
        QMessageBox::critical(this, tr("Modifier employe"), tr("Erreur lors de la modification de l'employe."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pb_afficher_3_clicked()
{
    ui->comboSupp->setModel(e.afficher());
    ui->ComboModif->setModel(e.afficher());
    ui->tab_equipement->setModel(e.afficher());//refresh
    ui->tab_equipement_2->setModel(e.afficher());//refresh
    ui->tab_equipement_5->setModel(e.afficher());//refresh

    QMessageBox::information(this, tr("Modifier employe"), tr("employe modifié!"), QMessageBox::Cancel);
}

void MainWindow::on_pb_afficher_4_clicked()
{

    ui->tab_equipement->setModel(e.afficher());//refresh
    ui->tab_equipement_2->setModel(e.afficher());//refresh
    ui->tab_equipement_5->setModel(e.afficher());//refresh
}


void MainWindow::on_reset_clicked()
{
    ui->ComboModif->clear();

        ui->type2->clear();
        ui->etat2->clear();

        ui->prix2->clear();
        ui->niveauremplissage2->clear();
        ui->date2->clear();
        ui->idZone2->clear();
}

void MainWindow::on_pushButton_clicked()
{
        QString enteredmail = ui->mail_lineEdit->text();
        QString enteredPassword = ui->password_lineEdit->text();

        QSqlQuery query;
        query.prepare("SELECT * FROM employe WHERE mail = :mail AND password = :password");
        query.bindValue(":mail", enteredmail);
        query.bindValue(":password", enteredPassword);

        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            return;
        }

        if (query.next()) {
            // Valid email and password
            QMessageBox::information(this, "Login Successful", "Login successful!");
        } else {
            // Invalid email or password
            qDebug() << "Invalid mail or password. Please try again.";
            QMessageBox::information(this, "try again", "wrong mail or password!");
        }
}

void MainWindow::on_pushButton_2_clicked()
{
 forget forget;
 forget.setModal(true);
 forget.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString searchText = ui->lineEditSearch->text(); // Assuming you have a QLineEdit for search input named lineEditSearch

    employe e; // Create an instance of your employe class
    QSqlQueryModel* searchResults = e.rechercher(searchText); // Call the modified rechercher function

    // Set the model for your QTableView (assuming tab_equipement_5 is a QTableView)
    ui->tab_equipement_5->setModel(searchResults);

    // Optionally, you may want to set column headers or other properties
    // ui->tab_equipement_5->setColumnHidden(0, true); // Uncomment if you want to hide the ID column
}






void MainWindow::on_checkBox_stateChanged(int)
{
    recaptcha recaptcha;
    recaptcha.setModal(true);
    recaptcha.exec();
}

QString MainWindow::fetchData()
{
    QString data;

       // Assuming db is your QSqlDatabase object already connected

       QSqlQuery query(db);
       query.prepare("SELECT * FROM EMPLOYE ORDER BY id ASC");

       if (query.exec())
       {
           while (query.next())
           {
               QString id = query.value("id").toString();
               QString poste = query.value("poste").toString();
               QString mail = query.value("mail").toString();
               QString password = query.value("password").toString();
               QString dateNaissance = query.value("date_naissance").toString();
               QString etat = query.value("etat").toString();

               // Format the data as a string (you can customize this part)
               data += "-----------------\n";
               data += "ID: " + id + "\n";
               data += "Poste: " + poste + "\n";
               data += "Mail: " + mail + "\n";
               data += "Password: " + password + "\n";
               data += "Date de Naissance: " + dateNaissance + "\n";
               data += "État: " + etat + "\n";
               data += "-----------------\n";
           }
       }
       else
       {
           // Handle the case where the query execution fails
           data = "Error: Unable to execute query! Error: " + query.lastError().text();
       }

       return data;
    }



void MainWindow::on_pushButton_4_clicked() {
    Stats *statsPage = new Stats(this);
    statsPage->calculateAndDisplayChart();
}




void MainWindow::on_exporter_clicked()
{
    // Fetch data
    QString dataToExport = fetchData();

    // Get the file path where the user wants to save the PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", QString(), "PDF Files (*.pdf)");

    if (!filePath.isEmpty()) {
        // Create a PDF printer
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);

        // Create a painter
        QPainter painter(&printer);

        // Set font and other formatting options if needed
        QFont font;
        font.setPointSize(12);
        painter.setFont(font);

        // Calculate the bounding rectangle that fits the text
        QRectF textRect = painter.boundingRect(printer.pageRect(), Qt::TextWordWrap, dataToExport);

        // Draw the data onto the PDF using the calculated rectangle
        painter.drawText(textRect, Qt::TextWordWrap, dataToExport);

        // Inform the user that the export was successful
        QMessageBox::information(this, "Export Successful", "Data exported as PDF!");
    }
}

//------------------------------------------------





















//--------------------------------------------










void MainWindow::on_pb_ajouter_2_clicked()
{
    // Réinitialisez les étiquettes d'erreur à vide
    ui->lblErreurId_2->setText("");
    ui->lblErreurType_2->setText("");
    ui->lblErreurEtat_2->setText("");
    ui->lblErreurPrix_2->setText("");
    ui->lblErreurNiveauremplissage_2->setText("");
    ui->lblErreurDate_acquisation_2->setText("");  // Correction du nom de la variable
    ui->lblErreuridZ_2->setText("");  // Correction du nom de la variable

    // Récupérez les valeurs d'entrée
    QString id_equipement = ui->le_idequipement_2->text();
    QString type = ui->type_2->currentText();
    QString etat = ui->etat_2->currentText();
    int prix = ui->prix_2->text().toInt();
    float niveau_remplissage = ui->niveauremplissage_2->text().toFloat();
    QDate date_acquisition = ui->date_2->date();  // Correction du nom de la variable

    QString idZ = ui->idZone_2->text();

    // Validez les champs d'entrée
    bool isValid = true;

    if (id_equipement.isEmpty()) {
        ui->lblErreurId_2->setText("<font color='red'>ID Equipement ne peut pas être vide!!!!</font>");
        isValid = false;
    }

    // Validation pour le titre (exemplaire, assurez-vous qu'il n'est pas vide)
    if (type.isEmpty()) {
        ui->lblErreurType_2->setText("<font color='red'>Choisir un Type!!!</font>");
        isValid = false;
    }

    if (etat.isEmpty()) {
        ui->lblErreurEtat_2->setText("<font color='red'>Choisir un etat!!!</font>");
        isValid = false;
    }
    if (prix < 0) {
        ui->lblErreurPrix_2->setText("<font color='red'>Prix doit être positif !!!</font>");
        isValid = false;
    }
    if (niveau_remplissage < 0) {
        ui->lblErreurNiveauremplissage_2->setText("<font color='red'>Niveau remplissage doit être positif!!!</font>");
        isValid = false;
    }

    // Ajouter une vérification de l'existence de l'ID dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT id_equipement from equipement  WHERE id_equipement = :id_equipement");
    checkQuery.bindValue(":id_equipement", id_equipement);
    if (checkQuery.exec() && checkQuery.next()) {
        ui->lblErreurId_2->setText("<font color='red'>ID Equipement existe déjà!!!!</font>");
        isValid = false;
    }

    if (isValid) {
        // Si l'entrée est valide et que l'ID n'existe pas, procédez à l'ajout de l'activité
        Equipement E(id_equipement, type, etat, prix, niveau_remplissage, date_acquisition, idZ);  // Correction de la création de l'objet Equipement

        QSqlQuery query;
        bool test = E.ajouter();
        if (test) {
            ui->tab_equipement_3->setModel(E.afficher());  // Refresh
ui->comboSupp_2->setModel(E.afficher());
ui->ComboModif_2->setModel(E.afficher());

            QMessageBox::information(nullptr, QObject::tr("Ajout Equipement"),
                QObject::tr("Equipement ajouté avec succès.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Ajout Equipement"),
                QObject::tr("Erreur lors de l'ajout de l'Equipement.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    } else {
        // Gérez l'erreur d'entrée invalide ou d'ID existant
    }
}

void MainWindow::on_pb_ajouter_3_clicked()

{
    data = "1";
  //  data = Ar.read_from_arduino();

    qDebug() << data;
    if (data == "1") // Assuming "1" indicates the condition to prompt the user
    {
        // Display a window to get user input
        bool ok;
        QString dechetID = QInputDialog::getText(this, tr("Enter Dechet ID"), tr("Dechet ID:"), QLineEdit::Normal, "", &ok);
        if (!ok) {
            // User pressed Cancel
            return;
        }

        QString equipementID = QInputDialog::getText(this, tr("Enter Equipement ID"), tr("Equipement ID:"), QLineEdit::Normal, "", &ok);
        if (!ok) {
            // User pressed Cancel
            return;
        }

        QString quantitee = QInputDialog::getText(this, tr("Enter QUANTITEE"), tr("QUANTITEE:"), QLineEdit::Normal, "", &ok);
        if (!ok) {
            // User pressed Cancel
            return;
        }

        // Convert strings to integers
        bool conversionSuccess;
        int dechetIDInt = dechetID.toInt(&conversionSuccess);
        if (!conversionSuccess) {
            qDebug() << "Invalid Dechet ID. Please enter a valid number.";
            return;
        }

        int equipementIDInt = equipementID.toInt(&conversionSuccess);
        if (!conversionSuccess) {
            qDebug() << "Invalid Equipement ID. Please enter a valid number.";
            return;
        }

        int quantiteeInt = quantitee.toInt(&conversionSuccess);
        if (!conversionSuccess) {
            qDebug() << "Invalid QUANTITEE. Please enter a valid number.";
            return;
        }

        // Call a function to verify existence and update quantity
        // This function should return the id_equipement and new quantity
        QString result = Ar.updateDechetQuantity(dechetIDInt, equipementIDInt, quantiteeInt);

        // Parse the result
        QStringList parts = result.split(",");
        if (parts.size() == 2) {
            int idEquipement = parts[0].toInt();
            int newQuantity = parts[1].toInt();
 qDebug() << "result: " << result;
 qDebug() << result ;
 QByteArray x=result.toUtf8();
 qDebug() << x ;
 Ar.write_to_arduino(x);
 qDebug()<<"valdie";
            // Display the result using qDebug()
            qDebug() << "ID Equipement: " << idEquipement;
            qDebug() << "New Quantity: " << newQuantity;
        } else {
            qDebug() << "Invalid result format.";
        }
    }
}


void MainWindow::on_qrcodegen_clicked()
{
    QString value = ui->lineEdit_qrcode->text();

        QSqlQuery qry;
        qry.prepare("SELECT * FROM Equipement WHERE id_equipement = :id_equipement");
        qry.bindValue(":id_equipement", value);
        qry.exec();

        if (qry.next()) {
            // ID exists in the database
            QString id_equipement = qry.value(0).toString();
            QString type = qry.value(1).toString();
            QString etat = qry.value(2).toString();
            QString prix = qry.value(3).toString();
            QString niveau_remplissage = qry.value(4).toString();
            QString date_acquisation = qry.value(5).toString();
            QString idZ = qry.value(6).toString();








            QString text = "ID Equipement :" + id_equipement + "\n" + "Type :" + type + "\n" + "Etat :" + etat + "\n" +
                           "Prix :" + prix + "\n" + "Niveau Remplissage :" + niveau_remplissage + "\n" + "Date Acquisation :" + date_acquisation + "\n" + "Id Zone :" + idZ  ;

            // Create the QR Code object
            QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);

            qint32 sz = qr.getSize();
            QImage im(sz, sz, QImage::Format_RGB32);
            QRgb black = qRgb(191, 112, 105);
            QRgb white = qRgb(255, 255, 255);

            for (int y = 0; y < sz; y++) {
                for (int x = 0; x < sz; x++) {
                    im.setPixel(x, y, qr.getModule(x, y) ? black : white);
                }
            }

            ui->qrcodecommande->setPixmap(QPixmap::fromImage(im.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));
        } else {
            // ID does not exist in the database
            QMessageBox::critical(nullptr, QObject::tr("ID Equipement introuvable"),
                QObject::tr("L'ID Equipement que vous avez saisi n'existe pas.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
}



void MainWindow::on_PDF_clicked()

{
    QPdfWriter pdf("C:/Users/GENERAL/Desktop/Gestion_equipements/Gestion_equipements/list_des_equipement.pdf");

            QPainter painter(&pdf);


                   int i = 4000;
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Book Script",20));
                   painter.drawText(2500, 1400, "LISTE DES EQUIPEMENT");
                   painter.setPen(Qt::red);
                   painter.setFont(QFont("Time New Roman", 10));
                   painter.drawRect(100, 100, 9200, 2700); // dimension ta3 rectangle
                   painter.drawRect(100, 3000, 9200, 500);


                   painter.drawText(300,3300,"ID EQUIPEMENT");
                   painter.drawText(1800,3300,"TYPE");
                   painter.drawText(2800,3300,"ETAT");
                   painter.drawText(3500,3300,"PRIX");
                   painter.drawText(4000,3300,"NIVEAU REMPLISSAGE");
                   painter.drawText(6000,3300,"DATE ACQUISATION");
                   painter.drawText(8000,3300,"IDZ");





                   QImage image("C:/Users/GENERAL/Desktop/Gestion_equipements/Gestion_equipements/image/logo_esprit.png");
                   painter.drawImage(QRectF(200, 200, 2000, 2000), image);

                   QImage image1("C:/Users/GENERAL/Desktop/Gestion_equipements/Gestion_equipements/image/logo_rec.png");
                   painter.drawImage(QRectF(7000, 200, 2000, 2000), image1);

                   painter.drawRect(100, 3700, 9200, 9000);

                   QSqlQuery query;
                   query.prepare("select * from Equipement");
                   query.exec();
                   while (query.next())
                   {
                       painter.drawText(700, i, query.value(0).toString());
                       painter.drawText(1800, i, query.value(1).toString());
                       painter.drawText(2800, i, query.value(2).toString());
                       painter.drawText(3500, i, query.value(3).toString());
                       painter.drawText(4800, i, query.value(4).toString());
                       painter.drawText(6000, i, query.value(5).toString());
                       painter.drawText(8000, i, query.value(6).toString());

                       i = i + 350;
                   }

                   QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                       QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_statistique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Equipement where type='Presse'");
     float dispo=model->rowCount();

           model->setQuery("select * from Equipement where type='Broyeur'");
           float dispo1=model->rowCount();




           model->setQuery("select * from Equipement where type='Concasseur'");
           float dispo2=model->rowCount();

           float total=dispo1+dispo+dispo2;
               QString a=QString("Type Broyeur" +QString::number((dispo1*100)/total,'f',2)+"%" );
               QString b=QString("Type Presse"+QString::number((dispo*100)/total,'f',2)+"%" );
               QString c=QString("Type Concasseur"+QString::number((dispo2*100)/total,'f',2)+"%" );

               QPieSeries *series = new QPieSeries();
               series->append(a,dispo1);
               series->append(b,dispo);
               series->append(c,dispo2);

           if (dispo1!=0)
           {QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());}
           if ( dispo!=0)
           {
               QPieSlice *slice1 = series->slices().at(1);
               slice1->setLabelVisible();
           }
           if ( dispo2!=0)
           {
               QPieSlice *slice2 = series->slices().at(2);
               slice2->setLabelVisible();
           }

           QChart *chart = new QChart();


           chart->addSeries(series);
           chart->setTitle("statistique par type      "+ QString::number(total));



           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->resize(1000,500);
           chartView->show();
}


void MainWindow::on_valider1_2_clicked()
{
    {
        QString id_equipement=ui->ComboModif_2->currentText();
                  QSqlQuery query;
                  query.prepare("select * from equipement where id_equipement='"+id_equipement+"'");
                  if (query.exec())
                  {
                   while (query.next())
                   {


                       ui->type2_2->setCurrentText(query.value(1).toString());
                       ui->etat2_2->setCurrentText(query.value(2).toString());
                       ui->prix2_2->setText(query.value(3).toString());
                       ui->niveauremplissage2_2->setText(query.value(4).toString());

                       ui->date2_2->setDate(query.value(5).toDate());
                       ui->idZone2_2->setText(query.value(6).toString());






                   }
                  }


}}

void MainWindow::on_reset_2_clicked()
{
    ui->ComboModif_2->clear();

        ui->type2_2->clear();
        ui->etat2_2->clear();

        ui->prix2_2->clear();
        ui->niveauremplissage2_2->clear();
        ui->date2_2->clear();
        ui->idZone2_2->clear();
}


void MainWindow::on_modifier_3_clicked()
{
    // Récupérez les valeurs d'entrée
    QString id_equipement = ui->ComboModif_2->currentText();
    QString type = ui->type2_2->currentText();
    QString etat = ui->etat2_2->currentText();
    int prix = ui->prix2_2->text().toInt();
    float niveau_remplissage = ui->niveauremplissage2_2->text().toFloat();
    QDate date_acquisation = ui->date2_2->date();
    QString idZ = ui->idZone2_2->text();

    // Créez un objet Equipement en utilisant le constructeur
    Equipement E(id_equipement, type, etat, prix, niveau_remplissage, date_acquisation, idZ);

    QSqlQuery query;

    bool test = E.modifier();
    if (test)
    {
        ui->tab_equipement_3->setModel(E.afficher());  // Refresh

        QMessageBox::information(nullptr, QObject::tr("Modifier Equipement"),
            QObject::tr("Equipement modifié avec succès.\n"
                        "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);

        // Mettez à jour les modèles pour les combobox
        ui->comboSupp_2->setModel(E.afficher());
        ui->ComboModif_2->setModel(E.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Equipement"),
            QObject::tr("Erreur lors de la modification de l'Equipement.\n"
                        "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }

    ui->ComboModif_2->clear();  // Effacez le contenu du combobox
}


void MainWindow::on_pb_supprimer_3_clicked()
{
    QString id_equipement=ui->comboSupp_2->currentText();

    bool test=E.supprimer(id_equipement);
    if(test)
    {
        ui->tab_equipement_2->setModel(E.afficher());//refresh

        ui->comboSupp_2->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer Equipement"),
                    QObject::tr("Equipement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


        ui->comboSupp_2->setModel(E.afficher());
        ui->ComboModif_2->setModel(E.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_send_mail_2_clicked()

{
    QString id_equipement=ui->comboSupp_2->currentText();

    bool test=E.supprimer(id_equipement);
    if(test)
    {
        ui->tab_equipement_2->setModel(E.afficher());//refresh

        ui->comboSupp_2->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer Equipement"),
                    QObject::tr("Equipement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


        ui->comboSupp_2->setModel(E.afficher());
        ui->ComboModif_2->setModel(E.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer Equipement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_10_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    int maxIndex = ui->stackedWidget->count() - 1;

    // Go to the next index without reaching the limit
    int nextIndex = (currentIndex < maxIndex) ? currentIndex + 1 : currentIndex;

    ui->stackedWidget->setCurrentIndex(nextIndex);
}

void MainWindow::on_pushButton_9_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();

    // Go to the previous index without going below 0
    int prevIndex = (currentIndex > 0) ? currentIndex - 1 : 0;

    ui->stackedWidget->setCurrentIndex(prevIndex);
}



void MainWindow::on_pushButton_12_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    int maxIndex = ui->stackedWidget->count() - 1;

    // Go to the next index without reaching the limit
    int nextIndex = (currentIndex < maxIndex) ? currentIndex + 1 : currentIndex;

    ui->stackedWidget->setCurrentIndex(nextIndex);
}

void MainWindow::on_pushButton_11_clicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();

    // Go to the previous index without going below 0
    int prevIndex = (currentIndex > 0) ? currentIndex - 1 : 0;

    ui->stackedWidget->setCurrentIndex(prevIndex);
}
