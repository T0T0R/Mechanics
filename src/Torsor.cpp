#include <iostream>
#include <string>
#include "../include/Vect3D.h"
#include "../include/Torsor.h"


/* Kinematic Torsor 
	Math. object used to represent both rotation and speed (on a specific point) of a body
	T = {Rot ; Speed}_(point)
	Couldn't find a prope translationfor the french term "torseur cinematique".*/


Torsor::Torsor():
	m_point(), m_speed(), m_rotation() 
	{}

Torsor::Torsor(Vect3D point):
	m_point(point), m_speed(), m_rotation()
	{}

Torsor::Torsor(Vect3D point, Vect3D torque):
	m_point(point), m_speed(torque), m_rotation()
	{}

Torsor::Torsor(Vect3D point, Vect3D torque, Vect3D force):
	m_point(point), m_speed(torque), m_rotation(force)
	{}

Vect3D Torsor::getPoint() const {return m_point;}
Vect3D Torsor::getRotation() const {return m_rotation;}
Vect3D Torsor::getSpeed() const {return m_speed;}

Vect3D Torsor::setPoint(Vect3D point){m_point = point; return point;}
Vect3D Torsor::setRotation(Vect3D rotation){m_rotation = rotation; return rotation;}
Vect3D Torsor::setSpeed(Vect3D speed){m_speed = speed; return speed;}


Torsor Torsor::move(Vect3D point) const {
	//M_B(R) = M_A(R) + BA*R
	Vect3D vectBA = m_point - point;
	return Torsor(point, m_speed + (vectBA*m_rotation), m_rotation);
}


int Torsor::debug() const {
	std::cout << "TYPE:\tTorsor\n"
	     << "DATAS:\t( "<<m_rotation.getX()<<"\t"<<m_speed.getX()<<" )\n"
	     << "\t) "<<m_rotation.getY()<<"\t"<<m_speed.getY()<<"(\n"
	     << "\t( "<<m_rotation.getZ()<<"\t"<<m_speed.getZ()<<")"<<m_point.datas()<<std::endl;
	return 0;
}



Torsor operator+(const Torsor& t1, const Torsor& t2){
	if (t1.getPoint() != t2.getPoint()) {
		std::cerr<< "*** Addition of torsors : different points of expression"<<std::endl;
	}
		return Torsor(t1.getPoint(), t1.getSpeed() + t2.getSpeed(), t1.getRotation() + t2.getRotation());
}
