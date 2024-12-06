#ifndef STORE_H
#define STORE_H

#include <QDialog>
#include <level1.h>
#include <QMessageBox>
#include "level1.h"

namespace Ui {
class Store;
}

class Store : public QDialog
{
    Q_OBJECT

public:
    explicit Store(Level1 *level, QWidget *parent = nullptr);
    ~Store();



private slots:
    void on_pushButtonBuyMushroom_clicked();

    void on_pushButtonBuyFireFlower_clicked();

    void on_pushButtonBuyLife_clicked();

    void on_pushButtonBuyStar_clicked();

private:
    Ui::Store *ui;
    Level1 *Level;
};

#endif // STORE_H
