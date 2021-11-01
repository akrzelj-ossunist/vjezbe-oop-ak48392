/*#include "Header.h"

void input_vector(vector<int>& v1, int &len)
{
	int m, size = 0;
	cout << "unestie duljinu vektora: " << endl;
	cin >> len;
	while (size != len)
	{
		cout << "unseite clan vektora: " << endl;
		cin >> m;
		v1.push_back(m);
		size++;
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
	int len;
	input_vector(v1, len);
	vector<int>::iterator it = v1.begin() + 2;
	v1.erase(it);
	it = v1.begin() + 2;
	v1.insert(it,v1[len-2]);
	v1.pop_back();
	print_vector(v1, len-1);
}*/