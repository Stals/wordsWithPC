/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 23. Aug 19:39:03 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *pcWordLabel;
    QVBoxLayout *verticalLayout;
    QLineEdit *playerWordForm;
    QPushButton *pushButton;
    QLabel *wordsCountLabel;
    QFrame *line;
    QLabel *statusLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(245, 137);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action->setCheckable(true);
        action->setChecked(true);
        action->setEnabled(true);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_2->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pcWordLabel = new QLabel(centralWidget);
        pcWordLabel->setObjectName(QString::fromUtf8("pcWordLabel"));
        pcWordLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(pcWordLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        playerWordForm = new QLineEdit(centralWidget);
        playerWordForm->setObjectName(QString::fromUtf8("playerWordForm"));

        verticalLayout->addWidget(playerWordForm);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setAutoDefault(true);
        pushButton->setDefault(true);

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        wordsCountLabel = new QLabel(centralWidget);
        wordsCountLabel->setObjectName(QString::fromUtf8("wordsCountLabel"));
        wordsCountLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(wordsCountLabel);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Yota InterFace"));
        statusLabel->setFont(font);
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(statusLabel);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(playerWordForm, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260 \"\320\241\320\273\320\276\320\262\320\260\"", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\320\241\320\273\321\203\321\207\320\260\320\271\320\275\320\276", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\321\201\321\201", 0, QApplication::UnicodeUTF8));
        pcWordLabel->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\273\320\276\320\262\320\276", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "OK", 0, QApplication::UnicodeUTF8));
        wordsCountLabel->setText(QApplication::translate("MainWindow", "\320\222\321\213 \320\262\320\262\320\265\320\273\320\270 0 \321\201\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\276\320\261\321\213 \320\275\320\260\321\207\320\260\321\202\321\214 \320\262\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\273\320\276\320\262\320\276 \320\270 \320\275\320\260\320\266\320\270\321\202\320\265 \"OK\"", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
