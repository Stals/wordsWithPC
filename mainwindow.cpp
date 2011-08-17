#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>
#include "cases.h"
#include "charFuncs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pcWord(""),
    wordsCount(0)
{
    ui->setupUi(this);
    // Делаем так чтобы форму нельзя было растягивать
    this->setFixedSize(this->width(),this->height());
}


MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::updateLabels(){
    //обновим слово компьютера
    if(pcWord.length() != 0){
        ui->pcWordLabel->setText(QString::fromLocal8Bit("Cлово: ") +
                                 QString::fromLocal8Bit(pcWord.c_str()));
    }else{
        ui->pcWordLabel->setText(QString::fromLocal8Bit("Введите слово"));
    }

    //обновим число удачно введенных слов
    ui->wordsCountLabel->setText(QString::fromLocal8Bit("Вы ввели ") +
                                 QString::number(wordsCount) + QString::fromLocal8Bit(" слов"));
}


//Получим слово введенное пользователем на форме
std::string MainWindow::getPlayerWord(){
    QString test=ui->playerWordForm->text().toLocal8Bit();
    return test.toStdString();
}


void MainWindow::showValidationStatus(const std::string str){
    ui->statusLabel->setText(QString::fromLocal8Bit(str.c_str()));
}


void MainWindow::on_pushButton_clicked(){

    //Если компьютер не смог найти слова - вы выйграли
    if(pcWord == "YOU WIN"){
        exit(0);
    }

    updateLabels();

    //Получаем слово пользователя
    playerWord = getPlayerWord();

    //Приводим слово к нижнему регистру
    cases::toLowerCase( playerWord );

    //Получим символ на который компьютер будет искать слово
    char playerLastLetter = charFuncs::getLastLetter( playerWord );

    //Получим необходимые сиволы для Validator'a
    char pcLastLetter = charFuncs::getLastLetter( pcWord );


    //Делаем проверку на все условия
    if( validator.isWordValid( playerWord, pcLastLetter, dictionary ) == true ){
        //Получаем случайное слово компьютера
        pcWord = dictionary.findRandomWord( playerLastLetter );
        //убирем слово введенное пользователем из словаря чтобы потом его не повторить
        dictionary.usedWord(playerWord, playerLastLetter);
        //Увеличиваем количество удачно введенных пользователем слов
        ++wordsCount;
    }
    //выводим статус проверки пользователю
    showValidationStatus( validator.getStatus() );

    ui->playerWordForm->setFocus();
    updateLabels();
    ui->playerWordForm->clear();

}
