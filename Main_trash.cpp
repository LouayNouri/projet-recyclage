#include "Main_trash.h"
#include "ui_Main_trash.h"
#include "connection.h"
#include "TTP.h"
#include <cstdlib>
#include "QString"
#include "QMessageBox"
#include <QtSql>
#include <QTableView>
#include <QComboBox>
#include <QSqlDatabase>
#include <QButtonGroup>
#include <QAbstractButton>
#include <QDebug>
#include <QIntValidator>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlTableModel>
#include <QApplication>
#include <QMovie>
#include <QItemSelectionModel>
#include <QKeyEvent>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSettings>
#include <QQuickStyle>
#include <iostream>



Main_trash::Main_trash(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_trash)

{
    qDebug("Main_Trash Launched");
    ui->setupUi(this);
    c = new connection();
    bool test = c->createconnect();
    if (!test) {
        qDebug() << "Database connection failed";
    }

//    ttsWindow = new TextToSpeechWindow(this); // Add this line
//    ttsWindow->show();
    this->move(0,0);
    movie = new QMovie(this);
    setupButtonGroup();
    QList<QPushButton*> addButtons = {ui->add1, ui->add2, ui->add3, ui->add4};
    for(QPushButton* button : addButtons) {
        connect(button, SIGNAL(clicked()), this, SLOT(goToTab1()));
    }
    QList<QPushButton*> displayButtons = {ui->display1, ui->display2, ui->display3, ui->display4};
    for(QPushButton* button : displayButtons) {
        connect(button, SIGNAL(clicked()), this, SLOT(goToTab2()));
    }
    QList<QPushButton*>rechButtons = {ui->rech1, ui->rech2, ui->rech3, ui->rech4};
    for(QPushButton* button : rechButtons) {
        connect(button, SIGNAL(clicked()), this, SLOT(goToTab3()));
    }
    QList<QPushButton*> statButtons = {ui->stat1, ui->stat2, ui->stat3, ui->stat4};
    for(QPushButton* button : statButtons) {
        connect(button, SIGNAL(clicked()), this, SLOT(goToTab4()));
    }

    connect(ui->delete_2, SIGNAL(clicked()), this, SLOT(deleteRow()));
    ui->Generated_code->setValidator(new QIntValidator(this));
    ui->Generated_code->setMaxLength(5);
    connect(ui->reset, SIGNAL(clicked()), this, SLOT(resetInputs()));
    connect(ui->reset_2, SIGNAL(clicked()), this, SLOT(resetFields()));
    connect(ui->check_button, SIGNAL(clicked()), this, SLOT(checkCodeInDatabase()));
    connect(ui->Delete_zone, SIGNAL(textChanged(const QString &)), this, SLOT(updateview(const QString &)));
    connect(ui->exportall, SIGNAL(clicked()), this, SLOT(exportall()));
    connect(ui->exportdisplayed, SIGNAL(clicked()), this, SLOT(exportdisplayed()));
    connect(ui->typeCheckBox, SIGNAL(stateChanged(int)), this, SLOT(updateTypeCheckBox(int)));
    connect(ui->dateCheckBox, SIGNAL(stateChanged(int)), this, SLOT(updateDateCheckBox(int)));
    connect(ui->metal_2, SIGNAL(toggled(bool)), this, SLOT(updateView_2()));
    connect(ui->glass_2, SIGNAL(toggled(bool)), this, SLOT(updateView_2()));
    connect(ui->paper_2, SIGNAL(toggled(bool)), this, SLOT(updateView_2()));
    connect(ui->plastic_2, SIGNAL(toggled(bool)), this, SLOT(updateView_2()));
    connect(ui->date_2, SIGNAL(dateChanged(const QDate &)), this, SLOT(updateView_2()));
    connect(ui->typeCheckBox, SIGNAL(stateChanged(int)), this, SLOT(updateView_2()));
    connect(ui->dateCheckBox, SIGNAL(stateChanged(int)), this, SLOT(updateView_2()));
    connect(ui->recyclableCheckBox, SIGNAL(toggled(bool)), this, SLOT(updateView_2()));
    connect(ui->biodegradableCheckBox, SIGNAL(toggled(bool)), this, SLOT(updateView_2()));
    connect(ui->reusableCheckBox, SIGNAL(toggled(bool)), this, SLOT(updateView_2()));
    updateView_2();
    connect(ui->ascendingButton, SIGNAL(clicked()), this, SLOT(sortAscending()));
    connect(ui->descendingButton, SIGNAL(clicked()), this, SLOT(sortDescending()));
    connect(ui->stats_1, &QPushButton::clicked, this, &Main_trash::on_stats_1_clicked);
    disconnect(ui->stats_1, &QPushButton::clicked, this, &Main_trash::on_stats_1_clicked);
    connect(ui->stats_2, &QPushButton::clicked, this, &Main_trash::on_stats_2_clicked);
    disconnect(ui->stats_2, &QPushButton::clicked, this, &Main_trash::on_stats_2_clicked);
    connect(ui->stats_3, &QPushButton::clicked, this, &Main_trash::on_stats_3_clicked);
    disconnect(ui->stats_3, &QPushButton::clicked, this, &Main_trash::on_stats_3_clicked);
    connect(ui->stats_4, &QPushButton::clicked, this, &Main_trash::on_stats_4_clicked);
    disconnect(ui->stats_4, &QPushButton::clicked, this, &Main_trash::on_stats_4_clicked);

    connect(ui->stack, &QPushButton::clicked, this, &Main_trash::on_stack_clicked);
    disconnect(ui->stack, &QPushButton::clicked, this, &Main_trash::on_stack_clicked);
    ui->stats_1->installEventFilter(this);
    ui->stats_2->installEventFilter(this);
    ui->stats_3->installEventFilter(this);
    ui->stats_4->installEventFilter(this);
    ui->stack->installEventFilter(this);
    ui->mecha->hide();
    ui->papcha->hide();
    ui->placha->hide();
    ui->glacha->hide();
    ui->stacha->hide();
    playGif("C:/Users/MEGA-PC/Desktop/QT-test/Project_2/FF.gif");
    ui->view_2->setSelectionBehavior(QAbstractItemView::SelectItems);
    this->installEventFilter(this);
    ui->view_2->installEventFilter(this);
    connect(ui->view_2->selectionModel(), &QItemSelectionModel::selectionChanged, this, &Main_trash::onSelectionChanged);
    ui->bio->setStyleSheet("QCheckBox { color: white; }"
                            "QCheckBox::indicator { width: 30px; height: 30px; }"
                            "QCheckBox::indicator:checked { image: url(C:/Users/MEGA-PC/Desktop/QT-test/Project_2/vecteezy_cheque_1200261.png); }"
                            );
    ui->recyclable->setStyleSheet("QCheckBox { color: white; }"
                            "QCheckBox::indicator { width: 30px; height: 30px;}"
                            "QCheckBox::indicator:checked { image: url(C:/Users/MEGA-PC/Desktop/QT-test/Project_2/vecteezy_cheque_1200261.png); }"
                            );
    ui->reusable->setStyleSheet("QCheckBox::indicator { width: 30px; height: 30px;}"
                            "QCheckBox::indicator:checked { image: url(C:/Users/MEGA-PC/Desktop/QT-test/Project_2/vecteezy_cheque_1200261.png); }"
                                "QCheckBox { color: white; }"
                            );
    ui->biodegradableCheckBox->setStyleSheet("QCheckBox::indicator { width: 20px; height: 20px;}"
                            "QCheckBox::indicator:checked { image: url(C:/Users/MEGA-PC/Desktop/QT-test/Project_2/vecteezy_cheque_1200261.png); }"
                                             "QCheckBox { color: white; }"
                            );
    ui->recyclableCheckBox->setStyleSheet("QCheckBox::indicator { width: 20px; height: 20px;}"
                            "QCheckBox::indicator:checked { image: url(C:/Users/MEGA-PC/Desktop/QT-test/Project_2/vecteezy_cheque_1200261.png); }"
                                          "QCheckBox { color: white; }"
                            );
    ui->reusableCheckBox->setStyleSheet("QCheckBox::indicator { width: 20px; height: 20px; }"
                            "QCheckBox::indicator:checked { image: url(C:/Users/MEGA-PC/Desktop/QT-test/Project_2/vecteezy_cheque_1200261.png); }"
                                        "QCheckBox { color: white; }"
                            );

       ui->dock->hide();

}



