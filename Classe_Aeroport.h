#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std ;


class Aeroport
{
private :
    int ID_Position{ 0 } ;
    string NameGlob{ "" } ;
    string NameEn{ "" } ;
    string NameFr{ "" } ;
    string IATA_Code{ "" } ;
    string ICAO_Code{ "" } ;
    string Wiki_Data{ "" } ;
    string Operator{ "" } ;
    string Country_Name{ "" } ;
    string Country_Code{ "" } ;

public :
    int Get_ID_Position () { return ID_Position ; }
    string Get_NameGlob () { return NameGlob ; }
    string Get_NameEn () { return NameEn ; }
    string Get_NameFr () { return NameFr ; }
    string Get_IATA_Code () { return IATA_Code ; }
    string Get_ICAO_Code () { return ICAO_Code ; }
    string Get_Wiki_Data () { return Wiki_Data ; }
    string Get_Operator () { return Operator ; }
    string Get_Country_Name () { return Country_Name ; }
    string Get_Country_Code () { return Country_Code ; }

    double Get_Latitude () { return Liste_Positions[ID_Position].Get_Latitude() ; }
    double Get_Longitude () { return Liste_Positions[ID_Position].Get_Longitude() ; }
    double Get_Altitude () { return Liste_Positions[ID_Position].Get_Altitude() ; }

    Aeroport () = default;
    Aeroport ( int Pos , string Name_Global , string Name_English , string Name_French , string IATA , string ICAO
    , string Wiki , string Operator_Name , string Country , string CountryCode )
    {
        ID_Position = Pos ;
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

    Aeroport ( int Pos , vector<string> Liste_Attributs ) // Attention a l'ordre !
    {
        ID_Position = Pos ;
        if ( Liste_Attributs.size() != 9 )
        {
       	  cerr << "Erreur : liste attributs constructeur 'Aeroport' mal dimensionnee" << endl ;
          cerr << "Contient " << Liste_Attributs.size() << " attributs" ;
    	  exit ( 4 ) ;
    	}

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
	Liste_Positions[ID_Position].Afficher () ;
}
} ;


int Charger_Liste_Aeroports ( string Nom_Fichier , vector<Aeroport> &A , vector<Position> &P )
{
    string Contenu{ "" } ;
    string Ligne{ "" } ;
    string Mot{ "" } ;
    vector<string> Ligne_Dissociee ;
    string Latit{ "" } , Longit{ "" } ;

    int n{ 0 } ;
    Position p{ 0 } ;
    int j{ 0 } ;
    int p_Adr{ 0 } ;

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
        getline ( ss , Longit , ',' ) ; // 1ere colonne : coordonnees
        getline ( ss , Latit , '\t' ) ;
	    while ( getline ( ss , Mot , '\t' ) )
	   	    Ligne_Dissociee.push_back ( Mot ) ;

        p.Set_Latitude ( stod ( Latit ) ) ;
        p.Set_Longitude ( stod ( Longit ) ) ;
        p.Set_Altitude ( stod ( Ligne_Dissociee[9] ) ) ;
	   	p_Adr = Ajouter_Sans_Doublon ( p , P ) ;
        Ligne_Dissociee.pop_back () ;
	   	A.push_back ( Aeroport ( p_Adr , Ligne_Dissociee ) ) ;
	   	Liste_Positions[p_Adr].Affecter_Aeroport ( A.size() - 1 ) ;
	   	//A[A.size()-1].Afficher_Tout () ;	cout << endl ;
	   	
        Ligne_Dissociee.clear() ;
	}
    
    return 0 ;
}
