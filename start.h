#ifndef START_H
#define START_H

#include <QDialog>
#include "LevelManager.h"

namespace Ui {
class START;
}

class START : public QDialog
{
    Q_OBJECT

public:
    explicit START(QWidget *parent = nullptr);
    ~START();

private slots:
    void on_pushButtonLev1_clicked();
    void on_pushButtonLev2_clicked();
    void on_pushButtonLev3_clicked();
    void on_pushButtonLev4_clicked();
    void on_pushButtonLev5_clicked();

private:
    Ui::START *ui;
   LevelManager Manager;
};

#endif // START_H
