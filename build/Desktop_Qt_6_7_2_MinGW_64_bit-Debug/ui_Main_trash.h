/********************************************************************************
** Form generated from reading UI file 'Main_trash.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_TRASH_H
#define UI_MAIN_TRASH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_trash
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_4;
    QDoubleSpinBox *amount;
    QCalendarWidget *date;
    QPushButton *Generat_Button;
    QGroupBox *properties;
    QCheckBox *recyclable;
    QCheckBox *bio;
    QCheckBox *reusable;
    QLabel *label_5;
    QPushButton *reset;
    QLineEdit *Generated_code;
    QGroupBox *groupBox;
    QPushButton *add1;
    QPushButton *display1;
    QPushButton *rech1;
    QPushButton *stat1;
    QLabel *label_17;
    QLabel *label;
    QComboBox *unit;
    QPushButton *check_button;
    QPushButton *modify;
    QPushButton *add;
    QGroupBox *type;
    QHBoxLayout *horizontalLayout;
    QRadioButton *glass;
    QRadioButton *paper;
    QRadioButton *metal;
    QRadioButton *plastic;
    QLabel *label_12;
    QLabel *label_2;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QPushButton *add2;
    QPushButton *display2;
    QPushButton *rech2;
    QPushButton *stat2;
    QLabel *label_18;
    QLabel *label_7;
    QLabel *label_8;
    QTableView *view;
    QPushButton *delete_2;
    QLineEdit *Delete_zone;
    QLabel *label_13;
    QPushButton *exportall;
    QPushButton *exportdisplayed;
    QPushButton *reset_2;
    QWidget *tab_3;
    QGroupBox *groupBox_4;
    QPushButton *add3;
    QPushButton *display3;
    QPushButton *rech3;
    QPushButton *stat3;
    QLabel *label_19;
    QLabel *label_10;
    QGroupBox *groupBox_3;
    QCheckBox *typeCheckBox;
    QCheckBox *dateCheckBox;
    QDateEdit *date_2;
    QRadioButton *metal_2;
    QRadioButton *plastic_2;
    QRadioButton *glass_2;
    QRadioButton *paper_2;
    QTableView *view_2;
    QFrame *line;
    QLabel *label_9;
    QGroupBox *groupBox_6;
    QCheckBox *recyclableCheckBox;
    QCheckBox *reusableCheckBox;
    QCheckBox *biodegradableCheckBox;
    QPushButton *ascendingButton;
    QPushButton *descendingButton;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_21;
    QWidget *tab_4;
    QGroupBox *groupBox_5;
    QPushButton *add4;
    QPushButton *display4;
    QPushButton *rech4;
    QPushButton *stat4;
    QLabel *label_20;
    QLabel *label_11;
    QPushButton *stats_1;
    QPushButton *stats_2;
    QPushButton *stats_3;
    QPushButton *stats_4;
    QPushButton *stack;
    QLabel *mecha;
    QLabel *glacha;
    QLabel *papcha;
    QLabel *placha;
    QLabel *stacha;
    QLabel *GIF;
    QDockWidget *dock;
    QWidget *dockWidgetContents_6;
    QLabel *label_3;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;

    void setupUi(QMainWindow *Main_trash)
    {
        if (Main_trash->objectName().isEmpty())
            Main_trash->setObjectName("Main_trash");
        Main_trash->resize(1324, 855);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Main_trash->sizePolicy().hasHeightForWidth());
        Main_trash->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Main_trash);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(1, -29, 1341, 841));
        tab = new QWidget();
        tab->setObjectName("tab");
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(660, 320, 101, 41));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        amount = new QDoubleSpinBox(tab);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(740, 390, 131, 51));
        sizePolicy.setHeightForWidth(amount->sizePolicy().hasHeightForWidth());
        amount->setSizePolicy(sizePolicy);
        amount->setStyleSheet(QString::fromUtf8("gridline-color: rgb(255, 85, 0);"));
        amount->setMaximum(100000.000000000000000);
        date = new QCalendarWidget(tab);
        date->setObjectName("date");
        date->setGeometry(QRect(360, 550, 281, 190));
        sizePolicy.setHeightForWidth(date->sizePolicy().hasHeightForWidth());
        date->setSizePolicy(sizePolicy);
        date->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        Generat_Button = new QPushButton(tab);
        Generat_Button->setObjectName("Generat_Button");
        Generat_Button->setGeometry(QRect(670, 680, 141, 51));
        sizePolicy.setHeightForWidth(Generat_Button->sizePolicy().hasHeightForWidth());
        Generat_Button->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        Generat_Button->setFont(font1);
        Generat_Button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Generat_Button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFA500; /* Neon Orange */\n"
