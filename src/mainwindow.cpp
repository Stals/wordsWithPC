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


// ������� ����� ��������� ������������� �� �����
// ����� �������� ��� � ������� �������� � �������� '�' � '�' �� '�' � '�'
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
    msgBox.setWindowTitle(QString::fromLocal8Bit("���� \"�����\""));
    msgBox.setText (QString::fromLocal8Bit("����� \"") +
                    QString::fromLocal8Bit(playerWord.c_str()) +
                    QString::fromLocal8Bit("\" ��� � �������.\n������ �������� ���?"));

    msgBox.setStandardButtons (QMessageBox::Yes | QMessageBox::No );
    msgBox.setDefaultButton (QMessageBox::Yes);

    int result = msgBox.exec ();

    switch  (result)  {
    case QMessageBox::Yes:
        //���� �� - ����� �������� ����� �� �����
        dictionary.addNewWord(playerWord);
        return true;
        break;
    case QMessageBox::No:
        //���� ��� - �������� ������������� ������ ������ �����
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

    //���� ��������� �� ���� ����� ����� - �� ��������
    if(pcWord == "YOU WIN")
        exit(0);

    updateLabels();

    playerWord = getPlayerWord();
    cases::toLowerCase( playerWord );

    //������� ������ �� ������� ��������� ����� ������ �����
    char playerLastLetter = charFuncs::getLastLetter( playerWord );

    //������� ����������� ������ ��� Validator'a
    char pcLastLetter = charFuncs::getLastLetter( pcWord );


    bool isWordValid = validator.isWordValid( playerWord, pcLastLetter, dictionary );
    bool isNewWord = dictionary.isNewWord(playerWord);
    //���� ����� �������� �������� �
    //( (��� �� ����� �����) ��� (���� �������� ����� ������ � �� ��������� ��� � �������) )
    if( isWordValid && ( !isNewWord || ( isNewWord && addNewWord(playerWord) ) ) ){

        //������� ����� � ������ �������������� ����� ����� ��� �� ��� ��������� �����
        dictionary.addUsedWord( playerWord );

        //������ ����� ��������� ������������� �� ������� ����� ����� ��� �� ��� ��������� ���������
        dictionary.removeWord( playerWord );

        //����������� ���������� ������ ��������� ������������� ����
        ++wordsCount;

        //�������� ��������� ����� ����������
        pcWord = dictionary.findRandomWord( playerLastLetter );
    }
    //������� ������ �������� ������������
    showValidationStatus( validator.getCurrentStatus() );

    ui->playerWordForm->setFocus();
    ui->playerWordForm->clear();
    updateLabels();    

}
