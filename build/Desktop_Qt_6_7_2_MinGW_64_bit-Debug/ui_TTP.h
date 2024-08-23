/********************************************************************************
** Form generated from reading UI file 'TTP.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TTP_H
#define UI_TTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextToSpeechWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_2;
    QComboBox *engine;
    QSlider *volume;
    QLabel *label_5;
    QComboBox *language;
    QLabel *label;
    QSlider *pitch;
    QComboBox *voice;
    QSlider *rate;
    QLabel *label_3;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout;
    QPushButton *speakButton;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QPushButton *stopButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TextToSpeechWindow)
    {
        if (TextToSpeechWindow->objectName().isEmpty())
            TextToSpeechWindow->setObjectName("TextToSpeechWindow");
        TextToSpeechWindow->resize(584, 775);
        centralwidget = new QWidget(TextToSpeechWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        plainTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        verticalLayout->addWidget(plainTextEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        engine = new QComboBox(centralwidget);
        engine->setObjectName("engine");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(engine->sizePolicy().hasHeightForWidth());
        engine->setSizePolicy(sizePolicy2);
        engine->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(engine, 4, 2, 1, 1);

        volume = new QSlider(centralwidget);
        volume->setObjectName("volume");
        volume->setMaximum(100);
        volume->setSingleStep(5);
        volume->setPageStep(20);
        volume->setValue(70);
        volume->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volume, 1, 2, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        language = new QComboBox(centralwidget);
        language->setObjectName("language");
        sizePolicy2.setHeightForWidth(language->sizePolicy().hasHeightForWidth());
        language->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(language, 5, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        pitch = new QSlider(centralwidget);
        pitch->setObjectName("pitch");
        pitch->setMinimum(-10);
        pitch->setMaximum(10);
        pitch->setSingleStep(1);
        pitch->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(pitch, 3, 2, 1, 1);

        voice = new QComboBox(centralwidget);
        voice->setObjectName("voice");

        gridLayout->addWidget(voice, 6, 2, 1, 1);

        rate = new QSlider(centralwidget);
        rate->setObjectName("rate");
        rate->setMinimum(-10);
        rate->setMaximum(10);
        rate->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rate, 2, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        speakButton = new QPushButton(centralwidget);
        speakButton->setObjectName("speakButton");
        speakButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(speakButton);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setEnabled(false);
        pauseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(pauseButton);

        resumeButton = new QPushButton(centralwidget);
        resumeButton->setObjectName("resumeButton");
        resumeButton->setEnabled(false);
        resumeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(resumeButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(170, 0, 0);\n"
"    border: 2px solid transparent; /* Invisible border */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    min-width: 70px;\n"
"}\n"
"QPushButton:hover {\n"
"    border: 2px solid rgb(74, 141, 198);; /* Blue border becomes visible when hovered over */\n"
"}\n"
""));

        horizontalLayout->addWidget(stopButton);


        verticalLayout->addLayout(horizontalLayout);

        TextToSpeechWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TextToSpeechWindow);
        statusbar->setObjectName("statusbar");
        TextToSpeechWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label_4->setBuddy(language);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(plainTextEdit, speakButton);
        QWidget::setTabOrder(speakButton, pauseButton);
        QWidget::setTabOrder(pauseButton, resumeButton);
        QWidget::setTabOrder(resumeButton, stopButton);

        retranslateUi(TextToSpeechWindow);

        QMetaObject::connectSlotsByName(TextToSpeechWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TextToSpeechWindow)
    {
        TextToSpeechWindow->setWindowTitle(QCoreApplication::translate("TextToSpeechWindow", "TextToSpeechWindow", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("TextToSpeechWindow", "Hello QtTextToSpeech,\n"
"this is an example text in English.\n"
"\n"
"QtSpeech is a library that makes text to speech easy with Qt.\n"
"Done, over and out.", nullptr));
        label_4->setText(QCoreApplication::translate("TextToSpeechWindow", "&Language:", nullptr));
        label_2->setText(QCoreApplication::translate("TextToSpeechWindow", "Volume:", nullptr));
        label_5->setText(QCoreApplication::translate("TextToSpeechWindow", "Engine", nullptr));
        label->setText(QCoreApplication::translate("TextToSpeechWindow", "Rate:", nullptr));
        label_3->setText(QCoreApplication::translate("TextToSpeechWindow", "Pitch:", nullptr));
        label_6->setText(QCoreApplication::translate("TextToSpeechWindow", "Voice name:", nullptr));
        speakButton->setText(QCoreApplication::translate("TextToSpeechWindow", "Speak", nullptr));
        pauseButton->setText(QCoreApplication::translate("TextToSpeechWindow", "Pause", nullptr));
        resumeButton->setText(QCoreApplication::translate("TextToSpeechWindow", "Resume", nullptr));
        stopButton->setText(QCoreApplication::translate("TextToSpeechWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextToSpeechWindow: public Ui_TextToSpeechWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTP_H