"    color: #000000; /* Black */\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #ffffff; /* White border becomes visible when hovered over */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FF4500; /* Darker Orange */\n"
"}\n"
""));
        properties = new QGroupBox(tab);
        properties->setObjectName("properties");
        properties->setGeometry(QRect(330, 450, 991, 80));
        sizePolicy.setHeightForWidth(properties->sizePolicy().hasHeightForWidth());
        properties->setSizePolicy(sizePolicy);
        properties->setStyleSheet(QString::fromUtf8("border:none"));
        recyclable = new QCheckBox(properties);
        recyclable->setObjectName("recyclable");
        recyclable->setGeometry(QRect(250, 20, 151, 41));
        sizePolicy.setHeightForWidth(recyclable->sizePolicy().hasHeightForWidth());
        recyclable->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(12);
        recyclable->setFont(font2);
        recyclable->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        bio = new QCheckBox(properties);
        bio->setObjectName("bio");
        bio->setGeometry(QRect(420, 20, 151, 41));
        sizePolicy.setHeightForWidth(bio->sizePolicy().hasHeightForWidth());
        bio->setSizePolicy(sizePolicy);
        bio->setFont(font2);
        bio->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        reusable = new QCheckBox(properties);
        reusable->setObjectName("reusable");
        reusable->setGeometry(QRect(600, 20, 151, 41));
        sizePolicy.setHeightForWidth(reusable->sizePolicy().hasHeightForWidth());
        reusable->setSizePolicy(sizePolicy);
        reusable->setFont(font2);
        reusable->setAutoFillBackground(false);
        reusable->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        reusable->setIconSize(QSize(500, 500));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(350, 470, 150, 41));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("MS Shell Dlg 2")});
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(false);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("font: 75 20pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 127, 84);\n"
""));
        reset = new QPushButton(tab);
        reset->setObjectName("reset");
        reset->setGeometry(QRect(1150, 680, 141, 71));
        sizePolicy.setHeightForWidth(reset->sizePolicy().hasHeightForWidth());
        reset->setSizePolicy(sizePolicy);
        reset->setFont(font1);
        reset->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white;  \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"}\n"
""));
        Generated_code = new QLineEdit(tab);
        Generated_code->setObjectName("Generated_code");
        Generated_code->setGeometry(QRect(710, 620, 281, 51));
        sizePolicy.setHeightForWidth(Generated_code->sizePolicy().hasHeightForWidth());
        Generated_code->setSizePolicy(sizePolicy);
        Generated_code->setFont(font1);
        Generated_code->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white;  \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"}\n"
""));
        Generated_code->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 331, 821));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        add1 = new QPushButton(groupBox);
        add1->setObjectName("add1");
        add1->setGeometry(QRect(0, 140, 331, 131));
        sizePolicy.setHeightForWidth(add1->sizePolicy().hasHeightForWidth());
        add1->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Mongolian Baiti")});
        font4.setPointSize(20);
        add1->setFont(font4);
        add1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        display1 = new QPushButton(groupBox);
        display1->setObjectName("display1");
        display1->setGeometry(QRect(0, 270, 331, 131));
        sizePolicy.setHeightForWidth(display1->sizePolicy().hasHeightForWidth());
        display1->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Mongolian Baiti")});
        font5.setPointSize(19);
        display1->setFont(font5);
        display1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        rech1 = new QPushButton(groupBox);
        rech1->setObjectName("rech1");
        rech1->setGeometry(QRect(0, 400, 331, 131));
        sizePolicy.setHeightForWidth(rech1->sizePolicy().hasHeightForWidth());
        rech1->setSizePolicy(sizePolicy);
        rech1->setFont(font4);
        rech1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        stat1 = new QPushButton(groupBox);
        stat1->setObjectName("stat1");
        stat1->setGeometry(QRect(0, 530, 331, 131));
        sizePolicy.setHeightForWidth(stat1->sizePolicy().hasHeightForWidth());
        stat1->setSizePolicy(sizePolicy);
        stat1->setFont(font4);
        stat1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(0, 0, 331, 821));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/pxfuel.jpg")));
        label_17->setScaledContents(true);
        label_17->raise();
        display1->raise();
        rech1->raise();
        stat1->raise();
        add1->raise();
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 0, 991, 821));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(11, 11, 11);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/wallpaperflare.com_wallpaper.jpg")));
        label->setScaledContents(true);
        unit = new QComboBox(tab);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/weight_gram_icon_138015.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        unit->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/kilogram.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        unit->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/weight-1-tonne.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        unit->addItem(icon2, QString());
        unit->setObjectName("unit");
        unit->setGeometry(QRect(710, 320, 211, 41));
        sizePolicy.setHeightForWidth(unit->sizePolicy().hasHeightForWidth());
        unit->setSizePolicy(sizePolicy);
        unit->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(27, 150, 0);\n"
"selection-color: rgb(146, 255, 162);\n"
""));
        unit->setIconSize(QSize(50, 50));
        check_button = new QPushButton(tab);
        check_button->setObjectName("check_button");
        check_button->setGeometry(QRect(900, 680, 141, 51));
        sizePolicy.setHeightForWidth(check_button->sizePolicy().hasHeightForWidth());
        check_button->setSizePolicy(sizePolicy);
        QFont font6;
        font6.setPointSize(16);
        check_button->setFont(font6);
        check_button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        check_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"	background-color: rgb(0, 100, 0);\n"
"    \n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #ffffff; /* White border becomes visible when hovered over */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FF4500; /* Darker Orange */\n"
"}\n"
""));
        modify = new QPushButton(tab);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(1150, 610, 141, 71));
        sizePolicy.setHeightForWidth(modify->sizePolicy().hasHeightForWidth());
        modify->setSizePolicy(sizePolicy);
        modify->setFont(font1);
        modify->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        modify->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white;  \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"}\n"
""));
        add = new QPushButton(tab);
        add->setObjectName("add");
        add->setGeometry(QRect(1150, 540, 141, 71));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(add->sizePolicy().hasHeightForWidth());
        add->setSizePolicy(sizePolicy2);
        add->setFont(font1);
        add->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white;  \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1);  \n"
