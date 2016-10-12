#ifndef cCOLLIDER_H_
#define cCOLLIDER_H_
#include <vector>
#include "cParticle.h"
#include "const_def_cPartic.h"


class cCollider {
	
		public:
			cCollider (int N_, part_param *param_, int pointer_ = 0);
			//cCollider (cParticle particle_);
			~cCollider ();
			bool show ();
			bool Ok ();
			
			rezalt_collider collision (rezalt_collider rezalt_);
			rezalt_collider step (int count_, rezalt_collider rezalt_, double size_of_step_ = 1.0, bool start_ = true);
		
		private:
		
		std::vector <cParticle*>  m_part;
		double m_time;
		int m_counter;
		
		rezalt_collider creat_rezalt_of_collid (rezalt_collider rezalt_, int i_, int j_);
		bool 	processing_error (const int namb_Of_error);
		
};


#endif 
