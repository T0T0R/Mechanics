#ifndef DEF_TORSOR
#define DEF_TORSOR

#include <string>
#include "Vect3D.h"

class Torsor
{
public:

	Torsor();
	Torsor(Vect3D point);
	Torsor(Vect3D point, Vect3D speed);
	Torsor(Vect3D point, Vect3D speed, Vect3D rotation);

	Vect3D getPoint() const;
	Vect3D getSpeed() const;
	Vect3D getRotation() const;

	Vect3D setRotation(Vect3D rotation);

	Torsor move(Vect3D point) const;

	int debug() const;



protected:
	Vect3D setPoint(Vect3D point);
	Vect3D setSpeed(Vect3D speed);

	Vect3D m_point;
	Vect3D m_rotation;
	Vect3D m_speed;
};

Torsor operator+(const Torsor& t1, const Torsor& t2);
#endif
