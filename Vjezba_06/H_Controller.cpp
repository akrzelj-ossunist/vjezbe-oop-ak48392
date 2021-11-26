#include "Header.h"


void Hangman_Controller::updateLives(Hangman_Model M)
{
	cout << "\nYou have " << M.miss_cnt << " lives left!" << endl;
}
void Hangman_Controller::userEntry(char& c)
{
	cout << "Input letter or number you want: " << endl;
	cin >> c;
	if (!isalpha(c) || !isdigit(c))
		while (!isalpha(c) && !isdigit(c))
		{
			cout << "Wrong input! " << endl;
			cout << "Input letter or number: " << endl;
			cin >> c;
		}
}
void Hangman_Controller::checkLetter(char c, Hangman_Model& M, int& it)
{
	char cc;
	it = M.str.find(c);
	if (it < 0)
	{
		it = M.str.find(toupper(c));
		if (it < 0)
			M.miss_cnt--;
		else
			for (int i = 0; i < M.str.size(); i++)
			{
				cc = c;
				if (isupper(M.str[i]))
				{
					if (M.str[i] == toupper(cc)) {
						cc = toupper(cc);
						swap(M.str_new[i], cc);
					}
				}
				cc = c;
				if (M.str[i] == c)
					swap(M.str_new[i], cc);
			}
	}
	else
		for (int i = 0; i < M.str.size(); i++)
		{
			cc = c;
			if (isupper(M.str[i]))
			{
				if (M.str[i] == toupper(cc)) {
					cc = toupper(cc);
					swap(M.str_new[i], cc);
				}
			}
			cc = c;
			if (M.str[i] == c)
				swap(M.str_new[i], cc);
		}
}
void Hangman_Controller::gameStatus(Hangman_Model M, char& c)
{
	if (M.str == M.str_new)
		cout << "\n\nCongratulation, you guessed it right!" << endl;
	if (M.miss_cnt == 0 || M.str == M.str_new)
	{
		cout << "\nDo you wanna continue playing?" << endl;
		cout << "If yes press 'Y' else press 'N': " << endl;
		cin >> c;
		while (c != 'y' && c != 'n')
		{
			cout << "Wrong input!" << endl;
			cout << "If you wanna continue press 'Y' else press 'N'!" << endl;
			cin >> c;
		}
	}
}