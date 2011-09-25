#include <QtGui/QApplication>
#include "mainwindow.h"
#include <locale>
#include <QRect>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setlocale(LC_ALL,".1251");
    MainWindow w;

    //������ ����� �� ������ ������
    QDesktopWidget *desktop = QApplication::desktop();
    w.move((desktop->screenGeometry().width() - w.width()) / 2, (desktop->screenGeometry().height() - w.height()) / 2);

    // ������ ��� ����� ����� ������ ���� �����������
    w.setFixedSize(w.width(),w.height());
    w.show();
    return a.exec();
}
