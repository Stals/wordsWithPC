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
    // ������ ��� ����� ����� ������ ���� �����������
    this->setFixedSize(this->width(),this->height());
}


MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::updateLabels(){
    //������� ����� ����������
    if(pcWord.length() != 0){
        ui->pcWordLabel->setText(QString::fromLocal8Bit("C����: ") +
                                 QString::fromLocal8Bit(pcWord.c_str()));
    }else{
        ui->pcWordLabel->setText(QString::fromLocal8Bit("������� �����"));
    }

    //������� ����� ������ ��������� ����
    ui->wordsCountLabel->setText(QString::fromLocal8Bit("�� ����� ") +
                                 QString::number(wordsCount) + QString::fromLocal8Bit(" ����"));
}


//������� ����� ��������� ������������� �� �����
std::string MainWindow::getPlayerWord(){
    QString test=ui->playerWordForm->text().toLocal8Bit();
    return test.toStdString();
}


void MainWindow::showValidationStatus(const std::string str){
    ui->statusLabel->setText(QString::fromLocal8Bit(str.c_str()));
}


void MainWindow::on_pushButton_clicked(){

    //���� ��������� �� ���� ����� ����� - �� ��������
    if(pcWord == "YOU WIN"){
        exit(0);
    }

    updateLabels();

    //�������� ����� ������������
    playerWord = getPlayerWord();

    //�������� ����� � ������� ��������
    cases::toLowerCase( playerWord );

    //������� ������ �� ������� ��������� ����� ������ �����
    char playerLastLetter = charFuncs::getLastLetter( playerWord );

    //������� ����������� ������ ��� Validator'a
    char pcLastLetter = charFuncs::getLastLetter( pcWord );


    //������ �������� �� ��� �������
    if( validator.isWordValid( playerWord, pcLastLetter, dictionary ) == true ){
        //�������� ��������� ����� ����������
        pcWord = dictionary.findRandomWord( playerLastLetter );
        //������ ����� ��������� ������������� �� ������� ����� ����� ��� �� ���������
        dictionary.usedWord(playerWord, playerLastLetter);
        //����������� ���������� ������ ��������� ������������� ����
        ++wordsCount;
    }
    //������� ������ �������� ������������
    showValidationStatus( validator.getStatus() );

    ui->playerWordForm->setFocus();
    updateLabels();
    ui->playerWordForm->clear();

}
