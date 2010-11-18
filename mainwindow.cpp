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
        if(fw.checkUsed(playerWord)){

        if(pcWord!=""){//для любого хода кроме первого
            //проверим совпадает ли первая буква слова игрока с последней в слове компа
            if((playerWord[0])!=pcWord[pcWord.size()-1]){
                ui->label_4->setText("Wrong first symbol");
                goto end;
            }else{
                ui->label_4->setText("Good first symbol");
            }

        }else{//игрок ввел первое слово
             ui->label_4->setText("Good first word");
        }
        if((playerWord[playerWord.size()-1]!='ы')&&(playerWord[playerWord.size()-1]!='ъ')&&(playerWord[playerWord.size()-1]!='ь')){
           pcWord=fw.findRandomWord(playerWord[playerWord.size()-1],playerWord);
       }else{
            pcWord=fw.findRandomWord(playerWord[playerWord.size()-2],playerWord);
       }
   }else{//слово уже использовалось
    ui->label_4->setText("Already used word");
   }

    }else{//нажал ок но ничего не ввел
         ui->label_4->setText("Write somthing first");

    }
    end:


updateLabels();
ui->playerWordForm->clear();

if(pcWord=="YOU WIN"){
    //TODO:
//сообщаем игроку и при нажатии OK выходим
}
    //Есть ли слово в скиске уже использованных?
}
