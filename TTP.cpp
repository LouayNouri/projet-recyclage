#include "TTP.h"
#include <QLoggingCategory>

TextToSpeechWindow::TextToSpeechWindow(QWidget *parent, const QString &data)
    : QMainWindow(parent),
    m_speech(nullptr)
{
    qDebug() << "Constructing TextToSpeechWindow";
        ui3 = new Ui::TextToSpeechWindow; // Add this line
        ui3->setupUi(this);
        qDebug() << "1st test";
    this->move(1330,0);
    ui3->plainTextEdit->setPlainText(data);
    QLoggingCategory::setFilterRules(QStringLiteral("qt.speech.tts=true \n qt.speech.tts.*=true"));

    // Populate engine selection list
    ui3->engine->addItem("Default", QString("default"));
    const auto engines = QTextToSpeech::availableEngines();
    for (const QString &engine : engines)
        ui3->engine->addItem(engine, engine);
    ui3->engine->setCurrentIndex(0);
    engineSelected(0);

    connect(ui3->speakButton, &QPushButton::clicked, this, &TextToSpeechWindow::speak);
    connect(ui3->pitch, &QSlider::valueChanged, this, &TextToSpeechWindow::setPitch);
    connect(ui3->rate, &QSlider::valueChanged, this, &TextToSpeechWindow::setRate);
    connect(ui3->volume, &QSlider::valueChanged, this, &TextToSpeechWindow::setVolume);
    connect(ui3->engine, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::engineSelected);

    qDebug() << "TextToSpeechWindow constructed";

    ui3->speakButton->setStyleSheet("QPushButton {font: 14pt bold;color: #319515;border: 2px solid transparent; border-radius: 10px;padding: 5px;min-width: 70px;}QPushButton:hover {border: 2px solid #319515;; }");
    ui3->resumeButton->setStyleSheet("QPushButton {font: 14pt bold;color: #319515;border: 2px solid transparent; border-radius: 10px;padding: 5px;min-width: 70px;}QPushButton:hover {border: 2px solid #319515;; }");
    ui3->pauseButton->setStyleSheet("QPushButton {font: 14pt bold;color: #319515;border: 2px solid transparent; border-radius: 10px;padding: 5px;min-width: 70px;}QPushButton:hover {border: 2px solid #319515;; }");
    ui3->stopButton->setStyleSheet("QPushButton {font: 14pt bold;color: red;border: 2px solid transparent; border-radius: 10px;padding: 5px;min-width: 70px;}QPushButton:hover {border: 2px solid red;; }");
    ui3->plainTextEdit->setStyleSheet("color: white;");
    ui3->label_2->setStyleSheet("font: 10pt bold;color: white;");
    ui3->label_3->setStyleSheet("color: white;font: 10pt bold");
    ui3->label_4->setStyleSheet("color: white;font: 10pt bold");
    ui3->label_5->setStyleSheet("color: white;font: 10pt bold");
    ui3->label_6->setStyleSheet("color: white;font: 10pt bold");
    ui3->label->setStyleSheet("color: white;font: 10pt bold");
    ui3->centralwidget->setStyleSheet("background-image: url(C:/Users/MEGA-PC/Desktop/QT-test/Project_2/dark-green-wall-backdrop-grunge-background-texture.jpg);");
    ui3->engine->view()->setStyleSheet("color: white;");
    ui3->language->view()->setStyleSheet("color: white;");
    ui3->voice->view()->setStyleSheet("color: white;");

}
void TextToSpeechWindow::updatePlainText(const QString &data)
{
    ui3->plainTextEdit->setPlainText(data);
}


void TextToSpeechWindow::speak()
{
    m_speech->say(ui3->plainTextEdit->toPlainText());
}
void TextToSpeechWindow::stop()
{
    m_speech->stop();
}

void TextToSpeechWindow::setRate(int rate)
{
    m_speech->setRate(rate / 10.0);
}

