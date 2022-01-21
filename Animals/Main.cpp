#include "Zivotinja.hpp"
#include "Cat.hpp"
#include "Bird.hpp"
#include "Insects.hpp"
#include "Spyders.hpp"
#include "Count.hpp"

void main() {
	Lion L;
	Eagle E;
	Tarantula T;
	Count C;

	C.addLegs(&L);
	C.addLegs(&T);
	C.addLegs(&E);
	C.legsOverall();
}