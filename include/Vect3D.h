
#ifndef DEF_VECT3D
#define DEF_VECT3D

#include <iostream>
#include <string>

//template<typename T>

class Vect3D
{
public:
	Vect3D::Vect3D();
	Vect3D::Vect3D(double X, double Y, double Z);

	double Vect3D::getX() const;
	double Vect3D::getY() const;
	double Vect3D::getZ() const;

	int Vect3D::setX(double X);
	int Vect3D::setY(double Y);
	int Vect3D::setZ(double Z);

	int Vect3D::debug() const ;
	std::string Vect3D::datas() const;


	bool Vect3D::operator==(const Vect3D& vect);
	bool Vect3D::operator!=(const Vect3D& vect);

protected:

	double m_X;
	double m_Y;
	double m_Z;
};


Vect3D operator*(const Vect3D& v, const double& b);
Vect3D operator*(const double& b, const Vect3D& v);
Vect3D operator*(const Vect3D& v1, const Vect3D& v2);
Vect3D operator+(const Vect3D& v1, const Vect3D& v2);
Vect3D operator-(const Vect3D& v1, const Vect3D& v2);

#endif
