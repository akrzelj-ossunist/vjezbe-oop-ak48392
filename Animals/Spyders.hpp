#ifndef SPYDERS_H
#define SPYDERS_H

#include "Zivotinja.hpp"

class Spyder : public Animals {
public:
	string A_type() { return "Spyder"; }
	int legs() { return 8; }
};

class Tarantula : public Spyder {
public:
	string A_type() { return "Tarantula"; }
};

class Black_widow : public Spyder {
public:
	string A_type() { return "Black Widow"; }
};

#endif // !SPYDERS_H
