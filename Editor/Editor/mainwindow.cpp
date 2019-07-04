#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//New Level event
void MainWindow::on_actionNeu_triggered()
{
    nl = new NewLevel(this);
    MainWindow::setDisabled(true);
    nl->setDisabled(false);
    nl->show();
    QObject::connect(nl, &NewLevel::closed, this, &MainWindow::windowClosed);
    QObject::connect(nl, &NewLevel::finished, this, &MainWindow::dataRecieved);
}

void MainWindow::windowClosed() {
    this->setDisabled(false);
}

void MainWindow::dataRecieved() {
    this->setDisabled(false);
    qDeleteAll(this->centralWidget()->children());
    this->levelName = nl->getLevelName();
    this->levelSize = nl->getLevelSize();
    this->setWindowTitle("Hnefatafl Editor - " + this->levelName + ".json - NOT SAVED");

    const QSize btnSize = QSize(50, 50);
    this->layout = new QGridLayout(this);
    this->layout->setSpacing(0);
    for (int row = 0; row < this->levelSize; row++) {
        for (int column = 0; column < this->levelSize; column++) {
            QPushButton *button = new QPushButton();
            button->setText("");
            button->setFixedSize(btnSize);
            this->layout->addWidget(button, row, column, 1, 1);
            QObject::connect(button, &QPushButton::clicked, this, &MainWindow::figurePlaced);
        }
    }
    this->centralWidget()->setLayout(this->layout);
}

void MainWindow::figurePlaced() {
    QPushButton *button = (QPushButton *)sender();
    this->setWindowTitle("Hnefatafl Editor - " + this->levelName + ".json - NOT SAVED");
    //button->setText(this->levelName);
    switch (this->selectedFigure) {
        case 0:
            button->setProperty("type", 0);
            button->setIcon(QIcon());
            break;
        case 1:
            button->setProperty("type", 1);
            button->setIcon(this->attackerIcon);
            break;
        case 2:
            button->setProperty("type", 2);
            button->setIcon(this->defenderIcon);
            break;
        case 3:
            button->setProperty("type", 3);
            button->setIcon(this->kingIcon);
            break;
    }
    button->setIconSize(this->attackerFile.rect().size());
}

//Attacker selected
void MainWindow::on_actionAngreifer_triggered()
{
    this->selectedFigure = 1;
}

//Defender selected
void MainWindow::on_actionVerteidiger_triggered()
{
    this->selectedFigure = 2;
}

//King Selected
void MainWindow::on_actionKoenig_triggered()
{
    this->selectedFigure = 3;
}

//Remove figures
void MainWindow::on_actionEntfernen_triggered()
{
    this->selectedFigure = 0;
}

//Save level
void MainWindow::on_actionSpeichern_triggered()
{
    json level;
    std::vector<std::string> figures;

    for (int row = 0; row < this->levelSize; row++) {
        std::string figureRow = "";
        for (int column = 0; column < this->levelSize; column++) {
            QLayoutItem* item = this->layout->itemAtPosition(row, column);
            QWidget* widget = item->widget();
            QPushButton* button = dynamic_cast<QPushButton*>(widget);

            if (button->property("type") == 1) {
                figureRow.append("+");
                printf("%s", button->icon().name().toStdString().c_str());
            } else if (button->property("type") == 2) {
                figureRow.append("-");
            } else if (button->property("type") == 3) {
                figureRow.append("#");
            } else {
                figureRow.append(" ");
            }
        }
        figures.push_back(figureRow);
    }
    level["field"] = figures;
    level["name"] = this->levelName.toStdString();
    level["fieldImg"] = "assets/images/"+nl->getFileName().toStdString();
    std::string saveFile = "../assets/levels/" + this->levelName.toStdString() + ".json";
    std::ofstream file(saveFile);
    file << std::setw(4) << level << std::endl;
    this->setWindowTitle("Hnefatafl Editor - " + this->levelName + ".json - SAVED");
}
