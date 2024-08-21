

#include "drilldownseries.h"

QT_CHARTS_USE_NAMESPACE

DrilldownBarSeries::DrilldownBarSeries(QStringList categories, QObject *parent)
    : QStackedBarSeries(parent)
{
    m_categories = categories;
}

void DrilldownBarSeries::mapDrilldownSeries(int index, DrilldownBarSeries *drilldownSeries)
{
    m_DrilldownSeries[index] = drilldownSeries;
}

DrilldownBarSeries *DrilldownBarSeries::drilldownSeries(int index)
{
    return m_DrilldownSeries[index];
}

QStringList DrilldownBarSeries::categories()
{
    return m_categories;
}

#include "moc_drilldownseries.cpp"
