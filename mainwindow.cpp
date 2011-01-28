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

        //������� ����� �����
        ui->label_2->setText(QString::fromLocal8Bit("C����: ")+QString::fromLocal8Bit(pcWord.c_str()));

        //������� ����� ��� ������� �������
        ui->label_3->setText(QString::fromLocal8Bit("�� ����� ")+QString::number(wordsCount)+QString::fromLocal8Bit(" ����") );
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
        //���������
        updateLabels();

        //��������� ����� � ������
        playerWord=getPlayerWord();

        //������� ����������� ��� �������, � ������ ������� ��� � ������� ��������
        playerLastLetter=c.lowerCase(getLastLetter(playerWord));

        //�->� �->� ��� ��� ��� ��������� ����� � �����
        changeChar(playerLastLetter);

        if(check.playerWord(playerWord,pcWord,c,fw)){//������ �������� �� ��� �������

                pcWord=fw.findRandomWord(playerLastLetter);//�������� ��������� ����� � pcWord
                fw.usedWord(playerWord);//������ ����� �� ����� �������� ����� ����� ��� �� ���������
                ++wordsCount;
        }
        //������� ������ �� check
        showCondition(check.stringStatus());


        ui->playerWordForm->setFocus();
        updateLabels();
        ui->playerWordForm->clear();


        //���� �� ����� � ������ ��� ��������������?
}
