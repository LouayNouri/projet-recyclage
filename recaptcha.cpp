#include "recaptcha.h"
#include "ui_recaptcha.h"
#include "randomstringgenerator.h"
#include <QDebug>
#include <QMessageBox>
recaptcha::recaptcha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recaptcha)
{
    ui->setupUi(this);

    // Generate a random string and set it in the line edit
    int length = 10; // You can adjust the length as needed
    generatedString = generateRandomString(length);
    ui->captcha->setText(generatedString);

    // Connect the clicked signal of the pushButton to the on_pushButton_clicked() slot
    connect(ui->pushButton, &QPushButton::clicked, this, &recaptcha::on_pushButton_clicked);
}

recaptcha::~recaptcha()
{
    delete ui;
}

QString recaptcha::generateRandomString(int length) {
    return ::generateRandomString(length);
}

void recaptcha::on_pushButton_clicked()
{
    QString enteredWord = ui->answer->text();
    qDebug() << "Entered Word:" << enteredWord;
    qDebug() << "Generated String:" << generatedString;

    if (enteredWord == generatedString) {
        emit captchaVerified(true); // Emit signal when captcha is correct
        accept();
    } else {
        emit captchaVerified(false); // Emit signal when captcha is incorrect
        QMessageBox::warning(this, "Try again", "CAPTCHA is incorrect!");
    }
}