"}\n"
""));
        type = new QGroupBox(tab);
        type->setObjectName("type");
        type->setGeometry(QRect(330, 170, 981, 128));
        sizePolicy.setHeightForWidth(type->sizePolicy().hasHeightForWidth());
        type->setSizePolicy(sizePolicy);
        type->setStyleSheet(QString::fromUtf8("border:none;"));
        type->setCheckable(true);
        type->setChecked(true);
        horizontalLayout = new QHBoxLayout(type);
        horizontalLayout->setObjectName("horizontalLayout");
        glass = new QRadioButton(type);
        glass->setObjectName("glass");
        sizePolicy.setHeightForWidth(glass->sizePolicy().hasHeightForWidth());
        glass->setSizePolicy(sizePolicy);
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Impact")});
        font7.setPointSize(14);
        glass->setFont(font7);
        glass->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        glass->setStyleSheet(QString::fromUtf8("color: rgb(90, 161, 86);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/gl.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        glass->setIcon(icon3);
        glass->setIconSize(QSize(110, 110));

        horizontalLayout->addWidget(glass);

        paper = new QRadioButton(type);
        paper->setObjectName("paper");
        sizePolicy.setHeightForWidth(paper->sizePolicy().hasHeightForWidth());
        paper->setSizePolicy(sizePolicy);
        paper->setFont(font7);
        paper->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        paper->setStyleSheet(QString::fromUtf8("color: rgb(74, 141, 198);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/p.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        paper->setIcon(icon4);
        paper->setIconSize(QSize(110, 110));

        horizontalLayout->addWidget(paper);

        metal = new QRadioButton(type);
        metal->setObjectName("metal");
        sizePolicy.setHeightForWidth(metal->sizePolicy().hasHeightForWidth());
        metal->setSizePolicy(sizePolicy);
        metal->setFont(font7);
        metal->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        metal->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/me.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        metal->setIcon(icon5);
        metal->setIconSize(QSize(110, 110));

        horizontalLayout->addWidget(metal);

        plastic = new QRadioButton(type);
        plastic->setObjectName("plastic");
        sizePolicy.setHeightForWidth(plastic->sizePolicy().hasHeightForWidth());
        plastic->setSizePolicy(sizePolicy);
        plastic->setFont(font7);
        plastic->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        plastic->setStyleSheet(QString::fromUtf8("color: rgb(248, 165, 45);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/pl.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        plastic->setIcon(icon6);
        plastic->setIconSize(QSize(110, 110));

        horizontalLayout->addWidget(plastic);

        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(780, 570, 151, 41));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        QFont font8;
        font8.setPointSize(16);
        font8.setBold(true);
        label_12->setFont(font8);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(720, 60, 969, 129));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 75 20pt \"MS Shell Dlg 2\";\n"
"color:  #ED8E4A    ;\n"
""));
        tabWidget->addTab(tab, QString());
        label->raise();
        label_4->raise();
        amount->raise();
        date->raise();
        Generat_Button->raise();
        properties->raise();
        label_5->raise();
        reset->raise();
        Generated_code->raise();
        groupBox->raise();
        unit->raise();
        check_button->raise();
        modify->raise();
        add->raise();
        type->raise();
        label_12->raise();
        label_2->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 0, 331, 821));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        add2 = new QPushButton(groupBox_2);
        add2->setObjectName("add2");
        add2->setGeometry(QRect(0, 140, 331, 131));
        add2->setFont(font4);
        add2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        display2 = new QPushButton(groupBox_2);
        display2->setObjectName("display2");
        display2->setGeometry(QRect(0, 270, 331, 131));
        display2->setFont(font5);
        display2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        rech2 = new QPushButton(groupBox_2);
        rech2->setObjectName("rech2");
        rech2->setGeometry(QRect(0, 400, 331, 131));
        rech2->setFont(font4);
        rech2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        stat2 = new QPushButton(groupBox_2);
        stat2->setObjectName("stat2");
        stat2->setGeometry(QRect(0, 530, 331, 131));
        stat2->setFont(font4);
        stat2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(0, 0, 331, 821));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/pxfuel.jpg")));
        label_18->setScaledContents(true);
        label_18->raise();
        add2->raise();
        display2->raise();
        rech2->raise();
        stat2->raise();
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(330, 0, 991, 821));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/dark-green-wall-backdrop-grunge-background-texture.jpg")));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(610, 20, 411, 71));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Poor Richard")});
        font9.setPointSize(36);
        label_8->setFont(font9);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        view = new QTableView(tab_2);
        view->setObjectName("view");
        view->setGeometry(QRect(690, 130, 631, 681));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Segoe UI")});
        view->setFont(font10);
        view->setStyleSheet(QString::fromUtf8("background-color: transparent; border: none;\n"
"color:white"));
        delete_2 = new QPushButton(tab_2);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(370, 540, 121, 51));
        QFont font11;
        font11.setPointSize(16);
        font11.setBold(false);
        delete_2->setFont(font11);
        delete_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        delete_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFA500; /* Neon Orange */\n"
"    color: #000000; /* Black */\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #ffffff; /* White border becomes visible when hovered over */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FF4500; /* Darker Orange */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/delete-127.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        delete_2->setIcon(icon7);
        delete_2->setIconSize(QSize(30, 30));
        Delete_zone = new QLineEdit(tab_2);
        Delete_zone->setObjectName("Delete_zone");
        Delete_zone->setGeometry(QRect(420, 360, 171, 51));
        Delete_zone->setFont(font1);
        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(430, 300, 151, 41));
        label_13->setFont(font6);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        exportall = new QPushButton(tab_2);
        exportall->setObjectName("exportall");
        exportall->setGeometry(QRect(370, 460, 121, 51));
        QFont font12;
        font12.setPointSize(11);
        font12.setBold(true);
        exportall->setFont(font12);
        exportall->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportall->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"	background-color: rgb(0, 100, 0);\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #ffffff; /* White border becomes visible when hovered over */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FF4500; /* Darker Orange */\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/pngtree-pdf-file-icon-png-png-image_7965915.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportall->setIcon(icon8);
        exportall->setIconSize(QSize(25, 25));
        exportdisplayed = new QPushButton(tab_2);
        exportdisplayed->setObjectName("exportdisplayed");
        exportdisplayed->setGeometry(QRect(540, 460, 121, 51));
        QFont font13;
        font13.setPointSize(12);
        font13.setBold(true);
        exportdisplayed->setFont(font13);
        exportdisplayed->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportdisplayed->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"	background-color: rgb(0, 100, 0);\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #ffffff; /* White border becomes visible when hovered over */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FF4500; /* Darker Orange */\n"
