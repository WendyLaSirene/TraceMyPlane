#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std ;


class Vol
{
	private :
	    int ID ;
	    string Nom ;
		vector<Moment> Moments_Etapes ;
		vector<Position> Positions_Etapes ;
		Aeroport Aeroport_Depart , Aeroport_Arrivee ;
	    
	public :
		Vol () ;
		Vol ( int i , string n , Moment m , Position p ) 
		{
	        ID = i ;
	        Nom = n ;
	        Moments_Etapes.push_back ( m ) ;
			Positions_Etapes.push_back ( p ) ;
		}
		Aeroport Get_Aeroport_Depart () { return Aeroport_Depart ; }
		Aeroport Get_Aeroport_Arrivee () { return Aeroport_Arrivee ; }
		Moment Get_Moment_Etape ( int n ) { return Moments_Etapes[n] ; }
		Position Get_Position_Etape ( int n ) { return Positions_Etapes[n] ; }
		string Get_Nom () { return Nom ; }
		int Get_Nombre_Etapes () { return Moments_Etapes.size() ; }
		void Add_Moment_Position ( Moment m , Position p ) { Moments_Etapes.push_back ( m ) ; Positions_Etapes.push_back ( p ) ; }
		
		void Rechercher_Depart_Arrivee ( vector<Aeroport> &A )
		{
		    Position p ;
		    int i ;
		    p = Positions_Etapes[0].Get_Position() ; // 1ere position du vol
		    for ( i = 0 ; i < A.size() ; i ++ )
		        if ( p == A[i].Get_Position_Aeroport() )
		        {
		            Aeroport_Depart = A[i] ;
		            break ;
		        }
		    if ( i == A.size() )
		        cout << "Probleme : aeroport de depart du vol " << Nom << " introuvable !" << endl ;
		        
		    p = Positions_Etapes[Moments_Etapes.size()-1].Get_Position() ; // Derniere position du vol
		    for ( i = 0 ; i < A.size() ; i ++ )
		        if ( p == A[i].Get_Position_Aeroport() )
		        {
		            Aeroport_Arrivee = A[i] ;
		            break ;
		        }
		    if ( i == A.size() )
		        cout << "Probleme : aeroport d'arrivee du vol " << Nom << " introuvable !" << endl ;
		}
		
		
		void Afficher_Etape ( int i )
		{	
		    cout << Nom << " / Heure " ;
		    Moments_Etapes[i].Afficher_Moment() ;
			cout << " / Coordonnees : " ;
		    Positions_Etapes[i].Afficher_Position() ;
		}
		
		void Afficher_Tout ()
		{
			int i ;
			cout << "Vol " << Aeroport_Depart.Get_IATA_Code() << " > " << Aeroport_Arrivee.Get_IATA_Code() << " :" << endl ;
		    for ( i = 0 ; i < Get_Nombre_Etapes () ; i ++ )
		    {
			    Afficher_Etape ( i ) ;
			    cout << endl ;
			}
		}
		
} ;


int Charger_Liste_Vols ( string Nom_Fichier , vector<Vol> &V , vector<Aeroport> &A )
{
    string Contenu ;
    string Ligne ;
    string Mot ;
    vector<string> Liste_Noms_Vols ;
    vector<string> Ligne_Dissociee ;
    
    int n ;
    Vol v() ;
    Moment m ;
    Position p ;
	int j ;
	
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
        
        m.Set_Heure ( stoi ( Ligne_Dissociee[1] ) ) ;
        m.Set_Minute ( stoi ( Ligne_Dissociee[2] ) ) ;
        p.Set_Latitude ( stod ( Ligne_Dissociee[3] ) ) ;
        p.Set_Longitude ( stod ( Ligne_Dissociee[4] ) ) ;
        p.Set_Altitude ( stod ( Ligne_Dissociee[5] ) ) ;
        
        n = Ajouter_Sans_Doublon_String ( Ligne_Dissociee[0] , Liste_Noms_Vols ) ;
        
        if ( n >= V.size() ) // Le vol a un nom non encore trouve : cree un nouveau
            V.push_back ( Vol ( n , Ligne_Dissociee[0] , m , p ) ) ;
        else // Le nom du vol a ete trouve : ajoute les informations audit vol
		    V[n].Add_Moment_Position ( m , p ) ;
        
        // 3 lignes d'affichage de debuggage
        //cout << V[n].Get_Nombre_Etapes () << "  " ;
		//V[n].Afficher_Etape ( V[n].Get_Nombre_Etapes () - 1 ) ; cout << endl ;
		//V[n].Afficher_Tout () ; cout << endl ;
        
        Ligne_Dissociee.clear() ;
	}
	
	for ( n = 0 ; n < V.size() ; n ++ )
	    V[n].Rechercher_Depart_Arrivee ( A ) ;
    
    return 0 ;
}