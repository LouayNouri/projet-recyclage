#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "zone.h"

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
    void on_pushButton_add_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_del_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_lineEdit_recherche_textChanged();

    void on_comboBox_trie_activated();

    void on_pushButton_clicked();

    void on_pushButton_afficher_clicked();

private:
    Ui::MainWindow *ui;
    Zone tmp;
};
#endif // MAINWINDOW_H
