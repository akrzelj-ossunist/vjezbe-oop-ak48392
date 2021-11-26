#ifndef _HEADER_H
#define _HEADER_H

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
	void displayUsedLetters(char c, int it, string& usedLettersC, string& usedLettersF);
	void displayHangman(Hangman_Model M);
};
class Hangman_Controller {
public:
	void userEntry(char& c);
	void checkLetter(char c, Hangman_Model& M, int& it);
	void updateLives(Hangman_Model M);
	void gameStatus(Hangman_Model M, char& c);
};

#endif // !_HEADER_H

