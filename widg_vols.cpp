#include "widg_vols.h"
#include "ui_widg_vols.h"

widg_Vols::widg_Vols(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widg_Vols)
{
    ui->setupUi(this);
}

widg_Vols::~widg_Vols()
{
    delete ui;
}
