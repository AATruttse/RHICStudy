#ifndef cPARTICLE_H_
#define cPARTICLE_H_

#include <TVector3.h>

class cParticle {

	public:

		cParticle (double x_, double _y, double _z, double Mass_, double Radius, double px_, double py_, double pz_);
		~cParticle 	();
		bool Show 	();
		bool Ok 	();

		TVector3 ReturnCoord ();
		TVector3 ReturnSpeed ();
		double 	 ReturnMass ();
		double   ReturnRadius ();

		void ChangeCoord (TVector3 NewCoord);
		void ChangeSpeed 	(TVector3 NewSpeed);
		void ChangeRadius 	(double NewRadius);
		void ChangeMass 		(double NewMass);

	private:

		TVector3 Coord, Speed;
		double Mass, Radius;


};
#endif
