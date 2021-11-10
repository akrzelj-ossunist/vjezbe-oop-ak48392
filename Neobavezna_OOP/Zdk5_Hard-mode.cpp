/*5. Koristeći vector napravite implementaciju igre šibica gdje korisnik igra protiv računala.
Pravila ove igre su vrlo jednostavna. Pred 2 igrača postavi se 21 šibica.
Igrači se izmjenjuju i uklanjaju 1, 2 ili 3 šibice odjednom. Igrač koji je prisiljen uzeti
posljednju šibicu gubi.
Korisnik unosi izbor, dok se za odabir računala bira slučajnim izborom. Igraču se
mora dati prednost, tako da računalo prvo započinje igru.
Prije pisanja koda promislite o problemu, koji su mogući slučajevi, kad je sigurna
pobjeda, kad je neizbježan poraz.*/

#include "Header.hpp"

int comp_vs_player_easy(vector<int>v,int &win)
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
			cout << "He picked " << ran << "..." << endl;
			while (ran)
			{
				v.pop_back();
				ran--;
			}
			if (v.size() == 0 && br == 0)
			{
				win = 1;
				return 0;
			}
				
			br++;
			}
			////////////////////////////////////////////////////////////////////
		    else if(br==0 && v.size()==2)
			{
			cout << "Computer is choosing how many matches he want... " << endl;
			int ran= rand() % 2 + 1;
			cout << "He picked " << ran << "..." << endl;
			while (ran)
			{
				v.pop_back();
				ran--;
			}
			if(v.size()==0 && br==0)
			{
				win = 1;
				return 0;
			}
			br++;
			}
			////////////////////////////////////////////////////////////////////
			else if (br == 0 && v.size() == 1)
			{
				cout << "Computer is choosing how many matches he want... " << endl;
				int ran = 1;
				cout << "He picked " << ran << "..." << endl;
				v.pop_back();
				if (v.size() == 0 && br == 0)
				{
					win = 1;
					return 0;
				}
			}
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
				{
					win = 0;
					return 0;
				}
				br--;
			}
		}
		else if (br == 0)
		{
			cout << "Computer is choosing how many matches he want... " << endl;
			int ran = rand() % 3 + 1;
			cout << "He picked " << ran << "..." << endl;
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

int comp_vs_player_normal(vector<int>v,int &win)
{
	int num = 0;
	int br = 0;
	srand((int)time(NULL));
	while (v.size())
	{
		if (v.size() <= 3)
		{

			if (br == 0)
				win = 1;
			else
				win = 0;
			return 0;
		}

		else if (br == 0)
		{
			cout << "\nComputer is choosing how many matches he want... " << endl;
			int ran = rand() % 3 + 1;
			cout << "He picked " << ran << "..." << endl;
			while (ran)
			{
				v.pop_back();
				ran--;
			}
			br++;
		}
		else
		{
			cout << "\nThere are " << v.size() << " matches left!" << endl;
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

int comp_vs_player_hard(vector<int>v,int &win)
{
	int num = 0;
	int len = v.size();
	srand((int)time(NULL));
	int br = rand() % 2;
	while (len)
	{
		len = v.size();
		if (br == 0 && len == 21)
		{
			cout << "Computer picked 1..." << endl;
			v.pop_back();
		}
			
		else if (br == 0 && len == 19)
		{
			cout << "Computer picked 3..." << endl;
			v.pop_back();
			v.pop_back();
			v.pop_back();
		}
		else if (br == 0 && len == 18)
		{
			cout << "Computer picked 2..." << endl;
			v.pop_back();
			v.pop_back();
		}
		else if (br == 0 && len == 17)
		{
			cout << "Computer picked 1..." << endl;
			v.pop_back();
		}		
		else if (br == 0 && len == 15)
		{
			cout << "Computer picked 3..." << endl;
			v.pop_back();
			v.pop_back();
			v.pop_back();
		}
		else if (br == 0 && len == 14)
		{
			cout << "Computer picked 2..." << endl;
			v.pop_back();
			v.pop_back();
		}
		else if (br == 0 && len == 13)
		{
			cout << "Computer picked 1..." << endl;
			v.pop_back();
		}		
		else if (br == 0 && len == 11)
		{
			cout << "Computer picked 3..." << endl;
			v.pop_back();
			v.pop_back();
			v.pop_back();
		}
		else if (br == 0 && len == 10)
		{
			cout << "Computer picked 2..." << endl;
			v.pop_back();
			v.pop_back();
		}
		else if (br == 0 && len == 9)
		{
			cout << "Computer picked 1..." << endl;
			v.pop_back();
		}
		else if (br == 0 && len == 7)
		{
			cout << "Computer picked 3..." << endl;
			v.pop_back();
			v.pop_back();
			v.pop_back();
		}
		else if (br == 0 && len == 6)
		{
			cout << "Computer picked 2..." << endl;
			v.pop_back();
			v.pop_back();
		}
		else if (br == 0 && len == 5)
		{
			cout << "Computer picked 1..." << endl;
			v.pop_back();
		}
		else if (br == 0 && len == 3)
		{
			cout << "Computer picked 3..." << endl;
			win = 1;
			return 0;
		}
		else if (br == 0 && len == 2)
		{
			cout << "Computer picked 2..." << endl;
			win = 1;
			return 0;
		}
		else if (br == 0 && len == 1)
		{
			cout << "Computer picked 1..." << endl;
			win = 1;
			return 0;
		}
		else if (br == 0 && (len == 4 || len == 8 || len == 12 || len == 16 || len == 20))
		{
			cout << "Computer is choosing how many matches he want... " << endl;
			int ran = rand() % 3 + 1;
			cout << "He picked " << ran << "..." << endl;
			while (ran)
			{
				v.pop_back();
				ran--;
			}
		}
		else
		{
		cout << "\nThere are " << len << " matches left!" << endl;
		if(len < 3)
			while (num > len || num < 1)
			{
				cout << "Input number between 1-" << len << ": " << endl;
				cin >> num;
			}
		else
			while(num > 3 || num < 1)
			{
				cout << "Input number between 1-3" << endl;
				cin >> num;
			}
		while (num)
		{
			v.pop_back();
			num--;
			len--;
		}
		if (len == 0)
		{
			win = 0;
			return 0;
		}
        }
		if (br == 0)
			br++;
		else
			br--;
	}
	

}

void main()
{
	vector<int>v = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	char diff;
	int Win;

	cout << "Pick the difficulty of computer you wanna play against? " << endl;
	puts(" ");
	cout << "Press 'e' for easy difficulty: " << endl;
	cout << "Press 'n' for normal difficulty: " << endl;
	cout << "Press 'h' for hard difficulty: " << endl;
	cin >> diff;
	if (diff == 'e')
		int Win_e = comp_vs_player_easy(v, Win);
	else if (diff == 'n')
		int Win_n = comp_vs_player_normal(v, Win);
	else if (diff == 'h')
		int Win_h = comp_vs_player_hard(v, Win);
	else
		cout << "Input error..." << endl;

	if (Win == 1)
		cout << "\nYou lost, better luck next time!" << endl;
	else
		cout << "\nCongratulation you won!!! " << endl;
}