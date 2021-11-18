#include "Header.hpp"

void shuffle(vector<int>& deck)
{
	for (int i = 0; i < 300; i++)
	{
		int ran1 = rand() % 51;
		int ran2 = rand() % 51;
		swap(deck[ran1], deck[ran2]);
	}
}

void print(vector<int>deck)
{
	for (int i = 0; i < deck.size(); i++)
		cout << deck[i] << endl;
}