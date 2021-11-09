/*2. Napisati funkciju koji prevodi engleske rečenice na pig latin jezik. 

Pravila su sljedeća:

(a) ako riječ počinje samoglasnikom dopisuje se hay na kraj riječi,

(b) inače, svi suglasnici s početka riječi prebacuju se na kraj te se na kraju riječi
dopisuje ay.

Rečenice treba spremiti u vector, a zatim prevesti slučajno odabranu rečenicu iz
vektora.

Primjer: ”What time is it?” prevodi se kao ”atwhay imetay ishay ithay?”

#include "Header.hpp"

void pig_lat(vector<string>&v)
{
	int k=0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == 'a' || v[i][j] == 'e' || v[i][j] == 'i' || v[i][j] == 'o' || v[i][j] == 'u'
				|| v[i][j] == 'A' || v[i][j] == 'E' || v[i][j] == 'I' || v[i][j] == 'O' || v[i][j] == 'U')
			{
				for (k = j; v[i][k] != ' ' && v[i][k] != '\0' && !ispunct(v[i][k]); k++);
				v[i].insert(v[i].begin() + k, 'h');
				v[i].insert(v[i].begin() + k + 1, 'a');
				v[i].insert(v[i].begin() + k + 2, 'y');
				j = k + 3;
			}
			else if (ispunct(v[i][j]))
				continue;
			else
			{
				for (k = j; v[i][k] != ' ' && v[i][k] != '\0' && !ispunct(v[i][k]); k++);
				for (j; v[i][j] != '\0' && v[i][j] != 'a' && v[i][j] != 'e' && v[i][j] != 'i' && v[i][j] != 'o' && v[i][j] != 'u';)
				{
					v[i].insert(v[i].begin() + k, v[i][j]);
					v[i].erase(v[i].begin()+j);
				}
				v[i].insert(v[i].begin() + k, 'a');
				v[i].insert(v[i].begin() + k+1, 'y');
				j = k + 2;	
			}
		}
	}
}

void print_vector(vector<string>v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}

void main()
{
	vector<string>v;
	string str;
	int num;
	cout << "Input number of sentences u want: " << endl;
	cin >> num;
	while (num)
	{
		cout << "Input sentence: "<< endl;
		cin.ignore();
		getline(cin, str);
		v.push_back(str);
		num--;
	}
	pig_lat(v);
	print_vector(v);
}*/