#ifndef Main_Employee_H
#define Main_Employee_H

#include <QMainWindow>
#include "Employee.h"
#include "forget.h"
#include "recaptcha.h"
#include <QStackedWidget>

class Main_trash;

namespace Ui {
class Main_Employee;
}

class Main_Employee : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_Employee(QWidget *parent = nullptr);
    ~Main_Employee();
    QSqlDatabase db;



protected:
    void closeEvent(QCloseEvent *event) override; // Ensure this matches the base class


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

    void switchToTrash();

    void onCaptchaVerified(bool isValid);

    void performLogin();



private:
    Ui::Main_Employee *ui;
    employe e;
    Main_trash *trashWindow;
    bool captchaSolved;
    recaptcha* recaptchaDialog;


};

#endif // Main_Employee_H
