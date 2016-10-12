#include <iostream>
#include <assert.h>

#include "cParticle.h"
#include "const_def_cPartic.h"

using std::cout;
using std::endl;
//==============================
cParticle::cParticle (double x_, double y_, double z_, double mass_, double radii_, double px_, double py_, double pz_) {
	
	m_mass = mass_;
	m_radii = radii_;
	
	m_coordin.SetX (x_);
	m_coordin.SetY (y_);
	m_coordin.SetZ (z_);
	
	m_speed.SetX (px_);
	m_speed.SetY (py_);
	m_speed.SetZ (pz_);
	
}

//==============================
cParticle::~cParticle () {
	
	cout << "I am  a distruction, I delit your Particle \n";
	
}

//==============================
bool cParticle::show () {
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
		
		cout << "m_mass = " << m_mass << endl;		// IF_ERROR_SHOW_(m_mass, "m_mass")
		cout << "m_radii_ = " << m_radii << endl;	// IF_ERROR_SHOW_(m_radii, "m_radii_")

		cout << "m_coordin X = " << m_coordin.X () << endl;
		cout << "m_coordin Y = " << m_coordin.Y () << endl;
		cout << "m_coordin Z = " << m_coordin.Z () << endl; 
		 
		cout << "m_speed X = " << m_speed.X () << endl;	
		cout << "m_speed Y = " << m_speed.Y () << endl;	
		cout << "m_speed Z = " << m_speed.Z () << endl;	
	 
//#undef IFERROR_SHOW_		
 	
}

//==============================
bool cParticle::Ok () {
	
	IF_ERROR_SHOW_(m_mass, "m_mass")
	IF_ERROR_SHOW_(m_radii, "m_radii_")
	
	
}

//==============================
cMyVector3 cParticle::return_coordin () {
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
		
	return m_coordin;	
}

//==============================
cMyVector3 cParticle::return_speed () {
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

	return m_speed;
}

//==============================
double cParticle::return_mass () {
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
	return m_mass;
}

//==============================
double cParticle::return_radii () {
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

	return m_radii;
}

//==============================
void cParticle::change_coordin (cMyVector3 new_coordin) {
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
	
		m_coordin = new_coordin;4
		
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
}

//==============================
void cParticle::change_speed (cMyVector3 new_speed) {
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif

		m_speed = new_speed;

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_()
#endif
}

//==============================
void cParticle::change_mass (double  new_mass) {
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_();
#endif

		m_mass = new_mass;

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_();
#endif
}

//==============================
void cParticle::change_radii (double new_radii) {
#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_();
#endif

		m_radii = new_radii;

#ifdef USE_SUPER_PUPER_GUARDS	
	_ASSERT_OK_();
#endif
}
