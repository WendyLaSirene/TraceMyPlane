#include "accueil.h"
#include "ui_accueil.h"
#include "Classe_Vol.h"
#include "Classe_Aeroport.h"
#include "widg_entete.h"
#include "widg_airports.h"
#include "widg_vols.h"
//#include "Fonctions_Diverses.h"
#include <vector>

Accueil::Accueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
    vector<Aeroport> vect_Airport;
    vector<Vol> vect_Fly;
    //vérifie les entrée des aéroports
    if(Charger_Liste_Aeroports(":/sourceClasses/Airports.csv",vect_Airport)){
        //si oui, commence par ajouter un entête
        auto widgAirportEntete = new Widg_Entete;
        auto listAirpotItem = new QListWidgetItem();
        widgAirportEntete->setTitle("Aéroports");
        widgAirportEntete->setIcon(":/icons/airport.png");
        listAirpotItem->setSizeHint(widgAirportEntete->minimumSize());
        ui->list_VolAero->addItem(listAirpotItem);
        ui->list_VolAero->setItemWidget(listAirpotItem,widgAirportEntete);

        //remplissage de la liste
        QString gName;
        vector<Aeroport>::const_iterator iAirport;
        for(iAirport=vect_Airport.begin();iAirport!=vect_Airport.end();iAirport++){
            Aeroport airport = *iAirport;
            auto widgAirport = new Widg_Airports;
            auto listAirports = new QListWidgetItem();
            listAirports->setSizeHint(widgAirport->minimumSize());

            gName=filtre_Aeroport_gName(airport.Get_NameGlob());
            widgAirport->set_Name(gName);
            ui->list_VolAero->addItem(listAirports);
            ui->list_VolAero->setItemWidget(listAirports,widgAirport);
        }
    }

    //vérifie les entrée des vols
    if(Charger_Liste_Vols(":/sourceClasses/Vol.csv",vect_Fly,vect_Airport)){
        //si oui, entête
        auto widgFlyEntete = new Widg_Entete;
        auto listFlyItem = new QListWidgetItem();
        widgFlyEntete->setTitle("Vols");
        widgFlyEntete->setIcon(":/icons/plane.png");
        listFlyItem->setSizeHint(widgFlyEntete->minimumSize());
        ui->list_VolAero->addItem(listFlyItem);
        ui->list_VolAero->setItemWidget(listFlyItem,widgFlyEntete);

        //remplissage de la liste
        vector<Vol>::const_iterator iVol;
        for(iVol=vect_Fly.begin();iVol!=vect_Fly.end();iVol++){
            Vol vol = *iVol;
            auto widgFly = new widg_Vols;
            auto listFly = new QListWidgetItem();
            QString airportStart,airportEnd;

            listFly->setSizeHint(widgFly->minimumSize());
            airportStart=filtre_Aeroport_gName(vol.Get_Aeroport_Depart().Get_NameGlob());
            airportEnd=filtre_Aeroport_gName(vol.Get_Aeroport_Arrivee().Get_NameGlob());
            widgFly->setFlyName(vol.Get_Nom());
            widgFly->setStartEnd(airportStart,airportEnd);
            listFly->setSizeHint(widgFly->minimumSize());
            ui->list_VolAero->addItem(listFly);
            ui->list_VolAero->setItemWidget(listFly,widgFly);
        }
    }
}

Accueil::~Accueil(){
    delete ui;
}
