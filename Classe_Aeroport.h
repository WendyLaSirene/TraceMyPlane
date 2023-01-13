#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std ;


class Aeroport:Position
{
	private :
	    string NameGlob ;
	    string NameEn ;
	    string NameFr ;
	    string IATA_Code ;
	    string ICAO_Code ;
	    string Wiki_Data ;
	    string Operator ;
	    string Country_Name ;
	    string Country_Code ;
	
	public :
		string Get_NameGlob () { return NameGlob ; }
		string Get_NameEn () { return NameEn ; }
		string Get_NameFr () { return NameFr ; }
		string Get_IATA_Code () { return IATA_Code ; }
		string Get_ICAO_Code () { return ICAO_Code ; }
		string Get_Wiki_Data () { return Wiki_Data ; }
		string Get_Operator () { return Operator ; }
		string Get_Country_Name () { return Country_Name ; }
		string Get_Country_Code () { return Country_Code ; }
		Position Get_Position_Aeroport() { return Get_Position() ; }
		
		Aeroport () { } ;
		Aeroport ( double Latit , double Longit , double Altit , string Name_Global , string Name_English , string Name_French
		, string IATA , string ICAO , string Wiki , string Operator_Name , string Country , string CountryCode )
		{
		    Latitude = Latit ;
		    Longitude = Longit ;
		    Altitude = Altit ;
	        NameGlob = Name_Global ;
	        NameEn = Name_English ;
	        NameFr = Name_French ;
	        IATA_Code = IATA ;
	        ICAO_Code = ICAO ;
	        Wiki_Data = Wiki ;
	        Operator = Operator_Name ;
	        Country_Name = Country ;
	        Country_Code = CountryCode ;
		}
		Aeroport ( double Latit , double Longit , double Altit , vector<string> Liste_Attributs ) // Attention a l'ordre !
		{
			
		    if ( Liste_Attributs.size() != 9 )
		    {
		    	cerr << "Erreur : liste attributs constructeur 'Aeroport' mal dimensionnee" << endl ;
		    	cerr << "Contient " << Liste_Attributs.size() << " attributs" ;
			    exit ( 4 ) ;
			}
		    Latitude = Latit ;
		    Longitude = Longit ;
		    Altitude = Altit ;
	        NameGlob = Liste_Attributs[0] ;
	        NameEn = Liste_Attributs[1] ;
	        NameFr = Liste_Attributs[2] ;
	        IATA_Code = Liste_Attributs[3] ;
	        ICAO_Code = Liste_Attributs[4] ;
	        Wiki_Data = Liste_Attributs[5] ;
	        Operator = Liste_Attributs[6] ;
	        Country_Name = Liste_Attributs[7] ;
	        Country_Code = Liste_Attributs[8] ;
		}
		
		void Afficher_Tout () {
			cout << NameGlob << " (" << IATA_Code << "/" << ICAO_Code << ") : "
			<< Country_Name	<< " / Position " ;
			Afficher_Position () ;
		}
} ;


int Charger_Liste_Aeroports ( string Nom_Fichier , vector<Aeroport> &A )
{
    string Contenu ;
    string Ligne ;
    string Mot ;
    vector<string> Ligne_Dissociee ;
    string Latit , Longit , Altit ;
    
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
        getline ( ss , Longit , ',' ) ; // 1ere colonne : coordonnees
        getline ( ss , Latit , '\t' ) ;
	    while ( getline ( ss , Mot , '\t' ) )
	   	    Ligne_Dissociee.push_back ( Mot ) ;
	   	    
        Altit = Ligne_Dissociee[9] ;
        Ligne_Dissociee.pop_back () ;
	   	A.push_back ( Aeroport ( stod ( Latit ) , stod ( Longit ) , stod ( Altit ) , Ligne_Dissociee ) ) ;
	   	//A[A.size()-1].Afficher_Tout () ; cout << endl ;
	   	
        Ligne_Dissociee.clear() ;
	}
    
    return 0 ;
}