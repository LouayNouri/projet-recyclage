#include "TTP.h"
#include <QLoggingCategory>

TextToSpeechWindow::TextToSpeechWindow(QWidget *parent)
    : QMainWindow(parent),
    m_speech(nullptr)
{
    qDebug() << "Constructing TextToSpeechWindow";
    ui->setupUi(this);
    QLoggingCategory::setFilterRules(QStringLiteral("qt.speech.tts=true \n qt.speech.tts.*=true"));

    // Populate engine selection list
    ui->engine->addItem("Default", QString("default"));
    const auto engines = QTextToSpeech::availableEngines();
    for (const QString &engine : engines)
        ui->engine->addItem(engine, engine);
    ui->engine->setCurrentIndex(0);
    engineSelected(0);

    connect(ui->speakButton, &QPushButton::clicked, this, &TextToSpeechWindow::speak);
    connect(ui->pitch, &QSlider::valueChanged, this, &TextToSpeechWindow::setPitch);
    connect(ui->rate, &QSlider::valueChanged, this, &TextToSpeechWindow::setRate);
    connect(ui->volume, &QSlider::valueChanged, this, &TextToSpeechWindow::setVolume);
    connect(ui->engine, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::engineSelected);
    qDebug() << "TextToSpeechWindow constructed";
}


void TextToSpeechWindow::speak()
{
    m_speech->say(ui->plainTextEdit->toPlainText());
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
        ui->statusbar->showMessage("Speech started...");
    } else if (state == QTextToSpeech::Ready) {
        ui->statusbar->showMessage("Speech stopped...", 2000);
        if (!m_localesQueried)
            queryLocales();
    }
    else if (state == QTextToSpeech::Paused)
        ui->statusbar->showMessage("Speech paused...");
    else
        ui->statusbar->showMessage("Speech error!");

    ui->pauseButton->setEnabled(state == QTextToSpeech::Speaking);
    ui->resumeButton->setEnabled(state == QTextToSpeech::Paused);
    ui->stopButton->setEnabled(state == QTextToSpeech::Speaking || state == QTextToSpeech::Paused);
}

void TextToSpeechWindow::engineSelected(int index)
{
    m_localesQueried = false;
    QString engineName = ui->engine->itemData(index).toString();
    delete m_speech;
    if (engineName == "default")
        m_speech = new QTextToSpeech(this);
    else
        m_speech = new QTextToSpeech(engineName, this);

    connect(m_speech, &QTextToSpeech::stateChanged, this, &TextToSpeechWindow::stateChanged);
}

void TextToSpeechWindow::queryLocales()
{
    disconnect(ui->language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::languageSelected);
    ui->language->clear();
    // Populate the languages combobox before connecting its signal.
    const QVector<QLocale> locales = m_speech->availableLocales();
    QLocale current = m_speech->locale();
    for (const QLocale &locale : locales) {
        QString name(QString("%1 (%2)")
                     .arg(QLocale::languageToString(locale.language()))
                     .arg(QLocale::countryToString(locale.country())));
        QVariant localeVariant(locale);
        ui->language->addItem(name, localeVariant);
        if (locale.name() == current.name())
            current = locale;
    }
    setRate(ui->rate->value());
    setPitch(ui->pitch->value());
    setVolume(ui->volume->value());
    connect(ui->stopButton, &QPushButton::clicked, m_speech, &QTextToSpeech::stop);
    connect(ui->pauseButton, &QPushButton::clicked, m_speech, &QTextToSpeech::pause);
    connect(ui->resumeButton, &QPushButton::clicked, m_speech, &QTextToSpeech::resume);

    connect(m_speech, &QTextToSpeech::localeChanged, this, &TextToSpeechWindow::localeChanged);

    connect(ui->language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::languageSelected);
    localeChanged(current);
    m_localesQueried = true;
}

void TextToSpeechWindow::languageSelected(int language)
{
    QLocale locale = ui->language->itemData(language).toLocale();
    m_speech->setLocale(locale);
}

void TextToSpeechWindow::voiceSelected(int index)
{
    m_speech->setVoice(m_voices.at(index));
}

void TextToSpeechWindow::localeChanged(const QLocale &locale)
{
    QVariant localeVariant(locale);
    ui->language->setCurrentIndex(ui->language->findData(localeVariant));

    disconnect(ui->voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::voiceSelected);
    ui->voice->clear();

    m_voices = m_speech->availableVoices();
    QVoice currentVoice = m_speech->voice();
    for (const QVoice &voice : qAsConst(m_voices)) {
        ui->voice->addItem(QString("%1 - %2 - %3").arg(voice.name())
                          .arg(QVoice::genderName(voice.gender()))
                          .arg(QVoice::ageName(voice.age())));
        if (voice.name() == currentVoice.name())
            ui->voice->setCurrentIndex(ui->voice->count() - 1);
    }
    connect(ui->voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TextToSpeechWindow::voiceSelected);
}

