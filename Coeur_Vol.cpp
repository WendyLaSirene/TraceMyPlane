#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std ;

#include "Fonctions_Diverses.h"

#include "Classe_Moment.h"
#include "Classe_Position.h"
vector<Position> Liste_Positions ;

vector<Moment> Liste_Moments ;

#include "Classe_Aeroport.h"
vector<Aeroport> Liste_Aeroports ;
#include "Classe_Vol.h"
vector<Vol> Liste_Vols ;


int main ( )
{

    int i{ 0 } ;
    int Nombre_Aeroports{ 0 } ;
    int Nombre_Vols{ 0 } ;

    Charger_Liste_Aeroports ( "Airports.csv" , Liste_Aeroports , Liste_Positions ) ;
    Charger_Liste_Vols ( "Vol.csv" , Liste_Vols , Liste_Moments , Liste_Positions ) ;


    // Juste pour tester

    /*for ( i = 0 ; i < Liste_Moments.size () ; i ++ )
    {
    	cout << &Liste_Moments[i] << "  " ;
        Liste_Moments[i].Afficher () ;
        cout << endl ;
    }*/

    /*for ( i = 0 ; i < Liste_Positions.size () ; i ++ )
    {
    	cout << &Liste_Positions[i] << "  " ;
        Liste_Positions[i].Afficher () ;
        cout << endl ;
    }*/

    int Choix{ 0 };

    Nombre_Aeroports = static_cast<int>(Liste_Aeroports.size()) ;
    for ( i = 0 ; i < Nombre_Aeroports ; i ++ )
        cout << i + 1 << ": " << Liste_Aeroports[i].Get_NameGlob() << endl ;
    cout << "Choisissez un aeroport en tapant un nombre : " << endl ;
    cin >> Choix ;
    if ( Choix <= 0 || Choix > Nombre_Aeroports )
        cout << "Saisie invalide !" << endl ;
    else
        Liste_Aeroports[Choix-1].Afficher_Tout() ;
    cout << Liste_Aeroports[Choix-1].Get_ID_Position() << endl ;

    Nombre_Vols = Liste_Vols.size() ;
    cout << endl ;
    cout << endl ;
    for ( i = 0 ; i < Nombre_Vols ; i ++ )
        cout << i + 1 << ": " << Liste_Vols[i].Get_Nom() << endl ;
    cout << "Choisissez un vol en tapant un nombre : " << endl ;
    cin >> Choix ;
    if ( Choix <= 0 || Choix > Nombre_Vols )
        cout << "Saisie invalide !" << endl ;
    else
        Liste_Vols[Choix-1].Afficher_Tout() ;

    /*for ( i = 0 ; i < Liste_Vols[Choix-1].Get_Nombre_Etapes() ; i ++ )
        cout << Liste_Vols[Choix-1].Get_ID_Positions_Vol(i) << endl ;*/

    return 0 ;
}
