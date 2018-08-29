#include <iostream>
#include "../include/Vect3D.h"
#include "../include/Object.h"
#include "../include/PBody.h"


/* Punctual Body
	Described by its mass, charge, position and velocity. 
	No mass distribution */


PBody::PBody():
	Object(), m_mass(0.0), m_charge(0.0)
	{}

PBody::PBody(Vect3D position, Vect3D velocity, double mass, double charge):
	Object(position, Vect3D(), velocity, Vect3D()), m_mass(mass), m_charge(charge)
	{}

double PBody::getMass() const {return m_mass;}
double PBody::getCharge() const {return m_charge;}

double PBody::setMass(double mass){m_mass = mass; return mass;}
double PBody::setCharge(double charge){m_charge = charge; return charge;}

int PBody::debug() const {
	Object::debug();
	std::cout << "TYPE:\tPunctual Body\n"
	     << "DATAS:\tMass = "<<m_mass<<" kg;\tCharge = "<<m_charge<<" C\n" <<std::endl;
	return 0;
}

