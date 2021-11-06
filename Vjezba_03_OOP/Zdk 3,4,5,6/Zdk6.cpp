#include "Header.h"

void new_vector(vector<string>& v, int& len)
{
	string s;
	cout << "Unesite koliko cete stringova: " << endl;
	cin >> len;
	int counter = 0;
	while (counter != len)
	{
		getline(cin, s);
		cout << s << endl;
		reverse(s.begin(),s.end());
		v.push_back(s);
		counter++;
	}
}


void print_vector(vector<string>v1, int len)
{
	for (int i = 0; i < len; i++)
		cout << v1[i] << "  ";
	cout << endl;
}

void main()
{
	vector<string>v;
	int len;
	new_vector(v, len);
	sort(v.begin(),v.end());
	print_vector(v, len);
}