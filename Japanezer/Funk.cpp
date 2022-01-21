#include "Game.hpp"

void Game::addPlayers(int p_cnt)
{
	string name;
	int cnt = 1;
	while (p_cnt) {
		cout << "Input " << cnt << ". player..." << endl;
		cin >> name;
		Human H(name, 0, 0);
		list.push_back(H);
		p_cnt--;
		cnt++;
	}
}

void Game::coinPick()
{
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].Name << " turn: " << endl;
		vector<int>coins = { 0, 1, 2, 0, 0, 5 };
		cout << "Pick 0-3 coins with value of 1,2 or 5" << endl;
		cout << "How many coins do you want to pick: " << endl;
		int num;
		cin >> num;
		while (num) {
			cout << "Which coin do you want to pick..." << endl;
			int coin;
			cin >> coin;
			if ((coin == 1 || coin == 2 || coin == 5) && coins[coin] != 0) {
				list[i].points += coin;
				coins[coin] = 0;
				num--;
			}
			else
				cout << "You picked coin that is not available! Pick again..." << endl;
		}
	}
}

void PC::pick_coin()
{
	srand(time(NULL));
	points = rand() % 7;
	while (points == 4)
		points = rand() % 7;
}

void Game::guess_points(vector<int>& guess)
{
	srand(time(NULL));
	int g;
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].Name << " is guessing..." << endl;
		cin >> g;
		guess.push_back(g);
	}
	cout << "Computer is guessing..." << endl;
	g = rand() % 7;
	while (g == 4)
		g = rand() % 7;
	guess.push_back(g);
}

void Game::check_result(vector<int> guess, PC stats)
{
	for (int i = 0; i < guess.size(); i++) {
		for (int j = 0; j < list.size(); j++) {
			if (i == guess.size() - 1 && guess[i] == list[j].points) {
				cout << "Computer guessed it right!  " << endl;
				stats.score += 1;
			}
			if (guess[i] == list[j].points && i != j ) {
				cout << "Player " << list[i].Name << " guessed right! " << endl;
				list[i].score += 1;
				break;
			}
		}
		if (i != guess.size() - 1 && guess[i] == stats.points) {
			cout << "Player " << list[i].Name << " guessed right! " << endl;
			list[i].score += 1;
		}
	}
}

void Game::showcase_score(PC stats)
{
	cout << "Computer score..." << stats.score << endl;
	for (int i = 0; i < list.size(); i++)
		cout << "Player " << list[i].Name << " score..." << list[i].score << endl;
}

bool Game::checkWinner(PC stats)
{
	int win = 0;
	if (stats.score == result) {
		cout << "Compuer won!!!" << endl;
		win += 1;
	}
	for (int i = 0; i < list.size(); i++) {
		if (list[i].score == result) {
			cout << "Player " << list[i].Name << " won!!! " << endl;
			win += 1;
		}
	}
	if (win > 0)
		return 0;
	else return 1;
}