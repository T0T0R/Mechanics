#ifndef DEF_BAR
#define DEF_BAR

#include "Vect3D.h"
#include "Object.h"

class Bar : public Object
{
public:

	Bar();
	Bar(Vect3D position, Vect3D orientation, double length);
	Bar(Vect3D position, Vect3D orientation, Vect3D velocity, Vect3D rotation, double lenght);

	double getLength() const;

	double setLength(double lenght);

	int debug() const;

protected:
	double m_length;
};

#endif
