#include "head_interact_airport.h"
#include "ui_head_interact_airport.h"

Head_Interact_Airport::Head_Interact_Airport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Head_Interact_Airport)
{
    ui->setupUi(this);
}

Head_Interact_Airport::~Head_Interact_Airport()
{
    delete ui;
}

void Head_Interact_Airport::setGName(QString gName){
    ui->lab_gName->setText(gName);
}

void Head_Interact_Airport::setEnName(QString enName){
    ui->lab_enName->setText(enName);
}

void Head_Interact_Airport::setCountry(QString countryCode){
    ui->lab_country->setText(countryCode);
}

void Head_Interact_Airport::setIata(QString iata){
    ui->lab_iataCode->setText(iata);
}

void Head_Interact_Airport::setIcao(QString icao){
    ui->lab_icaoCode->setText(icao);
}