void Main_trash::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
    select = ui->view_2->selectionModel();
    onPlusKeyPressed();

}


void Main_trash::onPlusKeyPressed() {
    double sum = 0;

    // Get the selected cells
    QModelIndexList selectedCells = select->selectedIndexes();

    qDebug() << "Number of selected cells: " << selectedCells.count();

    // Check if the number of selected cells is even
    if (selectedCells.count() % 2 != 0) {
        QMessageBox::information(this, "Error", "Please select both a unit cell and its corresponding value cell.");
        return;
    }

    // Iterate over the selected cells
    for (int i = 0; i < selectedCells.count(); i += 2) { // Assuming every two cells form a pair
        QModelIndex indexUnit = selectedCells.at(i);
        QModelIndex indexValue = selectedCells.at(i+1);

        // Get the data in the cell
        QString unit = indexUnit.data().toString();
        double cellData = indexValue.data().toDouble();

        // Convert the cell data to kilograms based on the unit
        if (unit == "Gram (g)") {
            cellData /= 1000; // convert grams to kilograms
        } else if (unit == "Tonne (t)") {
            cellData *= 1000; // convert tonnes to kilograms
        }

        qDebug() << "Cell data: " << cellData << " " << unit;

        // Add the cell data to the sum
        sum += cellData;
    }

    qDebug() << "Sum: " << sum;

    // Display the sum in a QMessageBox
    QMessageBox::information(this, "Sum", "The sum is: " + QString::number(sum) + " kg");
}






