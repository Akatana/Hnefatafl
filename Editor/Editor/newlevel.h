#ifndef NEWLEVEL_H
#define NEWLEVEL_H

#include <QDialog>

namespace Ui {
class NewLevel;
}

class NewLevel : public QDialog
{
    Q_OBJECT

public:
    explicit NewLevel(QWidget *parent = nullptr);
    ~NewLevel();
    QString getLevelName() {
        return this->levelName;
    }
    int getLevelSize() {
        return this->levelSize;
    }

private slots:
    void on_createButton_clicked();
    void on_cancelButton_clicked();

signals:
    void finished();
    void closed();

private:
    Ui::NewLevel *ui;
    QString levelName;
    int levelSize = 9;
};

#endif // NEWLEVEL_H
