#ifndef HEAD_INTERRACT_FLY_H
#define HEAD_INTERRACT_FLY_H

#include <QWidget>
#include "Classe_Moment.h"

namespace Ui {
class Head_Interract_Fly;
}

class Head_Interract_Fly : public QWidget
{
    Q_OBJECT

public:
    explicit Head_Interract_Fly(QWidget *parent = nullptr);
    void setName(QString);
    void setTrajet(QString,Moment,QString,Moment);
    ~Head_Interract_Fly();

private:
    Ui::Head_Interract_Fly *ui;
};

#endif // HEAD_INTERRACT_FLY_H
