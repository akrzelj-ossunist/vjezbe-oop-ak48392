﻿/*5. Koristeći vector napravite implementaciju igre šibica gdje korisnik igra protiv računala.
Pravila ove igre su vrlo jednostavna. Pred 2 igrača postavi se 21 šibica.
Igrači se izmjenjuju i uklanjaju 1, 2 ili 3 šibice odjednom. Igrač koji je prisiljen uzeti
posljednju šibicu gubi.
Korisnik unosi izbor, dok se za odabir računala bira slučajnim izborom. Igraču se
mora dati prednost, tako da računalo prvo započinje igru.
Prije pisanja koda promislite o problemu, koji su mogući slučajevi, kad je sigurna
pobjeda, kad je neizbježan poraz.*/

#include "Header.hpp"

int comp_vs_player(vector<int>v)
{
	int num = 0;
	int br = 0;
	while (v.size())
	{
		if (v.size() <= 3)
		{
			/*cout << "Computer is choosing how many matches he want... " << endl;
			int ran= rand() % 3 + 1;
			while (ran)
				v.pop_back();*/
			if (br == 0)
				return 1;
			else
				return 0;
			/*cout << "Input number between 1-3: " << endl;
			cin >> num;
			while (num)
				v.pop_back();*/
		}
		if (br == 0)
		{
			cout << "Computer is choosing how many matches he want... " << endl;
			int ran = rand() % 3 + 1;
			br++;
			while (ran)
			{
				v.pop_back();
				ran--;
			}
				
		}
		else
		{
			cout << "There are " << v.size() << " matches left!" << endl;
			while (num > 3 || num < 1)
			{
				cout << "Input number between 1-3: " << endl;
				cin >> num;
			}
			while (num)
			{
				v.pop_back();
				num--;
			}

			br--;
		}
	}
}

void main()
{
	vector<int>v = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int Win = comp_vs_player(v);
	if (Win == 1)
		cout << "You lost, better luck next time!" << endl;
	else
		cout << "Congratulation you won!!! " << endl;

}