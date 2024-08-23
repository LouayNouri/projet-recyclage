/********************************************************************************
** Form generated from reading UI file 'Home.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Home
{
public:
    QWidget *centralwidget;
    QPushButton *Hamza;
    QLabel *label;
    QPushButton *Hamza_2;
    QPushButton *Hamza_3;
    QPushButton *Hamza_4;
    QPushButton *Hamza_5;
    QPushButton *Hamza_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Home)
    {
        if (Home->objectName().isEmpty())
            Home->setObjectName("Home");
        Home->resize(520, 840);
        Home->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Home);
        centralwidget->setObjectName("centralwidget");
        Hamza = new QPushButton(centralwidget);
        Hamza->setObjectName("Hamza");
        Hamza->setGeometry(QRect(100, 50, 321, 121));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        Hamza->setFont(font);
        Hamza->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(255, 127, 84);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"	color: rgb(0, 170, 0);\n"
"}\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -40, 521, 891));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/pexels-kaique-rocha-775201.jpg")));
        label->setScaledContents(true);
        Hamza_2 = new QPushButton(centralwidget);
        Hamza_2->setObjectName("Hamza_2");
        Hamza_2->setGeometry(QRect(100, 170, 321, 121));
        Hamza_2->setFont(font);
        Hamza_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(255, 127, 84);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"	color: rgb(0, 170, 0);\n"
"}\n"
""));
        Hamza_3 = new QPushButton(centralwidget);
        Hamza_3->setObjectName("Hamza_3");
        Hamza_3->setGeometry(QRect(100, 290, 321, 121));
        Hamza_3->setFont(font);
        Hamza_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(255, 127, 84);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"	color: rgb(0, 170, 0);\n"
"}\n"
""));
        Hamza_4 = new QPushButton(centralwidget);
        Hamza_4->setObjectName("Hamza_4");
        Hamza_4->setGeometry(QRect(100, 410, 321, 121));
        Hamza_4->setFont(font);
        Hamza_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(255, 127, 84);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"	color: rgb(0, 170, 0);\n"
"}\n"
""));
        Hamza_5 = new QPushButton(centralwidget);
        Hamza_5->setObjectName("Hamza_5");
        Hamza_5->setGeometry(QRect(100, 530, 321, 121));
        Hamza_5->setFont(font);
        Hamza_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(255, 127, 84);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"	color: rgb(0, 170, 0);\n"
"}\n"
""));
        Hamza_6 = new QPushButton(centralwidget);
        Hamza_6->setObjectName("Hamza_6");
        Hamza_6->setGeometry(QRect(100, 650, 321, 121));
        Hamza_6->setFont(font);
        Hamza_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(255, 127, 84);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"	color: rgb(0, 170, 0);\n"
"}\n"
""));
        Home->setCentralWidget(centralwidget);
        label->raise();
        Hamza->raise();
        Hamza_2->raise();
        Hamza_3->raise();
        Hamza_4->raise();
        Hamza_5->raise();
        Hamza_6->raise();
        menubar = new QMenuBar(Home);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 520, 22));
        Home->setMenuBar(menubar);
        statusbar = new QStatusBar(Home);
        statusbar->setObjectName("statusbar");
        Home->setStatusBar(statusbar);

        retranslateUi(Home);

        QMetaObject::connectSlotsByName(Home);
    } // setupUi

    void retranslateUi(QMainWindow *Home)
    {
        Home->setWindowTitle(QCoreApplication::translate("Home", "MainWindow", nullptr));
        Hamza->setText(QCoreApplication::translate("Home", "ham", nullptr));
        label->setText(QString());
        Hamza_2->setText(QCoreApplication::translate("Home", "Nour", nullptr));
        Hamza_3->setText(QCoreApplication::translate("Home", "Louay", nullptr));
        Hamza_4->setText(QCoreApplication::translate("Home", "Aymen", nullptr));
        Hamza_5->setText(QCoreApplication::translate("Home", "Roua", nullptr));
        Hamza_6->setText(QCoreApplication::translate("Home", "Emna", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Home: public Ui_Home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
