#ifndef CAT_H
#define CAT_H

#include "Zivotinja.hpp"

class Cat : public Animals {
public:
	string A_type() { return "Cat"; }
	int legs() { return 4; }
};

class Lion : public Cat {
public:
	string A_type() { return "Lion"; }
};

class Tiger : public Cat {
public:
	string A_type() { return "Tiger"; }
};

#endif // !CAT_H

