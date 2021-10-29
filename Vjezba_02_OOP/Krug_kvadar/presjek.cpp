
#include <iostream>
#include <iomanip>

using namespace std;

typedef struct
{
	int x1, y1, x2, y2;

}kvadar;

typedef struct
{
	int x, y, r;

}kruznica;

void presjek(kvadar* niz,const kruznica &a, int num, int& k)
{
	k = 0;
	for (int i = 0; i < num; i++)
		{
			int x = max(niz[i].x1, min(a.x, niz[i].x2));
			int y = max(niz[i].y1, min(a.y, niz[i].y2));
			int X = x - a.x;
			int Y = y - a.y;
			if ((X * X + Y * Y) <= a.r * a.r)
				k++;
		}
}

void main()
{
	int num, k;
	kruznica a;
	cout << "unesite tocke kruznice: " << endl;
	cin >> a.x >> a.y;
	cout << "unesite radijus kruznice: " << endl;
	cin >> a.r;
	cout << "unesite koliko kvadra zelite testirat: " << endl;
	cin >> num;
	kvadar* arr=new kvadar[num];
	for (int i = 0; i < num; i++)
		{
			cout << "unesite "<< 1 << ". tocku "<< i+1 << " kvadra: " << endl;
			cin >> arr[i].x1 >> arr[i].y1;
			cout << "unesite "<< 2 << ". tocku " << i + 1 << " kvadra: " << endl;
			cin >> arr[i].x2 >> arr[i].y2;
		}
	presjek(arr, a, num, k);
	cout << "Sjece se " << k << " kvadra sa kruznicom!" << endl;
}