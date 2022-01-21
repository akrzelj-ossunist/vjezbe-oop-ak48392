#ifndef ZIVOTINJA_H
#define ZIVOTINJA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Animals {
public:
	virtual string A_type() = 0;
	virtual int legs() = 0;
};


#endif 