void Main_trash::updateView_2() {
    QString queryStr = "SELECT * FROM trash WHERE 1=1 ";
    select = ui->view_2->selectionModel();

    if (ui->typeCheckBox->isChecked()) {
        if (ui->metal_2->isChecked()) {
            queryStr += "AND MATERIAL_TYPE LIKE 'Metal%' ";
        } else if (ui->glass_2->isChecked()) {
            queryStr += "AND MATERIAL_TYPE LIKE 'Glass%' ";
        } else if (ui->paper_2->isChecked()) {
            queryStr += "AND MATERIAL_TYPE LIKE 'Paper%' ";
        } else if (ui->plastic_2->isChecked()) {
            queryStr += "AND MATERIAL_TYPE LIKE 'Plastic%' ";
        }
    }

    if (ui->dateCheckBox->isChecked()) {
        QDate date = ui->date_2->date();
        QString dateStr = date.toString("yyyy-MM-dd");
        queryStr += QString("AND TO_DATE(TO_CHAR(DATE_ADDED, 'YYYY-MM-DD'), 'YYYY-MM-DD') = TO_DATE('%1', 'YYYY-MM-DD') ").arg(dateStr);
    }

    if (ui->recyclableCheckBox->isChecked() && ui->reusableCheckBox->isChecked() && ui->biodegradableCheckBox->isChecked()) {
        queryStr += "ORDER BY CASE WHEN properties LIKE '%Recyclable%' AND properties LIKE '%Reusable%' AND properties LIKE '%Biodegradable%' THEN 0 ELSE 1 END, properties";
    } else if (ui->recyclableCheckBox->isChecked() && ui->reusableCheckBox->isChecked()) {
        queryStr += "ORDER BY CASE WHEN properties LIKE '%Recyclable%' AND properties LIKE '%Reusable%' THEN 0 ELSE 1 END, properties";
    } else if (ui->recyclableCheckBox->isChecked() && ui->biodegradableCheckBox->isChecked()) {
        queryStr += "ORDER BY CASE WHEN properties LIKE '%Recyclable%' AND properties LIKE '%Biodegradable%' THEN 0 ELSE 1 END, properties";
    } else if (ui->reusableCheckBox->isChecked() && ui->biodegradableCheckBox->isChecked()) {
        queryStr += "ORDER BY CASE WHEN properties LIKE '%Biodegradable%' AND properties LIKE '%Reusable%' THEN 0 ELSE 1 END, properties";
    } else if (ui->recyclableCheckBox->isChecked()) {
        queryStr += "ORDER BY CASE WHEN properties LIKE '%Recyclable%' THEN 0 ELSE 1 END, properties";
    } else if (ui->biodegradableCheckBox->isChecked()) {
        queryStr += "ORDER BY CASE WHEN properties LIKE '%Biodegradable%' THEN 0 ELSE 1 END, properties";
    } else if (ui->reusableCheckBox->isChecked()) {
        queryStr += "ORDER BY CASE WHEN properties LIKE '%Reusable%' THEN 0 ELSE 1 END, properties";
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();
    model->setQuery(query);
    ui->view_2->setModel(model);
    ui->view_2->resizeColumnsToContents();
    ui->view_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QString data;
    for(int row = 0; row < model->rowCount(); ++row) {
        for(int col = 0; col < model->columnCount(); ++col) {
            data += model->data(model->index(row, col)).toString() + "\t";
        }
        data += "\n";
    }
    emit viewUpdated(data);



}

void Main_trash::playGif(const QString &gifPath)
{
    movie->setFileName(gifPath);
    ui->GIF->setMovie(movie);
    ui->GIF->setScaledContents(true);
    movie->start();


}


bool Main_trash::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->stats_1) {
        if (event->type() == QEvent::HoverEnter) {
            // The mouse has entered the button.
            // Show the QLabel here.
            ui->mecha->show();
            return true;
        } else if (event->type() == QEvent::HoverLeave) {
            // The mouse has left the button.
            // Hide the QLabel here.
            ui->mecha->hide();
            return true;
        }
    }
        if (obj == ui->stats_2) {
            if (event->type() == QEvent::HoverEnter) {
                // The mouse has entered the button.
                // Show the QLabel here.
                ui->glacha->show();
                return true;
            } else if (event->type() == QEvent::HoverLeave) {
                // The mouse has left the button.
                // Hide the QLabel here.
                ui->glacha->hide();
                return true;
            }
        }
            if (obj == ui->stats_3) {
                if (event->type() == QEvent::HoverEnter) {
                    // The mouse has entered the button.
                    // Show the QLabel here.
                    ui->papcha->show();
                    return true;
                } else if (event->type() == QEvent::HoverLeave) {
                    // The mouse has left the button.
                    // Hide the QLabel here.
                    ui->papcha->hide();
                    return true;
                }
            }
                if (obj == ui->stats_4) {
                    if (event->type() == QEvent::HoverEnter) {
                        // The mouse has entered the button.
                        // Show the QLabel here.
                        ui->placha->show();
                        return true;
                    } else if (event->type() == QEvent::HoverLeave) {
                        // The mouse has left the button.
                        // Hide the QLabel here.
                        ui->placha->hide();
                        return true;
                    }
                }

                if (obj == ui->stack) {
                    if (event->type() == QEvent::HoverEnter) {
                        // The mouse has entered the button.
                        // Show the QLabel here.
                        ui->stacha->show();
                        return true;
                    } else if (event->type() == QEvent::HoverLeave) {
                        // The mouse has left the button.
                        // Hide the QLabel here.
                        ui->stacha->hide();
                        return true;
                    }
                }

                if (event->type() == QEvent::KeyPress) {
                    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
                    if (keyEvent->key() == Qt::Key_Escape) {
                        // Hide the window
                        QWidget *window = qobject_cast<QWidget *>(obj);
                        if (window) {
                            window->hide();
                        }
                        // Show the main window
                        this->show();
                        return true;
                    }
                    else if (keyEvent->key() == Qt::Key_F11) {
                        // Toggle fullscreen
                        QWidget *window = qobject_cast<QWidget *>(obj);
                        if (window) {
                            if (window->isFullScreen()) {
                                window->showNormal();
                            } else {
                                window->showFullScreen();
                            }
                        }
                        return true;
                    }
                }
                if (obj == ui->view_2 && event->type() == QEvent::KeyPress) {
                    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
                    if (keyEvent->key() == Qt::Key_A) {
                        qDebug() << "'A' key pressed";
                        updateView_2();
                        onPlusKeyPressed();
                        return true;
                    }
                }




                    if (event->type() == QEvent::HoverMove) {
                        QHoverEvent *hoverEvent = static_cast<QHoverEvent *>(event);
                        int x = hoverEvent->pos().x();
                        int y = hoverEvent->pos().y();

                        // Check if the mouse is in the desired area
                        if (x >= 0 && x <= 1350 && y >= 0 && y <= 30) {
                            // The mouse is in the top side of the screen.
                            // Show the dock widget here.
                            ui->dock->show();
                        } else {
                            // The mouse is not in the top side of the screen.
                            // Hide the dock widget here.
                            ui->dock->hide();
                        }
                        return true;
                    }





    // Standard event processing
    return QObject::eventFilter(obj, event);
}




