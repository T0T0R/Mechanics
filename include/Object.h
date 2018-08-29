#ifndef DEF_OBJECT
#define DEF_OBJECT

#include <vector>
#include <string>
#include "Vect3D.h"
#include "Torsor.h"

class Object
{
public:

	Object();
	Object(Vect3D position, Vect3D orientation);
	Object(Vect3D position, Vect3D orientation, Vect3D velocity, Vect3D rotation);
	Object(std::string name);

	Vect3D getPosition() const;
	Vect3D getOrientation() const;
	Vect3D getVelocity() const;
	Vect3D getRotation() const;

	Torsor getkTorsor() const;
	Torsor getkTorsor(Vect3D const& point) const;
	std::vector<Object*> getChilds();
	std::string getName() const;


	//Vect3D getPositionL() const;
	//Vect3D getOrientationL() const;
	//Vect3D getVelocityL() const;
	//Vect3D getRotationL() const;

	Vect3D setPosition(Vect3D position);
	Vect3D setOrientation(Vect3D orientation);
	Vect3D setVelocity(Vect3D velocity);
	Vect3D setRotation(Vect3D rotation);

	int setChilds(std::vector<Object*> childs);
	int appendChild(Object& child);
	int setName(std::string name);
	int setKTorsor(Torsor ktorsor);


	
	//Vect3D setPositionL(Vect3D position);
	//Vect3D setOrientationL(Vect3D orientation);
	//Vect3D setVelocityL(Vect3D velocity);
	//Vect3D setRotationL(Vect3D rotation);

	int debug() const;

protected:
	Vect3D m_position;
	Vect3D m_orientation;	//Stores angles, not a vector
	Vect3D m_velocity;
	Vect3D m_rotation;

	//Values not relative to the study referential,
	//	but relative to the parent object.
	Vect3D m_positionL;
	Vect3D m_orientationL;	//Stores EULER angles, not a vector
	Vect3D m_velocityL;
	Vect3D m_rotationL;

	Torsor m_kTorsor;	//Kinematic Torsor	

	std::vector<Object*> m_childs;

	std::string m_name;
};

#endif
