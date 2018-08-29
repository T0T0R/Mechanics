#include <iostream>
#include "../include/Torsor.h"
#include "../include/Object.h"
#include "../include/Link.h"


/* Link
	Used to link objects and to apply degrees of freedom */


Link::Link(Torsor DEF):
	m_DEF(DEF)
	{}


Torsor Link::getDEF() const{ return m_DEF; }

int Link::setDEF(Torsor DEF){
	m_DEF = DEF;
	return 0;
}


int Link::link(Object& obj1, Object& obj2){
	//Appending obj2 to the list of childs of obj1.
	return obj1.appendChild(obj2);
}

