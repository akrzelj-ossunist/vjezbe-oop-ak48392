/*1. Učitati string koji predstavlja rečenicu. Napisati funkciju koja iz stringa izbacuje
sve praznine koje se nalaze ispred znakova interpunkcije i dodaje praznine nakon
znaka interpunkcije ako nedostaju.
Primjer: Za rečenicu ”Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .”,
Ispravna rečenica glasi: ”Ja bih, ako ikako mogu, ovu recenicu napisala ispravno.”*/

#include "Header.hpp"

void interpuction(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(i, 1);
			i--;
		}
		if (str[i] == ' ' && ispunct(str[i + 1]))
			str.erase(i, 1);

		if (ispunct(str[i]) && isalpha(str[i + 1]))
			str.insert(str.begin()+i+1,' ');
	}
}

void main()
{
	string str = "Ja bih       ,ako ikako mogu         ,      ovu recenicu napisala ispravno     .";
	interpuction(str);
	cout << str << endl;
	cout << "Ja bih, ako ikako mogu, ovu recenicu napisala ispravno." << endl;
}