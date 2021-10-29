#include <iostream>
#include <iomanip>

using namespace std;

typedef struct
{
	int x,y;	

}kvadar;

typedef struct
{
	int x, y, r;

}kruznica;

void presjek(int** niz,const kruznica& a,int num,int &k)
{
    k = 0;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < 1; j++)
		{
			int x = max(niz[i][j], min(a.x, niz[i][j + 2]));
			int y= max(niz[i][j+1], min(a.y, niz[i][j + 3]));
			int X = x - a.x;
			int Y = y - a.y;
			if ((X * X + Y * Y) <= a.r * a.r)
				k++;
				
		}
}

void main()
{
	int num,k;
	kruznica a;
	kvadar b;
	cout << "unesite tocke kruznice: " << endl;
	cin >> a.x >> a.y;
	cout << "unesite radijus kruznice: " << endl;
	cin >> a.r;
	cout << "unesite koliko kvadra zelite testirat: " << endl;
	cin >> num;
	int** Arr=new int*[num];
	for (int i = 0; i < num; i++)
		for (int j = 0; j < 4; j++)
		{
			Arr[i] = new int[j];
			cout << "unesite " << j+1 << ". tocku za " <<i+1 <<" kvadar: " << endl;
			cin >> b.x >> b.y;
			Arr[i][j] = b.x;
			j++;
			Arr[i][j] = b.y;
		}
    presjek(Arr, a,num,k);
	cout <<"Sjece se " << k<< " kvadrova sa kruznicom!";
}