void TextToSpeechWindow::setPitch(int pitch)
{
    m_speech->setPitch(pitch / 10.0);
}

void TextToSpeechWindow::setVolume(int volume)
{
    m_speech->setVolume(volume / 100.0);
}

void TextToSpeechWindow::stateChanged(QTextToSpeech::State state)
{
    if (state == QTextToSpeech::Speaking) {
        ui3->statusbar->showMessage("Speech started...");
    } else if (state == QTextToSpeech::Ready) {
        ui3->statusbar->showMessage("Speech stopped...", 2000);
        if (!m_localesQueried)
            queryLocales();
    }
    else if (state == QTextToSpeech::Paused)
        ui3->statusbar->showMessage("Speech paused...");
    else
        ui3->statusbar->showMessage("Speech error!");

    ui3->pauseButton->setEnabled(state == QTextToSpeech::Speaking);
    ui3->resumeButton->setEnabled(state == QTextToSpeech::Paused);
    ui3->stopButton->setEnabled(state == QTextToSpeech::Speaking || state == QTextToSpeech::Paused);
}

void TextToSpeechWindow::engineSelected(int index)
{
    m_localesQueried = false;
    QString engineName = ui3->engine->itemData(index).toString();
    delete m_speech;
    if (engineName == "default")
        m_speech = new QTextToSpeech(this);
    else
        m_speech = new QTextToSpeech(engineName, this);

    connect(m_speech, &QTextToSpeech::stateChanged, this, &TextToSpeechWindow::stateChanged);
}

void TextToSpeechWindow::queryLocales()
{
    disconnect(ui3->language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::languageSelected);
    ui3->language->clear();
    // Populate the languages combobox before connecting its signal.
    const QVector<QLocale> locales = m_speech->availableLocales();
    QLocale current = m_speech->locale();
    for (const QLocale &locale : locales) {
        QString name(QString("%1 (%2)")
                     .arg(QLocale::languageToString(locale.language()))
                     .arg(QLocale::countryToString(locale.country())));
        QVariant localeVariant(locale);
        ui3->language->addItem(name, localeVariant);
        if (locale.name() == current.name())
            current = locale;
    }
    setRate(ui3->rate->value());
    setPitch(ui3->pitch->value());
    setVolume(ui3->volume->value());
    connect(ui3->stopButton, &QPushButton::clicked, m_speech, &QTextToSpeech::stop);
    connect(ui3->pauseButton, &QPushButton::clicked, m_speech, &QTextToSpeech::pause);
    connect(ui3->resumeButton, &QPushButton::clicked, m_speech, &QTextToSpeech::resume);

    connect(m_speech, &QTextToSpeech::localeChanged, this, &TextToSpeechWindow::localeChanged);

    connect(ui3->language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::languageSelected);
    localeChanged(current);
    m_localesQueried = true;
}

void TextToSpeechWindow::languageSelected(int language)
{
    QLocale locale = ui3->language->itemData(language).toLocale();
    m_speech->setLocale(locale);
}

void TextToSpeechWindow::voiceSelected(int index)
{
    m_speech->setVoice(m_voices.at(index));
}

void TextToSpeechWindow::localeChanged(const QLocale &locale)
{
    QVariant localeVariant(locale);
    ui3->language->setCurrentIndex(ui3->language->findData(localeVariant));

    disconnect(ui3->voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::voiceSelected);
    ui3->voice->clear();

    m_voices = m_speech->availableVoices();
    QVoice currentVoice = m_speech->voice();
    for (const QVoice &voice : qAsConst(m_voices)) {
        ui3->voice->addItem(QString("%1 - %2 - %3").arg(voice.name())
                          .arg(QVoice::genderName(voice.gender()))
                          .arg(QVoice::ageName(voice.age())));
        if (voice.name() == currentVoice.name())
            ui3->voice->setCurrentIndex(ui3->voice->count() - 1);
    }
    connect(ui3->voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::voiceSelected);
}

