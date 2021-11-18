#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

void shuffle(vector<int>& deck);
void print(vector<int>deck);
void game(vector<int>deck, int &reset);

#endif // !_HEADER_H

