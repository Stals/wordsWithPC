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
    //������� ����� ����������
    ui->pcWordLabel->setText(QString::fromLocal8Bit("C����: ")+QString::fromLocal8Bit(pcWord.c_str()));

    //������� ����� ��� ������� �������
    ui->wordsCountLabel->setText(QString::fromLocal8Bit("�� ����� ")+QString::number(wordsCount)+QString::fromLocal8Bit(" ����") );
}

//������� ����� ��������� ������������� �� �����
std::string MainWindow::getPlayerWord(){
    QString test=ui->playerWordForm->text().toLocal8Bit();
    return test.toStdString();
}

void MainWindow::showValidationStatus(const std::string str){
    ui->statusLabel->setText(QString::fromLocal8Bit(str.c_str()));
}

void MainWindow::on_pushButton_clicked()

{
    //���� ��������� �� ���� ����� ����� - �� ��������
    if(pcWord=="YOU WIN"){
        exit(0);
    }

    updateLabels();

    //�������� ����� ������������
    playerWord=getPlayerWord();

    //�������� ����� � ������� ��������
    cases::toLowerCase(playerWord);

    //������� ������ �� ������� ��������� ����� ������ �����
    playerLastLetter=charFuncs::getLastLetter(playerWord);

    //TODO ����� ��������� �� ���������� ���������� �������?
    //�->� �->� ��� ��� ��� ��������� ����� � �����
    charFuncs::changeChar(playerLastLetter);

    //������ �������� �� ��� �������
    if( validator.checkPlayerWord(playerWord, pcWord, dictionary) == OK ){
        //�������� ��������� ����� ����������
        pcWord=dictionary.findRandomWord(playerLastLetter);
        //������ ����� ��������� ������������� �� ������� ����� ����� ��� �� ���������
        dictionary.usedWord(playerWord, playerLastLetter);
        //����������� ���������� ������ ��������� ������������� ����
        ++wordsCount;
    }
    //������� ������ �������� ������������
    showValidationStatus(validator.getStatus());

    ui->playerWordForm->setFocus();
    updateLabels();
    ui->playerWordForm->clear();

}