Main_trash::~Main_trash()
{
    delete ui;
}



void Main_trash::initializeChart()
{
    // Define categories
    const QStringList months = {
    "Jan", "Feb", "Mars", "April", "May", "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec"
    };
    const QStringList weeks = {
        "week 1", "week 2", "week 3", "week 4"
    };
    const QStringList plants = {
        "Metal", "Glass", "Paper", "Plastic"
    };

    // Initialize chart
    drilldownChart = new DrilldownChart();
    drilldownChart->setAnimationOptions(QChart::SeriesAnimations);

    // Create drilldown structure
    DrilldownBarSeries *seasonSeries = new DrilldownBarSeries(months, drilldownChart);
    seasonSeries->setName("Trash Amount per month ");

    // Each month in season series has drilldown series for weekly data
    for (int month = 0; month < months.count(); month++) {

        // Create drilldown series for every week
        DrilldownBarSeries *weeklySeries = new DrilldownBarSeries(weeks, drilldownChart);
        seasonSeries->mapDrilldownSeries(month, weeklySeries);

        // Drilling down from weekly data brings us back to season data.
        for (int week = 0; week < weeks.count(); week++) {
            weeklySeries->mapDrilldownSeries(week, seasonSeries);
            weeklySeries->setName(QString("Trash Amount per week - " + months.at(month)));
        }

        // Use clicked signal to implement drilldown
        QObject::connect(weeklySeries, &DrilldownBarSeries::clicked,
                         drilldownChart, &DrilldownChart::handleClicked);
    }

    // Enable drilldown from season series using clicked signal
    QObject::connect(seasonSeries, &DrilldownBarSeries::clicked,
                     drilldownChart, &DrilldownChart::handleClicked);

    // Fill monthly and weekly series with data
    for (const QString &plant : plants) {
        QSqlQuery query;
        query.exec(QString("SELECT MATERIAL_TYPE, TO_CHAR(DATE_ADDED, 'MM-YYYY') AS MONTH_YEAR, SUM(CASE WHEN UNIT = 'Tonne (t)' THEN AMOUNT * 1000 WHEN UNIT = 'Gram (g)' THEN AMOUNT / 1000 ELSE AMOUNT END) AS TOTAL_AMOUNT_KG FROM trash WHERE MATERIAL_TYPE = '%1' GROUP BY MATERIAL_TYPE, TO_CHAR(DATE_ADDED, 'MM-YYYY') ORDER BY TOTAL_AMOUNT_KG ASC").arg(plant));

        QBarSet *monthlyCrop = new QBarSet(plant);
        for (int month = 0; month < months.count(); month++) {
            QBarSet *weeklyCrop = new QBarSet(plant);
            for (int week = 0; week < weeks.count(); week++)
                *weeklyCrop << (qrand() % 20);
            // Get the drilldown series from season series and add crop to it.
            seasonSeries->drilldownSeries(month)->append(weeklyCrop);
            *monthlyCrop << weeklyCrop->sum();
        }
        seasonSeries->append(monthlyCrop);
    }

    // Show season series in initial view
    drilldownChart->changeSeries(seasonSeries);
    drilldownChart->setTitle(seasonSeries->name());

    drilldownChart->axisX()->setGridLineVisible(false);
    drilldownChart->legend()->setVisible(true);
    drilldownChart->legend()->setAlignment(Qt::AlignBottom);
    QMainWindow *chartWindow = new QMainWindow(this);
    QChartView *chartView = new QChartView(drilldownChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartWindow->setCentralWidget(chartView);
    chartWindow->resize(1200, 700);
    chartWindow->show();
    chartWindow->installEventFilter(this);
    chartWindow->show();
}





void Main_trash::on_stack_clicked()
{
    initializeChart();
}



QPieSeries* Main_trash::createRecyclableSeries(const QMap<QString, double>& amounts, double totalAmount) {
    QPieSeries *series = new QPieSeries();
    series->setName("Recyclable");
    series->append("Recyclable Only", amounts["Recyclable "] / totalAmount * 100.0);
    series->append("Recyclable & Bio", (amounts["Recyclable Biodegradable"] + amounts["Biodegradable Recyclable"])  / totalAmount * 100.0);
    return series;
}

QPieSeries* Main_trash::createBiodegradableSeries(const QMap<QString, double>& amounts, double totalAmount) {
    QPieSeries *series = new QPieSeries();
    series->setName("Biodegradable");
    series->append("Bio Only", amounts["Biodegradable "] / totalAmount * 100.0);
    series->append("Biodegradable & Reusable", (amounts["Biodegradable Reusable "] + amounts["Reusable Biodegradable "]) / totalAmount * 100.0);
    return series;
}

QPieSeries* Main_trash::createReusableSeries(const QMap<QString, double>& amounts, double totalAmount) {
    QPieSeries *series = new QPieSeries();
    series->setName("Reusable");
    series->append("Reusable Only", amounts["Reusable "] / totalAmount * 100.0);
    series->append("Reusa & Recy", (amounts["Reusable Recyclable "] + amounts["Recyclable Reusable "]) / totalAmount * 100.0);
    series->append("Reusa & Bio & Recy", (amounts["Reusable Biodegradable Recyclable "] + amounts["Reusable Recyclable Reusable "]+amounts["Biodegradable Reusable Recyclable "] + amounts["Biodegradable Recyclable Reusable "]+amounts["Recyclable Biodegradable Reusable "] + amounts["Recyclable Reusable Biodegradable "]) / totalAmount * 100.0);
    return series;
}



void Main_trash::prepareChart(const QString& materialType, const QString& title, const QColor& color1, const QColor& color2, const QColor& color3) {
    QSqlQuery query;
    double totalAmount = 0.0;
    QMap<QString, double> amounts;

    query.prepare("SELECT PROPERTIES, COUNT(*) as total_count FROM Trash WHERE MATERIAL_TYPE = :materialType GROUP BY PROPERTIES");

    query.bindValue(":materialType", materialType);

    if (query.exec()) {
        // Calculate the total amount and store the amounts for each property type
        while (query.next()) {
            QString properties = query.value(0).toString();
            double amount = query.value(1).toDouble();
            amounts[properties] = amount;
            totalAmount += amount;
        }


        // Calculate the percentages and append them to the series
        QPieSeries *series1 = createRecyclableSeries(amounts, totalAmount);
        QPieSeries *series2 = createBiodegradableSeries(amounts, totalAmount);
        QPieSeries *series3 = createReusableSeries(amounts, totalAmount);

        DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
        donutBreakdown->setAnimationOptions(QChart::AllAnimations);
        donutBreakdown->setTitle(title);
        donutBreakdown->legend()->setAlignment(Qt::AlignRight);
        donutBreakdown->addBreakdownSeries(series1, color1);
        donutBreakdown->addBreakdownSeries(series2, color2);
        donutBreakdown->addBreakdownSeries(series3, color3);

        QMainWindow *chartWindow = new QMainWindow(this);
        QChartView *chartView = new QChartView(donutBreakdown);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartWindow->setCentralWidget(chartView);
        chartWindow->resize(1200, 700);
        chartWindow->show();
        chartWindow->installEventFilter(this);
        chartWindow->show();

    }
}



void Main_trash::showPieChart(int chartType)
{


    switch(chartType) {
        case 1:
            prepareChart("Metal", "Metal", QColor("#63666A"), QColor("#b2967d"), QColor("#bfc0c0"));
            break;
        case 2:
            prepareChart("Glass", "Glass", QColor("#004b23"), QColor("#80b918"), QColor("#008000"));
            break;
        case 3:
            prepareChart("Paper", "Paper", QColor("#644234"), QColor("#815f51"), QColor("#cba48b"));
            break;
        case 4:
            prepareChart("Plastic", "Plastic", QColor("#53599a"), QColor("#0077b6"), QColor("#5bc0be"));
            break;

    }

}



void Main_trash::on_stats_1_clicked()
{
    showPieChart(1);
}

void Main_trash::on_stats_2_clicked()
{
    showPieChart(2);
}

void Main_trash::on_stats_3_clicked()
{
    showPieChart(3);
}

void Main_trash::on_stats_4_clicked()
{
    showPieChart(4);
}






void Main_trash::sortAscending() {
    QString queryStr = "SELECT * FROM trash ORDER BY CASE WHEN unit = 'Tonne (t)' THEN amount * 1000 WHEN unit = 'Gram (g)' THEN amount / 1000 ELSE amount END ASC";
    executeQuery(queryStr);
}

void Main_trash::sortDescending() {
    QString queryStr = "SELECT * FROM trash ORDER BY CASE WHEN unit = 'Tonne (t)' THEN amount * 1000 WHEN unit = 'Gram (g)' THEN amount / 1000 ELSE amount END DESC";
    executeQuery(queryStr);
}

void Main_trash::executeQuery(QString queryStr) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();
    model->setQuery(query);
    ui->view_2->setModel(model);

    ui->view_2->resizeColumnsToContents();

    ui->view_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



void Main_trash::updateTypeCheckBox(int state) {
    bool enable = (state == Qt::Checked);
    ui->metal_2->setEnabled(enable);
    ui->plastic_2->setEnabled(enable);
    ui->glass_2->setEnabled(enable);
    ui->paper_2->setEnabled(enable);
}

void Main_trash::updateDateCheckBox(int state) {
    ui->date_2->setEnabled(state == Qt::Checked);
}


void Main_trash::updateview(const QString &text) {
    if (text == "ALL") {
        // Display all data
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT * FROM trash");
        query.exec();
        model->setQuery(query);
        ui->view->setModel(model);
    } else {
        // Display data based on the code
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT * FROM trash WHERE code LIKE :code");
        query.bindValue(":code", text + "%");
        query.exec();
        model->setQuery(query);
        ui->view->setModel(model);
        ui->view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    }
}

void Main_trash::deleteRow()
{
    int code = ui->Delete_zone->text().toInt();
    bool success = h.supprimer(code);
    if (success) {
        QMessageBox::information(this, "Success", "Row deleted successfully.");
    } else {
        QMessageBox::warning(this, "Failure", "No row found with the given code.");
    }
}

void Main_trash::goToTab1()
{
    ui->tabWidget->setCurrentIndex(0);
}

void Main_trash::goToTab2()
{
    ui->tabWidget->setCurrentIndex(1);
}

void Main_trash::goToTab3()
{
    ui->tabWidget->setCurrentIndex(2);
}

void Main_trash::goToTab4()
{
    ui->tabWidget->setCurrentIndex(3);
}



void Main_trash::on_Generat_Button_clicked()
{
    QString randomCode;

    do {
        randomCode = QString::number(rand());
        randomCode[0] = '1' + rand() % 9;
    } while (randomCode.length() < 5);

    ui->Generated_code->setText(randomCode);


}

void Main_trash::setupButtonGroup() {
    group = new QButtonGroup(this);
    group->addButton(ui->glass);
    group->addButton(ui->paper);
    group->addButton(ui->plastic);
    group->addButton(ui->metal);
}


void Main_trash::on_add_clicked()
{
    QString codeeString = ui->Generated_code->text();
    if (codeeString.length() != 5) {
        QMessageBox::information(nullptr, QObject::tr("Error"),
                                 QObject::tr("Please enter a 5-digit code."), QMessageBox::Ok);
        return;}
    QRadioButton *selectedButton = qobject_cast<QRadioButton*>(group->checkedButton());
    QString ty = selectedButton->text();

    QString un = ui->unit->currentText();
    double am = ui->amount->value();
    QString pr;

    if (ui->recyclable->isChecked()) {
        pr.append(ui->recyclable->text() + " ");
    }

    if (ui->bio->isChecked()) {
        pr.append(ui->bio->text() + " ");
    }

    if (ui->reusable->isChecked()) {
        pr.append(ui->reusable->text() + " ");
    }


    QDate da = ui->date->selectedDate();
    QString codeString = ui->Generated_code->text().trimmed();
    int co = codeString.toInt();


    trash h(ty, un, am, pr, da, co);

    bool test = h.ajouter();
    if (test) {

        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Record added successfully."), QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                              QObject::tr("Failed to add the record. Record may already exist."),
                              QMessageBox::Ok);
    }
}