"}\n"
""));
        exportdisplayed->setIcon(icon8);
        exportdisplayed->setIconSize(QSize(20, 20));
        reset_2 = new QPushButton(tab_2);
        reset_2->setObjectName("reset_2");
        reset_2->setGeometry(QRect(540, 540, 121, 51));
        reset_2->setFont(font11);
        reset_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        reset_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFA500; /* Neon Orange */\n"
"    color: #000000; /* Black */\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #ffffff; /* White border becomes visible when hovered over */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FF4500; /* Darker Orange */\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/5632370.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        reset_2->setIcon(icon9);
        reset_2->setIconSize(QSize(30, 30));
        tabWidget->addTab(tab_2, QString());
        label_7->raise();
        groupBox_2->raise();
        label_8->raise();
        view->raise();
        delete_2->raise();
        Delete_zone->raise();
        label_13->raise();
        exportall->raise();
        exportdisplayed->raise();
        reset_2->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(0, 0, 331, 821));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        add3 = new QPushButton(groupBox_4);
        add3->setObjectName("add3");
        add3->setGeometry(QRect(0, 140, 331, 131));
        add3->setFont(font4);
        add3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        display3 = new QPushButton(groupBox_4);
        display3->setObjectName("display3");
        display3->setGeometry(QRect(0, 270, 331, 131));
        display3->setFont(font5);
        display3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        rech3 = new QPushButton(groupBox_4);
        rech3->setObjectName("rech3");
        rech3->setGeometry(QRect(0, 400, 331, 131));
        rech3->setFont(font4);
        rech3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        stat3 = new QPushButton(groupBox_4);
        stat3->setObjectName("stat3");
        stat3->setGeometry(QRect(0, 530, 331, 131));
        stat3->setFont(font4);
        stat3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(0, 0, 331, 821));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/pxfuel.jpg")));
        label_19->setScaledContents(true);
        label_19->raise();
        add3->raise();
        display3->raise();
        rech3->raise();
        stat3->raise();
        label_10 = new QLabel(tab_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(320, 0, 1001, 821));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/dark-green-wall-backdrop-grunge-background-texture.jpg")));
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(370, 80, 331, 351));
        typeCheckBox = new QCheckBox(groupBox_3);
        typeCheckBox->setObjectName("typeCheckBox");
        typeCheckBox->setEnabled(true);
        typeCheckBox->setGeometry(QRect(120, 20, 151, 41));
        typeCheckBox->setFont(font3);
        typeCheckBox->setStyleSheet(QString::fromUtf8("font: 75 20pt \"MS Shell Dlg 2\";\n"
"color:  #ED8E4A    ;\n"
""));
        typeCheckBox->setChecked(false);
        dateCheckBox = new QCheckBox(groupBox_3);
        dateCheckBox->setObjectName("dateCheckBox");
        dateCheckBox->setGeometry(QRect(130, 200, 151, 41));
        dateCheckBox->setFont(font3);
        dateCheckBox->setStyleSheet(QString::fromUtf8("font: 75 20pt \"MS Shell Dlg 2\";\n"
"color:  #ED8E4A    ;\n"
""));
        date_2 = new QDateEdit(groupBox_3);
        date_2->setObjectName("date_2");
        date_2->setEnabled(false);
        date_2->setGeometry(QRect(70, 260, 201, 61));
        QFont font14;
        font14.setFamilies({QString::fromUtf8("Simplified Arabic Fixed")});
        font14.setPointSize(14);
        date_2->setFont(font14);
        metal_2 = new QRadioButton(groupBox_3);
        metal_2->setObjectName("metal_2");
        metal_2->setEnabled(false);
        metal_2->setGeometry(QRect(10, 80, 131, 41));
        QFont font15;
        font15.setFamilies({QString::fromUtf8("Mongolian Baiti")});
        font15.setPointSize(14);
        metal_2->setFont(font15);
        metal_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        metal_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        metal_2->setIcon(icon5);
        metal_2->setIconSize(QSize(40, 40));
        plastic_2 = new QRadioButton(groupBox_3);
        plastic_2->setObjectName("plastic_2");
        plastic_2->setEnabled(false);
        plastic_2->setGeometry(QRect(180, 80, 131, 41));
        plastic_2->setFont(font15);
        plastic_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        plastic_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        plastic_2->setIcon(icon6);
        plastic_2->setIconSize(QSize(40, 40));
        glass_2 = new QRadioButton(groupBox_3);
        glass_2->setObjectName("glass_2");
        glass_2->setEnabled(false);
        glass_2->setGeometry(QRect(10, 130, 131, 41));
        glass_2->setFont(font15);
        glass_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        glass_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        glass_2->setIcon(icon3);
        glass_2->setIconSize(QSize(40, 40));
        paper_2 = new QRadioButton(groupBox_3);
        paper_2->setObjectName("paper_2");
        paper_2->setEnabled(false);
        paper_2->setGeometry(QRect(180, 130, 131, 41));
        paper_2->setFont(font15);
        paper_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        paper_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        paper_2->setIcon(icon4);
        paper_2->setIconSize(QSize(40, 40));
        view_2 = new QTableView(tab_3);
        view_2->setObjectName("view_2");
        view_2->setGeometry(QRect(330, 450, 991, 371));
        QPalette palette;
        QBrush brush(QColor(105, 172, 62, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(105, 172, 62, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush5(QColor(105, 172, 62, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush7(QColor(105, 172, 62, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        view_2->setPalette(palette);
        view_2->setFont(font10);
        view_2->setStyleSheet(QString::fromUtf8("background-color: transparent; border: none;\n"
"color: rgb(105, 172, 62);"));
        view_2->setAlternatingRowColors(false);
        view_2->setGridStyle(Qt::DashLine);
        view_2->setSortingEnabled(false);
        line = new QFrame(tab_3);
        line->setObjectName("line");
        line->setGeometry(QRect(793, 90, 20, 241));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_9 = new QLabel(tab_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(470, 10, 141, 61));
        label_9->setFont(font9);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(910, 80, 331, 351));
        recyclableCheckBox = new QCheckBox(groupBox_6);
        recyclableCheckBox->setObjectName("recyclableCheckBox");
        recyclableCheckBox->setGeometry(QRect(10, 90, 101, 51));
        QFont font16;
        font16.setPointSize(11);
        recyclableCheckBox->setFont(font16);
        recyclableCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        reusableCheckBox = new QCheckBox(groupBox_6);
        reusableCheckBox->setObjectName("reusableCheckBox");
        reusableCheckBox->setGeometry(QRect(240, 90, 111, 51));
        reusableCheckBox->setFont(font16);
        reusableCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        biodegradableCheckBox = new QCheckBox(groupBox_6);
        biodegradableCheckBox->setObjectName("biodegradableCheckBox");
        biodegradableCheckBox->setGeometry(QRect(110, 90, 121, 51));
        biodegradableCheckBox->setFont(font16);
        biodegradableCheckBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ascendingButton = new QPushButton(groupBox_6);
        ascendingButton->setObjectName("ascendingButton");
        ascendingButton->setGeometry(QRect(10, 260, 151, 81));
        ascendingButton->setFont(font1);
        ascendingButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ascendingButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #FFA500; /* Neon Orange */\n"
"    color: #000000; /* Black */\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #ffffff; /* White border becomes visible when hovered over */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FF4500; /* Darker Orange */\n"
"}\n"
""));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/ascending-order.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ascendingButton->setIcon(icon10);
        ascendingButton->setIconSize(QSize(30, 30));
        ascendingButton->setCheckable(false);
        descendingButton = new QPushButton(groupBox_6);
        descendingButton->setObjectName("descendingButton");
        descendingButton->setGeometry(QRect(160, 260, 161, 81));
        descendingButton->setFont(font1);
        descendingButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        descendingButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    \n"
"	background-color: rgb(0, 100, 0);\n"
"	color: rgb(255, 255, 255);\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 2px solid #ffffff; /* White border becomes visible when hovered over */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #FF4500; /* Darker Orange */\n"
"}\n"
""));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/59216.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        descendingButton->setIcon(icon11);
        descendingButton->setIconSize(QSize(25, 25));
        descendingButton->setCheckable(false);
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(90, 40, 171, 31));
        label_15->setFont(font3);
        label_15->setStyleSheet(QString::fromUtf8("font: 75 20pt \"MS Shell Dlg 2\";\n"
"color:  #ED8E4A    ;\n"
""));
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(120, 200, 171, 31));
        label_16->setFont(font3);
        label_16->setStyleSheet(QString::fromUtf8("font: 75 20pt \"MS Shell Dlg 2\";\n"
"color:  #ED8E4A    ;\n"
""));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1040, 10, 91, 61));
        label_14->setFont(font9);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        label_21 = new QLabel(tab_3);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(740, 340, 131, 91));
        label_21->setPixmap(QPixmap(QString::fromUtf8("6430960.jpg")));
        label_21->setScaledContents(true);
        tabWidget->addTab(tab_3, QString());
        label_10->raise();
        groupBox_4->raise();
        groupBox_3->raise();
        view_2->raise();
        line->raise();
        label_9->raise();
        groupBox_6->raise();
        label_14->raise();
        label_21->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(0, 0, 331, 821));
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        add4 = new QPushButton(groupBox_5);
        add4->setObjectName("add4");
        add4->setGeometry(QRect(0, 140, 331, 131));
        add4->setFont(font4);
        add4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        display4 = new QPushButton(groupBox_5);
        display4->setObjectName("display4");
        display4->setGeometry(QRect(0, 270, 331, 131));
        display4->setFont(font5);
        display4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        rech4 = new QPushButton(groupBox_5);
        rech4->setObjectName("rech4");
        rech4->setGeometry(QRect(0, 400, 331, 131));
        rech4->setFont(font4);
        rech4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        stat4 = new QPushButton(groupBox_5);
        stat4->setObjectName("stat4");
        stat4->setGeometry(QRect(0, 530, 331, 131));
        stat4->setFont(font4);
        stat4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	color: rgb(105, 172, 62);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); \n"
