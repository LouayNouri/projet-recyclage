#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include "Formation.h"
#include "Main_Employee.h"
#include "TTP.h"

// Forward declaration of MainWindow class
class MainWindow;

namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *ui;
    Main_trash *w;
    TextToSpeechWindow *ttsWindow;
    Main_Employee *mw; // Add this line

};

#endif // HOME_H