void Main_trash::checkCodeInDatabase() {
    QString codeString = ui->Generated_code->text();
    if (codeString.length() != 5) {
        QMessageBox::information(nullptr, QObject::tr("Error"),
                                 QObject::tr("Please enter a 5-digit code."), QMessageBox::Ok);
        return;
    }

    int code = codeString.toInt();
    QSqlQuery query;
    query.prepare("SELECT * FROM trash WHERE CODE = :co");
    query.bindValue(":co", code);
    if (!query.exec() || !query.next()) {
        QMessageBox::information(nullptr, QObject::tr("Error"),
                                 QObject::tr("No record found with the entered code."), QMessageBox::Ok);
        return;
    }

    // If a record is found, fill the form with the record data.
    QString type = query.value("MATERIAL_TYPE").toString();
    QString unit = query.value("UNIT").toString();
    double amount = query.value("AMOUNT").toDouble();
    QString properties = query.value("PROPERTIES").toString();
    QDate date = query.value("DATE_ADDED").toDate();

    // Set the form fields.
    // For the radio buttons, you need to find the button with the same text as `type` and check it.
    QList<QAbstractButton *> buttons = group->buttons();
    for (int i = 0; i < buttons.size(); ++i) {
        QRadioButton *button = qobject_cast<QRadioButton *>(buttons[i]);
        if (button && button->text() == type) {
            button->setChecked(true);
            break;
        }
    }

    // For the combo box, you need to find the index of the item with the same text as `unit` and set the current index to it.
    int index = ui->unit->findText(unit);
    if (index != -1) {
        ui->unit->setCurrentIndex(index);
    }

    // For the double spin box, you can simply set the value.
    ui->amount->setValue(amount);

    // For the checkboxes, you need to check if `properties` contains the text of each checkbox and check or uncheck it accordingly.
    ui->recyclable->setChecked(properties.contains(ui->recyclable->text()));
    ui->bio->setChecked(properties.contains(ui->bio->text()));
    ui->reusable->setChecked(properties.contains(ui->reusable->text()));

    // For the date edit, you can simply set the date.
    ui->date->setSelectedDate(date);
}

