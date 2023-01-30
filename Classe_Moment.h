#include <string>
#include<QString>
#ifndef CLASSE_MOMENT_H
#define CLASSE_MOMENT_H
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

        QString readTime(){
            QString minuteToAdd=QString::number(Minute);
            QString toRead=QString::number(Heure)+":";
            if(Minute==0){
                toRead=toRead+"00";
                return toRead;
            }
            if(minuteToAdd.size()==1){
                toRead=toRead+"0"+minuteToAdd;
                return toRead;
            }
            toRead=toRead+minuteToAdd;
            return toRead;
        }
		
        //void Afficher_Moment () { cout << Heure << ":" << Minute ; }
		
	bool operator== ( Moment m ) const
	{ return ( Heure == m.Heure && Minute == m.Minute ) ; }
} ;
#endif
