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

class Ui_Dialog: public QObject
{
Q_OBJECT
public:
    QDialogButtonBox *buttonBox;
    QPushButton *ShowButton;
    QPushButton *HideButton;
    Ui_Dialog *dialog;

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
        
        ShowButton = new QPushButton(Dialog);
        ShowButton->setObjectName(QString::fromUtf8("ShowButton"));
        ShowButton->setGeometry(QRect(0, 0, 111, 41));
        
        HideButton = new QPushButton(Dialog);
        HideButton->setObjectName(QString::fromUtf8("HideButton"));
        HideButton->setGeometry(QRect(110, 0, 111, 41));
        
        dialog = new Ui_Dialog;

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));
//        QObject::connect(ShowButton, SIGNAL(clicked())), this, SLOT(print_show());
//        QObject::connect(ShowButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(ShowButton, SIGNAL(clicked()), dialog, SLOT(print_show()), Qt::QueuedConnection);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        ShowButton->setText(QApplication::translate("Dialog", "Show", 0, QApplication::UnicodeUTF8));
        HideButton->setText(QApplication::translate("Dialog", "Hide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

private slots:
    void print_show()
    {
        printf("print_show()\n");
    }
};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NAVSEHLLDIALOG_H
