#include "Header.hpp"

void players::game(vector<int>deck, int& reset)
{
	int player_num, br;
	vector<int>hand_total;
	cout << "How many players do want to play from 1-5: " << endl;
	cin >> player_num;
	while (player_num < 0 && player_num > 5)
	{
		cout << "You can only pick from 1-5 players: " << endl;
		cin >> player_num;
	}
	shuffle(deck);
	cout << "Host is dealing the cards... " << endl;
	br = player_num * 2 + 2;
	for (int i = 0; i < player_num; i++)
		player(deck, i + 1, br, player_num, hand_total);
	comp(deck, br, player_num, hand_total);

	cout << "Do you wanna play again? " << endl;
	cout << "Type 'y' for yes or 'n' for no: " << endl;
	char c;
	cin >> c;
	while (c != 'y' && c != 'n')
	{
		cout << "Wrong input! " << endl;
		cout << "Press 'y' to continue or 'n' to end!" << endl;
		cin >> c;
	}
	if (c == 'y')
		reset = 1;
	else
		reset = 0;
}