#include <string>
using namespace std ;


class Moment
{
	private :
	    int ID ;
	    int Heure ;
	    int Minute ;
	
	public :
		void Set_ID ( int i ) { ID = i ; }
		void Set_Heure ( int h ) { Heure = h ; }
		void Set_Minute ( int m ) { Minute = m ; }
		
		int Get_Heure () { return Heure ; }
		int Get_Minute () { return Minute ; }
		
		void Afficher () { cout << Heure << ":" << Minute ; }
		
	bool operator== ( Moment m ) const
	{ return ( Heure == m.Heure && Minute == m.Minute ) ; }
} ;