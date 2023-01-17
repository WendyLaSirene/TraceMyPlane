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
