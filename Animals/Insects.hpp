#ifndef INSECTS_H
#define INSECTS_H

#include "Zivotinja.hpp"

class Insects : public Animals {
public:
	string A_type() { return "Insects"; }
	int legs() { return 6; }
};

class Fly : public Insects {
public:
	string A_type() { return "Fly"; }
};

class Roach : public Insects {
public:
	string A_type() { return "Roach"; }
};

#endif // !SPYDERS_H