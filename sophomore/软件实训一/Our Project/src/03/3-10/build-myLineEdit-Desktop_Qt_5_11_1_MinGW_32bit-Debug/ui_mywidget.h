/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QLineEdit *lineEdit1;
    QLabel *label;
    QLineEdit *lineEdit2;
    QLabel *label_2;
    QLineEdit *lineEdit3;
    QLabel *label_3;
    QLineEdit *lineEdit4;
    QLabel *label_4;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(400, 300);
        lineEdit1 = new QLineEdit(MyWidget);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));
        lineEdit1->setGeometry(QRect(120, 20, 221, 31));
        lineEdit1->setEchoMode(QLineEdit::Password);
        label = new QLabel(MyWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 71, 16));
        lineEdit2 = new QLineEdit(MyWidget);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        lineEdit2->setGeometry(QRect(120, 80, 221, 31));
        lineEdit2->setEchoMode(QLineEdit::Normal);
        label_2 = new QLabel(MyWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 61, 16));
        lineEdit3 = new QLineEdit(MyWidget);
        lineEdit3->setObjectName(QStringLiteral("lineEdit3"));
        lineEdit3->setGeometry(QRect(120, 140, 221, 31));
        lineEdit3->setEchoMode(QLineEdit::Normal);
        label_3 = new QLabel(MyWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 150, 54, 12));
        lineEdit4 = new QLineEdit(MyWidget);
        lineEdit4->setObjectName(QStringLiteral("lineEdit4"));
        lineEdit4->setGeometry(QRect(120, 200, 221, 31));
        lineEdit4->setEchoMode(QLineEdit::Normal);
        label_4 = new QLabel(MyWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 210, 54, 12));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", nullptr));
        lineEdit1->setInputMask(QString());
        label->setText(QApplication::translate("MyWidget", "\346\230\276\347\244\272\346\250\241\345\274\217\357\274\232", nullptr));
        lineEdit2->setInputMask(QApplication::translate("MyWidget", ">AA-90-bb-!aa\\#H;*", nullptr));
        lineEdit2->setText(QApplication::translate("MyWidget", "---#", nullptr));
        label_2->setText(QApplication::translate("MyWidget", "\350\276\223\345\205\245\346\216\251\347\240\201\357\274\232", nullptr));
        lineEdit3->setInputMask(QString());
        label_3->setText(QApplication::translate("MyWidget", "\350\276\223\345\205\245\351\252\214\350\257\201\357\274\232", nullptr));
        lineEdit4->setInputMask(QString());
        label_4->setText(QApplication::translate("MyWidget", "\350\207\252\345\212\250\345\256\214\346\210\220\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