"    color:  #ED8E4A; \n"
"}\n"
""));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(0, 0, 331, 821));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/pxfuel.jpg")));
        label_20->setScaledContents(true);
        label_20->raise();
        add4->raise();
        display4->raise();
        rech4->raise();
        stat4->raise();
        label_11 = new QLabel(tab_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(330, 0, 991, 821));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/dark-green-wall-backdrop-grunge-background-texture.jpg")));
        stats_1 = new QPushButton(tab_4);
        stats_1->setObjectName("stats_1");
        stats_1->setGeometry(QRect(330, 0, 201, 111));
        QFont font17;
        font17.setFamilies({QString::fromUtf8("Microsoft Uighur")});
        font17.setPointSize(24);
        font17.setBold(true);
        font17.setItalic(false);
        stats_1->setFont(font17);
        stats_1->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stats_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #FF0000; /* Red */\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid #FF0000; /* Red border becomes visible when hovered over */\n"
"}\n"
""));
        stats_2 = new QPushButton(tab_4);
        stats_2->setObjectName("stats_2");
        stats_2->setGeometry(QRect(530, 0, 201, 111));
        QFont font18;
        font18.setFamilies({QString::fromUtf8("Microsoft Uighur")});
        font18.setPointSize(24);
        font18.setBold(true);
        stats_2->setFont(font18);
        stats_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stats_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #FFA500; /* Orange */\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid #FFA500; /* Orange border becomes visible when hovered over */\n"
