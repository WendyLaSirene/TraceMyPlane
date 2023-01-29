#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <QString>
#include <QFile>
#include <QTextStream>
//#include "Classe_Position.h"
#include "Classe_Moment.h"
#include "Classe_Aeroport.h"
#include "Fonctions_Diverses.h"
#ifndef CLASSE_VOL_H
#define CLASSE_VOL_H

using namespace std ;


class Vol
{
	private :
	    int ID ;
        QString Nom ;
		vector<Moment> Moments_Etapes ;
		vector<Position> Positions_Etapes ;
		Aeroport Aeroport_Depart , Aeroport_Arrivee ;
		vector<Aeroport> Aeroports_Escale ;
		vector<Moment> Moments_Escale ;
	    
	public :
        Vol () {};
        Vol ( int i , QString n , Moment m , Position p )
		{
	        ID = i ;
	        Nom = n ;
	        Moments_Etapes.push_back ( m ) ;
			Positions_Etapes.push_back ( p ) ;
		}
        int get_VolId(){return ID;}
		Aeroport Get_Aeroport_Depart () { return Aeroport_Depart ; }
		Aeroport Get_Aeroport_Arrivee () { return Aeroport_Arrivee ; }
		Moment Get_Moment_Depart () { return Moments_Etapes[0] ; }
		Moment Get_Moment_Arrivee () { return Moments_Etapes[Moments_Etapes.size()-1] ; }
		
		Moment Get_Moment_Escale ( int n ) { return Moments_Escale[n] ; }
		Aeroport Get_Aeroport_Escale ( int n ) { return Aeroports_Escale[n] ; }
		int Get_Nombre_Escales () { return Moments_Escale.size() ; }
		
		Moment Get_Moment_Etape ( int n ) { return Moments_Etapes[n] ; }
		Position Get_Position_Etape ( int n ) { return Positions_Etapes[n] ; }
		int Get_Nombre_Etapes () { return Moments_Etapes.size() ; }
		
        QString Get_Nom () { return Nom ; }
		void Add_Moment_Position ( Moment m , Position p ) { Moments_Etapes.push_back ( m ) ; Positions_Etapes.push_back ( p ) ; }
		
		void Rechercher_Escales ( vector<Aeroport> &A )
		{
		    Position p ;
		    int i , j ;
		    p = Positions_Etapes[0].Get_Position() ; // 1ere position du vol
		    for ( i = 0 ; i < A.size() ; i ++ )
		        if ( p == A[i].Get_Position_Aeroport() )
		        {
		            Aeroport_Depart = A[i] ;
		            break ;
		        }
		    if ( i == A.size() )
                //cout << "Probleme : aeroport de depart du vol " << Nom << " introuvable !" << endl ;
		        
		    p = Positions_Etapes[Moments_Etapes.size()-1].Get_Position() ; // Derniere position du vol
		    for ( i = 0 ; i < A.size() ; i ++ )
		        if ( p == A[i].Get_Position_Aeroport() )
		        {
		            Aeroport_Arrivee = A[i] ;
		            break ;
		        }
		        
		    // Positions intermediaires : escales
		    for ( j = 1 ; j < Moments_Etapes.size() - 1 ; j ++ )
			    for ( i = 0 ; i < A.size() ; i ++ )
			        if ( p == A[i].Get_Position_Aeroport() )
			        {
			            Aeroports_Escale.push_back ( A[i] ) ;
			            Moments_Escale.push_back ( Moments_Etapes[j] ) ;
			            break ;
			        }
		    
            //if ( i == A.size() )
                //cout << "Probleme : aeroport d'arrivee du vol " << Nom << " introuvable !" << endl ;
		}
		
		
		void Afficher_Etape ( int i )
		{	
            /*cout << Nom << " / Heure " ;
            Moments_Etapes[i].Afficher_Moment() ;
            cout << " / Coordonnees : " ;
            Positions_Etapes[i].Afficher_Position() ;*/
		}
		
		void Afficher_Tout ()
		{
			int i ;
            //cout << "Vol " << Aeroport_Depart.Get_IATA_Code() << " > " << Aeroport_Arrivee.Get_IATA_Code() << " :" << endl ;
		    for ( i = 0 ; i < Get_Nombre_Etapes () ; i ++ )
		    {
			    Afficher_Etape ( i ) ;
			    cout << endl ;
			}
		}
		
} ;


bool Charger_Liste_Vols ( QString Nom_Fichier , vector<Vol> &V , vector<Aeroport> &A )
{
    QString line,flyName;
    QStringList line_Splited;
    bool okToInt;
    Moment moment;
    Position position;
    int nbrOfFly;
    vector<QString> listNomVols;

    QFile file(Nom_Fichier);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return false;

        QTextStream in(&file);
        in.readLine();// 1ere ligne est a jeter : en-tete
        while (!in.atEnd()) {
            line = in.readLine();
            line_Splited = line.split(',');
            if(line_Splited[0]!=""){ //filtre les lignes de de donnés inutilisables
                moment.Set_Heure(line_Splited[1].toInt(&okToInt,10));
                moment.Set_Minute(line_Splited[2].toInt(&okToInt,10));
                position.Set_Latitude(line_Splited[4].toFloat(&okToInt));
                position.Set_Longitude(line_Splited[3].toFloat(&okToInt));
                position.Set_Altitude(line_Splited[5].toFloat(&okToInt));

                nbrOfFly=Ajouter_Sans_Doublon_String(line_Splited[0],listNomVols);

                if(nbrOfFly>=V.size()){V.push_back(Vol(nbrOfFly,line_Splited[0],moment,position));}
                else{V[nbrOfFly].Add_Moment_Position ( moment , position ) ;}
            }
        }
        for ( nbrOfFly = 0 ; nbrOfFly < V.size() ; nbrOfFly ++ ){
            V[nbrOfFly].Rechercher_Escales ( A ) ;
        }
        return true;

    /*string Contenu ;
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
        
        //n = Ajouter_Sans_Doublon_String ( Ligne_Dissociee[0] , Liste_Noms_Vols ) ;
        
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
	    V[n].Rechercher_Escales ( A ) ;
    
    return 0 ;*/
}
#endif
