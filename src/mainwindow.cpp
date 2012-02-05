#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <windows.h>

#include "utils\cases.h"
#include "utils\charFuncs.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pcWord(""),
    wordsCount(0)
{
    ui->setupUi(this);
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


// Получим слово введенное пользователем на форме
// Сразу приведем его к нижнему регистру и поменяем 'ё' и 'й' на 'е' и 'и'
std::string MainWindow::getPlayerWord(){
    QString qplayerWord = ui->playerWordForm->text().toLocal8Bit();
    std::string playerWord = qplayerWord.toStdString();
    cases::toLowerCase( playerWord );
    charFuncs::changeString(playerWord);
    return playerWord;
}


void MainWindow::showValidationStatus(const std::string str){
    ui->statusLabel->setText(QString::fromLocal8Bit(str.c_str()));
}


bool MainWindow::addNewWord(std::string playerWord){

    QMessageBox msgBox;
    msgBox.setWindowTitle(QString::fromLocal8Bit("Игра \"Слова\""));
    msgBox.setText (QString::fromLocal8Bit("Слова \"") +
                    QString::fromLocal8Bit(playerWord.c_str()) +
                    QString::fromLocal8Bit("\" нет в словаре.\nХотите добавить его?"));

    msgBox.setStandardButtons (QMessageBox::Yes | QMessageBox::No );
    msgBox.setDefaultButton (QMessageBox::Yes);

    int result = msgBox.exec ();

    switch  (result)  {
    case QMessageBox::Yes:
        //Еслм Да - тогда сохраним слово на диске
        dictionary.addNewWord(playerWord);
        return true;
        break;
    case QMessageBox::No:
        //Если Нет - попросим пользователся ввести другое слово
        validator.setCurrentStatus(Status::NotNewWord);
        return false;
        break;
    default:
        return false;
        break;
    }
    return false;

}


void MainWindow::on_pushButton_clicked(){

    //Если компьютер не смог найти слова - вы выйграли
    if(pcWord == "YOU WIN")
        exit(0);

    updateLabels();

    playerWord = getPlayerWord();
    cases::toLowerCase( playerWord );

    //Получим символ на который компьютер будет искать слово
    char playerLastLetter = charFuncs::getLastLetter( playerWord );

    //Получим необходимый символ для Validator'a
    char pcLastLetter = charFuncs::getLastLetter( pcWord );


    bool isWordValid = validator.isWordValid( playerWord, pcLastLetter, dictionary );
    bool isNewWord = dictionary.isNewWord(playerWord);
    //Если слово проходит проверку И
    //( (это не новое слово) ИЛИ (если является новым словом И мы добавляем его в словарь) )
    if( isWordValid && ( !isNewWord || ( isNewWord && addNewWord(playerWord) ) ) ){

        //добавим слово в список использованных чтобы потом его не мог повторить игрок
        dictionary.addUsedWord( playerWord );

        //убирем слово введенное пользователем из словаря чтобы потом его не мог повторить компьютер
        dictionary.removeWord( playerWord );

        //Увеличиваем количество удачно введенных пользователем слов
        ++wordsCount;

        //Получаем случайное слово компьютера
        pcWord = dictionary.findRandomWord( playerLastLetter );
    }
    //выводим статус проверки пользователю
    showValidationStatus( validator.getCurrentStatus() );

    ui->playerWordForm->setFocus();
    ui->playerWordForm->clear();
    updateLabels();    

}
