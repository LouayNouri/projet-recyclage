#include "Main_Employee.h"
#include "ui_Main_Employee.h"
#include "Employee.h"
#include "Formation.h"
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


Main_Employee::Main_Employee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main_Employee)
   , trashWindow(nullptr)
{
    ui->setupUi(this);
    trashWindow = new Main_trash();  // Initialize Main_trash
    ui->tab_equipement->setModel(e.afficher());//refresh
    ui->tab_equipement_2->setModel(e.afficher());//refresh
    ui->tab_equipement_5->setModel(e.afficher());//refresh
    connect(ui->exporter, &QPushButton::clicked, this, &Main_Employee::on_exporter_clicked);
    connect(ui->switchToTrash, &QPushButton::clicked, this, &Main_Employee::switchToTrash);

    QPushButton *switchToTrashButton = ui->dock->findChild<QPushButton *>("switchToTrashButton");
        if (switchToTrashButton) {
            connect(switchToTrashButton, &QPushButton::clicked, this, &Main_Employee::switchToTrash);
        }


}

Main_Employee::~Main_Employee()
{
    delete ui;
}





void Main_Employee::switchToTrash()
{
    if (!trashWindow) {
        trashWindow = new Main_trash(this);
    }
    trashWindow->show();
    trashWindow->raise();  // Bring the window to the front
    trashWindow->activateWindow();  // Activate the window
}

void Main_Employee::closeEvent(QCloseEvent *event)
{
    if (trashWindow) {
        trashWindow->close();  // Close the trash window if it is open
        delete trashWindow;
        trashWindow = nullptr;  // Reset the pointer
    }
    event->accept();
}


void Main_Employee::on_pb_ajouter_clicked()
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

void Main_Employee::on_pb_afficher_clicked()
{
    ui->tab_equipement->setModel(e.afficher());//refresh
    ui->tab_equipement_2->setModel(e.afficher());//refresh
    ui->tab_equipement_5->setModel(e.afficher());//refresh


}

void Main_Employee::on_pb_supprimer_2_clicked()
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

void Main_Employee::on_modifier_2_clicked()
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


void Main_Employee::on_pb_afficher_3_clicked()
{
    ui->comboSupp->setModel(e.afficher());
    ui->ComboModif->setModel(e.afficher());
    ui->tab_equipement->setModel(e.afficher());//refresh
    ui->tab_equipement_2->setModel(e.afficher());//refresh
    ui->tab_equipement_5->setModel(e.afficher());//refresh

    QMessageBox::information(this, tr("Modifier employe"), tr("employe modifié!"), QMessageBox::Cancel);
}

void Main_Employee::on_pb_afficher_4_clicked()
{

    ui->tab_equipement->setModel(e.afficher());//refresh
    ui->tab_equipement_2->setModel(e.afficher());//refresh
    ui->tab_equipement_5->setModel(e.afficher());//refresh
}


void Main_Employee::on_reset_clicked()
{
    ui->ComboModif->clear();

        ui->type2->clear();
        ui->etat2->clear();

        ui->prix2->clear();
        ui->niveauremplissage2->clear();
        ui->date2->clear();
        ui->idZone2->clear();
}

void Main_Employee::on_pushButton_clicked()
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

void Main_Employee::on_pushButton_2_clicked()
{
 forget forget;
 forget.setModal(true);
 forget.exec();
}

void Main_Employee::on_pushButton_3_clicked()
{
    QString searchText = ui->lineEditSearch->text(); // Assuming you have a QLineEdit for search input named lineEditSearch

    employe e; // Create an instance of your employe class
    QSqlQueryModel* searchResults = e.rechercher(searchText); // Call the modified rechercher function

    // Set the model for your QTableView (assuming tab_equipement_5 is a QTableView)
    ui->tab_equipement_5->setModel(searchResults);

    // Optionally, you may want to set column headers or other properties
    // ui->tab_equipement_5->setColumnHidden(0, true); // Uncomment if you want to hide the ID column
}






void Main_Employee::on_checkBox_stateChanged(int)
{
    recaptcha recaptcha;
    recaptcha.setModal(true);
    recaptcha.exec();
}

QString Main_Employee::fetchData()
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



void Main_Employee::on_pushButton_4_clicked() {
    Stats *statsPage = new Stats(this);
    statsPage->calculateAndDisplayChart();
}




void Main_Employee::on_exporter_clicked()
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

