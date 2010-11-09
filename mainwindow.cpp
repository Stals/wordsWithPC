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
    //������� ����� �����
    ui->label_2->setText(QString::fromLocal8Bit("C����: ")+QString::fromLocal8Bit(pcWord.c_str()));

     //������� ����� ��� ������� �������
    ui->label_3->setText(QString::fromLocal8Bit("�� ����� ")+QString::number(wordsCount)+QString::fromLocal8Bit(" ����") );
       }
void MainWindow::on_pushButton_clicked()
{
    //������ lowercase
    updateLabels();
    if(ui->playerWordForm->text()!=""){
        playerWord=ui->playerWordForm->text().toStdString();

        //if(pcWord!=""){//��� ������ ���� ����� �������
            //�������� ��������� �� ������ ����� ����� ������ � ��������� � ����� �����
            if((playerWord[0])==pcWord[pcWord.size()-1]){
                ui->label_3->setText("lol");
            }

        //}

    }
    //������ ����� ���������� = ��������� ����� �����?



    //���� �� ����� � ������ ��� ��������������?
}
