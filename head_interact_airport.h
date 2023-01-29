#ifndef HEAD_INTERACT_AIRPORT_H
#define HEAD_INTERACT_AIRPORT_H

#include <QWidget>

namespace Ui {
class Head_Interact_Airport;
}

class Head_Interact_Airport : public QWidget
{
    Q_OBJECT

public:
    explicit Head_Interact_Airport(QWidget *parent = nullptr);
    void setGName(QString);
    void setEnName(QString);
    void setCountry(QString);
    void setIata(QString);
    void setIcao(QString);
    ~Head_Interact_Airport();

private:
    Ui::Head_Interact_Airport *ui;
};

#endif // HEAD_INTERACT_AIRPORT_H
