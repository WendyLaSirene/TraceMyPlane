#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class Accueil;
}

class Accueil : public QWidget
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();

private slots:
    void on_list_VolAero_itemClicked(QListWidgetItem *item);

private:
    Ui::Accueil *ui;
};

#endif // ACCUEIL_H
