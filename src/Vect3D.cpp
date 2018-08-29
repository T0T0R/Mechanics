#include <iostream>
#include <string>
#include "../include/Vect3D.h"


/* Implements the mathematical object vector */


Vect3D::Vect3D():
	m_X(0.0), m_Y(0.0), m_Z(0.0)
	{}

Vect3D::Vect3D(double X, double Y, double Z):
	m_X(X), m_Y(Y), m_Z(Z)
	{}

double Vect3D::getX() const {return m_X;}
double Vect3D::getY() const {return m_Y;}
double Vect3D::getZ() const {return m_Z;}

int Vect3D::setX(double X){m_X = X; return 0;}
int Vect3D::setY(double Y){m_Y = Y; return 0;}
int Vect3D::setZ(double Z){m_Z = Z; return 0;}

int Vect3D::debug() const {
	std::cout << "TYPE:\t3D Vector\n"
	     << "DATAS:\tx="<<m_X <<" ; y="<<m_Y <<" ; z="<<m_Z <<"\n"<<std::endl;
	return 0;
}
std::string Vect3D::datas() const{
	return "(" + std::to_string(m_X) + " ; " + std::to_string(m_Y) + " ; " + std::to_string(m_Z) + ")";
}



bool Vect3D::operator==(const Vect3D& vect) {
	if (vect.getX() == m_X && vect.getY() == m_Y && vect.getZ() == m_Z) {
		return true;
	}else{
		return false;
	}
}


bool Vect3D::operator!=(const Vect3D& vect) {
	if (*this == vect) {
		return false;
	}else{
		return true;
	}
}



Vect3D operator*(const Vect3D& v, const double& b) {
	return Vect3D(b*v.getX(), b*v.getY(), b*v.getZ());
}


Vect3D operator*(const double& b, const Vect3D& v) {
	return Vect3D(b*v.getX(), b*v.getY(), b*v.getZ());
}


Vect3D operator*(const Vect3D& v1, const Vect3D& v2) {	//Cross product
	double x = v1.getY() * v2.getZ() - v1.getZ()*v2.getY();
	double y = v1.getZ() * v2.getX() - v1.getX()*v2.getZ();
	double z = v1.getX() * v2.getY() - v1.getY()*v2.getX();
	return Vect3D(x, y, z);
}



Vect3D operator+(const Vect3D& v1, const Vect3D& v2){
	return Vect3D(v1.getX()+v2.getX() , v1.getY()+v2.getY() , v1.getZ()+v2.getZ());
}

Vect3D operator-(const Vect3D& v1, const Vect3D& v2){
	return v1+(-1*v2);
}

