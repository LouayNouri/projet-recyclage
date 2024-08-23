#ifndef DRILLDOWNSERIES_H
#define DRILLDOWNSERIES_H

#include <QtCharts/QStackedBarSeries>
#include <QtCore/QMap>

// Use the QtCharts namespace explicitly
QT_CHARTS_USE_NAMESPACE

class DrilldownBarSeries : public QStackedBarSeries
{
    Q_OBJECT
public:
    DrilldownBarSeries(QStringList categories, QObject *parent = 0);

    void mapDrilldownSeries(int index, DrilldownBarSeries *drilldownSeries);

    DrilldownBarSeries *drilldownSeries(int index);

    QStringList categories();

private:
    QMap<int, DrilldownBarSeries *> m_DrilldownSeries;
    QStringList m_categories;
};

#endif // DRILLDOWNSERIES_H
