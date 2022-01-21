#ifndef COUNT_H
#define COUNT_H

#include "Zivotinja.hpp"

class Count {
	int total = 0;
public:
	void addLegs(Animals* a) { cout << "Animal: " << a->A_type() << endl; total += a->legs(); }
	void legsOverall() { cout << "Total legs: " << total << endl; }
};

#endif // !COUNT_H
