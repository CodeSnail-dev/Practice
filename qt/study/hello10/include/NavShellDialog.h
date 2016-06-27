/********************************************************************************
** Form generated from reading UI file 'sample.ui'
**
** Created: Mon Jun 6 21:29:42 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NAVSHELLDIALOG_H
#define NAVSHELLDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QSpinBox>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

#include "stdio.h"

QT_BEGIN_NAMESPACE

class NavShellDialog : public QObject
{
Q_OBJECT

public:
    QDialogButtonBox *buttonBox;
    QPushButton *showButton;
    QPushButton *hideButton;
    QSpinBox *volumeSpinBox;
    QSlider *volumeSlider;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(222, 101);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 70, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        	
        showButton = new QPushButton(Dialog);
        showButton->setObjectName(QString::fromUtf8("ShowButton"));
        showButton->setGeometry(QRect(0, 0, 111, 41));
        
        hideButton = new QPushButton(Dialog);
        hideButton->setObjectName(QString::fromUtf8("HideButton"));
        hideButton->setGeometry(QRect(110, 0, 111, 41));
        
        volumeSpinBox = new QSpinBox(Dialog);
        volumeSpinBox->setObjectName(QString::fromUtf8("volumeEditor"));
        volumeSpinBox->setEnabled(false);
        volumeSpinBox->setGeometry(QRect(170, 40, 51, 31));
        volumeSpinBox->setRange(0, 100);
        
        volumeSlider = new QSlider(Dialog);
        volumeSlider->setObjectName(QString::fromUtf8("volumeProgressbar"));
        volumeSlider->setGeometry(QRect(9, 40, 151, 31));
        volumeSlider->setOrientation(Qt::Horizontal);
        volumeSlider->setRange(0, 100);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));
        QObject::connect(showButton, SIGNAL(clicked()), this, SLOT(show()));
        QObject::connect(hideButton, SIGNAL(clicked()), this, SLOT(hide()));
        
        QObject::connect(volumeSlider, SIGNAL(valueChanged(int)), volumeSpinBox, SLOT(setValue(int)));
        QObject::connect(volumeSpinBox, SIGNAL(valueChanged(int)), volumeSlider, SLOT(setValue(int)));
        

        QMetaObject::connectSlotsByName(Dialog);
        
        volumeSlider->setValue(30);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        showButton->setText(QApplication::translate("Dialog", "Show", 0, QApplication::UnicodeUTF8));
        hideButton->setText(QApplication::translate("Dialog", "Hide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

public slots:
    void show()
    {
        printf("show()\n");
    }
    
    void hide()
    {
        printf("hide()\n");
    }
};

namespace NavShell {
    class Dialog: public NavShellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SAMPLE_H