void Main_trash::exportall() {
    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", "", "*.pdf");
    if (fileName.isEmpty()) return; // User canceled the dialog

    QPdfWriter pdf(fileName);
    QPainter painter(&pdf);

    painter.setPen(Qt::red);
    painter.setFont(QFont("Arial", 40));
    painter.drawText(2500,2700,"-List of Submits-");

    painter.drawPixmap(QRect(2900,80,4000,1800),QPixmap("C:/Users/MEGA-PC/Desktop/QT-test/Project_2/im1.png"));
    painter.drawPixmap(QRect(7500,-200,2300,2000),QPixmap("C:/Users/MEGA-PC/Desktop/QT-test/Project_2/6430960.jpg"));
    painter.drawPixmap(QRect(0,-200,2300,2000),QPixmap("C:/Users/MEGA-PC/Desktop/QT-test/Project_2/6430960.jpg"));


    painter.setPen(Qt::green);
    painter.setFont(QFont("Arial bold", 15));
    painter.drawText(200,3300,"Material");
    painter.drawText(1300,3300,"Unit");
    painter.drawText(2200,3300,"Amount");
    painter.drawText(4200,3300,"Properties");
    painter.drawText(7000,3300,"Date");
    painter.drawText(8700,3300,"Code");

    QSqlQuery query;
    query.prepare("select * from trash");
    query.exec();

    int i = 4000;
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));
    while (query.next()) {
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1000,i,query.value(1).toString());
        painter.drawText(2500,i,query.value(2).toString());
        painter.drawText(3200,i,query.value(3).toString());
        painter.drawText(6500,i,query.value(4).toString());
        painter.drawText(8700,i,query.value(5).toString());

        i = i + 500;
    }

    h.afficher();
    QMessageBox::information(nullptr,QObject::tr("Export PDF"),QObject::tr("Exported successfully"),QMessageBox::Cancel);
}