"}\n"
""));
        stats_3 = new QPushButton(tab_4);
        stats_3->setObjectName("stats_3");
        stats_3->setGeometry(QRect(730, 0, 201, 111));
        stats_3->setFont(font18);
        stats_3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stats_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #00FF00; /* Green */\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid #00FF00; /* Green border becomes visible when hovered over */\n"
"}\n"
""));
        stats_4 = new QPushButton(tab_4);
        stats_4->setObjectName("stats_4");
        stats_4->setGeometry(QRect(930, 0, 201, 111));
        stats_4->setFont(font18);
        stats_4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stats_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"   color: rgb(74, 141, 198);\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid rgb(74, 141, 198);; /* Blue border becomes visible when hovered over */\n"
"}\n"
""));
        stack = new QPushButton(tab_4);
        stack->setObjectName("stack");
        stack->setGeometry(QRect(1130, 0, 191, 111));
        QFont font19;
        font19.setFamilies({QString::fromUtf8("Microsoft Uighur")});
        font19.setPointSize(18);
        font19.setBold(true);
        stack->setFont(font19);
        stack->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stack->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(170, 85, 255);\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid rgb(170, 85, 255);; /* Blue border becomes visible when hovered over */\n"
"}\n"
""));
        mecha = new QLabel(tab_4);
        mecha->setObjectName("mecha");
        mecha->setEnabled(true);
        mecha->setGeometry(QRect(330, 110, 991, 701));
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mecha->sizePolicy().hasHeightForWidth());
        mecha->setSizePolicy(sizePolicy3);
        mecha->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        mecha->setMouseTracking(false);
        mecha->setFocusPolicy(Qt::NoFocus);
        mecha->setStyleSheet(QString::fromUtf8("background-color: transparent; border: none;\n"
"color: rgb(0, 170, 0);\n"
"\n"
""));
        mecha->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Metalpng.png")));
        mecha->setScaledContents(true);
        glacha = new QLabel(tab_4);
        glacha->setObjectName("glacha");
        glacha->setGeometry(QRect(330, 110, 991, 711));
        glacha->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Glasspng.png")));
        glacha->setScaledContents(true);
        papcha = new QLabel(tab_4);
        papcha->setObjectName("papcha");
        papcha->setGeometry(QRect(330, 110, 991, 711));
        papcha->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/pap.png")));
        papcha->setScaledContents(true);
        placha = new QLabel(tab_4);
        placha->setObjectName("placha");
        placha->setGeometry(QRect(330, 110, 991, 711));
        placha->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Pla.png")));
        placha->setScaledContents(true);
        stacha = new QLabel(tab_4);
        stacha->setObjectName("stacha");
        stacha->setGeometry(QRect(330, 110, 991, 711));
        stacha->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/stack.png")));
        stacha->setScaledContents(true);
        GIF = new QLabel(tab_4);
        GIF->setObjectName("GIF");
        GIF->setGeometry(QRect(480, 230, 691, 421));
        GIF->setCursor(QCursor(Qt::CursorShape::BlankCursor));
        GIF->setScaledContents(true);
        tabWidget->addTab(tab_4, QString());
        label_11->raise();
        groupBox_5->raise();
        stats_1->raise();
        stats_2->raise();
        stats_3->raise();
        stats_4->raise();
        stack->raise();
        GIF->raise();
        mecha->raise();
        glacha->raise();
        papcha->raise();
        placha->raise();
        stacha->raise();
        Main_trash->setCentralWidget(centralwidget);
        dock = new QDockWidget(Main_trash);
        dock->setObjectName("dock");
        dock->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);\n"
"background-color: rgb(45, 45, 43);"));
        dock->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetVerticalTitleBar);
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName("dockWidgetContents_6");
        dockWidgetContents_6->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        dockWidgetContents_6->setMouseTracking(true);
        label_3 = new QLabel(dockWidgetContents_6);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, -10, 311, 61));
        QFont font20;
        font20.setPointSize(18);
        font20.setBold(true);
        label_3->setFont(font20);
        label_3->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 44, 40);\n"
"color: rgb(246, 166, 37);"));
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_11 = new QPushButton(dockWidgetContents_6);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(310, -10, 161, 61));
        QFont font21;
        font21.setPointSize(14);
        font21.setBold(true);
        pushButton_11->setFont(font21);
        pushButton_11->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    outline: 0;\n"
"    text-align: center;\n"
"    padding: 17px 30px;\n"
"    border: 0;\n"
"    color: #fff;\n"
"    font-size: 17.5px;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #36c275, stop:0.95 #808080, stop:1 #808080);\n"
"    line-height: 30px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #FF8C00, stop:0.95 #808080, stop:1 #808080); /* Dark orange gradient when hovering */\n"
"    color: #000;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: #808080; /* Dark grey background when pressed */\n"
"    color: #000;\n"
"}\n"
""));
        pushButton_12 = new QPushButton(dockWidgetContents_6);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(470, -10, 161, 61));
        pushButton_12->setFont(font21);
        pushButton_12->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    outline: 0;\n"
