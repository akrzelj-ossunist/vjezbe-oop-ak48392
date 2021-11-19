#include "Header.hpp"

void players::player(vector<int>deck, int player_num, int &br, int player_cnt, vector<int> &hand_total)
{
	cout << 2 << endl;
	int card_br = 2;
	p_hand = new int[11];
	p_hand[0] = deck[player_num - 1];
	p_hand[1] = deck[player_num + player_cnt];
	cout << "\nHost got: " << deck[player_cnt] << " and ???" << endl;
	cout << "Player " << player_num << " got: " << p_hand[0] << " and " << p_hand[1] << endl;
	hand_total.push_back(p_hand[0] + p_hand[1]);
	if (p_hand[0] == 1)
	{
		p_hand[0] = 11;
		hand_total[player_num - 1] += 10;
	}
	else if (p_hand[1] == 1)
	{
		p_hand[1] = 11;
		hand_total[player_num - 1] += 10;
	}

	if (hand_total[player_num - 1] == 21 && (deck[player_cnt] != 10 || deck[player_cnt] != 1))
	{
		cout << "\nCongratulation Player " << player_num << " got BlackJack!" << endl;
		hand_total[player_num - 1] = 0;
		return;
	}

	if ((deck[player_cnt] == 10 || deck[player_cnt] == 1) && ((deck[player_cnt] == 10 && deck[player_cnt * 2 + 1] == 1) || (deck[player_cnt] == 1 && deck[player_cnt * 2 + 1] == 10)))
	{
		if (hand_total[player_num - 1] != 21)
		{
			cout << "\nHost won, Player " << player_num << " lost, better luck next time!" << endl;
			hand_total[player_num - 1] = 0;
			return;
		}
	}

	if ((deck[player_cnt] == 10 || deck[player_cnt] == 1) && ((deck[player_cnt] == 10 && deck[player_cnt * 2 + 1] == 1) || (deck[player_cnt] == 1 && deck[player_cnt * 2 + 1] == 10)))
	{
		if (hand_total[player_num - 1] == 21)
		{
			cout << "\nPlayer " << player_num << " got a tie!" << endl;
			hand_total[player_num - 1] = 0;
			return;
		}
	}

	for (br; br < deck.size(); br++)
	{
		cout << "Player " << player_num << " hand: " << endl;
		hand_list(p_hand, card_br);
		cout << "Your cards total is: " << hand_total[player_num - 1] << endl;
		char c;
		decision(c);
		if (c == 'y')
		{	
			cout << "You got... " << deck[br] << endl;
			if (deck[br] == 1 && hand_total[player_num - 1] + 11 <= 21)
				deck[br] == 11;
			p_hand[card_br] = deck[br];
			card_br++;
			hand_total[player_num - 1] += deck[br];
			if (hand_total[player_num - 1] > 21)
			{
				for (int j = 0; j < card_br; j++)
					if (p_hand[j] == 11)
					{
						p_hand[j] = 1;
						hand_total[player_num - 1] -= 10;
						break;
					}
			}
			if (hand_total[player_num - 1] > 21)
			{
				cout << "Host won, Player "<< player_num <<" lost, better luck next time!" << endl;
				hand_total[player_num - 1] = 0;
				return;
			}
		}
		else
			break;
	}
	delete[] p_hand;
}

void players::comp(vector<int>deck, int& br, int player_cnt, vector<int> &hand_total)
{
	p_hand = new int[11];
	p_hand[0] = deck[player_cnt];
	p_hand[1] = deck[player_cnt * 2 + 1];
	int host_br = 2;
	hand_total.push_back(p_hand[0] + p_hand[1]);
	if (p_hand[0] == 1)
	{
		p_hand[0] = 11;
		hand_total[player_cnt] += 10;
	}
	else if (p_hand[1] == 1)
	{
		p_hand[1] = 11;
		hand_total[player_cnt] += 10;
	}

	cout << "\nHost's hand looks like: " << p_hand[0] << " " << p_hand[1] << endl;

	for (int i = 0; i < player_cnt; i++)
	{
		if (hand_total[i] <= 21 && hand_total[i] != 0 && hand_total[i] < hand_total[player_cnt]){
			cout << "Host won, Player " << i + 1 << " lost, better luck next time!" << endl;
			hand_total[i] = 0;
		}
			
		else if (hand_total[i] == 21 && hand_total[i] == hand_total[player_cnt]) {
			cout << "Player " << i + 1 << " got a tie!" << endl;
			hand_total[i] = 0;
		}
			
	}

	int sum = 0;
	for (int i = 0; i < hand_total.size() - 1; i++)
		sum += hand_total[i];
	if (sum == 0)
		return;

	for (br; br < deck.size(); br++)
	{
		cout << "Host is drawing a card... " << endl;
		cout << "He got: " << deck[br] << endl;

		if (deck[br] == 1 && hand_total[player_cnt] + 11 <= 21)
			deck[br] = 11;

		p_hand[host_br] = deck[br];
		host_br++;
		hand_total[player_cnt] += deck[br];
		cout << "Host's hand looks like: " << endl;
		hand_list(p_hand, host_br);
		if (hand_total[player_cnt] >= 22)
		{
			for (int j = 0; j < host_br; j++)
				if (p_hand[j] == 11)
				{
					p_hand[j] = 1;
					hand_total[player_cnt] -= 10;
					break;
				}
		}
		for (int j = 0; j < player_cnt; j++)
		{
			if (21 >= hand_total[player_cnt] && hand_total[player_cnt] > hand_total[j] && hand_total[j] != 0)
			{
				cout << "Host won, Player " << j+1 <<" lost, better luck next time!" << endl;
				hand_total[j] = 0;
			}
			else if (hand_total[player_cnt] == 21 && hand_total[j] == 21)
			{
				cout << "Player "<< j+1 << " is a tie with a host!" << endl;
				hand_total[j] = 0;
			}
			else if (hand_total[player_cnt] > 21 && hand_total[j] != 0)
			{
				cout << "Congratulation player " << j+1 << " you won!" << endl;
				hand_total[j] = 0;
			}
		}
		sum = 0;
		for (int i = 0; i < hand_total.size() - 1; i++)
			sum += hand_total[i];
		if (sum == 0)
			return;
	}
}