#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include "Main_trash.h"
#include "TTP.h"


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
};

#endif // HOME_H
