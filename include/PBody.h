#ifndef DEF_PBODY
#define DEF_PBODY

#include "Vect3D.h"
#include "Object.h"

class PBody : public Object
{
public:

	PBody();
	PBody(Vect3D position, Vect3D velocity, double mass, double charge);

	double getMass() const;
	double getCharge() const;

	double setMass(double mass);
	double setCharge(double charge);

	int debug() const;

protected:
	double m_mass;
	double m_charge;
};

#endif
