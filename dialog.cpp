#include "dialog.h"
#include "ui_dialog.h"
#include<QDialog>
#include"fournisseur.h"
#include"mainwindow.h"
#include<QMessageBox>
#include<QApplication>
#include<QCompleter>
Dialog::Dialog(int cin,QWidget *parent) :
    QDialog(parent),
    m_cin(cin),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("SELECT NOM FROM FOURNISSEUR WHERE CIN = :CIN");
    query.bindValue(":CIN", cin);
    if (query.exec() && query.next()) {
        QString nom = query.value("NOM").toString();
        ui->lineEdit_nom_2->setText(nom);}
    query.prepare("SELECT PRENOM FROM FOURNISSEUR WHERE CIN = :CIN");
    query.bindValue(":CIN", cin);
    if (query.exec() && query.next()) {
        QString prenom = query.value("PRENOM").toString();
        ui->lineEdit_nom_3->setText(prenom);}
    query.prepare("SELECT EMAIL FROM FOURNISSEUR WHERE CIN = :CIN");
    query.bindValue(":CIN", cin);
    if (query.exec() && query.next()) {
        QString email = query.value("EMAIL").toString();
        ui->lineEdit_nom_6->setText(email);}
        query.prepare("SELECT NBRP FROM FOURNISSEUR WHERE CIN = :CIN");
        query.bindValue(":CIN", cin);
        if (query.exec() && query.next()) {
           QString nbrp = query.value("NBRP").toString();
        ui->lineEdit_nom_5->setText(nbrp);}
        query.prepare("SELECT SEXE FROM FOURNISSEUR WHERE CIN = :CIN");
        query.bindValue(":CIN", cin);
        if (query.exec() && query.next()) {
            QString sexe = query.value("SEXE").toString();
            ui->lineEdit_sexe_->setText(sexe);}
            query.prepare("SELECT MOTP FROM FOURNISSEUR WHERE CIN = :CIN");
            query.bindValue(":CIN", cin);
            if (query.exec() && query.next()) {
                QString motp = query.value("MOTP").toString();
              ui->lineEdit_motp_->setText(motp);
            }
            QStringList sexeList = {"femme", "homme"};
            QCompleter *sexeCompleter = new QCompleter(sexeList, this);
                   sexeCompleter->setCaseSensitivity(Qt::CaseInsensitive);
                   ui->lineEdit_sexe_->setCompleter(sexeCompleter);

  ui->lineEdit_motp_->setEchoMode(QLineEdit::Password);
}


Dialog::~Dialog()
{
    delete ui;
}





void Dialog::on_modifier_clicked()
{
    {
        QSqlQuery query;
        QString prenom = ui->lineEdit_nom_3->text();
        QString nom = ui->lineEdit_nom_2->text();
        QString email = ui->lineEdit_nom_6->text();
       int nbrp= ui->lineEdit_nom_5->text().toInt();
       QString sexe = ui->lineEdit_sexe_->text();
       QString motp = ui->lineEdit_motp_->text();
       QStringList sexeList = {"femme", "homme"};
          if (!sexeList.contains(sexe)) {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Le sexe est invalide.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
              return;
          }


               QRegularExpression regex("^[A-Za-z ]+$");

                      QRegularExpressionMatch match = regex.match(nom);



                      if (!match.hasMatch()) {



                          QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Nom ne doit contenir que des lettres et non vide.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);

                          ui->lineEdit_nom_2->setStyleSheet("QLineEdit { border: 2px solid red; }");

                          return;



                      }
                      QRegularExpressionMatch match1 = regex.match(prenom);



                      if (!match.hasMatch()) {



                          QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Nom ne doit contenir que des lettres et non vide.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);

                          ui->lineEdit_nom_3->setStyleSheet("QLineEdit { border: 2px solid red; }");

                          return;



                      }


    fournisseur F(nom,prenom,email,m_cin,nbrp,sexe,motp);

     F.modifier(m_cin);

     QMessageBox::information(nullptr, QObject::tr("OK"),

                 QObject::tr("MODIFICATION effectué avec succés.\n"

                             "Click Cancel to exit."), QMessageBox::Cancel); }
}

