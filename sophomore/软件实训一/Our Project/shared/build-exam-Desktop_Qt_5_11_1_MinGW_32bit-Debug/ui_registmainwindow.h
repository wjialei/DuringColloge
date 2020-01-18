/********************************************************************************
** Form generated from reading UI file 'registmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTMAINWINDOW_H
#define UI_REGISTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistMainWindow
{
public:
    QWidget *centralwidget;
    QLabel *RegistAgainPasswordlabel;
    QPushButton *RegistRegistpushButton;
    QLabel *RegistIDlabel;
    QLineEdit *RegistAgainPasswordlineEdit;
    QLabel *RegistPasswordlabel;
    QLineEdit *RegistPasswordlineEdit;
    QLineEdit *RegistIDlineEdit;
    QLabel *RegistWavelabel;
    QLabel *RegistWarnlabel;
    QMenuBar *menubar;
    QMenu *menuRegist;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegistMainWindow)
    {
        if (RegistMainWindow->objectName().isEmpty())
            RegistMainWindow->setObjectName(QStringLiteral("RegistMainWindow"));
        RegistMainWindow->resize(600, 400);
        RegistMainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(RegistMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        RegistAgainPasswordlabel = new QLabel(centralwidget);
        RegistAgainPasswordlabel->setObjectName(QStringLiteral("RegistAgainPasswordlabel"));
        RegistAgainPasswordlabel->setGeometry(QRect(10, 160, 231, 61));
        QFont font;
        font.setFamily(QStringLiteral("Segoe Print"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        RegistAgainPasswordlabel->setFont(font);
        RegistAgainPasswordlabel->setStyleSheet(QStringLiteral("color: rgb(0,0,0);"));
        RegistRegistpushButton = new QPushButton(centralwidget);
        RegistRegistpushButton->setObjectName(QStringLiteral("RegistRegistpushButton"));
        RegistRegistpushButton->setGeometry(QRect(200, 250, 161, 71));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        RegistRegistpushButton->setFont(font1);
        RegistIDlabel = new QLabel(centralwidget);
        RegistIDlabel->setObjectName(QStringLiteral("RegistIDlabel"));
        RegistIDlabel->setGeometry(QRect(110, 30, 141, 51));
        RegistIDlabel->setFont(font);
        RegistIDlabel->setStyleSheet(QStringLiteral("color: rgb(0,0,0);"));
        RegistAgainPasswordlineEdit = new QLineEdit(centralwidget);
        RegistAgainPasswordlineEdit->setObjectName(QStringLiteral("RegistAgainPasswordlineEdit"));
        RegistAgainPasswordlineEdit->setGeometry(QRect(250, 180, 261, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe Print"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        RegistAgainPasswordlineEdit->setFont(font2);
        RegistAgainPasswordlineEdit->setMaxLength(16);
        RegistAgainPasswordlineEdit->setEchoMode(QLineEdit::Password);
        RegistPasswordlabel = new QLabel(centralwidget);
        RegistPasswordlabel->setObjectName(QStringLiteral("RegistPasswordlabel"));
        RegistPasswordlabel->setGeometry(QRect(10, 90, 231, 61));
        RegistPasswordlabel->setFont(font);
        RegistPasswordlabel->setStyleSheet(QStringLiteral("color: rgb(0,0,0);"));
        RegistPasswordlineEdit = new QLineEdit(centralwidget);
        RegistPasswordlineEdit->setObjectName(QStringLiteral("RegistPasswordlineEdit"));
        RegistPasswordlineEdit->setGeometry(QRect(250, 110, 261, 31));
        RegistPasswordlineEdit->setFont(font2);
        RegistPasswordlineEdit->setMaxLength(16);
        RegistPasswordlineEdit->setEchoMode(QLineEdit::Password);
        RegistIDlineEdit = new QLineEdit(centralwidget);
        RegistIDlineEdit->setObjectName(QStringLiteral("RegistIDlineEdit"));
        RegistIDlineEdit->setGeometry(QRect(250, 50, 261, 31));
        RegistIDlineEdit->setFont(font);
        RegistIDlineEdit->setMaxLength(10);
        RegistWavelabel = new QLabel(centralwidget);
        RegistWavelabel->setObjectName(QStringLiteral("RegistWavelabel"));
        RegistWavelabel->setGeometry(QRect(0, 0, 600, 338));
        RegistWarnlabel = new QLabel(centralwidget);
        RegistWarnlabel->setObjectName(QStringLiteral("RegistWarnlabel"));
        RegistWarnlabel->setGeometry(QRect(300, 150, 181, 21));
        RegistMainWindow->setCentralWidget(centralwidget);
        RegistWavelabel->raise();
        RegistAgainPasswordlabel->raise();
        RegistRegistpushButton->raise();
        RegistIDlabel->raise();
        RegistAgainPasswordlineEdit->raise();
        RegistPasswordlabel->raise();
        RegistPasswordlineEdit->raise();
        RegistIDlineEdit->raise();
        RegistWarnlabel->raise();
        menubar = new QMenuBar(RegistMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 26));
        menuRegist = new QMenu(menubar);
        menuRegist->setObjectName(QStringLiteral("menuRegist"));
        RegistMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegistMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RegistMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuRegist->menuAction());

        retranslateUi(RegistMainWindow);

        QMetaObject::connectSlotsByName(RegistMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegistMainWindow)
    {
        RegistMainWindow->setWindowTitle(QApplication::translate("RegistMainWindow", "MainWindow", nullptr));
        RegistAgainPasswordlabel->setText(QApplication::translate("RegistMainWindow", "Password Again:", nullptr));
        RegistRegistpushButton->setText(QString());
        RegistIDlabel->setText(QApplication::translate("RegistMainWindow", "Enter ID\357\274\232", nullptr));
        RegistAgainPasswordlineEdit->setText(QString());
        RegistPasswordlabel->setText(QApplication::translate("RegistMainWindow", "Enter Password\357\274\232", nullptr));
        RegistWavelabel->setText(QString());
        RegistWarnlabel->setText(QApplication::translate("RegistMainWindow", "Too Short\357\274\201At Least 6\357\274\201", nullptr));
        menuRegist->setTitle(QApplication::translate("RegistMainWindow", "Regist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistMainWindow: public Ui_RegistMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTMAINWINDOW_H
