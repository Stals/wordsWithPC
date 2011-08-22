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

private:
    Ui::MainWindow *ui;
    Validator validator;
    Dictionary dictionary;


    std::string pcWord;//Слово компьютера
    std::string playerWord;//Слово игрока

    int wordsCount; //Счётчик слов введённых пользователем

    //Обновляет Лейблы на форме
    void updateLabels();

    //Читает слово с формы и возвращает его в виде std::string
    std::string getPlayerWord();

    //Выводит str в строке состояния
    void showValidationStatus(const std::string str);

    //Спрашивает нужно ли добавить новое слово и если нужно добавляет его и возвращает true, иначе false
    bool addNewWord(std::string playerWord);

private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H
