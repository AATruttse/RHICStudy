#include <iostream>
#include <assert.h>
#include "cCollider.h"
#include "const_def_cPartic.h"
#include <cerrno> 
using std::cout;
using std::endl;

//==============================
/*
cCollider::cCollider (cParticle particle_) {
	
		//m_part [0] = new cParticle;
		//m_counter = 0;
		//m_time = 0;
	
}
*/
//==============================
cCollider::cCollider  (int N_, part_param param_, int pointer_) {
	
	for (int i = pointer_; i < N_; i++) {
		//111111111111111111111111111111111
			m_part [i] = new cParticle (param_.x, param_.y, param_.z, param_.mass, param_.radii, param_.px, param_.py, param_.pz);
		//2222222222222222222222222222222
			m_part.push_back(new cParticle (param_.x, param_.y, param_.z, param_.mass, param_.radii, param_.px, param_.py, param_.pz));
		//3333333333333333333333333333333
			m_part.resize (10);
			m_part [i] = new cParticle (param_.x, param_.y, param_.z, param_.mass, param_.radii, param_.px, param_.py, param_.pz);
		//==============================
		m_counter = i;
	}
	m_time = 0;
} 
//==============================
cCollider::~cCollider () {
	for (int i = 0; i < m_counter; i++) {	
		if (m_part [i] != NULL) {
				delete   m_part[i];
		} 	
	}
}

//==============================
bool cCollider::show () {
	
	cout << "m_counter" << m_counter; IF_ERROR_SHOW_( m_counter,  "m_counter")
	cout << "m_time" << m_time; IF_ERROR_SHOW_( m_time,  "m_time")
	
	for (int i = 0; i <= m_counter; i++ ) {
		m_part [0]->show ();
	}
}

//==============================
bool cCollider::Ok () {
	
	IF_ERROR_SHOW_( m_counter,  "m_counter")
	IF_ERROR_SHOW_( m_time,  "m_time")
	
	for (int i = 0; i <= m_counter; i++ ) {
		m_part [0]->Ok ();
	}
}

//==============================
rezalt_collider cCollider::collision (rezalt_collider rezalt_) {
		
		
		if (m_counter = 0) {
			processing_error (one_part_in_collid);
			errno = 125; 		// ECANCELED
			return rezalt_;
		}
		
		TVector3 dist1;
		TVector3 dist2;
		
		for (int i = 0; i < m_counter; i++) {
			for (int j = (i + 1); j <= m_counter; j++ ) {
				dist1 =	m_part [i]->return_coordin ();
				dist2 = m_part [j]->return_coordin ();
				if ((m_part [i]->return_radii () + m_part [j]->return_radii ()) < (TMath::Abs (dist1.X() - dist2.X()))) {
						errno = 0;
						return creat_rezalt_of_collid (rezalt_,i, j);
				}
				if ((m_part [i]->return_radii () + m_part [j]->return_radii ()) < TMath::Abs (dist1.Y() - dist2.Y())) {
						errno = 0;
						return creat_rezalt_of_collid (rezalt_,i, j);
				}
				if ((m_part [i]->return_radii () + m_part [j]->return_radii ()) < TMath::Abs (dist1.Z() - dist2.Z())) {
						errno = 0;
						return creat_rezalt_of_collid (rezalt_,i, j);
				}
			}
		}
		
		errno = 10;		//ECHILD	
		return rezalt_;
}

//==============================
rezalt_collider cCollider::creat_rezalt_of_collid (rezalt_collider rezalt_, int i_, int j_) {
	
	/*
	 * mast to do 
	 * maybe it will do by Stepan ???
		*/
	return rezalt_;
}

//==============================
bool 	cCollider::processing_error (const int namb_Of_error) {
	
	#define IF_ERROR_NUMBER_COLLIDER_(err, text) \
				if (namb_Of_error == err) {     \
					cout << text << endl;       \
					return true; 								\
				}	
	
	 IF_ERROR_NUMBER_COLLIDER_(one_part_in_collid,
		"One particle in collider not enough to impinge \n")
	
	 IF_ERROR_NUMBER_COLLIDER_(time_to_collide_passid,
		"Time to collisions has passed \n")
	#undef IF_ERROR_NUMBER_COLLIDER_
}

//==============================
rezalt_collider cCollider::step (int count_, rezalt_collider rezalt_, double size_of_step_ , bool start_) {
	
	collision (rezalt_);
	if (errno == 125) {
			cout << "I cannot collide one particl \n";
			return rezalt_;
	}
	
	TVector3 speed;
	TVector3 coordin_old;
	TVector3 coordin_new;
	
	double px, py, pz;
	double x, y, z;
	while (start_ && (errno == 10)) {
		for (int i = 0; i <= m_counter; i++) {
			speed = m_part [i]->return_speed ();
			px = size_of_step_ * speed.X ();
			py = size_of_step_ * speed.Y ();
			pz = size_of_step_ * speed.Z ();
		
			coordin_old = m_part [i]->return_coordin ();
			x = coordin_old.X ();
			y = coordin_old.Y ();
			z = coordin_old.Z ();
			
			coordin_new.SetXYZ (x, y, z);
			m_part [i]->change_coordin (coordin_new);
		} //end of for
		m_time++;
		collision (rezalt_);
		if (m_time == time_to_collide_passid) {
				start_ = false;
				processing_error (time_to_collide_passid);
		}
	}	// end of while

	return rezalt_;
}
