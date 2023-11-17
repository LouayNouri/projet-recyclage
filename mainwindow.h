#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipement.h"
#include <QDebug>
#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QSound>
#include <QMainWindow>
#include <QPainter>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QTextEdit>
#include "smtp.h"
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
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QFile>
#include "smtp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_afficher_clicked();

    void on_pb_supprimer_2_clicked();

    void on_modifier_2_clicked();

    void on_pb_afficher_3_clicked();

    void on_pb_afficher_4_clicked();

    void on_valider1_2_clicked();

    void on_reset_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);
   void on_comboBox_tri_activated(const QString &arg1);

   void on_statistique_clicked();

   void on_PDF_clicked();

   void on_qrcodegen_clicked();



   void on_send_mail_2_clicked();

private:
    Ui::MainWindow *ui;
    Equipement E;


    QStringList files;

      QString mnomemp="localhost";
      quint16 mport=3333;
      QTcpSocket *mSocket;
};
#endif // MAINWINDOW_H
