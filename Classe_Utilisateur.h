#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <QFile>
#include <QTextStream>
using namespace std ;


class Utilisateur
{
	private :
	    int ID ;
        QString Nom ;
        QString Mot_De_Passe ;
	    
	public :
		Utilisateur () ;
        Utilisateur ( int i , QString Name , QString MDP )
		{
	        ID = i ;
	        Nom = Name ;
	        Mot_De_Passe = MDP ;
		}
		void Set_ID ( int i ) { ID = i ; }
        void Set_Nom ( QString n ) { Nom = n ; }
        void Set_MDP ( QString MDP ) { Mot_De_Passe = MDP ; }
        QString Get_Nom () { return Nom ; }
        bool Check_MDP ( QString MDP_Candidat ) { return MDP_Candidat == Mot_De_Passe ; }
		// La fonction "Get_MDP" n'existe pas et c'est normal : on ne veut pas que n'importe qui recupere les mots de passe !
		
        //void Afficher_Tout () { cout << "ID : / " << ID << " / Nom : " << Nom << " / MDP : " << Mot_De_Passe ; }
} ;


bool Charger_Liste_Utilisateurs ( QString Nom_Fichier , vector<Utilisateur> &U )
{
    /*string Contenu ;
    string Ligne ;
    string Mot ;
    vector<string> Ligne_Dissociee ;*/

    QString line;
    QStringList line_Splited;
    bool okToInt;
	
    QFile file(Nom_Fichier);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return false;

        QTextStream in(&file);
        in.readLine();// 1ere ligne est a jeter : en-tete
        while (!in.atEnd()) {
            line = in.readLine();
            line_Splited = line.split(',');
            U.push_back(Utilisateur(line_Splited[2].toInt(&okToInt,10),line_Splited[0],line_Splited[1]));
        }
        return true;

    /*stringstream ss ;
    
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
    
    return 0 ;*/
}

//verifie si la combinaison nom-mot de passe est correct. renvoie 0 s'il y as eu une erreur d'ouvertur du fichier,
//1 si l'utilisateur n'as pas été trouver et 2 s'il est bon mais avec un mauvais Mot de passe et 3 si tout est bon
int correctEntry(QString nameEnter, QString mdpEnter){
    vector<Utilisateur> vectorUsers;
    if(Charger_Liste_Utilisateurs(":/sourceClasses/Users.csv",vectorUsers)){
        for (vector<Utilisateur>::const_iterator i=vectorUsers.begin(); i != vectorUsers.end(); i++) {
            Utilisateur userToCompar = *i;
            if(nameEnter==userToCompar.Get_Nom()){
                if (userToCompar.Check_MDP(mdpEnter)){
                    return 3;//utilisateur trouvé avec le bon mot de passe
                }else return 2;//utilisateur trouvé mais mauvais mot de passe
            }
        }
        return 1;//utilisateur non trouvé
    }else return 0;//erreur lors de l'ouverture du fichier
}
