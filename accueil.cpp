#include "accueil.h"
#include "ui_accueil.h"
#include "Classe_Vol.h"
#include "Classe_Aeroport.h"
#include <vector>

Accueil::Accueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
    vector<Aeroport> vect_Airport;
    //if()

}

Accueil::~Accueil()
{
    delete ui;

}
