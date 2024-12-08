#ifndef OVER_H
#define OVER_H

#include <QDialog>

namespace Ui {
class OVER;
}

class OVER : public QDialog
{
    Q_OBJECT

public:
    explicit OVER(QWidget *parent = nullptr);
    ~OVER();

private:
    Ui::OVER *ui;
};

#endif // OVER_H
