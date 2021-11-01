#include "Header.h"

void new_vector(vector<string>& v, int& len)
{
	string s;
	cout << "Unesite koliko cete stringova: " << endl;
	cin >> len;
	int counter = 0;
	while (counter != len)
	{
		cin >> s;
		reverse(s.begin(),s.end());
		v.push_back(s);
		counter++;
	}
}

void string_sort(vector<string>&v1, int len)
{
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			if (i != j)
			{
				if (v1[i] < v1[j])
					swap(v1[i], v1[j]);
			}
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
	string_sort(v, len);
	print_vector(v, len);
}