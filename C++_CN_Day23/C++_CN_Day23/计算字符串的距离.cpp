#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int flag = 0;
	string s1, s2;
	vector<vector<int>> v;
	while (cin >> s1 >> s2)
	{
		v.resize(s1.size() + 1, vector<int>(s2.size() + 1));
		for (int i = 0; i <= s1.size(); i++)//ºá×Ý×ø±ê
		{
			v[i][0] = i;
		}

		for (int i = 1; i <= s2.size(); i++)
		{
			v[0][i] = i;
		}

		for (int i = 1; i <= s1.size(); i++)
		{
			for (int j = 1; j <= s2.size(); j++)
			{
				flag = (s1[i - 1] != s2[j - 1]) ? 1 : 0;
				v[i][j] = min(min(v[i][j - 1] + 1, v[i - 1][j] + 1), v[i - 1][j - 1] + flag);
			}
		}
		for (int i = 0; i <= s1.size(); i++)
		{
			for (int j = 0; j <= s2.size(); j++)
			{
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		cout << v[s1.size() - 1][s2.size() - 1] << endl;
	}
	system("pause");
	return 0;
}