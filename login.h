#ifndef LOGIN_H
#define LOGIN_H
#include"mainwindow.h"
#include <QDialog>


namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    MainWindow *mainWindow;
    fournisseur F;
};

#endif // LOGIN_H