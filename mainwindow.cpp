#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "findword.h"
#include <windows.h>


findWord fw;
cases c;
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
void MainWindow::showCondition(std::string str){

 ui->label_4->setText(QString::fromLocal8Bit(str.c_str()));
}
void MainWindow::on_pushButton_clicked()
{
    //���������
    updateLabels();

    //��������� ����� � ������
    playerWord=getPlayerWord();


    if(ui->playerWordForm->text()!=""){//���� ���� ��� �� ���� �� ������ ���

       //��� ������� ����� �� 2 ����
       if(playerWord.size()>=2){

       //�������� �������� �� ��������� ����� ������ �������
       if((c.rusLetter(playerWord[playerWord.size()-1]))&&(c.rusLetter(playerWord[playerWord.size()-2]))){
           //������ lowercase
        playerWord=c.lowerCase(playerWord);
        //������ �� � -> �
        if(playerWord[playerWord.size()-1]=='�'){
            playerWord[playerWord.size()-1]='�';
        }
        //������ �� � -> �
        if(playerWord[playerWord.size()-1]=='�'){
            playerWord[playerWord.size()-1]='�';
        }

        if(fw.checkUsed(playerWord)){//�������� - �� ��������������� �� ��� �����

        if(pcWord!=""){//��� ������ ���� ����� �������
            char pcLastLetter = pcWord[pcWord.size()-1];
            if(pcLastLetter=='�'||pcLastLetter=='�'||pcLastLetter=='�'){
                pcLastLetter = pcWord[pcWord.size()-2];
            }

             //�������� ��������� �� ������ ����� ����� ������ � ��������� � ����� �����
            if((playerWord[0])==pcLastLetter){
                showCondition("���������� ����");
            }else if((playerWord[0]=='�'&&pcLastLetter=='�')||(playerWord[0]=='�'&&pcLastLetter=='�')){
                 showCondition("���������� ����");

             }else if((playerWord[0]=='�'&&pcLastLetter=='�')||(playerWord[0]=='�'&&pcLastLetter=='�')){
                 showCondition("���������� ����");
            }else{
                 showCondition("������������ ������ ������");
                 goto end;

            }

        }else{//����� ���� ������ �����
             showCondition("���������� ����");
        }
        if((playerWord[playerWord.size()-1]!='�')&&(playerWord[playerWord.size()-1]!='�')&&(playerWord[playerWord.size()-1]!='�')){
           pcWord=fw.findRandomWord(playerWord[playerWord.size()-1],playerWord);
           fw.usedWord(playerWord);//������ ����� �� ����� �������� ����� ����� ��� �� ���������
       }else{
            pcWord=fw.findRandomWord(playerWord[playerWord.size()-2],playerWord);
            fw.usedWord(playerWord);//������ ����� �� ����� �������� ����� ����� ��� �� ���������
       }
       ++wordsCount;
   }else{//����� ��� ��������������
     showCondition("��� ����� ��� ��������������");
   }
}else{//����� �� ������� (������� ��� ���������)

     showCondition("�� ������� �����");
}

}else{

 showCondition("������� �������� �����");
}

    }else{//����� �� �� ������ �� ����
        showCondition("������� ���-������ ��������");

    }
    end:

ui->playerWordForm->setFocus();
updateLabels();
ui->playerWordForm->clear();

if(pcWord=="YOU WIN"){
    //TODO:
//�������� ������ � ��� ������� OK �������
}
    //���� �� ����� � ������ ��� ��������������?
}
//Qt::Key_Enter
