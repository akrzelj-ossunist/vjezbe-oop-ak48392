/*#include "Header.h"

void input_vector(vector<int>&v1, int min, int max, int& suma, int &len)
{
	int m, size=0;
	cout << "unestie duljinu vektora: " << endl;
	cin >> len;
	while (size != len)
	{
		cout << "unseite clan vektora: " << endl;
		cin >> m;
		v1.push_back(m);
		size++;
		if (min > m)
			min = m;
		if (max < m)
			max = m;
		suma += m;
	}
}

void print_vector(vector<int>v1, int len)
{
	for (int i = 0; i < len; i++)
		cout << v1[i] << "  ";
	cout << endl;
}

void main()
{
	vector<int>v1;
	int min = INT_MAX, max = INT_MIN, suma = 0, len;
	input_vector(v1, min, max, suma, len);
	sort(v1.begin(), v1.end());
	vector<int>::iterator it = v1.end();
	it = v1.begin();
	v1.insert(it, 0);
	it = v1.end();
	v1.insert(it, suma);
	print_vector(v1, len + 2);
}*/