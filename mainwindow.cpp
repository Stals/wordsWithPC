#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findword.h"
#include <windows.h>


findWord fw;
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
void MainWindow::on_pushButton_clicked()
{
    //делаем lowercase
    updateLabels();

    if(ui->playerWordForm->text()!=""){//если хоть что то ввел то дальше идём
        QString test=ui->playerWordForm->text().toLocal8Bit();
        playerWord=test.toStdString();
        //как минимум слово из 2 букв
        if(playerWord.size()>=2){
       cases c;
       //проверим является ли последняя буква игрок русской
       if((c.rusLetter(playerWord[playerWord.size()-1]))&&(c.rusLetter(playerWord[playerWord.size()-2]))){
        playerWord=c.lowerCase(playerWord);
        //делаем из ё -> е
        if(playerWord[playerWord.size()-1]=='ё'){
            playerWord[playerWord.size()-1]='е';
        }
        //делаем из й -> и
        if(playerWord[playerWord.size()-1]=='й'){
            playerWord[playerWord.size()-1]='и';
        }

        if(fw.checkUsed(playerWord)){//проверка - не использованлось ли уже слово

        if(pcWord!=""){//для любого хода кроме первого
            char pcLastLetter = pcWord[pcWord.size()-1];
            if(pcLastLetter=='ы'||pcLastLetter=='ь'||pcLastLetter=='ъ'){
                pcLastLetter = pcWord[pcWord.size()-2];
            }

             //проверим совпадает ли первая буква слова игрока с последней в слове компа
            if((playerWord[0])==pcLastLetter){
                ui->label_4->setText(QString::fromLocal8Bit("Правильный ввод"));
            }else if((playerWord[0]=='и'&&pcLastLetter=='й')||(playerWord[0]=='й'&&pcLastLetter=='и')){
                 ui->label_4->setText(QString::fromLocal8Bit("Правильный ввод"));

             }else if((playerWord[0]=='е'&&pcLastLetter=='ё')||(playerWord[0]=='ё'&&pcLastLetter=='е')){
                 ui->label_4->setText(QString::fromLocal8Bit("Правильный ввод"));
            }else{
                ui->label_4->setText(QString::fromLocal8Bit("Неправильный первый символ"));
                 goto end;

            }

        }else{//игрок ввел первое слово
             ui->label_4->setText(QString::fromLocal8Bit("Правильный ввод"));
        }
        if((playerWord[playerWord.size()-1]!='ы')&&(playerWord[playerWord.size()-1]!='ъ')&&(playerWord[playerWord.size()-1]!='ь')){
           pcWord=fw.findRandomWord(playerWord[playerWord.size()-1],playerWord);
       }else{
            pcWord=fw.findRandomWord(playerWord[playerWord.size()-2],playerWord);
       }
       ++wordsCount;
   }else{//слово уже использовалось
    ui->label_4->setText(QString::fromLocal8Bit("Это слово уже использовалось"));
   }
}else{//буква не русская (большая или маленькая)

    ui->label_4->setText(QString::fromLocal8Bit("Не русское слово"));
}

}else{

ui->label_4->setText(QString::fromLocal8Bit("Слишком короткое слово"));
}

    }else{//нажал ок но ничего не ввел
        ui->label_4->setText(QString::fromLocal8Bit("Сначала что-нибудь напишите"));

    }
    end:

ui->playerWordForm->setFocus();
updateLabels();
ui->playerWordForm->clear();

if(pcWord=="YOU WIN"){
    //TODO:
//сообщаем игроку и при нажатии OK выходим
}
    //Есть ли слово в скиске уже использованных?
}
//Qt::Key_Enter
