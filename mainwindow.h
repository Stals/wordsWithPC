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
    Check check; //Класс проверок
    Dictionary dictionary;


    std::string pcWord;//для хранения и дальнейшего вывода слова компа
    char pcLastLetter;
    std::string playerWord;
    char playerFirstLetter;
    char playerLastLetter;

    int wordsCount; //Счётчик слов введённых пользователем

    void updateLabels();
    std::string getPlayerWord();                  //Читает слово с формы и конвертирует его из Qstring в std::string
    void showCondition(const std::string str);    //Выводит str в строке состояния

private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H
