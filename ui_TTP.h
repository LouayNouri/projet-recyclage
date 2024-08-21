/********************************************************************************
** Form generated from reading UI file 'TTP.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TTP_H
#define UI_TTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TTP
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *pitch;
    QLabel *label_6;
    QSlider *volume;
    QComboBox *language;
    QComboBox *voice;
    QLabel *label;
    QLabel *label_2;
    QSlider *rate;
    QComboBox *engine;
    QHBoxLayout *horizontalLayout;
    QPushButton *speakButton;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QPushButton *stopButton;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TextToSpeechWindow )
    {
        if (TextToSpeechWindow ->objectName().isEmpty())
            TextToSpeechWindow ->setObjectName(QStringLiteral("MainWindow"));
        TextToSpeechWindow ->resize(551, 448);
        centralwidget = new QWidget(TextToSpeechWindow );
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(plainTextEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        pitch = new QSlider(centralwidget);
        pitch->setObjectName(QStringLiteral("pitch"));
        pitch->setMinimum(-10);
        pitch->setMaximum(10);
        pitch->setSingleStep(1);
        pitch->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(pitch, 3, 2, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        volume = new QSlider(centralwidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setMaximum(100);
        volume->setSingleStep(5);
        volume->setPageStep(20);
        volume->setValue(70);
        volume->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volume, 1, 2, 1, 1);

        language = new QComboBox(centralwidget);
        language->setObjectName(QStringLiteral("language"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(language->sizePolicy().hasHeightForWidth());
        language->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(language, 5, 2, 1, 1);

        voice = new QComboBox(centralwidget);
        voice->setObjectName(QStringLiteral("voice"));

        gridLayout->addWidget(voice, 6, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        rate = new QSlider(centralwidget);
        rate->setObjectName(QStringLiteral("rate"));
        rate->setMinimum(-10);
        rate->setMaximum(10);
        rate->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rate, 2, 2, 1, 1);

        engine = new QComboBox(centralwidget);
        engine->setObjectName(QStringLiteral("engine"));
        sizePolicy2.setHeightForWidth(engine->sizePolicy().hasHeightForWidth());
        engine->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(engine, 4, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        speakButton = new QPushButton(centralwidget);
        speakButton->setObjectName(QStringLiteral("speakButton"));

        horizontalLayout->addWidget(speakButton);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);

        horizontalLayout->addWidget(pauseButton);

        resumeButton = new QPushButton(centralwidget);
        resumeButton->setObjectName(QStringLiteral("resumeButton"));
        resumeButton->setEnabled(false);

        horizontalLayout->addWidget(resumeButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout->addWidget(stopButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        TextToSpeechWindow ->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TextToSpeechWindow );
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TextToSpeechWindow ->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(language);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(plainTextEdit, speakButton);
        QWidget::setTabOrder(speakButton, pauseButton);
        QWidget::setTabOrder(pauseButton, resumeButton);
        QWidget::setTabOrder(resumeButton, stopButton);

        retranslateUi(TextToSpeechWindow );

        QMetaObject::connectSlotsByName(TextToSpeechWindow );
    } // setupUi

    void retranslateUi(QMainWindow *TextToSpeechWindow )
    {
        TextToSpeechWindow ->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "Hello QtTextToSpeech,\n"
"this is an example text in English.\n"
"\n"
"QtSpeech is a library that makes text to speech easy with Qt.\n"
"Done, over and out.", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Engine", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Pitch:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "&Language:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Voice name:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Rate:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Volume:", Q_NULLPTR));
        speakButton->setText(QApplication::translate("MainWindow", "Speak", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        resumeButton->setText(QApplication::translate("MainWindow", "Resume", Q_NULLPTR));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TextToSpeechWindow : public Ui_TTP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TTP_H
