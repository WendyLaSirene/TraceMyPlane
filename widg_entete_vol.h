#ifndef WIDG_ENTETE_VOL_H
#define WIDG_ENTETE_VOL_H

#include <QWidget>

namespace Ui {
class Widg_Entete_Vol;
}

class Widg_Entete_Vol : public QWidget
{
    Q_OBJECT

public:
    explicit Widg_Entete_Vol(QWidget *parent = nullptr);
    ~Widg_Entete_Vol();

private:
    Ui::Widg_Entete_Vol *ui;
};

#endif // WIDG_ENTETE_VOL_H
