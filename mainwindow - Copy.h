#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entreprise.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();
     //void on_TricomboBoxReglement_currentTextChanged(const QString );
     void on_input_Rechercher_textChanged(const QString );

     void on_tier_clicked();

     void on_chercher_clicked();
     void on_pb_stats_clicked();
     void on_exportButton_clicked();
     void on_findNearestZoneButton_clicked();

private:
    Ui::MainWindow *ui;
    Entreprise E;
};

#endif // MAINWINDOW_H
