/*1. Napisati klasu za poziciju točke u prostoru koja ima tri double podatka: dužinu,
širinu i visinu (x, y, z koordinate). Klasa ima sljedeće funkcije:
◦ Funkciju za postavljanje vrijednosti članova (treba imati pretpostavljene vrijednosti 0).
◦ Funkciju za postavljanje pseudorandom vrijednosti članova (granice intervala
su parametri funkcije).
◦ Funkciju za dohvaćanje vrijednosti članova.
◦ Funkciju koja računa udaljenost do druge točke u 2D ravnini (zanemarujući z
koordinatu).
◦ Funkciju koja računa udaljenost do druge točke u 3D prostoru.
U main funkciji postavite vrijednost za dvije točke u prostoru i ispišite obe udaljenosti.*/

/*2. Napisati klasu koja predstavlja oružje. Oružje ima svoj položaj u prostoru (jedna
točka u prostoru), broj metaka koji stanu u jedno punjenje i trenutni broj metaka u
punjenju. Može pucati (shoot) i ponovo se puniti (reload).

3. Napisati klasu koja predstavlja metu. Meta je oblika kvadra i zadana je donjom
lijevom i gornjom desnom točkom. Ima dva stanja: pogođena i nepogođena.

4. Napisati program koji će generirati n meta i jednog pucača (oružje). Uz pretpostavku
da je položaj oružja horizontalan i da se oružje može zakretati za 360◦, izračunati
koliko je meta pogođeno jednim punjenjem.*/

#include <iostream>
#include <iomanip>

using namespace std;

class Dot {
public:
	double x = 0, y = 0, z = 0;
	void set()
	{
		cout << "Input values of coordinates: " << endl;
		cin >> x >> y >> z;
	}
	void random(int int_low, int int_high)
	{
		if (int_low < 0)
		{
			x = rand() % int_high - int_low + int_low;
			y = rand() % int_high - int_low + int_low;
			z = rand() % int_high - int_low + int_low;
		}
		else
		{
			x = rand() % int_high + int_low;
			y = rand() % int_high + int_low;
			z = rand() % int_high + int_low;
		}
	}
	void gets(double& X, double& Y, double& Z)
	{
		X = x; Y = y; Z = z;
	}
	void len_2D(double x1, double x2, double y1, double y2, double z1, double z2, double& len)
	{
		len = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	}
	void len_3D(double x1, double x2, double y1, double y2, double z1, double z2, double& len)
	{
		len = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
	}

};

class Guns {
public:
	Dot Position;
	int Ammo;
	int Clip_ammo;
};

class Target {
public:
	Dot Dot_1, Dot_2;
	int hit = 0, missed = 0;
};

void shoot_and_reload(Dot D, Guns G, Target* (&T), int num, int br, int* (&count), int& cnt)
{
	int rest = 0;
	int sum = 0;
	for (G.Ammo; G.Ammo > G.Clip_ammo; G.Ammo -= G.Clip_ammo, cnt++)
	{
		for (int i = G.Clip_ammo; i != 0; i--)
		{
			D.random(-5, 5);
			D.gets(G.Position.x, G.Position.y, G.Position.z);
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
		sum = 0;
	}
	if (G.Ammo != 0)
	{
		for (int i = G.Ammo; i > 0; i--)
		{
			D.random(-5, 5);
			D.gets(G.Position.x, G.Position.y, G.Position.z);
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
	srand((double)time(NULL));
	int int_low, int_high;
	cout << "Set min and max intervals: " << endl;
	cin >> int_low >> int_high;
	double x1, x2, y1, y2, z1, z2, len_2D, len_3D;
	Dot D;
	D.random(int_low, int_high);
	D.gets(x1, y1, z1);
	D.random(int_low, int_high);
	D.gets(x2, y2, z2);
	cout << "X1 = " << x1 << " X2 = " << x2 << endl << "Y1 = " << y1 << " Y2 = " << y2 << endl << "Z1 = " << z1 << " Z2 = " << z2 << endl;
	D.len_2D(x1, x2, y1, y2, z1, z2, len_2D);
	D.len_3D(x1, x2, y1, y2, z1, z2, len_3D);
	cout << "Lenght between two dots in 2D is: " << fixed << setprecision(2) << len_2D << " and in 3D is: " << len_3D << endl;

	int num = rand() % 5 + 1;
	int br = 0, cnt = 0;
	Guns G;
	cout << "\nThere are " << num << " targets!" << endl;
	Target* T = new Target[num];
	for (int i = 0; i < num; i++)
	{
		D.random(int_low, int_high);
		D.gets(T[i].Dot_1.x, T[i].Dot_1.y, T[i].Dot_1.z);
		D.random(int_low, int_high);
		D.gets(T[i].Dot_2.x, T[i].Dot_2.y, T[i].Dot_2.z);
	}

	/*for (int i = 0; i < num; i++)
	{
		cout << T[i].Dot_1.x << "  " << T[i].Dot_1.y << endl;
		cout << T[i].Dot_2.x << "  " << T[i].Dot_2.y << endl;
		puts(" ");
	}*/

	cout << "\nInput how many bullets you want: " << endl;
	cin >> G.Ammo;
	cout << "Input size of your guns clip: " << endl;
	cin >> G.Clip_ammo;
	int clip_num = G.Ammo / G.Clip_ammo;
	int* count = new int[clip_num];

	shoot_and_reload(D, G, T, num, br, count, cnt);

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