void Main_trash::exportdisplayed() {
    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", "", "*.pdf");
    if (fileName.isEmpty()) return; // User canceled the dialog

    QPdfWriter pdf(fileName);
    QPainter painter(&pdf);

    painter.setPen(Qt::red);
    painter.setFont(QFont("Arial", 40));
    painter.drawText(2300,2700,"-Filtered Submits-");

    painter.drawPixmap(QRect(2900,80,4000,1800),QPixmap("C:/Users/MEGA-PC/Desktop/QT-test/Project_2/im1.png"));
    painter.drawPixmap(QRect(7500,-100,2300,2000),QPixmap("C:/Users/MEGA-PC/Desktop/QT-test/Project_2/6356816.jpg"));
    painter.drawPixmap(QRect(0,-100,2300,2000),QPixmap("C:/Users/MEGA-PC/Desktop/QT-test/Project_2/6356816.jpg"));

    painter.setPen(Qt::green);
    painter.setFont(QFont("Arial bold", 15));
    painter.drawText(200,3300,"Material");
    painter.drawText(1300,3300,"Unit");
    painter.drawText(2200,3300,"Amount");
    painter.drawText(4200,3300,"Properties");
    painter.drawText(7000,3300,"Date");
    painter.drawText(8700,3300,"Code");

    QAbstractItemModel *model = ui->view->model();
    int rows = model->rowCount();

    int i = 4000;
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));
    for (int r = 0; r < rows; ++r) {
        painter.drawText(200,i,model->data(model->index(r, 0)).toString());
        painter.drawText(1000,i,model->data(model->index(r, 1)).toString());
        painter.drawText(2500,i,model->data(model->index(r, 2)).toString());
        painter.drawText(3200,i,model->data(model->index(r, 3)).toString());
        painter.drawText(6500,i,model->data(model->index(r, 4)).toString());
        painter.drawText(8700,i,model->data(model->index(r, 5)).toString());

        i = i + 500;
    }

    // Assuming h is an object in your class with a method afficher()
    h.afficher();

    QMessageBox::information(nullptr,QObject::tr("Export PDF"),QObject::tr("Exported successfully"),QMessageBox::Cancel);
}


