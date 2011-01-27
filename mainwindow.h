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
    std::string playerWord;

    int wordsCount;

    void updateLabels();
    std::string getPlayerWord();
private slots:
    void on_pushButton_clicked();


};

#endif // MAINWINDOW_H
