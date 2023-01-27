#include "widg_airports.h"
#include "ui_widg_airports.h"

Widg_Airports::Widg_Airports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widg_Airports)
{
    ui->setupUi(this);
}

Widg_Airports::~Widg_Airports()
{
    delete ui;
}

void Widg_Airports::set_Name(QString name){
    ui->lab_NameG->setText(name);
}
