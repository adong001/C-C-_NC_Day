#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main2()
{
	int n,i = 0;
	while (cin >> n)
	{
		if (n <= 0)
		{
			return 0;
		}
		vector<int> v(n);
		while (n--)
		{
			cin >> v[i];
		}
		int max = v[0], tmp = 0;
		for (auto& e : v)
		{
			if (tmp >= 0)
			{
				tmp += e;
			}
			else
			{
				tmp = e;
			}
			if (max > tmp)
			{
				max = tmp;
			}
		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}