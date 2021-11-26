#include "Header.h"

void main()
{
	Hangman_View V;
	Hangman_Model M;
	Hangman_Controller C;
	int it;
	fstream fp, fp1;
	int play = 0;
	string usedLettersC, usedLettersF;
	char c;
	int seek = 0;
	fp.open("movies.txt");
	fp1.open("movies.txt");
	while (fp)
	{
		getline(fp, M.str);
		M.miss_cnt = 8;
		usedLettersC.clear();
		usedLettersF.clear();
		M.str_new.clear();
		for (int i = 0; i < M.str.size(); i++)
		{
			if (!isalpha(M.str[i]) && !isdigit(M.str[i]))
				M.str_new += M.str[i];
			else
				M.str_new += '*';
		}
		for (M.miss_cnt; M.miss_cnt != 0 && M.str != M.str_new;)
		{
			C.updateLives(M);
			C.userEntry(c);
			C.checkLetter(c, M, it);
			V.displayProgress(M);
			V.displayUsedLetters(c, it, usedLettersC, usedLettersF);
			V.displayHangman(M);
			C.gameStatus(M, c);
		}
		if (c == 'y')
		{
			if (M.miss_cnt == 0)
			{
				cout << "Do you wanna try same sentence?" << endl;
				cout << "If yes press 'Y' else press 'N': " << endl;
				cin >> c;
				while (c != 'y' && c != 'n')
				{
					cout << "Wrong input!" << endl;
					cout << "If you wanna same press 'Y' else press 'N'!" << endl;
					cin >> c;
				}
				if (c == 'y')
					fp.seekg(seek);
				else
					seek += M.str.size();
			}
			else
				seek += M.str.size();
		}
		else
			break;
	}
}