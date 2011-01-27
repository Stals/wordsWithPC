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

    std::string pcWord;//для хранения и дальнейшего вывода слова компа
    char pcLastLetter;
    std::string playerWord;
    char playerLastLetter;

    int wordsCount;

    void updateLabels();
    std::string getPlayerWord();            //Конвертирует слово из Qstring в std::string
    void showCondition(const std::string str);    //Выводит str в строке состояния
    char getLastLetter(const std::string str);    //Возвращает последний символ, при этом возвращает предпоследний если последний ь ъ ы
    void changeChar(char& letter);//если символ ё меняет на е и если символ й меняет на и
private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H
