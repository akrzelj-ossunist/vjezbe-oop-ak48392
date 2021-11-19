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
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

class Hangman_Model {
public:
	int miss_cnt = 0;
	string str;
	string str_new;
	vector<char> used_letters;
};

class Hangman_View {
public:
	vector<char> correct;
	vector<char> incorrect;

};

class Hangman_Contorller {
public:
	void miss1()
	{
	    cout << "______" << endl;
		cout << "|" << endl;
	}
	void miss2()
	{
		cout << "______" << endl;
		cout << "|" << endl;
		cout << endl;
		cout << "O" << endl;
	}
	void miss4()
	{
		cout << "______" << endl;
		cout << "|" << endl;
		cout << endl;
		cout << "O" << endl;
		cout << "|" << endl;
	}
	void miss5()
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|" << endl;
	}
	void miss6()
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
	}
	void miss7()
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
		cout << "/" << endl;
	}
	void miss8()
	{
		cout << " ______" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " O" << endl;
		cout << "/|\\" << endl;
		cout << "/ \\" << endl;
		cout << "You lost better luck next time! " << endl;
	}

};

void random(string &s)
{
	int len;
	cout << "\nInput size of new string: " << endl;
	cin >> len;
	s.clear();
	for (int i = 0; i < len; i++)
	{
		int r = rand() % 26;
		char c = 'a' + r;
		s = s + c;
	}
}

void shuffle(string& s)
{
	for (int j, i = 0; i < s.size(); i++)
	{
		j = (rand() * rand()) % s.size();
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void main()
{
	srand(time(NULL));
	string S = "banana";
	string new_s;
	char c;
	int br = 0;
	for (int i = 0; i < S.size(); i++)
		new_s = new_s + '_';
	for (int cnt = 0; cnt < 8;)
	{
		cout << "Pick a letter! \n";
		cin >> c;
		for (int j = 0; j < S.size(); j++)
		{
			if (c == S[j])
				new_s[j] = c;

			else
				br++;
		}
		cout << new_s << endl;
		if (br == S.size())
			cnt++;
		br = 0;
		if (cnt == 1)
		{
			cout << "______" << endl;
			cout << "|" << endl;
		}
		if (cnt == 2)
		{
			cout << "______" << endl;
			cout << "|" << endl;
			cout << endl;
			cout << "O" << endl;
		}
		if (cnt == 3)
		{
			cout << "______" << endl;
			cout << "|" << endl;
			cout << endl;
			cout << "O" << endl;
			cout << "|" << endl;
		}
		if (cnt == 4)
		{
			cout << " ______" << endl;
			cout << " |" << endl;
			cout << endl;
			cout << " O" << endl;
			cout << "/|" << endl;
		}
		if (cnt == 5)
		{
			cout << " ______" << endl;
			cout << " |" << endl;
			cout << endl;
			cout << " O" << endl;
			cout << "/|\\" << endl;
		}
		if (cnt == 6)
		{
			cout << " ______" << endl;
			cout << " |" << endl;
			cout << endl;
			cout << " O" << endl;
			cout << "/|\\" << endl;
			cout << "/" << endl;
		}
		if (cnt == 7)
		{
			cout << " ______" << endl;
			cout << " |" << endl;
			cout << endl;
			cout << " O" << endl;
			cout << "/|\\" << endl;
			cout << "/ \\" << endl;
		}
		if (cnt == 8)
		{
			cout << " ______" << endl;
			cout << " |" << endl;
			cout << " |" << endl;
			cout << " O" << endl;
			cout << "/|\\" << endl;
			cout << "/ \\" << endl;
			cout << "You lost better luck next time! " << endl;
			cout << "Do you wanna play again? " << endl;
			cout << "If yes pick 'y' if no pick 'n': " << endl;
			char decision;
			cin >> decision;
			if (decision == 'y')
				cnt = 0;
			else
				break;
		}
		if (S == new_s)
		{
			cout << "Congratulation you won! " << endl;
			cout << "Do you wanna play again? " << endl;
			cout << "If yes pick 'y' if no pick 'n': " << endl;
			char decision;
			cin >> decision;
			if (decision == 'y')
			{
				cout << "Pick new word: " << endl;
				cnt = 0;
				//cin >> S;
				random(S);
				shuffle(S);
				cout << S << endl;
				for (int i = 0; i < S.size(); i++)
					new_s = new_s + '_';
			}
			else
				break;
		}
	}
}