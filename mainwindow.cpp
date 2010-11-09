#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pcWord="defias";
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
    if(ui->playerWordForm->text()!=""){
        playerWord=ui->playerWordForm->text().toStdString();

        //if(pcWord!=""){//для любого хода кроме первого
            //проверим совпадает ли первая буква слова игрока с последней в слове компа
            if((playerWord[0])==pcWord[pcWord.size()-1]){
                ui->label_3->setText("lol");
            }

        //}

    }
    //Первая буква введенного = последней слова компа?



    //Есть ли слово в скиске уже использованных?
}
