#include "randomstringgenerator.h"
#include <QDebug>

QString generateRandomString(int length) {
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString randomString;
    for (int i = 0; i < length; ++i) {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }

    qDebug() << "Generated Random String:" << randomString;

    return randomString;
}

