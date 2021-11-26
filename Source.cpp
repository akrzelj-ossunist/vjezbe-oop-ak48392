/*Napišite igru ”vješala” implementirajući Model-View-Controller pattern. Riječi koje se
pogađaju mogu biti imena filmova dana u datoteci movie.txt, gdje se film odabire slučajnim
odabirom.
1. Klasa HangmanModel opisuje rečenicu koju treba pogoditi, trenutno stanje rečenice
koju gradimo, slova koja su pogođena i slično.
2. Klasa HangmanView opisuje prikaz vješala, prikaz trenutnog stanja rečenice koja se
gradi i prikaz pogođenih/promašenih slova.
3. Klasa HangmanController omogućuje i verificira unos, updatea prikaz, modificira
model.Odvojite implementaciju i sučelje klasa u različite datoteke. Za ispis vješala možete
koristiti ovakvu sliku:
_______
| / |
|/  O
|  /|\
|   |
|  / \
|
|____


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class Hangman_Model {
public:
	int miss_cnt = 8;
	string str;
	string str_new;
};

class Hangman_View {
public:
	void displayProgress(Hangman_Model M);
	void displayUsedLetters(char c, int it, string &usedLettersC, string &usedLettersF);
	void displayHangman(Hangman_Model M);
};

class Hangman_Controller {
public:
	void userEntry(char& c);
	void checkLetter(char c, Hangman_Model& M, int& it);
	void updateLives(Hangman_Model M);
	void gameStatus(Hangman_Model M, char &c);
};

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
void Hangman_View::displayUsedLetters(char c, int it, string &usedLettersC, string &usedLettersF)
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

void Hangman_Controller::updateLives(Hangman_Model M)
{
	cout << "\nYou have " << M.miss_cnt << " lives left!" << endl;
}

void Hangman_Controller::userEntry(char &c)
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

void Hangman_Controller::checkLetter(char c, Hangman_Model &M, int &it)
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

void Hangman_Controller::gameStatus(Hangman_Model M, char &c)
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
}*/