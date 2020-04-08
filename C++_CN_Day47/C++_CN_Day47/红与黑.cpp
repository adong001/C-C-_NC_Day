#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void PathCount(vector<vector<char>>& v, int i, int j, int& count)
{
	if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] == '#' || v[i][j] == '*')
	{//越界，走过(*)，不能走(#)返回
		return;
	}
	count++;
	v[i][j] = '*';//标记已经走过
	PathCount(v, i + 1, j, count);
	PathCount(v, i - 1, j, count);
	PathCount(v, i, j + 1, count);
	PathCount(v, i, j - 1, count);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<char>> v(m,vector<char>(n));
		int x, y;
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}
		PathCount(v, x, y, count);
		cout << count << endl;
	}
    return 0;
}
