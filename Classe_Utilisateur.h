#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std ;


class Utilisateur
{
	private :
	    int ID ;
	    string Nom ;
	    string Mot_De_Passe ;
	    
	public :
		Utilisateur () ;
		Utilisateur ( int i , string Name , string MDP ) 
		{
	        ID = i ;
	        Nom = Name ;
	        Mot_De_Passe = MDP ;
		}
		void Set_ID ( int i ) { ID = i ; }
		void Set_Nom ( string n ) { Nom = n ; }
		void Set_MDP ( string MDP ) { Mot_De_Passe = MDP ; }
		string Get_Nom () { return Nom ; }
		bool Check_MDP ( string MDP_Candidat ) { return MDP_Candidat == Mot_De_Passe ; }
		// La fonction "Get_MDP" n'existe pas et c'est normal : on ne veut pas que n'importe qui recupere les mots de passe !
		
		void Afficher_Tout () { cout << "ID : / " << ID << " / Nom : " << Nom << " / MDP : " << Mot_De_Passe ; }
} ;


int Charger_Liste_Utilisateurs ( string Nom_Fichier , vector<Utilisateur> &U )
{
    string Contenu ;
    string Ligne ;
    string Mot ;
    vector<string> Ligne_Dissociee ;
    
    int n ;
	
    stringstream ss ;
    
    ifstream Fichier ( Nom_Fichier ) ;
	if ( ! Fichier.is_open() )
	{
        cerr << "Erreur : fichier '" << Nom_Fichier << "'" << endl;
        exit ( EXIT_FAILURE ) ;
    }
    
    getline ( Fichier , Ligne ) ; // 1ere ligne est a jeter : en-tete
    while ( getline ( Fichier , Ligne ) )
    {
        istringstream ss ( Ligne ) ;
	    while ( getline ( ss , Mot , ',' ) )
	   	    Ligne_Dissociee.push_back ( Mot ) ;
        
        U.push_back ( Utilisateur ( stoi ( Ligne_Dissociee[2] ) , Ligne_Dissociee[0] , Ligne_Dissociee[1] ) ) ;
        
        // 1 ligne d'affichage de debuggage
		//U[U.size()-1].Afficher_Tout () ; cout << endl ;
        
        Ligne_Dissociee.clear() ;
	}
    
    return 0 ;
}