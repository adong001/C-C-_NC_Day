#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	vector<int> v;
	int T, n, K;
	cin >> T;
	while (T--)
	{
		cin >> n >> K;
		v.resize(2 * n);
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> v[i];
		}
		vector<int> tmp = v;
		while (K--)
		{
			vector<int> tmp(v);
			for (int i = 0; i < n; ++i)
			{
				v[2 * i] = tmp[i];
				v[2 * i + 1] = tmp[i + n];
			}
		}
		for (auto& e : v)
		{
			cout << e << " ";
		}


	}
	system("pause");
	return 0;
}