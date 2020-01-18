/********************************************************************************
** Form generated from reading UI file 'roommainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMMAINWINDOW_H
#define UI_ROOMMAINWINDOW_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *RoomPlaypushButton;
    QLabel *RoomCominglabel;
    QLabel *RoomRulelabel;
    QLabel *RoomLoadinglabel;
    QLabel *RoomPassageWaylabel;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QLineEdit *senderLine;
    QMenuBar *menubar;
    QMenu *menuRoom;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RoomMainWindow)
    {
        if (RoomMainWindow->objectName().isEmpty())
            RoomMainWindow->setObjectName(QStringLiteral("RoomMainWindow"));
        RoomMainWindow->resize(567, 480);
        RoomMainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(RoomMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        RoomPlaypushButton = new QPushButton(centralwidget);
        RoomPlaypushButton->setObjectName(QStringLiteral("RoomPlaypushButton"));
        RoomPlaypushButton->setGeometry(QRect(210, 330, 161, 71));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        RoomPlaypushButton->setFont(font);
        RoomPlaypushButton->setStyleSheet(QStringLiteral(""));
        RoomCominglabel = new QLabel(centralwidget);
        RoomCominglabel->setObjectName(QStringLiteral("RoomCominglabel"));
        RoomCominglabel->setGeometry(QRect(150, 300, 301, 131));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\351\273\204\350\215\211\347\256\200\344\275\223"));
        font1.setPointSize(26);
        RoomCominglabel->setFont(font1);
        RoomCominglabel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        RoomRulelabel = new QLabel(centralwidget);
        RoomRulelabel->setObjectName(QStringLiteral("RoomRulelabel"));
        RoomRulelabel->setGeometry(QRect(180, 20, 211, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\272\221\344\271\246\346\263\225\346\211\213\344\271\246\347\275\227\350\245\277\347\241\254\347\254\224\350\241\214\346\245\267"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        RoomRulelabel->setFont(font2);
        RoomRulelabel->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        RoomLoadinglabel = new QLabel(centralwidget);
        RoomLoadinglabel->setObjectName(QStringLiteral("RoomLoadinglabel"));
        RoomLoadinglabel->setGeometry(QRect(250, 100, 141, 141));
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe Print"));
        font3.setPointSize(26);
        font3.setBold(true);
        font3.setWeight(75);
        RoomLoadinglabel->setFont(font3);
        RoomLoadinglabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        RoomPassageWaylabel = new QLabel(centralwidget);
        RoomPassageWaylabel->setObjectName(QStringLiteral("RoomPassageWaylabel"));
        RoomPassageWaylabel->setGeometry(QRect(0, 0, 567, 426));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(140, 70, 291, 191));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 280, 71, 31));
        senderLine = new QLineEdit(centralwidget);
        senderLine->setObjectName(QStringLiteral("senderLine"));
        senderLine->setGeometry(QRect(140, 280, 221, 31));
        RoomMainWindow->setCentralWidget(centralwidget);
        RoomPassageWaylabel->raise();
        RoomPlaypushButton->raise();
        RoomRulelabel->raise();
        RoomCominglabel->raise();
        pushButton->raise();
        senderLine->raise();
        textBrowser->raise();
        RoomLoadinglabel->raise();
        menubar = new QMenuBar(RoomMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 567, 26));
        menuRoom = new QMenu(menubar);
        menuRoom->setObjectName(QStringLiteral("menuRoom"));
        RoomMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RoomMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RoomMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuRoom->menuAction());

        retranslateUi(RoomMainWindow);

        QMetaObject::connectSlotsByName(RoomMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RoomMainWindow)
    {
        RoomMainWindow->setWindowTitle(QApplication::translate("RoomMainWindow", "MainWindow", nullptr));
        RoomPlaypushButton->setText(QString());
        RoomCominglabel->setText(QApplication::translate("RoomMainWindow", "  \346\226\260\347\224\237\345\205\245\345\255\246\344\270\255......", nullptr));
        RoomRulelabel->setText(QApplication::translate("RoomMainWindow", "  \346\226\260\347\224\237\344\272\244\346\265\201\347\276\244", nullptr));
        RoomLoadinglabel->setText(QString());
        RoomPassageWaylabel->setText(QString());
        pushButton->setText(QApplication::translate("RoomMainWindow", "Send", nullptr));
        menuRoom->setTitle(QApplication::translate("RoomMainWindow", "Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomMainWindow: public Ui_RoomMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMMAINWINDOW_H
