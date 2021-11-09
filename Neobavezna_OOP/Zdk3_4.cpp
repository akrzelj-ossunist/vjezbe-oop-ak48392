/*3. Napisati program u kojem korisnik unosi binarne znamenke (0 i 1) i sprema ih u
container. Unosu je kraj kad korisnik unese vrijednost koja ne predstavlja binarnu
znamenku. Nakon toga napisati funkciju stuffing_bit koja primjeni bit stuffing
algoritam na container. Bit stuffing je tehnika koja se koristi u HDLC protokolima
za prijenos podataka u kojima je početak i završetak paketa određen sa nizom bitova
01111110. Da se ne bi sadržaj paketa brkao sa stop-bitovima, potrebno je nakon
svakog niza od pet jedinica umetnuti jednu nulu.
Primjer: za uneseni niz bitova
00111011111110001111111011
rezultat je
0011101111101100011111011011.
*/

#include "Header.hpp"

void input_binary(vector<int>&v)
{
	int m;
	cout << "input bin: " << endl;
	cin >> m;
	while (0 == m || m == 1)
	{
		v.push_back(m);
		cout << "input bin: " << endl;
		cin >> m;
	}
}

void bit_stuffing(vector<int>& v)
{
	int br = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if(v[i]==1)
			for (i; i < v.size() && v[i] != 0; i++)
			{
				br++;
				if (br == 5)
					v.insert(v.begin() + i + 1, 0);
			}
		br = 0;
	}
}

void unstuffing_bit(vector<int>& v)
{
	int br = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 1)
			for (i; i < v.size() && v[i] != 0; i++)
			{
				br++;
				if (br == 5) 
					v.erase(v.begin() + i + 1);	
			}
		br = 0;
	}
}

void print_new_binary(vector<int>v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}

void main()
{
	vector<int>v;
	input_binary(v);
	print_new_binary(v);
	puts(" ");
	bit_stuffing(v);
	print_new_binary(v);
	//4. Napisati funkciju unstuffing_bit koja je inverzna funkciji stuffin_bit iz predhodnog zadatka. 
	//Funkcija prima modificirani container i izbacuje umetnute nule kako bi se dobila originalna sekvenca.
	puts(" ");
	unstuffing_bit(v);
	print_new_binary(v);
}


