/*2. Napisati klasu koja predstavlja oružje. Oružje ima svoj položaj u prostoru (jedna
točka u prostoru), broj metaka koji stanu u jedno punjenje i trenutni broj metaka u
punjenju. Može pucati (shoot) i ponovo se puniti (reload).

3. Napisati klasu koja predstavlja metu. Meta je oblika kvadra i zadana je donjom
lijevom i gornjom desnom točkom. Ima dva stanja: pogođena i nepogođena.

4. Napisati program koji će generirati n meta i jednog pucača (oružje). Uz pretpostavku
da je položaj oružja horizontalan i da se oružje može zakretati za 360◦, izračunati koliko je meta pogođeno jednim punjenjem.*/#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class coordinates {
public:
	int x, y;
};

class Guns {
public:
	coordinates Position;
	int Ammo;
	int Clip_ammo;
};

class Target {
public:
	coordinates Dot_1, Dot_2;
	int hit = 0, missed = 0;
};

void shoot_and_reload(Guns G, Target* (&T), int num, int br, int* (&count), int& cnt)
{
	int rest = 0;
	int sum = 0;
	for (G.Ammo; G.Ammo > G.Clip_ammo; G.Ammo -= G.Clip_ammo, cnt++)
	{	
		for (int i = G.Clip_ammo; i != 0; i--)
		{
			G.Position.x = rand() % 10 - 5;
			G.Position.y = rand() % 10 - 5;
			for (int j = 0; j < num; j++)
			{
				if (T[j].Dot_1.x >= T[j].Dot_2.x)
				{
					if (G.Position.x <= T[j].Dot_1.x && G.Position.x >= T[j].Dot_2.x)
						br++;
				}
				else
				{
					if (G.Position.x <= T[j].Dot_2.x && G.Position.x >= T[j].Dot_1.x)
						br++;
				}
				if (T[j].Dot_1.y >= T[j].Dot_2.y)
				{
					if (G.Position.y <= T[j].Dot_1.y && G.Position.y >= T[j].Dot_2.y)
						br++;
				}
				else
				{
					if (G.Position.y <= T[j].Dot_2.y && G.Position.y >= T[j].Dot_1.y)
						br++;
				}
				if (br == 2)
				{
					T[j].hit += 1;
					sum++;
					count[cnt] = T[j].hit;
				}
				else
					T[j].missed += 1;
				br = 0;
			}
		}
		count[cnt] = sum;
		sum = 0;
    }
	if (G.Ammo != 0)
	{
		for (int i = G.Ammo; i > 0; i--)
		{
			G.Position.x = rand() % 10 - 5;
			G.Position.y = rand() % 10 - 5;
			for (int j = 0; j < num; j++)
			{
				if (T[j].Dot_1.x >= T[j].Dot_2.x)
				{
					if (G.Position.x <= T[j].Dot_1.x && G.Position.x >= T[j].Dot_2.x)
						br++;
				}
				else
				{
					if (G.Position.x <= T[j].Dot_2.x && G.Position.x >= T[j].Dot_1.x)
						br++;
				}
				if (T[j].Dot_1.y >= T[j].Dot_2.y)
				{
					if (G.Position.y <= T[j].Dot_1.y && G.Position.y >= T[j].Dot_2.y)
						br++;
				}
				else
				{
					if (G.Position.y <= T[j].Dot_2.y && G.Position.y >= T[j].Dot_1.y)
						br++;
				}
				if (br == 2)
				{
					T[j].hit += 1;
					sum++;
				}
				else
					T[j].missed += 1;
				br = 0;
			}
		}
		count[cnt] = sum;
	}
}
void main()
{
	srand((int)time(NULL));
	Guns G;
	int num, br = 0, cnt = 0;
	cout << "How many targets do you want: " << endl;
	cin >> num;
	Target* T=new Target[num];
	for (int i = 0; i < num; i++)
	{
		T[i].Dot_1.x = rand() % 10 - 5;
		T[i].Dot_1.y = rand() % 10 - 5;
		T[i].Dot_2.x = rand() % 10 - 5;
		T[i].Dot_2.y = rand() % 10 - 5;
	}
	/*for (int i = 0; i < num; i++)
	{
		cout << T[i].Dot_1.x << "  " << T[i].Dot_1.y << endl;
		cout << T[i].Dot_2.x << "  " << T[i].Dot_2.y << endl;
		puts(" ");
	}*/
	cout << "Input how many bullets you want: " << endl;
	cin >> G.Ammo;
	cout << "Input size of your guns clip: " << endl;
	cin >> G.Clip_ammo;
	int clip_num = G.Ammo / G.Clip_ammo + 2;
	int* count = new int[clip_num];
	shoot_and_reload(G, T, num, br, count, cnt);

	for (int i = 0; i < num; i++)
	{
		cout << "Target " << i + 1 << " got hit " << T[i].hit << " times!" << endl;
		cout << "Target " << i + 1 << " got missed " << T[i].missed << " times!" << endl;
	}
	for (int i = 0; i <= cnt; i++)
	{
		cout << i + 1 << ". clip shot targets " << count[i] << " times!" << endl;
	}
}
