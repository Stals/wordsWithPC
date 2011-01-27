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

char MainWindow::getLastLetter(const std::string str){

        char last=str[str.size()-1];//��������� ������
        if(last=='�'||last=='�'||last=='�'){
                return last=str[str.size()-2];
        }else return last;
}

void MainWindow::changeChar(char& letter){

        //������ �� � -> �
        if(letter=='�'){
                letter='�';
        }
        //������ �� � -> �
        if(letter=='�'){
                letter='�';
        }


}
void MainWindow::on_pushButton_clicked()

{
        //���������
        updateLabels();

        //��������� ����� � ������
        playerWord=getPlayerWord();

        if(playerWord!=""){//���� ���� ��� �� ���� �� ������ ���

                //��� ������� ����� �� 2 ����
                if(playerWord.size()>=2){

                        //������� ����������� ��� �������, � ������ ������� �� � ������� ��������
                        playerFirstLetter=c.lowerCase(playerWord[0]);
                        playerLastLetter=c.lowerCase(getLastLetter(playerWord));
                        pcLastLetter=c.lowerCase(getLastLetter(pcWord));

                        //�->� �->� ��� ��� ��� ��������� ����� � �����
                        changeChar(playerFirstLetter);
                        changeChar(playerLastLetter);


                        //�������� �������� �� ��������� ����� ������ �������
                        if(c.rusLetter(playerLastLetter)){

                                if(fw.checkUsed(playerWord)){//�������� - �� ��������������� �� ��� �����

                                        if(pcWord!=""){//��� ������ ���� ����� �������


                                                //�������� ��������� �� ������ ����� ����� ������ � ��������� � ����� �����
                                                if( playerFirstLetter==pcLastLetter){
                                                        showCondition("���������� ����");
                                                }else if( (playerFirstLetter=='�'&&pcLastLetter=='�')){
                                                        showCondition("���������� ����");

                                                }else if(( playerFirstLetter=='�'&&pcLastLetter=='�')){
                                                        showCondition("���������� ����");
                                                }else{
                                                        showCondition("������������ ������ ������");
                                                        goto end;

                                                }

                                        }else{//����� ���� ������ ����� (��� �� ������������ ��� ��� � ��� ��� ��� ����� �����)
                                                showCondition("���������� ����");
                                        }

                                        pcWord=fw.findRandomWord(playerLastLetter);//�������� ��������� ����� � pcWord
                                        fw.usedWord(playerWord);//������ ����� �� ����� �������� ����� ����� ��� �� ���������
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
