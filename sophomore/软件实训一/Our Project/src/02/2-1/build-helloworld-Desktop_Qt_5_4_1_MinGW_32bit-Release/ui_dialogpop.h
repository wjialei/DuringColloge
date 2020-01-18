/********************************************************************************
** Form generated from reading UI file 'dialogpop.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPOP_H
#define UI_DIALOGPOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogPop
{
public:

    void setupUi(QDialog *DialogPop)
    {
        if (DialogPop->objectName().isEmpty())
            DialogPop->setObjectName(QStringLiteral("DialogPop"));
        DialogPop->resize(400, 300);

        retranslateUi(DialogPop);

        QMetaObject::connectSlotsByName(DialogPop);
    } // setupUi

    void retranslateUi(QDialog *DialogPop)
    {
        DialogPop->setWindowTitle(QApplication::translate("DialogPop", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogPop: public Ui_DialogPop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPOP_H
