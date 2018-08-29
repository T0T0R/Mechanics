#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "../include/main.h"
#include "../include/Vect3D.h"
#include "../include/Torsor.h"
#include "../include/Link.h"
#include "../include/Object.h"
#include "../include/PBody.h"
#include "../include/Bar.h"


int main(){
	std::cout<< "Hello World!" <<std::endl;
	
	Vect3D v1 = Vect3D(0.0, 1.0, 2.0);
	Vect3D v2 = Vect3D(0.0, -1.0, 1.0);
	Vect3D v3 = Vect3D(1.0, 1.0, 1.0);
	Vect3D v4 = Vect3D();

	Object obj1 = Object("OBJ1 - Parent");
	Object obj2 = Object("OBJ2 - Child");

	Torsor t1 = Torsor(v1);
	Torsor t2 = Torsor(v2);

	Link myLink = Link(t1);



	std::cout<< "OBJ1 = "<<obj1.getName()<<" ; OBJ2 = "<<obj2.getName() <<std::endl;


	int i_obj2 = myLink.link(obj1, obj2);
	std::vector<Object*> childsA = obj1.getChilds();
	std::cout<< "OBJ inside OBJ1 child's list : "<<childsA[i_obj2]->getName() <<std::endl;

	obj2.setName("TEST");
	std::cout<< "OBJ inside OBJ1 child's list : "<< childsA[i_obj2]->getName() <<std::endl;


	return EXIT_SUCCESS;
}
