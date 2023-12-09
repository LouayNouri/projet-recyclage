#include "Home.h"
#include "ui_Home.h"
#include "connection.h"
#include "TTP.h"

Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    w = new Main_trash(this);
    ttsWindow = new TextToSpeechWindow(this); // Add this line
    connect(ui->Hamza, &QPushButton::clicked, w, &Main_trash::show);
    connect(ui->Hamza, &QPushButton::clicked, ttsWindow, &TextToSpeechWindow::show); // Add this line
    connect(w, &Main_trash::viewUpdated, ttsWindow, &TextToSpeechWindow::updatePlainText);

}

Home::~Home()
{
    delete ui;
}
