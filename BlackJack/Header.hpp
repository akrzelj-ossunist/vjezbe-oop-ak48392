#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

typedef struct players{
	int* host_hand;
	int* p_hand;
	int win, lose, tie;

	void game(vector<int>deck, int& reset);
	void player(vector<int>deck, int player_num, int& br, int player_cnt, vector<int> &hand_total);
	void comp(vector<int>deck, int& br, int player_cnt, vector<int> &hand_total);

}players;

void shuffle(vector<int>& deck);
void hand_list(int* (&hand), int br);
void decision(char& c);


#endif 

