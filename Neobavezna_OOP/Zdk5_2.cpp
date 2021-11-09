/*5. Koristeći vector napravite implementaciju igre šibica gdje korisnik igra protiv računala.
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
	srand((int)time(NULL));
	while (v.size())
	{
		if (v.size() <= 3)
		{
			//////////////////////////////////////////////////////////////////////
			if(br==0 && v.size()==3)
			{
			cout << "Computer is choosing how many matches he want... " << endl;
			int ran= rand() % 3 + 1;
			while (ran)
			{
				v.pop_back();
				ran--;
			}
			if(v.size()==0 && br==0)
				return 1;
			br++;
			}
			////////////////////////////////////////////////////////////////////
		    else if(br==0 && v.size()==2)
			{
			cout << "Computer is choosing how many matches he want... " << endl;
			int ran= rand() % 2 + 1;
			while (ran)
			{
				v.pop_back();
				ran--;
			}
			if(v.size()==0 && br==0)
				return 1;
			br++;
			}
			////////////////////////////////////////////////////////////////////
			else if (br == 0 && v.size() == 1)
			{
				cout << "Computer is choosing how many matches he want... " << endl;
				int ran = 1;
				v.pop_back();
				if (v.size() == 0 && br == 0)
					return 1;
			}
			////////////////////////////////////////////////////////////////////
			/*if (br == 0)
				return 1;
			else
				return 0;*/
			else
			{
				cout << "There are " << v.size() << " matches left!" << endl;
				while (num > v.size() || num < 1)
				{
					cout << "Input number between 1-" << v.size() << ": " << endl;
					cin >> num;
				}
				while (num)
				{
					v.pop_back();
					num--;
				}
				if (v.size() == 0)
					return 0;
				br--;
			}
		}
		else if (br == 0)
		{
			cout << "Computer is choosing how many matches he want... " << endl;
			int ran = rand() % 3 + 1;
			while (ran)
			{
				v.pop_back();
				ran--;
			}
			br++;
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
		cout << "\nYou lost, better luck next time!" << endl;
	else
		cout << "Congratulation you won!!! " << endl;

}