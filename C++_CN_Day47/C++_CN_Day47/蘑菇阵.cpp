#include<iostream>
#include<vector>
#define EPSINON 1e-6
using namespace std;

int main2()
{
	int m, n, k;
	while (cin >> m >> n >> k)
	{
		int x, y;
		vector<vector<double>> v(m, vector<double>(n, 1));
		v[0][0] = 1.0;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			v[x - 1][y - 1] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!(i == 0 && j == 0))
				{
					if (EPSINON < v[i][j])
					{
						v[i][j] = (i - 1 >= 0 ? v[i - 1][j] * (j == n - 1 ? 1 : 0.5) : 0) + (j - 1 >= 0 ? v[i][j - 1] * (i == m - 1 ? 1 : 0.5) : 0);
					}
				}
			}
		}
		printf("%.2lf\n", v[m - 1][n - 1]);
	}
	return 0;
}