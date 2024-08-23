
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent)
    : QWidget(parent), chartView(nullptr) {

}

Stats::~Stats() {

}


void Stats::calculateAndDisplayChart() {
    QVector<QPair<QString, int>> posteCountData = getPosteCountDataFromDB();

    if (posteCountData.isEmpty()) {
        QMessageBox::information(this, "No Data", "No data available for statistics.");
        return;
    }

    // Create a chart and add the series
    QtCharts::QChart *chart = new QtCharts::QChart();

    // Create a bar series
    QtCharts::QBarSeries *barSeries = new QtCharts::QBarSeries();

    // Create a bar set for each category with different colors
    for (const auto& pair : posteCountData) {
        QtCharts::QBarSet *barSet = new QtCharts::QBarSet(pair.first);
        *barSet << pair.second;
        barSeries->append(barSet);
    }

    chart->addSeries(barSeries);
    chart->setTitle("Poste Counts");
    chart->createDefaultAxes();

    // Set up a new QMainWindow to display the chart
    QMainWindow *newWindow = new QMainWindow();
    chartView = new QtCharts::QChartView(chart);
    chartView->setMinimumSize(400,400);
    newWindow->setCentralWidget(chartView);
    newWindow->setWindowTitle("Statistics Chart");
    newWindow->show();
}

QVector<QPair<QString, int>> Stats::getPosteCountDataFromDB() {
    QVector<QPair<QString, int>> posteCountData;

    QSqlQuery query;
    query.prepare("SELECT POSTE, COUNT(*) FROM EMPLOYE GROUP BY POSTE");

    if (query.exec()) {
        while (query.next()) {
            QString poste = query.value(0).toString();
            int count = query.value(1).toInt();
            posteCountData.push_back(qMakePair(poste, count));
        }
    } else {

    }

    return posteCountData;
}
