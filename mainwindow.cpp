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

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::updateLabels(){
    //обновим слово компьютера
    ui->pcWordLabel->setText(QString::fromLocal8Bit("Cлово: ")+QString::fromLocal8Bit(pcWord.c_str()));

    //обновим число раз сколько вводили
    ui->wordsCountLabel->setText(QString::fromLocal8Bit("Вы ввели ")+QString::number(wordsCount)+QString::fromLocal8Bit(" слов") );
}

//Получим слово введенное пользователем на форме
std::string MainWindow::getPlayerWord(){
    QString test=ui->playerWordForm->text().toLocal8Bit();
    return test.toStdString();
}

void MainWindow::showValidationStatus(const std::string str){
    ui->statusLabel->setText(QString::fromLocal8Bit(str.c_str()));
}

void MainWindow::on_pushButton_clicked()

{
    //Если компьютер не смог найти слова - вы выйграли
    if(pcWord=="YOU WIN"){
        exit(0);
    }

    updateLabels();

    //Получаем слово пользователя
    playerWord=getPlayerWord();

    //Приводим слово к нижнему регистру
    cases::toLowerCase(playerWord);

    //Получим символ на который компьютер будет искать слово
    playerLastLetter=charFuncs::getLastLetter(playerWord);

    //TODO может поставить до получаения последнего символа?
    //ё->е й->и так как они считаются одним и темже
    charFuncs::changeChar(playerLastLetter);

    //Делаем проверку на все условия
    if( validator.checkPlayerWord(playerWord, pcWord, dictionary) == OK ){
        //Получаем случайное слово компьютера
        pcWord=dictionary.findRandomWord(playerLastLetter);
        //убирем слово введенное пользователем из словаря чтобы потом его не повторить
        dictionary.usedWord(playerWord, playerLastLetter);
        //Увеличиваем количество удачно введенных пользователем слов
        ++wordsCount;
    }
    //выводим статус проверки пользователю
    showValidationStatus(validator.getStatus());

    ui->playerWordForm->setFocus();
    updateLabels();
    ui->playerWordForm->clear();

}
