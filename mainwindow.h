#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QPushButton>
#include <string>
#include <iostream>
#include <list>
#include "cases.h"
#include "findword.h"
#include "check.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Check check; //����� ��������
    Dictionary dictionary;


    std::string pcWord;//��� �������� � ����������� ������ ����� �����
    char pcLastLetter;
    std::string playerWord;
    char playerFirstLetter;
    char playerLastLetter;

    int wordsCount; //������� ���� �������� �������������

    void updateLabels();
    std::string getPlayerWord();                  //������ ����� � ����� � ������������ ��� �� Qstring � std::string
    void showCondition(const std::string str);    //������� str � ������ ���������

private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H
