#include <QtGui/QApplication>
#include "mainwindow.h"
#include <locale>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setlocale(LC_ALL,".1251");
    MainWindow w;
    w.show();
    return a.exec();
}
