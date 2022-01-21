#ifndef GAME_H
#define GAME_H

#include "Player.hpp"

class Game {
	vector<Human> list;
	int result = 0;
public:
	Game(int r) :result(r) {};
	void addPlayers(int p_cnt);
	bool checkWinner(PC stats);
	void coinPick();
	void guess_points(vector<int>& guess);
	void check_result(vector<int> guess, PC stats);
	void showcase_score(PC stats);
};

#endif