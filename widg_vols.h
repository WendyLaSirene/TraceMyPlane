#ifndef WIDG_VOLS_H
#define WIDG_VOLS_H

#include <QWidget>

namespace Ui {
class widg_Vols;
}

class widg_Vols : public QWidget
{
    Q_OBJECT

public:
    explicit widg_Vols(QWidget *parent = nullptr);
    void setFlyName(QString);
    void setStartEnd(QString,QString);
    ~widg_Vols();

private:
    Ui::widg_Vols *ui;
};

#endif // WIDG_VOLS_H
