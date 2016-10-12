#ifndef cPARTICLE_H_
#define cPARTICLE_H_



#include "MyVector3.h"
//class cMyVector3;

class cParticle {
	
	public:
	
		cParticle (double x_, double y_, double z_, double mass_, double radii_, double px_, double py_, double pz_);
		~cParticle 	();
		bool show 	();
		bool Ok 		();
	
		cMyVector3 return_coordin ();
		cMyVector3 return_speed ();
		double 	 return_mass ();
		double   return_radii ();
		
		void change_coordin (cMyVector3 new_coordin);
		void change_speed 	(cMyVector3 new_speed);
		void change_radii 	(double new_radii);
		void change_mass 		(double new_mass);
	
	private:
	
		cMyVector3 m_coordin;
		double m_mass;
		double m_radii;
		cMyVector3 m_speed;


};
#endif
