#include "Header.hpp"

void shuffle(vector<int>& deck)
{
	for (int i = 0; i < 1000; i++)
	{
		int ran1 = rand() % 51;
		int ran2 = rand() % 51;
		swap(deck[ran1], deck[ran2]);
	}
}

void hand_list(int* (&hand), int br)
{
	for (int j = 0; j < br; j++)
		cout << hand[j] << "\t";
}

void decision(char& c)
{
	cout << "Do you wanna take a new card? " << endl;
	cout << "Type 'y' for yes or 'n' for no: " << endl;
	cin >> c;
	while (c != 'y' && c != 'n')
	{
		cout << "Wrong input! " << endl;
		cout << "Press 'y' to continue or 'n' to end!" << endl;
		cin >> c;
	}
}