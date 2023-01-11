#include <string>
using namespace std ;


class Position
{
	private :
	    int ID ;
	    double Latitude ;
	    double Longitude ;
	    double Altitude ;
	
	public :
		void Set_ID ( int i ) { ID = i ; }
		void Set_Latitude ( double l ) { Latitude = l ; }
		void Set_Longitude ( double l ) { Longitude = l ; }
		void Set_Altitude ( double a ) { Altitude = a ; }
		
		double Get_Latitude () { return Latitude ; }
		double Get_Longitude () { return Longitude ; }
		double Get_Altitude () { return Altitude ; }
		
		void Afficher () { cout << Latitude << "E," << Longitude << "N," << Altitude << "m" ; }
		
	bool operator== ( Position p ) const
	{ return ( Latitude == p.Latitude && Longitude == p.Longitude && Altitude == p.Altitude ) ; }
} ;