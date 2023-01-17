#include "widg_entete_vol.h"
#include "ui_widg_entete_vol.h"

Widg_Entete_Vol::Widg_Entete_Vol(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widg_Entete_Vol)
{
    ui->setupUi(this);
}

Widg_Entete_Vol::~Widg_Entete_Vol()
{
    delete ui;
}
