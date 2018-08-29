#ifndef DEF_LINK	
#define DEF_LINK

#include "Vect3D.h"
#include "Torsor.h"
#include "Object.h"

class Link
{
public:

	Link(Torsor DEF);	//DEF stands for "degrees of freedom"

	Torsor getDEF() const;

	int setDEF(Torsor DEF);

	int link(Object& obj1, Object& obj2);


protected:
	Torsor m_DEF;	//DEF stands for "degrees of freedom"
};

#endif