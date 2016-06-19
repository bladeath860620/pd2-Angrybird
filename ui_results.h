/********************************************************************************
** Form generated from reading UI file 'results.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTS_H
#define UI_RESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Results
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLabel *label_2;

    void setupUi(QDialog *Results)
    {
        if (Results->objectName().isEmpty())
            Results->setObjectName(QStringLiteral("Results"));
        Results->resize(400, 300);
        buttonBox = new QDialogButtonBox(Results);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Retry);
        buttonBox->setCenterButtons(true);
        label = new QLabel(Results);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 40, 200, 40));
        label->setFrameShape(QFrame::Box);
        lcdNumber = new QLCDNumber(Results);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(100, 80, 200, 40));
        label_2 = new QLabel(Results);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(6, 176, 381, 21));
        label_2->setFrameShape(QFrame::Box);

        retranslateUi(Results);
        QObject::connect(buttonBox, SIGNAL(accepted()), Results, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Results, SLOT(reject()));

        QMetaObject::connectSlotsByName(Results);
    } // setupUi

    void retranslateUi(QDialog *Results)
    {
        Results->setWindowTitle(QApplication::translate("Results", "Dialog", 0));
        label->setText(QApplication::translate("Results", "                      SCORE", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Results: public Ui_Results {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTS_H
