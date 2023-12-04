#include "login.h"
#include "ui_login.h"
#include<QSqlQuery>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMainWindow>
#include<QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->le_password_3->setEchoMode(QLineEdit::Password);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    int cin = ui->le_cin_3->text().toInt();
            QString motp = ui->le_password_3->text();


            QSqlQuery query;
            query.prepare("SELECT COUNT(*) FROM Fournisseur WHERE CIN=:CIN AND MOTP=:MOTP");
            query.bindValue(":CIN", cin);
            query.bindValue(":MOTP", motp);
            query.exec();

            if (query.next()) {
                int count = query.value(0).toInt();


if (count>0){ QMessageBox::information(nullptr, QObject::tr("OK"),
                                       QObject::tr("Cin et Mot de passe correct.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                    mainWindow = new MainWindow;
                    mainWindow->show();
                    accept(); // Ferme la boîte de dialogue
                } else {
                    // Affichez un message d'erreur si l'identification échoue
                    QMessageBox::critical(nullptr, QObject::tr("Non OK"),
                        QObject::tr("Veuillez vérifier votre cin, mot de passe et code.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
                }

}
}
