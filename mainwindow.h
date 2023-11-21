#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QMovie>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QButtonGroup>
#include <QIntValidator>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "donutbreakdownchart.h"
#include "trash.h"
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include "drilldownseries.h"
#include "drilldownchart.h"


QT_CHARTS_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);    
    ~MainWindow();
    void initializeChart();
    void playGif(const QString &gifPath);


public slots:
    void updateview(const QString &text);
    void executeQuery(QString queryStr);



protected:
    bool eventFilter(QObject *obj, QEvent *event);


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


private:
    Ui::MainWindow *ui;
    QButtonGroup *group;
    trash h;
    void showPieChart(int chartType);
    QMainWindow *chartWindow;  // Add this line
    QMainWindow *chartWindow1;
    QMainWindow *chartWindow2;
    QMainWindow *chartWindow3;
    QMainWindow *chartWindow4;
    DrilldownChart *drilldownChart;
    QChartView *chartView;
    QMovie *movie;


};




#endif


