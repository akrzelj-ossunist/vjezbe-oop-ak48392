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
	void random(int int_low,int int_high)
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
	void gets(double &X,double &Y,double &Z)
	{
		X = x; Y = y; Z = z;
	}
	void len_2D(double x1, double x2, double y1, double y2, double z1, double z2, double &len)
	{
		len = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	}
	void len_3D(double x1, double x2, double y1, double y2, double z1, double z2, double& len)
	{
		len = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
	}
			
};

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
}