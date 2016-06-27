/********************************************************************************
** Form generated from reading UI file 'sample.ui'
**
** Created: Wed Jun 1 17:37:49 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NAVSEHLLDIALOG_H
#define NAVSEHLLDIALOG_H
#pragma once
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <stdio.h>

QT_BEGIN_NAMESPACE

class NavShellDialog: public QObject
{
Q_OBJECT
public:
    QDialogButtonBox *buttonBox;
    QPushButton *showButton;
    QPushButton *hideButton;
    NavShellDialog *dialog;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(222, 79);
        
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 50, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        
        showButton = new QPushButton(Dialog);
        showButton->setObjectName(QString::fromUtf8("ShowButton"));
        showButton->setGeometry(QRect(0, 0, 111, 41));
        
        hideButton = new QPushButton(Dialog);
        hideButton->setObjectName(QString::fromUtf8("HideButton"));
        hideButton->setGeometry(QRect(110, 0, 111, 41));
        
        dialog = new NavShellDialog;

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));
        QObject::connect(showButton, SIGNAL(clicked()), dialog, SLOT(print_show()), Qt::QueuedConnection);
        QObject::connect(hideButton, SIGNAL(clicked()), dialog, SLOT(print_hide()), Qt::QueuedConnection);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        showButton->setText(QApplication::translate("Dialog", "Show", 0, QApplication::UnicodeUTF8));
        hideButton->setText(QApplication::translate("Dialog", "Hide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

private slots:
    void print_show()
    {
        printf("print_show()\n");
    }
    
    void print_hide()
    {
        printf("print_hide()\n");
    }
};

namespace NavShell {
    class Dialog: public NavShellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NAVSEHLLDIALOG_H
