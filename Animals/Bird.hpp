#ifndef BIRD_H
#define BIRD_H

#include "Zivotinja.hpp"

class Bird : public Animals {
public:
	string A_type() { return "Bird"; }
	int legs() { return 2; }
};

class Eagle : public Bird {
public:
	string A_type() { return "Eagle"; }
};

class Ostrich : public Bird{
public:
	string A_type() { return "Ostrich"; }
};


#endif 

