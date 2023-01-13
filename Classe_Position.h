#include <string>
using namespace std ;


class Position
{
	protected :
	    float Latitude ;
	    float Longitude ;
	    float Altitude ;
	
	public :
		Position () { } ;
		Position ( double Latit , double Longit , double Altit ) { Latitude = Latit ; Longitude = Longit ; Altitude = Altit ; }
		void Set_Latitude ( double l ) { Latitude = l ; }
		void Set_Longitude ( double l ) { Longitude = l ; }
		void Set_Altitude ( double a ) { Altitude = a ; }
		Position Get_Position () { return *this ; }
		
		double Get_Latitude () { return Latitude ; }
		double Get_Longitude () { return Longitude ; }
		double Get_Altitude () { return Altitude ; }
		
		
		void Afficher_Position () { cout << abs ( Latitude ) << ( Latitude >= 0 ? "N, " : "S, " )
		<< abs ( Longitude ) << ( Longitude >= 0 ? "E, " : "W, " ) << Altitude << "m" ; }
		
	bool operator== ( Position p ) const
	{ return ( Latitude == p.Latitude && Longitude == p.Longitude && Altitude == p.Altitude ) ; }
} ;