/********************************************************************************
** Form generated from reading UI file 'newlevel.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLEVEL_H
#define UI_NEWLEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewLevel
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *createButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QToolButton *toolButton;
    QLineEdit *bgImage;

    void setupUi(QDialog *NewLevel)
    {
        if (NewLevel->objectName().isEmpty())
            NewLevel->setObjectName(QString::fromUtf8("NewLevel"));
        NewLevel->setEnabled(true);
        NewLevel->resize(240, 219);
        NewLevel->setFocusPolicy(Qt::StrongFocus);
        horizontalLayoutWidget = new QWidget(NewLevel);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 180, 241, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        createButton = new QPushButton(horizontalLayoutWidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));

        horizontalLayout->addWidget(createButton);

        cancelButton = new QPushButton(horizontalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        label = new QLabel(NewLevel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 241, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        lineEdit = new QLineEdit(NewLevel);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 30, 241, 31));
        QFont font1;
        font1.setPointSize(11);
        lineEdit->setFont(font1);
        label_2 = new QLabel(NewLevel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 60, 241, 31));
        label_2->setFont(font);
        spinBox = new QSpinBox(NewLevel);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(0, 90, 241, 31));
        spinBox->setFont(font1);
        label_3 = new QLabel(NewLevel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 120, 241, 31));
        label_3->setFont(font);
        toolButton = new QToolButton(NewLevel);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(190, 150, 51, 31));
        bgImage = new QLineEdit(NewLevel);
        bgImage->setObjectName(QString::fromUtf8("bgImage"));
        bgImage->setGeometry(QRect(0, 150, 191, 31));
        QFont font2;
        font2.setPointSize(12);
        bgImage->setFont(font2);
        bgImage->setReadOnly(true);

        retranslateUi(NewLevel);

        QMetaObject::connectSlotsByName(NewLevel);
    } // setupUi

    void retranslateUi(QDialog *NewLevel)
    {
        NewLevel->setWindowTitle(QCoreApplication::translate("NewLevel", "Neues Level", nullptr));
        createButton->setText(QCoreApplication::translate("NewLevel", "Erstellen", nullptr));
        cancelButton->setText(QCoreApplication::translate("NewLevel", "Abbrechen", nullptr));
        label->setText(QCoreApplication::translate("NewLevel", "Level Name:", nullptr));
        label_2->setText(QCoreApplication::translate("NewLevel", "Feldl\303\244nge:", nullptr));
        label_3->setText(QCoreApplication::translate("NewLevel", "Hintergrundbild:", nullptr));
        toolButton->setText(QCoreApplication::translate("NewLevel", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewLevel: public Ui_NewLevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLEVEL_H
