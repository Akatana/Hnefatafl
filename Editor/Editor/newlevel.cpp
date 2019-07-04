#include "newlevel.h"
#include "ui_newlevel.h"
#include <QLineEdit>
#include <QSpinBox>

NewLevel::NewLevel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLevel)
{
    ui->setupUi(this);
}

NewLevel::~NewLevel()
{
    delete ui;
}


void NewLevel::on_createButton_clicked()
{
    this->levelName = ui->lineEdit->text();
    this->levelSize = ui->spinBox->value();
    emit this->finished();
    this->close();
}

void NewLevel::on_cancelButton_clicked()
{
    emit this->closed();
    this->close();
}


