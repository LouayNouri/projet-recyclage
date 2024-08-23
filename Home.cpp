#include "Home.h"
#include "ui_Home.h"
#include "Main_Employee.h"  // Make sure to include the MainWindow header
#include "Formation.h"
#include "TTP.h"

Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    w = new Main_trash(this);  // Existing code for Main_trash
    mw = new Main_Employee(this);  // Initialize MainWindow

    ttsWindow = new TextToSpeechWindow(this); // Existing code for TextToSpeechWindow


    // Existing connections
    connect(ui->Formation_home, &QPushButton::clicked, w, &Main_trash::show);
    connect(ui->Formation_home, &QPushButton::clicked, ttsWindow, &TextToSpeechWindow::show);
    connect(w, &Main_trash::viewUpdated, ttsWindow, &TextToSpeechWindow::updatePlainText);

    // Connect the second button to show MainWindow
    connect(ui->Employee_home, &QPushButton::clicked, mw, &Main_Employee::show);
}

Home::~Home()
{
    delete ui;
    delete w;
    delete ttsWindow;

}
