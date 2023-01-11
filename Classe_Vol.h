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
	    vector<Moment*> Moments_Vol ;
	    vector<Position*> Positions_Vol ;
	    
	public :
		Vol () ;
		Vol ( int i , string n , Moment* m , Position* p ) 
		{
	        ID = i ;
	        Nom = n ;
	        Add_Moment_Position ( m , p ) ;
		}
		void Set_ID ( int i ) { ID = i ; }
		void Add_Moment_Position ( Moment* m , Position* p ) { Moments_Vol.push_back ( m ) ; Positions_Vol.push_back ( p ) ; }
		
		string Get_Nom () { return Nom ; }
		int Get_Nombre_Etapes () { return Moments_Vol.size() ; }
		
		void Afficher_Etape ( int i )
		{
		    cout << Nom << " / Heure " ;
		    Moments_Vol[i]->Afficher() ;
			cout << " / Coordonnees : " ;
			Positions_Vol[i]->Afficher() ;
		}
		
		void Afficher_Tout ()
		{
			int i ;
		    for ( i = 0 ; i < Get_Nombre_Etapes () ; i ++ )
		    {
			    Afficher_Etape ( i ) ;
			    cout << endl ;
			}
		}
		
} ;


int Charger_Liste_Vols ( string Nom_Fichier , vector<Vol> &V , vector<Moment> &M , vector<Position> &P )
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
	Moment *m_Adr ;
	Position *p_Adr ;
	
    stringstream ss ;
    
    cout << Nom_Fichier << endl ;
    
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
        
        m_Adr = Ajouter_Sans_Doublon ( m , M ) ;
		p_Adr = Ajouter_Sans_Doublon ( p , P ) ;
        cout << m_Adr << endl ;
        
        n = Ajouter_Sans_Doublon_String ( Ligne_Dissociee[0] , Liste_Noms_Vols ) ;
        if ( n >= V.size() )
            V.push_back ( Vol ( n , Ligne_Dissociee[0] , m_Adr , p_Adr ) ) ;
        else
		    V[n].Add_Moment_Position ( m_Adr , p_Adr ) ;
        
        //cout << V[n].Get_Nombre_Etapes () << "  " ;
		//V[n].Afficher_Etape ( V[n].Get_Nombre_Etapes () - 1 ) ; cout << endl ;
		//V[n].Afficher_Tout () ; cout << endl ;
        
        Ligne_Dissociee.clear() ;
	}
    
    return 0 ;
}