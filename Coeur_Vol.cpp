#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std ;

#include "Fonctions_Diverses.h"

#include "Classe_Moment.h"
vector<Moment> Liste_Moments ;
#include "Classe_Position.h"
vector<Position> Liste_Positions ;


#include "Classe_Aeroport.h"
vector<Aeroport> Liste_Aeroports ;
#include "Classe_Vol.h"
vector<Vol> Liste_Vols ;
#include "Classe_Utilisateur.h"
vector<Utilisateur> Liste_Utilisateurs ;




int main ( )
{
	
	int i ;
	int Nombre_Aeroports ;
	int Nombre_Vols ;
	
	Charger_Liste_Aeroports ( "Airports.csv" , Liste_Aeroports , Liste_Positions ) ;
	Charger_Liste_Vols ( "Vol.csv" , Liste_Vols , Liste_Moments , Liste_Positions ) ;
	Charger_Liste_Utilisateurs ( "Users.csv" , Liste_Utilisateurs ) ;
	
	
	// Juste pour tester
	cout << "Liste des utilisateurs : " << endl ;
	for ( i = 0 ; i < Liste_Utilisateurs.size () ; i ++ )
		cout << Liste_Utilisateurs[i].Get_Nom() << endl ;
	
	string Saisie ;
	cout << "Saisir nom d'utilisateur : " ;
	cin >> Saisie ;
	
	for ( i = 0 ; i < Liste_Utilisateurs.size () ; i ++ )
		if ( Saisie == Liste_Utilisateurs[i].Get_Nom() )
		    break ;
	
	if ( i >= Liste_Utilisateurs.size () )
	    cout << "L'utilisateur n'existe pas !" << endl ;
	else
	{
	    cout << "Saisir mot de passe : " ;
	    cin >> Saisie ;
	    if ( ! Liste_Utilisateurs[i].Check_MDP ( Saisie ) )
	    {
		    cout << "Mot de passe incorrect. Saisir mot de passe : " ;
		    cin >> Saisie ;
		}
	    if ( ! Liste_Utilisateurs[i].Check_MDP ( Saisie ) )
	    {
		    cout << "Mot de passe incorrect. Saisir mot de passe (dernier essai) : " ;
		    cin >> Saisie ;
		}
		
		if ( ! Liste_Utilisateurs[i].Check_MDP ( Saisie ) )
		    cout << "Mot de passe incorrect. Vous avez epuise vos 3 essais. Adieu pauvre idiot !" ;
		else
		    cout << "Bienvenue " << Liste_Utilisateurs[i].Get_Nom() << " !" << endl ;
	}
	
	
	
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
	
	/*
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
	    Liste_Vols[Choix-1].Afficher_Tout() ;*/
	
	
	
    return 0 ;
}