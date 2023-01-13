#include <string>
using namespace std ;


class Moment
{
	protected :
	    int Heure ;
	    int Minute ;
	
	public :
		Moment () { } ;
		Moment ( int h , int m ) { Heure = h ; Minute = m ; }
		void Set_Heure ( int h ) { Heure = h ; }
		void Set_Minute ( int m ) { Minute = m ; }
		
		int Get_Heure () { return Heure ; }
		int Get_Minute () { return Minute ; }
		
		void Afficher_Moment () { cout << Heure << ":" << Minute ; }
		
	bool operator== ( Moment m ) const
	{ return ( Heure == m.Heure && Minute == m.Minute ) ; }
} ;