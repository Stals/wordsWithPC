#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>
#include "charFuncs.h"
#include "findword.h"
#include "check.h"

findWord fw;
cases c;

check check;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::showCondition(const std::string str){

        ui->label_4->setText(QString::fromLocal8Bit(str.c_str()));

}


void MainWindow::on_pushButton_clicked()

{
    if(pcWord=="YOU WIN"){
        exit(0);
    }
        //обновляем
        updateLabels();

        //Переводим слово в строку
        playerWord=getPlayerWord();

        //Получим Необходимый нам символы, а заодно приведём его к нижнему регистру
        playerLastLetter=c.lowerCase(getLastLetter(playerWord));

        //ё->е й->и так как они считаются одним и темже
        changeChar(playerLastLetter);

        if(check.playerWord(playerWord,pcWord,c,fw)){//делаем проверку на все условия

                pcWord=fw.findRandomWord(playerLastLetter);//Получаем случайное слово в pcWord
                fw.usedWord(playerWord);//убрали слово из наших словарей чтобы потом его не повторить
                ++wordsCount;
        }
        //выводим статус из check
        showCondition(check.stringStatus());


        ui->playerWordForm->setFocus();
        updateLabels();
        ui->playerWordForm->clear();


        //Есть ли слово в скиске уже использованных?
}
