#include <iostream>
#include <assert.h>
#include "cParticle.h"
#include "const_def_cPartic.h"

using std::cout;
using std::endl;
//==============================
cParticle::cParticle (double x_, double y_, double z_, double Mass_, double Radius_, double px_, double py_, double pz_) {

	Mass = Mass_;
	Radius = Radius_;

	Coordin.SetX (x_);
	Coordin.SetY (y_);
	Coordin.SetZ (z_);

	Speed.SetX (px_);
	Speed.SetY (py_);
	Speed.SetZ (pz_);

}

//==============================
cParticle::~cParticle () {

	cout << "Particle Destructed\n";

}

//==============================
bool cParticle::Show () {
/*
#define IF_ERROR_SHOW_(variable, msg)	if (variable < 0)	{ \
																	cout << "ERROR!!!" << endl; \
																	cout << msg << "< 0" << endl; \
																	cout << __FILE__ << endl; \
																	cout << _FUNC_<< "   " << __LINE__ << endl; \
																	return false; \
																} \
																else cout << endl; \
																	return true;
*/
		cout << __FILE__ << "   "<< _FUNC_ << endl;

		cout << "Mass = " << Mass; IF_ERROR_SHOW_(Mass, "Mass")
		cout << "Radius_ = " << Radius; IF_ERROR_SHOW_(Radius, "Radius_")

		cout << "Coordin X = " << Coord.X () << endl;
		cout << "Coordin Y = " << Coord.Y () << endl;
		cout << "Coordin Z = " << Coord.Z () << endl;

		cout << "Speed X = " << Speed.X () << endl;
		cout << "Speed Y = " << Speed.Y () << endl;
		cout << "Speed Z = " << Speed.Z () << endl;

//#undef IFERROR_SHOW_

}

//==============================
bool cParticle::Ok () {

	IF_ERROR_SHOW_(Mass, "Mass")
	IF_ERROR_SHOW_(Radius, "Radius_")


}

//==============================
TVector3 cParticle::ReturnCoord () {
#ifdef CHECK
	_ASSERT_OK_()
#endif

	return Coord;
}

//==============================
TVector3 cParticle::ReturnSpeed () {
#ifdef CHECK
	_ASSERT_OK_()
#endif

	return Speed;
}

//==============================
double cParticle::ReturnMass () {
#ifdef CHECK
	_ASSERT_OK_()
#endif
	return Mass;
}

//==============================
double cParticle::ReturnRadius () {
#ifdef CHECK
	_ASSERT_OK_()
#endif

	return Radius;
}

//==============================
void cParticle::ChangeCoordin (TVector3 NewCoord) {
#ifdef CHECK
	_ASSERT_OK_()
#endif
		Coord = NewCoord;
}

//==============================
void cParticle::ChangeSpeed (TVector3 NewSpeed) {
#ifdef CHECK
	_ASSERT_OK_()
#endif

		Speed = NewSpeed;

#ifdef CHECK
	_ASSERT_OK_()
#endif
}

//==============================
void cParticle::ChangeMass (double  NewMass) {
#ifdef CHECK
	_ASSERT_OK_()
#endif

		Mass = NewMass;

#ifdef CHECK
	_ASSERT_OK_()
#endif
}

//==============================
void cParticle::ChangeRadius (double NewRadius) {
#ifdef CHECK
	_ASSERT_OK_()
#endif

		Radius = NewRadius;

#ifdef CHECK
	_ASSERT_OK_()
#endif
}
