#include "Header.hpp"


void game(vector<int>deck, int &reset)
{
	shuffle(deck);
	cout << "Host is dealing the cards... " << endl;
	cout << "You got: " << deck[0] << " and " << deck[2] << endl;
	cout << "Host got: " << deck[1] << " and ???" << endl;
	if (deck[1] == 10 || deck[1] == 1)
	{
		if ((deck[3] == 1 && deck[1] == 10) || (deck[3] == 10 && deck[1] == 1))
		{
			if ((deck[0] == 1 && deck[2] == 10) || (deck[0] == 10 && deck[2] == 1))
			{
				cout << "Its a tie!" << endl;
				cout << "Do you wanna continue: " << endl;
				cout << "Type 'y' for yes or 'n' for no: " << endl;
				char c;
				cin >> c;
				while (c != 'y' && c != 'n')
				{
					cout << "Wrong input! " << endl;
					cout << "Press 'y' to continue or 'n' to end!" << endl;
					cin >> c;
				}
				if (c == 'y'){
					reset = 1;
					return;
				}	
				else{
					reset = 0;
					return;
				}
			}
			else
			{
				cout << "Host won, better luck next time!" << endl;
				cout << "Do you wanna continue: " << endl;
				cout << "Type 'y' for yes or 'n' for no: " << endl;
				char c;
				cin >> c;
				while (c != 'y' && c != 'n')
				{
					cout << "Wrong input! " << endl;
					cout << "Press 'y' to continue or 'n' to end!" << endl;
					cin >> c;
				}
				if (c == 'y') {
					reset = 1;
					return;
				}
				else {
					reset = 0;
					return;
				}
			}
		}
	}
	if ((deck[0] == 1 && deck[2] == 10) || (deck[0] == 10 && deck[2] == 1))
	{
		cout << "Congratulation you got BlackJack! " << endl;
		cout << "Do you wanna continue: " << endl;
		cout << "Type 'y' for yes or 'n' for no: " << endl;
		char c;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "Wrong input! " << endl;
			cout << "Press 'y' to continue or 'n' to end!" << endl;
			cin >> c;
		}
		if (c == 'y') {
			reset = 1;
			return;
		}
		else {
			reset = 0;
			return;
		}
	}

	int card_total = deck[0] + deck[2];
	if (deck[0] == 1)
	{
		deck[0] = 11;
		card_total = deck[0] + deck[2];
	}
	else if (deck[2] == 1)
	{
		deck[2] = 11;
		card_total = deck[0] + deck[2];
	}

	int* hand = new int[11];
	hand[0] = deck[0];
	hand[1] = deck[2];
	int ace_counter = 0;
	int br = 2;
	for (int i = 4; i < deck.size(); i++)
	{
		cout << "Your hand: " << endl;
		for (int j = 0; j < br; j++)
			cout << hand[j] << "\t";
		cout << "Your cards total is: " << card_total << endl;
		cout << "Do you wanna take a new card? " << endl;
		cout << "If YES press 'y' if NO press 'n'... " << endl;
		char c;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "Wrong input! " << endl;
			cout << "Press 'y' for new card or 'n' to pass!" << endl;
			cin >> c;
		}
		if (c == 'y')
		{
			br++;
			hand[br - 1] = deck[i];
			cout << "You got " << deck[i] << endl;
			if (deck[i] == 1 && card_total + 11 <= 21)
				deck[i] == 11;
			card_total = card_total + deck[i];
			if (card_total > 21)
			{
				for (int j = 0; j < br; j++)
					if (hand[j] == 11)
					{
						hand[j] = 1;
						card_total -= 10;
						break;
					}
			}
			if (card_total > 21)
			{
				cout << "Host won, better luck next time!" << endl;
				cout << "Do you wanna continue: " << endl;
				cout << "Type 'y' for yes or 'n' for no: " << endl;
				char c;
				cin >> c;
				while (c != 'y' && c != 'n')
				{
					cout << "Wrong input! " << endl;
					cout << "Press 'y' to continue or 'n' to end!" << endl;
					cin >> c;
				}
				if (c == 'y') {
					reset = 1;
					return;
				}
				else {
					reset = 0;
					return;
				}
			}
		}
		else
			break;
	}
	delete[] hand;
	hand = new int[11];
	hand[0] = deck[1];
	hand[1] = deck[3];
	int host_br = 2;
	int host_card_total = deck[1] + deck[3];

	if (deck[1] == 1)
	{
		deck[1] = 11;
		card_total = deck[1] + deck[3];
	}
	else if (deck[3] == 1)
	{
		deck[3] = 11;
		card_total = deck[1] + deck[3];
	}

	cout << "Host's hand looks like: " << deck[1] << " " << deck[3] << endl;
	if (host_card_total > card_total)
	{
		cout << "Host won, better luck next time!" << endl;
		cout << "Do you wanna continue: " << endl;
		cout << "Type 'y' for yes or 'n' for no: " << endl;
		char c;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "Wrong input! " << endl;
			cout << "Press 'y' to continue or 'n' to end!" << endl;
			cin >> c;
		}
		if (c == 'y') {
			reset = 1;
			return;
		}
		else {
			reset = 0;
			return;
		}
	}
	for (int i = br + 2; i < deck.size(); i++)
	{
		cout << "Host is drawing a card... " << endl;
		cout << "He got: " << deck[i] << endl;

		if (deck[i] == 1 && host_card_total + 11 <= 21)
			deck[i] == 11;

		hand[host_br] = deck[i];
		host_br++;
		host_card_total += deck[i];
		cout << "Host's hand looks like: " << endl;
		for (int j = 0; j < host_br; j++)
			cout << hand[j] << "\t";
		if (host_card_total > 21)
		{
			for (int j = 0; j < br; j++)
				if (hand[j] == 11)
				{
					hand[j] = 1;
					host_card_total -= 10;
					break;
				}
		}
		if (host_card_total < card_total)
			continue;
		else if (host_card_total == 21 && card_total == 21)
		{
			cout << "Its a tie!" << endl;
			cout << "Do you wanna continue: " << endl;
			cout << "Type 'y' for yes or 'n' for no: " << endl;
			char c;
			cin >> c;
			while (c != 'y' && c != 'n')
			{
				cout << "Wrong input! " << endl;
				cout << "Press 'y' to continue or 'n' to end!" << endl;
				cin >> c;
			}
			if (c == 'y') {
				reset = 1;
				return;
			}
			else {
				reset = 0;
				return;
			}
		}
		else if (host_card_total == card_total)
			continue;
		else if (host_card_total > 21)
		{
			cout << "Congratulation you won! " << endl;
			cout << "Do you wanna continue: " << endl;
			cout << "Type 'y' for yes or 'n' for no: " << endl;
			char c;
			cin >> c;
			while (c != 'y' && c != 'n')
			{
				cout << "Wrong input! " << endl;
				cout << "Press 'y' to continue or 'n' to end!" << endl;
				cin >> c;
			}
			if (c == 'y') {
				reset = 1;
				return;
			}
			else {
				reset = 0;
				return;
			}
		}
	}
	delete[] hand;
}