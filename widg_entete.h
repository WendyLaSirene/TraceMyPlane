#ifndef WIDG_ENTETE_H
#define WIDG_ENTETE_H

#include <QWidget>

namespace Ui {
class Widg_Entete;
}

class Widg_Entete : public QWidget
{
    Q_OBJECT

public:
    explicit Widg_Entete(QWidget *parent = nullptr);
    void setTitle(QString);
    void setIcon(QString);
    ~Widg_Entete();

private:
    Ui::Widg_Entete *ui;
};

#endif // WIDG_ENTETE_H
