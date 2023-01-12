#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>

namespace Ui {
class Accueil;
}

class Accueil : public QWidget
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

private:
    Ui::Accueil *ui;
};

#endif // ACCUEIL_H
