#ifndef TTP_H
#define TTP_H

#include <QtWidgets/qmainwindow.h>

#include "ui_TTP.h"

#include <QTextToSpeech>

namespace Ui {
class TextToSpeechWindow;
}

class TextToSpeechWindow : public QMainWindow
{
    Q_OBJECT
public:
    TextToSpeechWindow(QWidget *parent = 0, const QString &data = QString());

    void queryLocales();

public slots:
    void speak();
    void stop();

    void setRate(int);
    void setPitch(int);
    void setVolume(int volume);

    void stateChanged(QTextToSpeech::State state);
    void engineSelected(int index);
    void languageSelected(int language);
    void voiceSelected(int index);

    void localeChanged(const QLocale &locale);
    void updatePlainText(const QString &data);

private:
    Ui::TextToSpeechWindow *ui3;
    QTextToSpeech *m_speech;
    QVector<QVoice> m_voices;
    bool m_localesQueried;
};

#endif


