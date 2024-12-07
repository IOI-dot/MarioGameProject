#ifndef STORE_H
#define STORE_H

#include <QDialog>
#include <QMessageBox>
#include "level3.h"

namespace Ui {
class Store;
}

class Store : public QDialog
{
    Q_OBJECT

public:
    explicit Store(Level3 *level, QWidget *parent = nullptr);
    ~Store();



private slots:
    void on_pushButtonBuyMushroom_clicked();

    void on_pushButtonBuyFireFlower_clicked();

    void on_pushButtonBuyLife_clicked();

    void on_pushButtonBuyStar_clicked();

    void on_pushButtonNext_clicked();

private:
    Ui::Store *ui;
    Level3 *Level;
};

#endif // STORE_H
