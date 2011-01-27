#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>
#include "charFuncs.h"
#include "findword.h"

findWord fw;
cases c;
charFunc cf;

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

char MainWindow::getLastLetter(const std::string str){

        char last=str[str.size()-1];//последний символ
        if(last=='ы'||last=='ь'||last=='ъ'){
                return last=str[str.size()-2];
        }else return last;
}

void MainWindow::changeChar(char& letter){

        //делаем из ё -> е
        if(letter=='ё'){
                letter='е';
        }
        //делаем из й -> и
        if(letter=='й'){
                letter='и';
        }


}
void MainWindow::on_pushButton_clicked()

{
        //обновляем
        updateLabels();

        //Переводим слово в строку
        playerWord=getPlayerWord();

        if(playerWord!=""){//если хоть что то ввел то дальше идём

                //как минимум слово из 2 букв
                if(playerWord.size()>=2){

                        //Получим Необходимые нам символы, а заодно приведём их к нижнему регистру
                        playerFirstLetter=c.lowerCase(playerWord[0]);
                        playerLastLetter=c.lowerCase(getLastLetter(playerWord));
                        pcLastLetter=c.lowerCase(getLastLetter(pcWord));

                        //ё->е й->и так как они считаются одним и темже
                        changeChar(playerFirstLetter);
                        changeChar(playerLastLetter);


                        //проверим является ли последняя буква игрока русской
                        if(c.rusLetter(playerLastLetter)){

                                if(fw.checkUsed(playerWord)){//проверка - не использованлось ли уже слово

                                        if(pcWord!=""){//для любого хода кроме первого


                                                //проверим совпадает ли первая буква слова игрока с последней в слове компа
                                                if( playerFirstLetter==pcLastLetter){
                                                        showCondition("Правильный ввод");
                                                }else if( (playerFirstLetter=='и'&&pcLastLetter=='й')){
                                                        showCondition("Правильный ввод");

                                                }else if(( playerFirstLetter=='е'&&pcLastLetter=='ё')){
                                                        showCondition("Правильный ввод");
                                                }else{
                                                        showCondition("Неправильный первый символ");
                                                        goto end;

                                                }

                                        }else{//игрок ввел первое слово (оно не сравнивается так как у нас еще нет слова Компа)
                                                showCondition("Правильный ввод");
                                        }

                                        pcWord=fw.findRandomWord(playerLastLetter);//Получаем случайное слово в pcWord
                                        fw.usedWord(playerWord);//убрали слово из наших словарей чтобы потом его не повторить
                                        ++wordsCount;

                                }else{//слово уже использовалось
                                        showCondition("Это слово уже использовалось");
                                }
                        }else{//буква не русская (большая или маленькая)

                                showCondition("Не русское слово");
                        }

                }else{

                        showCondition("Слишком короткое слово");
                }

        }else{//нажал ок но ничего не ввел
                showCondition("Сначала что-нибудь напишите");

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