"    text-align: center;\n"
"    padding: 17px 30px;\n"
"    border: 0;\n"
"    color: #fff;\n"
"    font-size: 17.5px;\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #36c275, stop:0.95 #808080, stop:1 #808080);\n"
"    line-height: 30px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #FF8C00, stop:0.95 #808080, stop:1 #808080); /* Dark orange gradient when hovering */\n"
"    color: #000;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: #808080; /* Dark grey background when pressed */\n"
"    color: #000;\n"
"}\n"
""));
        pushButton_13 = new QPushButton(dockWidgetContents_6);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(630, -10, 161, 61));
        pushButton_13->setFont(font21);
        pushButton_13->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    outline: 0;\n"
"    text-align: center;\n"
"    padding: 17px 30px;\n"
"    border: 0;\n"
"    color: #fff;\n"
"    font-size: 17.5px;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #36c275, stop:0.95 #808080, stop:1 #808080);\n"
"    line-height: 30px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #FF8C00, stop:0.95 #808080, stop:1 #808080); /* Dark orange gradient when hovering */\n"
"    color: #000;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: #808080; /* Dark grey background when pressed */\n"
"    color: #000;\n"
"}\n"
""));
        pushButton_14 = new QPushButton(dockWidgetContents_6);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(790, -10, 161, 61));
        pushButton_14->setFont(font21);
        pushButton_14->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    outline: 0;\n"
"    text-align: center;\n"
"    padding: 17px 30px;\n"
"    border: 0;\n"
"    color: #fff;\n"
"    font-size: 17.5px;\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #36c275, stop:0.95 #808080, stop:1 #808080);\n"
"    line-height: 30px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #FF8C00, stop:0.95 #808080, stop:1 #808080); /* Dark orange gradient when hovering */\n"
"    color: #000;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: #808080; /* Dark grey background when pressed */\n"
"    color: #000;\n"
"}\n"
""));
        pushButton_15 = new QPushButton(dockWidgetContents_6);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(950, -10, 161, 61));
        pushButton_15->setFont(font21);
        pushButton_15->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    outline: 0;\n"
"    text-align: center;\n"
"    padding: 17px 30px;\n"
"    border: 0;\n"
"    color: #fff;\n"
"    font-size: 17.5px;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #36c275, stop:0.95 #808080, stop:1 #808080);\n"
"    line-height: 30px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #FF8C00, stop:0.95 #808080, stop:1 #808080); /* Dark orange gradient when hovering */\n"
"    color: #000;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: #808080; /* Dark grey background when pressed */\n"
"    color: #000;\n"
"}\n"
""));
        pushButton_16 = new QPushButton(dockWidgetContents_6);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(1110, -10, 191, 61));
        pushButton_16->setFont(font21);
        pushButton_16->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    outline: 0;\n"
