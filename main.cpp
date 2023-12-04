#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSqlDatabase>
#include "TTP.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    TextToSpeechWindow ttsWindow;
    ttsWindow.show();
    connection c;
    bool test=c.createconnect(); //etablir connection
    if(test)
    {
        w.show();
    }
    QObject::connect(&w, &MainWindow::viewUpdated, &ttsWindow, &TextToSpeechWindow::updatePlainText);

    return a.exec();
}
