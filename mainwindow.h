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


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);    
    ~MainWindow();
    QSqlDatabase db;

private slots:
    void on_Generat_Button_clicked();
    void on_add_clicked();
    void setupButtonGroup();
    void resetInputs();
    void resetFields();
    void checkCodeInDatabase();
    void on_modify_clicked();
    void goToTab1();
    void goToTab2();
    void goToTab3();
    void goToTab4();
    void deleteRow();
    void exportall();
    void exportdisplayed();
    void updateTypeCheckBox(int state);
    void updateDateCheckBox(int state);
    void updateView_2();
    void sortAscending();
    void sortDescending();
    void on_stats_1_clicked();
    void on_stats_2_clicked();
    void on_stats_3_clicked();
    void on_stats_4_clicked();
    void prepareChart(const QString& materialType, const QString& title, const QColor& color1, const QColor& color2, const QColor& color3);
    QPieSeries* createRecyclableSeries(const QMap<QString, double>& amounts, double totalAmount);
    QPieSeries* createBiodegradableSeries(const QMap<QString, double>& amounts, double totalAmount);
    QPieSeries* createReusableSeries(const QMap<QString, double>& amounts, double totalAmount);
    void on_stack_clicked();
    void onPlusKeyPressed();
    void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

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



      QString mnomemp="localhost";
      quint16 mport=3333;
      QTcpSocket *mSocket;

      Arduino Ar;
      QByteArray data;
      Entreprise En;
        Zone tmp;
   fournisseur F;

};




#endif


