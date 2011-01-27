#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QPushButton>
#include <string>
#include <iostream>
#include <list>
#include "cases.h"
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

    std::string pcWord;//��� �������� � ����������� ������ ����� �����
    char pcLastLetter;
    std::string playerWord;
    char playerLastLetter;

    int wordsCount;

    void updateLabels();
    std::string getPlayerWord();            //������������ ����� �� Qstring � std::string
    void showCondition(const std::string str);    //������� str � ������ ���������
    char getLastLetter(const std::string str);    //���������� ��������� ������, ��� ���� ���������� ������������� ���� ��������� � � �
    void changeChar(char& letter);//���� ������ � ������ �� � � ���� ������ � ������ �� �
private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H
