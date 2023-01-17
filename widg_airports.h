#ifndef WIDG_AIRPORTS_H
#define WIDG_AIRPORTS_H

#include <QWidget>

namespace Ui {
class Widg_Airports;
}

class Widg_Airports : public QWidget
{
    Q_OBJECT

public:
    explicit Widg_Airports(QWidget *parent = nullptr);
    ~Widg_Airports();

private:
    Ui::Widg_Airports *ui;
};

#endif // WIDG_AIRPORTS_H
