#ifndef DRILLDOWNSERIES_H
#define DRILLDOWNSERIES_H
#include <QtCharts/QStackedBarSeries>
#include <QtCore/QMap>

QT_CHARTS_USE_NAMESPACE

//! [1]
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
//! [1]

#endif // DRILLDOWNSERIES_H
