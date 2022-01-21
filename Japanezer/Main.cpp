#include "Game.hpp"

void main()
{
	int p_cnt;
	cout << "How many players do you want? " << endl;
	cin >> p_cnt;
	cout << "What is the result you want to acquire?" << endl;
	int r;
	cin >> r;
	Game g(r);
	PC stats(0, 0);
	g.addPlayers(p_cnt);
	system("CLS");
	while (g.checkWinner(stats)) {
		puts(" ");
		g.coinPick();
		stats.pick_coin();
		vector<int> guess;
		g.guess_points(guess);
		system("CLS");
		g.check_result(guess, stats);
		g.showcase_score(stats);
	}
}
