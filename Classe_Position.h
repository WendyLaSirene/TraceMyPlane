#include <string>
using namespace std ;


class Position
{
	private :
	    int ID ;
	    float Latitude ;
	    float Longitude ;
	    float Altitude ;
	    int ID_Aeroport = -1 ;
	
	public :
		void Set_ID ( int i ) { ID = i ; }
		void Set_Latitude ( double l ) { Latitude = l ; }
		void Set_Longitude ( double l ) { Longitude = l ; }
		void Set_Altitude ( double a ) { Altitude = a ; }
		void Affecter_Aeroport ( int i ) { ID_Aeroport = i ; }
		
		double Get_Latitude () { return Latitude ; }
		double Get_Longitude () { return Longitude ; }
		double Get_Altitude () { return Altitude ; }
		double Get_ID_Aeroport () { return ID_Aeroport ; }
		
		
		void Afficher () { cout << Latitude << "E," << Longitude << "N," << Altitude << "m" ; }
		
	bool operator== ( Position p ) const
	{ return ( Latitude == p.Latitude && Longitude == p.Longitude && Altitude == p.Altitude ) ; }
} ;