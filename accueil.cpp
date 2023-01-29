#include "accueil.h"
#include "ui_accueil.h"
#include "Classe_Vol.h"
#include "Classe_Aeroport.h"
#include "widg_entete.h"
#include "widg_airports.h"
#include "widg_vols.h"
#include "head_interact_airport.h"
#include "head_interract_fly.h"
//#include "Fonctions_Diverses.h"
#include <vector>

vector<Aeroport> vect_Airport;
vector<Vol> vect_Fly;

Accueil::Accueil(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
    //vérifie les entrée des aéroports
    if(Charger_Liste_Aeroports(":/sourceClasses/Airports.csv",vect_Airport)){
        //si oui, commence par ajouter un entête
        auto widgAirportEntete = new Widg_Entete;
        auto listAirpotItem = new QListWidgetItem();
        widgAirportEntete->setTitle("Aéroports");
        widgAirportEntete->setIcon(":/icons/airport.png");
        listAirpotItem->setSizeHint(widgAirportEntete->minimumSize());
        listAirpotItem->setToolTip("hHead");
        ui->list_VolAero->addItem(listAirpotItem);
        ui->list_VolAero->setItemWidget(listAirpotItem,widgAirportEntete);

        //remplissage de la liste
        QString gName;
        vector<Aeroport>::const_iterator iAirport;
        for(iAirport=vect_Airport.begin();iAirport!=vect_Airport.end();iAirport++){
            Aeroport airport = *iAirport;
            auto widgAirport = new Widg_Airports;
            auto listAirports = new QListWidgetItem();
            QString toolParam = "a"+airport.Get_ICAO_Code();
            listAirports->setSizeHint(widgAirport->minimumSize());
            listAirports->setToolTip(toolParam);

            //retire "Aeroport de " du nom d'aeroport car redondant
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
        listFlyItem->setToolTip("hHead");
        ui->list_VolAero->addItem(listFlyItem);
        ui->list_VolAero->setItemWidget(listFlyItem,widgFlyEntete);

        //remplissage de la liste
        vector<Vol>::const_iterator iVol;
        for(iVol=vect_Fly.begin();iVol!=vect_Fly.end();iVol++){
            Vol vol = *iVol;
            auto widgFly = new widg_Vols;
            auto listFly = new QListWidgetItem();
            QString airportStart,airportEnd;
            QString toolParam = "v"+QString::number(vol.get_VolId());

            //parametre de l'item
            listFly->setSizeHint(widgFly->minimumSize());
            listFly->setToolTip(toolParam);
            //retire "Aeroport de " du nom d'aeroport car redondant
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

void Accueil::on_list_VolAero_itemClicked(QListWidgetItem *item)
{
    //récupère et nétoie le type du tooltype
    QString typeItem=item->toolTip()[0];
    QString toSearch=item->toolTip().remove(0,1);

    ui->list_Interact->clear();
    //affiche l'interaction des aeroports
    if(typeItem=="a"){
        Aeroport airport;
        vector<Aeroport>::const_iterator iAirport;
        for(iAirport=vect_Airport.begin();iAirport!=vect_Airport.end();iAirport++){
            airport=*iAirport;
            if(airport.Get_ICAO_Code()==toSearch){
                break;
            }
        }
        auto listHeadItem = new QListWidgetItem();
        auto widgHeadInteract = new Head_Interact_Airport;

        widgHeadInteract->setGName(airport.Get_NameGlob());
        widgHeadInteract->setEnName(airport.Get_NameEn());
        widgHeadInteract->setCountry(" ("+airport.Get_Country_Code()+")");
        widgHeadInteract->setIata(airport.Get_IATA_Code());
        widgHeadInteract->setIcao(airport.Get_ICAO_Code());
        listHeadItem->setSizeHint(widgHeadInteract->minimumSize());

        ui->list_Interact->addItem(listHeadItem);
        ui->list_Interact->setItemWidget(listHeadItem,widgHeadInteract);

    //affiche les intéraction des vols
    }else if(typeItem=="v"){
        vector<Vol>::const_iterator iVol;
        Vol vol;
        for(iVol=vect_Fly.begin();iVol!=vect_Fly.end();iVol++){
            vol=*iVol;
            if(QString::number(vol.get_VolId())==toSearch){
             break;
            }
        }
        auto listHeadItem = new QListWidgetItem();
        auto widgHeadInterract = new Head_Interract_Fly;

        widgHeadInterract->setName(vol.Get_Nom());
        widgHeadInterract->setTrajet(vol.Get_Aeroport_Depart().Get_NameGlob(),vol.Get_Aeroport_Arrivee().Get_NameGlob());
        listHeadItem->setSizeHint(widgHeadInterract->minimumSize());

        ui->list_Interact->addItem(listHeadItem);
        ui->list_Interact->setItemWidget(listHeadItem,widgHeadInterract);
    }
}

