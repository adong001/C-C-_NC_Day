#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main5()
{
	int n;
	while (cin >> n)
	{
		vector<int> m;
		int count = 0, tmp;
		for (int i = 0; i < n; i++)
		{
			cin >> m[i];
			if (count == 0)
			{
				tmp = m[i];
				count = 1;
			}
			else if (tmp != m[i])
			{
				count--;
			}
			else
			{
				count++;
			}
		}
		cout << tmp << endl;
	}
	return 0;
}