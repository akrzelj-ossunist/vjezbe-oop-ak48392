#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Player {
public:
	int score;
	int points;

};

class Human : public Player {
public:
	string Name;
	Human(string name, int s, int p) {
		Name = name;
		score = s;
		points = p;
	};

};

class PC : public Player {
public:
	PC(int s, int p) {
		score = s;
		points = p;
	};
	void pick_coin();
};


#endif