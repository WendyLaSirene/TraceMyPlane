#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "Classe_Position.h"
#ifndef CLASSE_AEROPORT_H
#define CLASSE_AEROPORT_H
using namespace std ;


class Aeroport:Position
{
	private :
        QString NameGlob ;
        QString NameEn ;
        QString NameFr ;
        QString IATA_Code ;
        QString ICAO_Code ;
        QString Wiki_Data ;
        QString Operator ;
        QString Country_Name ;
        QString Country_Code ;
	
	public :
        QString Get_NameGlob () { return NameGlob ; }
        QString Get_NameEn () { return NameEn ; }
        QString Get_NameFr () { return NameFr ; }
        QString Get_IATA_Code () { return IATA_Code ; }
        QString Get_ICAO_Code () { return ICAO_Code ; }
        QString Get_Wiki_Data () { return Wiki_Data ; }
        QString Get_Operator () { return Operator ; }
        QString Get_Country_Name () { return Country_Name ; }
        QString Get_Country_Code () { return Country_Code ; }
        Position Get_Position_Aeroport() { return Get_Position() ; }
		
		Aeroport () { } ;
        Aeroport ( double Latit , double Longit , double Altit , QString Name_Global , QString Name_English , QString Name_French
        , QString IATA , QString ICAO , QString Wiki , QString Operator_Name , QString Country , QString CountryCode )
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
        Aeroport ( double Latit , double Longit , double Altit , vector<QString> Liste_Attributs ) // Attention a l'ordre des Attributs !
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
		
        /*void Afficher_Tout () {
			cout << NameGlob << " (" << IATA_Code << "/" << ICAO_Code << ") : "
			<< Country_Name	<< " / Position " ;
            //Afficher_Position () ;
        }*/
} ;


bool Charger_Liste_Aeroports ( QString Nom_Fichier , vector<Aeroport> &A )
{
    QString line;
    QStringList line_splited;
    QStringList coordSplited;
    bool okToInt;

    QFile file(Nom_Fichier);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    in.readLine();// 1ere ligne est a jeter : en-tete
    while (!in.atEnd()) {
        line = in.readLine();
        line_splited = line.split('\t');
        coordSplited = line_splited[0].split(",");
        A.push_back(Aeroport(coordSplited[0].toFloat(&okToInt),coordSplited[1].toFloat(&okToInt),line_splited[10].toInt(&okToInt,10),
                line_splited[1],line_splited[2],line_splited[3],line_splited[4],line_splited[5],line_splited[6],line_splited[7],line_splited[8],line_splited[9]));
    }
    return true;

    /*string Contenu ;
    string Ligne ;
    string Mot ;
    vector<string> Ligne_Dissociee ;
    string Latit , Longit , Altit ;
    
    //int n ;
	
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
        Ligne_Dissociee.pop_back () ; // On supprime un element pour que le vecteur envoye comme "Attribut" soit de la bonne taille
	   	A.push_back ( Aeroport ( stod ( Latit ) , stod ( Longit ) , stod ( Altit ) , Ligne_Dissociee ) ) ;
	   	
        // 1 ligne d'affichage de debuggage
	   	//A[A.size()-1].Afficher_Tout () ; cout << endl ;
	   	
        Ligne_Dissociee.clear() ;
	}
    
    return 0 ;*/
}

QString filtre_Aeroport_gName(QString nameToFiltre){
    nameToFiltre.remove(0,9);
    if(nameToFiltre.section(" ",0,0)=="de"){
        nameToFiltre.remove(0,3);
    }
    return nameToFiltre;
}

#endif
