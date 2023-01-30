#include "head_interract_fly.h"
#include "ui_head_interract_fly.h"
#include "Classe_Moment.h"

Head_Interract_Fly::Head_Interract_Fly(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Head_Interract_Fly)
{
    ui->setupUi(this);
}

Head_Interract_Fly::~Head_Interract_Fly()
{
    delete ui;
}

void Head_Interract_Fly::setName(QString name){
    ui->lab_vol->setText(name);
}

void Head_Interract_Fly::setTrajet(QString start,Moment momentStart,QString end,Moment momentEnd){
    ui->lab_trajet->setText(start+"("+momentStart.readTime()+")"+" -> "+end+"("+momentEnd.readTime()+")");
}
