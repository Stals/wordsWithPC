#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include <list>

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
    std::string playerWord;

    int wordsCount;

    void updateLabels();
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
