

#ifndef DRILLDOWNCHART_H
#define DRILLDOWNCHART_H

#include <QtCharts/QChart>
#include "drilldownseries.h"

QT_CHARTS_USE_NAMESPACE

//! [1]
class DrilldownChart : public QChart
{
    Q_OBJECT
public:
    explicit DrilldownChart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);

    void changeSeries(DrilldownBarSeries *series);

public Q_SLOTS:
    void handleClicked(int index, QBarSet *barset);

private:
    DrilldownBarSeries *m_currentSeries;
};
//! [1]

#endif // DRILLDOWNCHART_H
