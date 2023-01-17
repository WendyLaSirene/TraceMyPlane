#include <QString>
#include <vector>

template <typename T>
int Ajouter_Sans_Doublon ( const T element , vector<T> &V )
{
    int i ;
    int Taille = V.size() ;
    for ( i = 0 ; i < Taille ; i ++ )
        if ( V[i] == element ) // Existe deja
	        break ; // Adresse
	if ( i == Taille ) // Fin du tableau atteint : n'existe pas encore
	{
        V.push_back ( element ) ;
        V[i].Set_ID ( i ) ;
    }
    return ( i ) ;
}


int Ajouter_Sans_Doublon_String ( const QString element , vector<QString> &V )
{
    int i ;
    int Taille = V.size() ;
    for ( i = 0 ; i < Taille ; i ++ )
        if ( V[i] == element ) // Existe deja
	        break ;
	if ( i == Taille ) // Fin du tableau atteint : n'existe pas encore
        V.push_back ( element ) ;
    return i ; // ID
}
