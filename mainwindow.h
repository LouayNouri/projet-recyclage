#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"fournisseur.h"

#include <QMainWindow>
#include "employe.h"
#include "forget.h"
#include <QStackedWidget>
#include "smtp.h"
#include "arduino.h"
#include "equipement.h"
#include <QDebug>
#include <QDialog>
#include <QMediaPlayer>
#include <QSound>
#include <QPainter>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QFile>
#include "zone.h"

#include "entreprise.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_afficher_clicked();

    void on_pb_supprimer_2_clicked();

    void on_modifier_2_clicked();

    void on_pb_afficher_3_clicked();

    void on_pb_afficher_4_clicked();


    void on_reset_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_4_clicked();


    QString fetchData();

    void on_exporter_clicked();
    //---------------------------------------

    //---------------------------------------


    void on_pb_ajouter_2_clicked();

    void on_pb_ajouter_3_clicked();

    void on_qrcodegen_clicked();

    void on_PDF_clicked();

    void on_statistique_clicked();

    void on_valider1_2_clicked();

    void on_reset_2_clicked();

    void on_modifier_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_send_mail_2_clicked();



    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();
    //------------------------

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();

    //------------------------

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();


    void on_pb_ajouter_7_n_clicked();

    //------------------

    void on_pushButton_add_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_del_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_lineEdit_recherche_textChanged();

    void on_comboBox_trie_activated();


    void on_pushButton_afficher_clicked();



    //----------------

    void on_pushButton_5_clicked();

    void on_lineEdit_recherche_2_cursorPositionChanged(int arg1, int arg2);
    //--------------------------------------

    //---------------------
    void on_pushButton_ajouter_clicked();

    void on_pb_supprimer_clicked();



    void on_entrer_clicked();



   // void on_pushButton_2_clicked();
    void on_trie_clicked();


    void on_trie_2_clicked();

    void on_trie_3_clicked();

  //  void on_pushButton_clicked();



    void on_le_chercher_textChanged(const QString &text);

    void on_pb_stat_clicked();

    void loadHistoryToTableView();


    //void on_pushButton_3_clicked();
 void on_pb_valider_pdf_clicked();
void on_pushButton_15_clicked();

void on_pushButton_16_clicked();

void on_pushButton_20_clicked();

void on_pushButton_21_clicked();

void on_pushButton_7_clicked();

void on_pushButton_6_clicked();

void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    employe e;
    Equipement E;


    QStringList files;

      QString mnomemp="localhost";
      quint16 mport=3333;
      QTcpSocket *mSocket;

      Arduino Ar;
      QByteArray data;
      Entreprise En;
        Zone tmp;
   fournisseur F;

};
#endif // MAINWINDOW_H
