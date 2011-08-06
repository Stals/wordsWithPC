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


    std::string pcWord;//Слово компьютера
    char pcLastLetter; //Последний символ слова компьютера
    std::string playerWord;//Слово игрока
    char playerFirstLetter;
    char playerLastLetter;

    int wordsCount; //Счётчик слов введённых пользователем

    //Обновляет Лейблы на форме
    void updateLabels();
    //Читает слово с формы и возвращает его в виде std::string
    std::string getPlayerWord();
    //Выводит str в строке состояния
    void showValidationStatus(const std::string str);

private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H
