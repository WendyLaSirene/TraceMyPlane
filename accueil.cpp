#include "accueil.h"
#include "ui_accueil.h"
#include "Classe_Position.h"
#include "Classe_Aeroport.h"
#include "Classe_Moment.h"
#include "Classe_Vol.h"

Accueil::Accueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::~Accueil()
{
    delete ui;
}
