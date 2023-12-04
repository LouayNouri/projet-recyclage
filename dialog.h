#ifndef DIALOG_H
#define DIALOG_H

#include"fournisseur.h"
#include <QMainWindow>
#include <QtSql>
#include<QDialog>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int m_cin,QWidget *parent = nullptr);
    ~Dialog();

private slots:




    void on_modifier_clicked();

private:
    int m_cin;
    Ui::Dialog *ui;

       fournisseur F;


};

#endif // DIALOG_H
