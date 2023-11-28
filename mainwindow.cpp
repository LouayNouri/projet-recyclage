#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zone.h"
#include "QMessageBox"
#include "QSqlQuery"

#include<QPieSlice >
#include<QPieSeries>
#include<QPrinter>
#include <QFileDialog>
#include<QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include<QtCharts>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_nbmax->setValidator(new QIntValidator(0,99,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString type=ui->lineEdit_type->text();
    QString localisation=ui->lineEdit_localisation->text();
   int nbmax=ui->lineEdit_nbmax->text().toInt();
   float prix=ui->lineEdit_prix->text().toFloat();
    Zone z(id,type,localisation,nbmax,prix);
bool test=z.ajouter();
if (test)
{
    ui->tableView->setModel(tmp.afficher());

    QMessageBox::information(nullptr, QObject::tr("modification"),
                      QObject::tr(" successful.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

  }
      else
          QMessageBox::critical(nullptr, QObject::tr("modification"),
                      QObject::tr("failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString type=ui->lineEdit_type->text();
    QString localisation=ui->lineEdit_localisation->text();
   int nbmax=ui->lineEdit_nbmax->text().toInt();
   float prix=ui->lineEdit_prix->text().toFloat();
    Zone z(id,type,localisation,nbmax,prix);
    bool test=z.modifier(id);
    ui->tableView->setModel(tmp.afficher());
 if(test){
     QMessageBox::information(nullptr, QObject::tr("modification"),
                       QObject::tr(" successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("modification"),
                       QObject::tr("failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


 }



void MainWindow::on_pushButton_del_clicked()
{
    int i;
    QModelIndex index=ui->tableView->currentIndex();
i=index.row();
QModelIndex in=index.sibling(i,0);

int val=ui->tableView->model()->data(in).toInt();

    bool test=tmp.supprimer(val);
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("modification"),
                          QObject::tr(" successful.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

      }
          else
              QMessageBox::critical(nullptr, QObject::tr("modification"),
                          QObject::tr("failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();


        QSqlQuery qry;
        qry.prepare("select IDZ,TYPE,LOCALISATION,NBMAX,PRIX from zonedecollection where IDZ='"+val+"' " );


        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit_id->setText(qry.value(0).toString());
                ui->lineEdit_type->setText(qry.value(1).toString());
                ui->lineEdit_localisation->setText(qry.value(2).toString());
                ui->lineEdit_prix->setText(qry.value(4).toString());
                ui->lineEdit_nbmax->setText(qry.value(3).toString());
}}}

void MainWindow::on_lineEdit_recherche_textChanged()
{
    QString rech=ui->lineEdit_recherche->text();
    ui->tableView->setModel(tmp.RechercheZone(rech));
}

void MainWindow::on_comboBox_trie_activated()
{
    if(ui->comboBox_trie->currentText()=="Tri par idz")
    {
        ui->tableView->setModel(tmp.trierZoneparidz());

    }else if(ui->comboBox_trie->currentText()=="Tri par nbmax")
    {
        ui->tableView->setModel(tmp.trierZoneparnbmax());

    }else if(ui->comboBox_trie->currentText()=="Tri par Prix")
    {
        ui->tableView->setModel(tmp.trierZoneparprix());
    }
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from zonedecollection where prix < 10 ");
                         float prix=model->rowCount();
                         model->setQuery("select * from zonedecollection where prix  between 10 and 50 ");
                         float prixx=model->rowCount();
                         model->setQuery("select * from zonedecollection where prix >50  ");
                         float prixxx=model->rowCount();
                         float total=prix+prixx+prixxx;
                         QString a=QString("moins de 10 DT "+QString::number((prix*100)/total,'f',2)+"%" );
                         QString b=QString("between 10DT and 50 DT "+QString::number((prixx*100)/total,'f',2)+"%" );
                         QString c=QString("+50 DT"+QString::number((prixxx*100)/total,'f',2)+"%" );
                         QPieSeries *series = new QPieSeries();
                         series->append(a,prix);
                         series->append(b,prixx);
                         series->append(c,prixxx);
                 if (prix!=0)
                 {QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());}
                 if ( prixx!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabelVisible();
                 }
                 if(prixxx!=0)
                 {
                          // Add labels to rest of slices
                          QPieSlice *slice2 = series->slices().at(2);
                          //slice1->setExploded();
                          slice2->setLabelVisible();
                 }
                         // Create the chart widget
                         QChart *chart = new QChart();
                         // Add data to chart with title and hide legend
                         chart->addSeries(series);
                         chart->setTitle("Pourcentage Par Prix :Nombre Des Zone "+ QString::number(total));
                         chart->legend()->hide();
                         // Used to display the chart
                         QChartView *chartView = new QChartView(chart);
                         chartView->setRenderHint(QPainter::Antialiasing);
                         chartView->resize(1000,500);
                         chartView->show();
}

void MainWindow::on_pushButton_afficher_clicked()
{
        ui->tableView->setModel(tmp.afficher());
}
