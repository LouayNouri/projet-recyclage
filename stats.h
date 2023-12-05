
#ifndef STATS_H
#define STATS_H

#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QPair>

#include "ui_stats.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Stats;
}
QT_END_NAMESPACE

class Stats : public QWidget {
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = nullptr);
    ~Stats();

    void calculateAndDisplayChart();

private:
    Ui::Stats *ui;  // Use the forward declaration

    QtCharts::QChartView *chartView;

    QVector<QPair<QString, int>> getPosteCountDataFromDB();
};

#endif // STATS_H
