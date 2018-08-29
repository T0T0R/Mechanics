#include <iostream>
#include <vector>
#include <string>
#include "../include/Vect3D.h"
#include "../include/Torsor.h"
#include "../include/Object.h"


/* Object
	Parent class of all moving objects, providing
	position, velocity, rotation globally
	(relative to the study referential) and localy
	(relative to the object referential).

	--Local values named with a "L" at the end--*/


Object::Object(){
	Vect3D m_position = Vect3D();
	Vect3D m_orientation = Vect3D(0.0, 0.0, 0.0); //Stores angles, not a vector
	Vect3D m_velocity = Vect3D();
	Vect3D m_rotation = Vect3D();
}

Object::Object(Vect3D position, Vect3D orientation):
	m_position(position), m_orientation(orientation){
	Vect3D velocity = Vect3D();
	Vect3D rotation = Vect3D();
}

Object::Object(Vect3D position, Vect3D orientation, Vect3D velocity, Vect3D rotation):
	m_position(position), m_orientation(orientation), m_velocity(velocity), m_rotation(rotation)
	{}

Object::Object(std::string name):
	m_name(name){
	Vect3D m_position = Vect3D();
	Vect3D m_orientation = Vect3D(0.0, 0.0, 0.0); //Stores angles, not a vector
	Vect3D m_velocity = Vect3D();
	Vect3D m_rotation = Vect3D();
}


Vect3D Object::getPosition() const {return m_position;}
Vect3D Object::getOrientation() const {return m_orientation;}
Vect3D Object::getVelocity() const {return m_velocity;}
Vect3D Object::getRotation() const {return m_rotation;}

Torsor Object::getkTorsor() const {return m_kTorsor;}
Torsor Object::getkTorsor(Vect3D const& point) const { return m_kTorsor.move(point); }
std::vector<Object*> Object::getChilds(){
	//Returns an array of ptr on each childs this object is linked to.
	return m_childs;
}
std::string Object::getName() const{return m_name;}

//Vect3D Object::getPositionL() const {return m_positionL;}
//Vect3D Object::getOrientationL() const {return m_orientationL;}
//Vect3D Object::getVelocityL() const {return m_velocityL;}
//Vect3D Object::getRotationL() const {return m_rotationL;}

Vect3D Object::setPosition(Vect3D position){
	m_position = position; return position;}
Vect3D Object::setOrientation(Vect3D orientation){
	m_orientation = orientation; return orientation;}
Vect3D Object::setVelocity(Vect3D velocity){
	m_velocity = velocity; return velocity;}
Vect3D Object::setRotation(Vect3D rotation){
	m_rotation = rotation; return rotation;}

int Object::setChilds(std::vector<Object*> childs){
	m_childs = childs;
	return m_childs.size();
}

int Object::appendChild(Object& child){
	Object *_child(0);
	_child = &child;
	m_childs.push_back(_child);
	return m_childs.size()-1;	//Returns index of child stored in m_childs.
}

int Object::setName(std::string name){
	m_name = name;
	return 0;
}

//Vect3D Object::setPositionL(Vect3D position){
//	m_positionL = position; return position;}
//Vect3D Object::setOrientationL(Vect3D orientation){
//	m_orientationL = orientation; return orientation;}
//Vect3D Object::setVelocityL(Vect3D velocity){
//	m_velocityL = velocity; return velocity;}
//Vect3D Object::setRotationL(Vect3D rotation){
//	m_rotationL = rotation; return rotation;}


int Object::setKTorsor(Torsor ktorsor){
	m_kTorsor = ktorsor;
	return 0;
}

int Object::debug() const {
	std::cout << "TYPE:\tObject\n"
	     << "DATAS:\tPosition = ("<<m_position.getX()<<" ; "<<m_position.getY()<<" ; "<<m_position.getZ()<<") m\tLocal Position = ("<<m_positionL.getX()<<" ; "<<m_positionL.getY()<<" ; "<<m_positionL.getZ()<<") m\n"
	     << "\tOrientation = ("<<m_orientation.getX()<<" ; "<<m_orientation.getY()<<" ; "<<m_orientation.getZ()<<") °\tLocal Orientation = ("<<m_orientationL.getX()<<" ; "<<m_orientationL.getY()<<" ; "<<m_orientationL.getZ()<<") °\n"
	     << "\tVelocity = ("<<m_velocity.getX()<<" ; "<<m_velocity.getY()<<" ; "<<m_velocity.getZ()<<") m/s\tLocal Velocity = ("<<m_velocityL.getX()<<" ; "<<m_velocityL.getY()<<" ; "<<m_velocityL.getZ()<<") m/s\n"
	     << "\tRotation = ("<<m_rotation.getX()<<" ; "<<m_rotation.getY()<<" ; "<<m_rotation.getZ()<<") Nm\tLocal Rotation = ("<<m_rotationL.getX()<<" ; "<<m_rotationL.getY()<<" ; "<<m_rotationL.getZ()<<") Nm"<<std::endl;
	return 0;
}

