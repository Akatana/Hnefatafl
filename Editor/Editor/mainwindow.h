#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QGroupBox>
#include <QObject>
#include <json.hpp>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "newlevel.h"

// for convenience
using json = nlohmann::json;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNeu_triggered();
    void dataRecieved();
    void windowClosed();
    void figurePlaced();
    void on_actionAngreifer_triggered();
    void on_actionVerteidiger_triggered();
    void on_actionKoenig_triggered();
    void on_actionEntfernen_triggered();
    void on_actionSpeichern_triggered();

private:
    Ui::MainWindow *ui;
    NewLevel *nl;
    QGridLayout *layout;
    int levelSize = 9;
    QString levelName;
    int selectedFigure = 0;
    QPixmap attackerFile = QPixmap(":/images/attacker.png");
    QIcon attackerIcon = QIcon(this->attackerFile);
    QPixmap defenderFile = QPixmap(":/images/defender.png");
    QIcon defenderIcon = QIcon(this->defenderFile);
    QPixmap kingFile = QPixmap(":/images/king.png");
    QIcon kingIcon = QIcon(this->kingFile);
};

#endif // MAINWINDOW_H