"    text-align: center;\n"
"    padding: 17px 30px;\n"
"    border: 0;\n"
"    color: #fff;\n"
"    font-size: 17.5px;\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #36c275, stop:0.95 #808080, stop:1 #808080);\n"
"    line-height: 30px;\n"
"    font-weight: 800;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 #808080, stop:0.05 #808080, stop:0.5 #FF8C00, stop:0.95 #808080, stop:1 #808080); /* Dark orange gradient when hovering */\n"
"    color: #000;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: #808080; /* Dark grey background when pressed */\n"
"    color: #000;\n"
"}\n"
""));
        dock->setWidget(dockWidgetContents_6);
        pushButton_11->raise();
        label_3->raise();
        pushButton_12->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        pushButton_15->raise();
        pushButton_16->raise();
        Main_trash->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, dock);

        retranslateUi(Main_trash);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Main_trash);
    } // setupUi

    void retranslateUi(QMainWindow *Main_trash)
    {
        Main_trash->setWindowTitle(QCoreApplication::translate("Main_trash", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("Main_trash", "Unit", nullptr));
        Generat_Button->setText(QCoreApplication::translate("Main_trash", "Generate", nullptr));
        properties->setTitle(QString());
        recyclable->setText(QCoreApplication::translate("Main_trash", "Recyclable", nullptr));
        bio->setText(QCoreApplication::translate("Main_trash", "Biodegradable", nullptr));
        reusable->setText(QCoreApplication::translate("Main_trash", "Reusable", nullptr));
        label_5->setText(QCoreApplication::translate("Main_trash", "Properties :", nullptr));
        reset->setText(QCoreApplication::translate("Main_trash", "Reset", nullptr));
        groupBox->setTitle(QString());
        add1->setText(QCoreApplication::translate("Main_trash", "ADD / Modify", nullptr));
        display1->setText(QCoreApplication::translate("Main_trash", "Display / Delete / PDF", nullptr));
        rech1->setText(QCoreApplication::translate("Main_trash", "Search / Sort", nullptr));
        stat1->setText(QCoreApplication::translate("Main_trash", "Statistic", nullptr));
        label_17->setText(QString());
        label->setText(QString());
        unit->setItemText(0, QCoreApplication::translate("Main_trash", "Gram (g)", nullptr));
        unit->setItemText(1, QCoreApplication::translate("Main_trash", "Kilogram (kg)", nullptr));
        unit->setItemText(2, QCoreApplication::translate("Main_trash", "Tonne (t)", nullptr));

        check_button->setText(QCoreApplication::translate("Main_trash", "Check", nullptr));
        modify->setText(QCoreApplication::translate("Main_trash", "Modify", nullptr));
        add->setText(QCoreApplication::translate("Main_trash", "ADD", nullptr));
        type->setTitle(QString());
        glass->setText(QCoreApplication::translate("Main_trash", "Glass", nullptr));
        paper->setText(QCoreApplication::translate("Main_trash", "Paper", nullptr));
        metal->setText(QCoreApplication::translate("Main_trash", "Metal", nullptr));
        plastic->setText(QCoreApplication::translate("Main_trash", "Plastic", nullptr));
        label_12->setText(QCoreApplication::translate("Main_trash", "       CODE", nullptr));
        label_2->setText(QCoreApplication::translate("Main_trash", "Material Type :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Main_trash", "Tab 1", nullptr));
        groupBox_2->setTitle(QString());
        add2->setText(QCoreApplication::translate("Main_trash", "ADD / Modify", nullptr));
        display2->setText(QCoreApplication::translate("Main_trash", "Display / Delete / PDF", nullptr));
        rech2->setText(QCoreApplication::translate("Main_trash", "Search / Sort", nullptr));
        stat2->setText(QCoreApplication::translate("Main_trash", "Statistic", nullptr));
        label_18->setText(QString());
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("Main_trash", "Display - sort - delete", nullptr));
        delete_2->setText(QCoreApplication::translate("Main_trash", "Delete", nullptr));
        label_13->setText(QCoreApplication::translate("Main_trash", "       CODE", nullptr));
        exportall->setText(QCoreApplication::translate("Main_trash", "Export ALL", nullptr));
        exportdisplayed->setText(QCoreApplication::translate("Main_trash", "Export\n"
"Displayed", nullptr));
        reset_2->setText(QCoreApplication::translate("Main_trash", "Reset", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Main_trash", "Tab 2", nullptr));
        groupBox_4->setTitle(QString());
        add3->setText(QCoreApplication::translate("Main_trash", "ADD / Modify", nullptr));
        display3->setText(QCoreApplication::translate("Main_trash", "Display / Delete / PDF", nullptr));
        rech3->setText(QCoreApplication::translate("Main_trash", "Search / Sort", nullptr));
        stat3->setText(QCoreApplication::translate("Main_trash", "Statistic", nullptr));
        label_19->setText(QString());
        label_10->setText(QString());
        groupBox_3->setTitle(QString());
        typeCheckBox->setText(QCoreApplication::translate("Main_trash", " Type", nullptr));
        dateCheckBox->setText(QCoreApplication::translate("Main_trash", " Date", nullptr));
        metal_2->setText(QCoreApplication::translate("Main_trash", "Metal", nullptr));
        plastic_2->setText(QCoreApplication::translate("Main_trash", "Plastic", nullptr));
        glass_2->setText(QCoreApplication::translate("Main_trash", "Glass", nullptr));
        paper_2->setText(QCoreApplication::translate("Main_trash", "Paper", nullptr));
        label_9->setText(QCoreApplication::translate("Main_trash", "Search", nullptr));
        groupBox_6->setTitle(QString());
        recyclableCheckBox->setText(QCoreApplication::translate("Main_trash", "recyclable", nullptr));
        reusableCheckBox->setText(QCoreApplication::translate("Main_trash", "Reusable", nullptr));
        biodegradableCheckBox->setText(QCoreApplication::translate("Main_trash", "Biodegradable", nullptr));
        ascendingButton->setText(QCoreApplication::translate("Main_trash", "Ascending", nullptr));
        descendingButton->setText(QCoreApplication::translate("Main_trash", "Descending", nullptr));
        label_15->setText(QCoreApplication::translate("Main_trash", "Properties", nullptr));
        label_16->setText(QCoreApplication::translate("Main_trash", "Amount", nullptr));
        label_14->setText(QCoreApplication::translate("Main_trash", "Sort", nullptr));
        label_21->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Main_trash", "Page", nullptr));
        groupBox_5->setTitle(QString());
        add4->setText(QCoreApplication::translate("Main_trash", "ADD / Modify", nullptr));
        display4->setText(QCoreApplication::translate("Main_trash", "Display / Delete / PDF", nullptr));
        rech4->setText(QCoreApplication::translate("Main_trash", "Search / Sort", nullptr));
        stat4->setText(QCoreApplication::translate("Main_trash", "Statistic", nullptr));
        label_20->setText(QString());
        label_11->setText(QString());
        stats_1->setText(QCoreApplication::translate("Main_trash", "Metal PieChart", nullptr));
        stats_2->setText(QCoreApplication::translate("Main_trash", "Glass PieChart", nullptr));
        stats_3->setText(QCoreApplication::translate("Main_trash", "Paper PieChart", nullptr));
        stats_4->setText(QCoreApplication::translate("Main_trash", "Plastic PieChart", nullptr));
        stack->setText(QCoreApplication::translate("Main_trash", "proportion Bar-Graph", nullptr));
        mecha->setText(QString());
        glacha->setText(QString());
        papcha->setText(QString());
        placha->setText(QString());
        stacha->setText(QString());
        GIF->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Main_trash", "Page", nullptr));
        label_3->setText(QCoreApplication::translate("Main_trash", "Earth Rebirth", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Main_trash", "Tab-1", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Main_trash", "Tab-1", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Main_trash", "Tab-1", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Main_trash", "Tab-1", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Main_trash", "Tab-1", nullptr));
        pushButton_16->setText(QCoreApplication::translate("Main_trash", "Tab-1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_trash: public Ui_Main_trash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_TRASH_H
