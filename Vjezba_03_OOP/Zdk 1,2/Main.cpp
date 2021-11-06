#include "Header.hpp"

void vector_input(vector<int>&v1,int &len)
{
	int m;
	while (cin >> m)
	{
		len++;
		v1.push_back(m);
		if (len == 10)
			break;
	}
}

void vector_input_1(vector<int>& v2, int& len1, int& interval_min, int& interval_max)
{
	int m;
	cout << "unesite granice intervala: " << endl;
	cin >> interval_min >> interval_max;
	while (cin >> m)
	{
		if (interval_min < m && m < interval_max)
		{
			len1++;
			v2.push_back(m);
		}
		else
			break;
	}
}

void vector_input_2(vector<int>v1, vector<int>v2, vector<int>& v3, int len, int len1, int& len2)
{
	int br = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len1; j++)
			if (v1[i] == v2[j])
				br++;
		if (br == 0)
		{
			len2++;
			v3.push_back(v1[i]);
		}
		br=0;
	}
}

void print_vector(vector<int>v1,int len)
{
	for (int i = 0; i < len; i++)
		cout << v1[i] << " ";
}

void main()
{
	int len = 0;
	vector<int>v1;
	vector_input(v1,len);
	print_vector(v1,len);

	int len1 = 0;
	int interval_min, interval_max;
	vector<int>v2;
	vector_input_1(v2, len1, interval_min,interval_max);
	print_vector(v2, len1);

	int len2 = 0;
	vector<int>v3;
	vector_input_2(v1, v2,v3, len, len1, len2);
	print_vector(v3, len2);
}