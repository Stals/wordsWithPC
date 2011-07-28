#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>
#include "cases.h"
#include "charFuncs.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    pcWord="";
    wordsCount=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::updateLabels(){
    //обновим слово компа
    ui->label_2->setText(QString::fromLocal8Bit("Cлово: ")+QString::fromLocal8Bit(pcWord.c_str()));

    //обновим число раз сколько вводили
    ui->label_3->setText(QString::fromLocal8Bit("Вы ввели ")+QString::number(wordsCount)+QString::fromLocal8Bit(" слов") );
}

std::string MainWindow::getPlayerWord(){
    QString test=ui->playerWordForm->text().toLocal8Bit();
    return test.toStdString();
}

void MainWindow::showCheckStatus(const std::string str){
    ui->label_4->setText(QString::fromLocal8Bit(str.c_str()));
}

void MainWindow::on_pushButton_clicked()

{

    if(pcWord=="YOU WIN"){
        exit(0);
    }
    //обновляем
    updateLabels();

    //Получаем слово пользователя
    playerWord=getPlayerWord();

    //Приводим слово к нижнему регистру
    cases::toLowerCase(playerWord);

    //Получим Необходимый нам символ
    playerLastLetter=charFuncs::getLastLetter(playerWord);

    //TODO может поставить до получаения последнего символа?
    //ё->е й->и так как они считаются одним и темже
    charFuncs::changeChar(playerLastLetter);

    if(validator.checkPlayerWord(playerWord,pcWord,dictionary)){//делаем проверку на все условия
        //Получаем случайное слово в pcWord
        pcWord=dictionary.findRandomWord(playerLastLetter);
        //убирем слово из наших словарей чтобы потом его не повторить
        dictionary.usedWord(playerWord,playerLastLetter);
        ++wordsCount;
    }
    //выводим статус из check
    showCheckStatus(validator.stringStatus());


    ui->playerWordForm->setFocus();
    updateLabels();
    ui->playerWordForm->clear();



}
