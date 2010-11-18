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
    //������� ����� �����
    ui->label_2->setText(QString::fromLocal8Bit("C����: ")+QString::fromLocal8Bit(pcWord.c_str()));

     //������� ����� ��� ������� �������
    ui->label_3->setText(QString::fromLocal8Bit("�� ����� ")+QString::number(wordsCount)+QString::fromLocal8Bit(" ����") );
       }
void MainWindow::on_pushButton_clicked()
{
    //������ lowercase
    updateLabels();

    if(ui->playerWordForm->text()!=""){//���� ���� ��� �� ���� �� ������ ���
        QString test=ui->playerWordForm->text().toLocal8Bit();
        playerWord=test.toStdString();
        if(fw.checkUsed(playerWord)){

        if(pcWord!=""){//��� ������ ���� ����� �������
            //�������� ��������� �� ������ ����� ����� ������ � ��������� � ����� �����
            if((playerWord[0])!=pcWord[pcWord.size()-1]){
                ui->label_4->setText("Wrong first symbol");
                goto end;
            }else{
                ui->label_4->setText("Good first symbol");
            }

        }else{//����� ���� ������ �����
             ui->label_4->setText("Good first word");
        }
        if((playerWord[playerWord.size()-1]!='�')&&(playerWord[playerWord.size()-1]!='�')&&(playerWord[playerWord.size()-1]!='�')){
           pcWord=fw.findRandomWord(playerWord[playerWord.size()-1],playerWord);
       }else{
            pcWord=fw.findRandomWord(playerWord[playerWord.size()-2],playerWord);
       }
   }else{//����� ��� ��������������
    ui->label_4->setText("Already used word");
   }

    }else{//����� �� �� ������ �� ����
         ui->label_4->setText("Write somthing first");

    }
    end:


updateLabels();
ui->playerWordForm->clear();

if(pcWord=="YOU WIN"){
    //TODO:
//�������� ������ � ��� ������� OK �������
}
    //���� �� ����� � ������ ��� ��������������?
}
