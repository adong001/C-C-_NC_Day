#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		map<int, int> m;
		while (cin >> n)
		{
			m[n]++;
		}
		int max = -1000000;
		int tmp = m[n];
		for (auto it = m.begin(); it != m.end(); it++)
		{
			if (max > it->second)
			{
				max = it->second;
				tmp = it->first;
			}
		}
		cout << tmp;
	}
	return 0;
}