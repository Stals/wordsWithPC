#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QPushButton>
#include <string>
#include <iostream>
#include <list>
#include "cases.h"
#include "dictionary.h"
#include "validator.h"

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
    Validator validator;
    Dictionary dictionary;


    std::string pcWord;//����� ����������
    char pcLastLetter; //��������� ������ ����� ����������
    std::string playerWord;//����� ������
    char playerFirstLetter;
    char playerLastLetter;

    int wordsCount; //������� ���� �������� �������������

    //��������� ������ �� �����
    void updateLabels();
    //������ ����� � ����� � ���������� ��� � ���� std::string
    std::string getPlayerWord();
    //������� str � ������ ���������
    void showValidationStatus(const std::string str);

private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H
