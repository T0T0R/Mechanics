
#ifndef DEF_VECT3D
#define DEF_VECT3D

#include <iostream>
#include <string>

//template<typename T>

class Vect3D
{
public:
	Vect3D();
	Vect3D(double X, double Y, double Z);

	double getX() const;
	double getY() const;
	double getZ() const;

	int setX(double X);
	int setY(double Y);
	int setZ(double Z);

	int debug() const ;
	std::string datas() const;


	bool operator==(const Vect3D& vect);
	bool operator!=(const Vect3D& vect);

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
