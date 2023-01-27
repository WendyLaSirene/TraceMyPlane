#include "widg_entete.h"
#include "ui_widg_entete.h"

Widg_Entete::Widg_Entete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widg_Entete)
{
    ui->setupUi(this);
}

Widg_Entete::~Widg_Entete()
{
    delete ui;
}

void Widg_Entete::setTitle(QString title){
    ui->lab_NameTete->setText(title);
}

void Widg_Entete::setIcon(QString icon){
    ui->wid_Icon->setStyleSheet("border-image: url("+icon+")");
}
