#include <iostream>
#include "../include/Vect3D.h"
#include "../include/Object.h"
#include "../include/Bar.h"


/* Bar
	Simple bar with no mass and no volume.
	Rigid body. */


Bar::Bar():
	Object()
	{}

Bar::Bar(Vect3D position, Vect3D orientation, double length):
	Object(position, orientation, Vect3D(), Vect3D()), m_length(length)
	{}

Bar::Bar(Vect3D position, Vect3D orientation, Vect3D velocity, Vect3D rotation, double length):
	Object(position, orientation, velocity, rotation), m_length(length)
	{}

double Bar::getLength() const {return m_length;}

double Bar::setLength(double length){m_length = length; return length;}

int Bar::debug() const {
	Object::debug();
	std::cout << "TYPE:\tSimple Bar\n"
	     << "DATAS:\tLength = "<<m_length<<" m"<<std::endl;
	return 0;
}