void Main_trash::resetInputs() {

    ui->glass->setChecked(false);
    ui->paper->setChecked(false);
    ui->plastic->setChecked(false);
    ui->metal->setChecked(false);
    ui->unit->setCurrentIndex(0);
    ui->amount->setValue(0);
    ui->recyclable->setChecked(false);
    ui->bio->setChecked(false);
    ui->reusable->setChecked(false);
    ui->date->setSelectedDate(QDate::currentDate());
        ui->Generated_code->clear();
}


void Main_trash::resetFields() {
    ui->Delete_zone->clear();
    ui->view->setModel(NULL);
}


void Main_trash::on_modify_clicked()
{
    // Get the values from the form fields.
    QRadioButton *selectedButton = qobject_cast<QRadioButton*>(group->checkedButton());
    QString type = selectedButton->text();
    QString ty = type;
    QString un = ui->unit->currentText();
    double am = ui->amount->value();
    QString pr;

    if (ui->recyclable->isChecked()) {
        pr.append(ui->recyclable->text() + " ");
    }

    if (ui->bio->isChecked()) {
        pr.append(ui->bio->text() + " ");
    }

    if (ui->reusable->isChecked()) {
        pr.append(ui->reusable->text() + " ");
    }

    QDate da = ui->date->selectedDate();
    QString codeString = ui->Generated_code->text().trimmed();
    int co = codeString.toInt();

    // Create a new trash object with the form values.
    trash h(ty, un, am, pr, da, co);

    // Call the modifier function.
    bool test = h.modifier();
    if (test) {
        // If the modification was successful, show a success message.
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Record modified successfully."), QMessageBox::Ok);
    } else {
        // If the modification failed, show an error message.
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Failed to modify the record."), QMessageBox::Ok);
    }


}

