/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNeu;
    QAction *actionSpeichern;
    QAction *actionAngreifer;
    QAction *actionVerteidiger;
    QAction *actionKoenig;
    QAction *actionEntfernen;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuHnefatafl_Editor;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/attacker.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNeu = new QAction(MainWindow);
        actionNeu->setObjectName(QString::fromUtf8("actionNeu"));
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName(QString::fromUtf8("actionSpeichern"));
        actionAngreifer = new QAction(MainWindow);
        actionAngreifer->setObjectName(QString::fromUtf8("actionAngreifer"));
        actionAngreifer->setIcon(icon);
        actionVerteidiger = new QAction(MainWindow);
        actionVerteidiger->setObjectName(QString::fromUtf8("actionVerteidiger"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/defender.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8("../../assets/images/figures/set1_defender.png"), QSize(), QIcon::Normal, QIcon::On);
        actionVerteidiger->setIcon(icon1);
        actionKoenig = new QAction(MainWindow);
        actionKoenig->setObjectName(QString::fromUtf8("actionKoenig"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/king.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8("../../assets/images/figures/set1_king.png"), QSize(), QIcon::Normal, QIcon::On);
        actionKoenig->setIcon(icon2);
        actionEntfernen = new QAction(MainWindow);
        actionEntfernen->setObjectName(QString::fromUtf8("actionEntfernen"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEntfernen->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuHnefatafl_Editor = new QMenu(menuBar);
        menuHnefatafl_Editor->setObjectName(QString::fromUtf8("menuHnefatafl_Editor"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::AllToolBarAreas);
        toolBar->setOrientation(Qt::Vertical);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menuBar->addAction(menuHnefatafl_Editor->menuAction());
        menuHnefatafl_Editor->addAction(actionNeu);
        menuHnefatafl_Editor->addAction(actionSpeichern);
        toolBar->addAction(actionAngreifer);
        toolBar->addAction(actionVerteidiger);
        toolBar->addAction(actionKoenig);
        toolBar->addAction(actionEntfernen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Hnefatafl Editor", nullptr));
        actionNeu->setText(QCoreApplication::translate("MainWindow", "Neu", nullptr));
#if QT_CONFIG(shortcut)
        actionNeu->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSpeichern->setText(QCoreApplication::translate("MainWindow", "Speichern", nullptr));
#if QT_CONFIG(shortcut)
        actionSpeichern->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAngreifer->setText(QCoreApplication::translate("MainWindow", "Angreifer", nullptr));
#if QT_CONFIG(tooltip)
        actionAngreifer->setToolTip(QCoreApplication::translate("MainWindow", "Angreifer platzieren", nullptr));
#endif // QT_CONFIG(tooltip)
        actionVerteidiger->setText(QCoreApplication::translate("MainWindow", "Verteidiger", nullptr));
#if QT_CONFIG(tooltip)
        actionVerteidiger->setToolTip(QCoreApplication::translate("MainWindow", "Verteidiger platzieren", nullptr));
#endif // QT_CONFIG(tooltip)
        actionKoenig->setText(QCoreApplication::translate("MainWindow", "Koenig", nullptr));
#if QT_CONFIG(tooltip)
        actionKoenig->setToolTip(QCoreApplication::translate("MainWindow", "K\303\266nig platzieren", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEntfernen->setText(QCoreApplication::translate("MainWindow", "Entfernen", nullptr));
#if QT_CONFIG(tooltip)
        actionEntfernen->setToolTip(QCoreApplication::translate("MainWindow", "Figuren entfernen", nullptr));
#endif // QT_CONFIG(tooltip)
        menuHnefatafl_Editor->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
