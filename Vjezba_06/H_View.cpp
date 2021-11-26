#include "Header.h"


void Hangman_View::displayHangman(Hangman_Model M)
{
	if (M.miss_cnt == 8)
		return;
	if (M.miss_cnt == 7)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
	}
	if (M.miss_cnt == 6)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
	}
	if (M.miss_cnt == 5)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << " |" << endl;
	}
	if (M.miss_cnt == 4)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|" << endl;
	}
	if (M.miss_cnt == 3)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
	}
	if (M.miss_cnt == 2)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
		cout << "/ " << endl;
	}
	if (M.miss_cnt == 1)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
		cout << "/ \\" << endl;
	}
	if (M.miss_cnt == 0)
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
		cout << "/ \\" << endl;
		cout << "You lost better luck next time! " << endl;
	}
}
void Hangman_View::displayProgress(Hangman_Model M)
{
	cout << "Current state of your sentence is: " << M.str_new << endl;
}
void Hangman_View::displayUsedLetters(char c, int it, string& usedLettersC, string& usedLettersF)
{
	int brC = 0, brF = 0;
	for (int i = 0; i < usedLettersC.size(); i++)
		if (c == usedLettersC[i])
			brC++;
	for (int i = 0; i < usedLettersF.size(); i++)
		if (c == usedLettersF[i])
			brF++;
	if (it < 0 && brF == 0) {
		usedLettersF += c;
		usedLettersF += ',';
	}
	else if (it >= 0 && brC == 0) {
		usedLettersC += c;
		usedLettersC += ',';
	}
	cout << "You used correct letters: " << usedLettersC << endl << "You used incorrect letters: " << usedLettersF << endl;
}