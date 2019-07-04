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
    QFile::copy(this->filePath, "../assets/images/"+this->fileName);
    emit this->finished();
    this->close();
}

void NewLevel::on_cancelButton_clicked()
{
    emit this->closed();
    this->close();
}



void NewLevel::on_toolButton_clicked()
{
    this->filePath = QFileDialog::getOpenFileName(this, tr("Datei auswählen"),
                                                    ".png",
                                                    tr("Images (*.png)"));
    QFileInfo info(this->filePath);
    this->fileName = info.fileName();
    ui->bgImage->setText(info.fileName());
}
