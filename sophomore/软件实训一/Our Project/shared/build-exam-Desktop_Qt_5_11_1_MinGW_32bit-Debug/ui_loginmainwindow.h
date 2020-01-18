/********************************************************************************
** Form generated from reading UI file 'loginmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINMAINWINDOW_H
#define UI_LOGINMAINWINDOW_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginMainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *LoginIDlineEdit;
    QPushButton *RegistpushButton;
    QLabel *Passwordlabel;
    QLineEdit *LoginPasswordlineEdit;
    QPushButton *LoginpushButton;
    QLabel *LoginIDlabel;
    QLabel *LoginWavelabel;
    QMenuBar *menuBar;
    QMenu *menuLogin;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginMainWindow)
    {
        if (LoginMainWindow->objectName().isEmpty())
            LoginMainWindow->setObjectName(QStringLiteral("LoginMainWindow"));
        LoginMainWindow->resize(600, 400);
        LoginMainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(LoginMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LoginIDlineEdit = new QLineEdit(centralWidget);
        LoginIDlineEdit->setObjectName(QStringLiteral("LoginIDlineEdit"));
        LoginIDlineEdit->setGeometry(QRect(290, 70, 281, 41));
        QFont font;
        font.setFamily(QStringLiteral("Segoe Print"));
        font.setPointSize(14);
        LoginIDlineEdit->setFont(font);
        LoginIDlineEdit->setMaxLength(10);
        RegistpushButton = new QPushButton(centralWidget);
        RegistpushButton->setObjectName(QStringLiteral("RegistpushButton"));
        RegistpushButton->setGeometry(QRect(70, 230, 141, 61));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        RegistpushButton->setFont(font1);
        RegistpushButton->setStyleSheet(QStringLiteral(""));
        Passwordlabel = new QLabel(centralWidget);
        Passwordlabel->setObjectName(QStringLiteral("Passwordlabel"));
        Passwordlabel->setGeometry(QRect(40, 140, 221, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe Print"));
        font2.setPointSize(26);
        font2.setBold(true);
        font2.setWeight(75);
        Passwordlabel->setFont(font2);
        Passwordlabel->setStyleSheet(QStringLiteral("color:rgb(0, 0, 0)"));
        LoginPasswordlineEdit = new QLineEdit(centralWidget);
        LoginPasswordlineEdit->setObjectName(QStringLiteral("LoginPasswordlineEdit"));
        LoginPasswordlineEdit->setGeometry(QRect(290, 160, 281, 41));
        LoginPasswordlineEdit->setFont(font);
        LoginPasswordlineEdit->setMaxLength(16);
        LoginPasswordlineEdit->setEchoMode(QLineEdit::Password);
        LoginpushButton = new QPushButton(centralWidget);
        LoginpushButton->setObjectName(QStringLiteral("LoginpushButton"));
        LoginpushButton->setGeometry(QRect(400, 230, 141, 61));
        LoginpushButton->setFont(font1);
        LoginIDlabel = new QLabel(centralWidget);
        LoginIDlabel->setObjectName(QStringLiteral("LoginIDlabel"));
        LoginIDlabel->setGeometry(QRect(120, 60, 81, 61));
        LoginIDlabel->setFont(font2);
        LoginIDlabel->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0)"));
        LoginWavelabel = new QLabel(centralWidget);
        LoginWavelabel->setObjectName(QStringLiteral("LoginWavelabel"));
        LoginWavelabel->setGeometry(QRect(0, 0, 600, 338));
        LoginMainWindow->setCentralWidget(centralWidget);
        LoginWavelabel->raise();
        LoginIDlineEdit->raise();
        LoginIDlabel->raise();
        Passwordlabel->raise();
        RegistpushButton->raise();
        LoginpushButton->raise();
        LoginPasswordlineEdit->raise();
        menuBar = new QMenuBar(LoginMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuLogin = new QMenu(menuBar);
        menuLogin->setObjectName(QStringLiteral("menuLogin"));
        LoginMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LoginMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoginMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuLogin->menuAction());

        retranslateUi(LoginMainWindow);

        QMetaObject::connectSlotsByName(LoginMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginMainWindow)
    {
        LoginMainWindow->setWindowTitle(QApplication::translate("LoginMainWindow", "LoginMainWindow", nullptr));
        RegistpushButton->setText(QString());
        Passwordlabel->setText(QApplication::translate("LoginMainWindow", "Password\357\274\232", nullptr));
        LoginpushButton->setText(QString());
        LoginIDlabel->setText(QApplication::translate("LoginMainWindow", "ID:", nullptr));
        LoginWavelabel->setText(QString());
        menuLogin->setTitle(QApplication::translate("LoginMainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginMainWindow: public Ui_LoginMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINMAINWINDOW_H
