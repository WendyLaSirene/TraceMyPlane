#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std ;

#include "Classe_Moment.h"
#include "Classe_Position.h"
vector<Moment> Liste_Moments ;
vector<Position> Liste_Positions ;

#include "Fonctions_Diverses.h"

#include "Classe_Aeroport.h"
#include "Classe_Vol.h"




int main ( )
{
	vector<Aeroport> Liste_Aeroports ;
	vector<Vol> Liste_Vols ;
	
	int i ;
	int Nombre_Aeroports ;
	int Nombre_Vols ;
	
	Charger_Liste_Aeroports ( "Airports.csv" , Liste_Aeroports , Liste_Positions ) ;
	Charger_Liste_Vols ( "Vol.csv" , Liste_Vols , Liste_Moments , Liste_Positions ) ;
	
	
	// Juste pour tester
	
	for ( i = 0 ; i < Liste_Moments.size () ; i ++ )
	{
		cout << &Liste_Moments[i] << "  " ;
	    Liste_Moments[i].Afficher () ;
	    cout << endl ;
	}
	
	/*for ( i = 0 ; i < Liste_Positions.size () ; i ++ )
	{
		cout << &Liste_Positions[i] << "  " ;
	    Liste_Positions[i].Afficher () ;
	    cout << endl ;
	}*/
	
	int Choix = 0 ;
	
	Nombre_Aeroports = Liste_Aeroports.size() ;
	for ( i = 0 ; i < Nombre_Aeroports ; i ++ )
	    cout << i + 1 << ": " << Liste_Aeroports[i].Get_NameGlob() << endl ;
	cout << "Choisissez un aeroport en tapant un nombre : " << endl ;
	cin >> Choix ;
	if ( Choix <= 0 || Choix > Nombre_Aeroports )
	    cout << "Saisie invalide !" << endl ;
	else
	    Liste_Aeroports[Choix-1].Afficher_Tout() ;
	    
	/*Nombre_Vols = Liste_Vols.size() ;
	cout << endl ;
	cout << endl ;
	for ( i = 0 ; i < Nombre_Vols ; i ++ )
	    cout << i + 1 << ": " << Liste_Vols[i].Get_Nom() << endl ;
	cout << "Choisissez un vol en tapant un nombre : " << endl ;
	cin >> Choix ;
	if ( Choix <= 0 || Choix > Nombre_Vols )
	    cout << "Saisie invalide !" << endl ;
	else
	    Liste_Vols[Choix-1].Afficher_Tout() ;*/
	
    return 0 ;
}