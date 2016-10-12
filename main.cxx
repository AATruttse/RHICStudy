#include  <iostream>

#include "cCollider.h"
#include "const_def_cPartic.h"

using std::cout;

int main () {
	
	part_param part_one [2];
						
	part_one[0].x = 0;
	part_one[0].y = 3;
	part_one[0].z = 0;
	        
	part_one[0].px = 1;
	part_one[0].py = 0;
	part_one[0].pz = 0;
	        
	part_one[0].mass = 1;
	part_one[0].radii = 1;

	part_one[1].x = 1;
	part_one[1].y = 5;
	part_one[1].z = 1;
	         
	part_one[1].px = 1;
	part_one[1].py = 1;
	part_one[1].pz = 1;
	         
	part_one[1].mass = 2;
	part_one[1].radii = 3;
	
	cCollider collid1 (2, part_one, 0);
	collid1.show ();

	cout << "IIII Ok \n";
	

return 0;	
}
