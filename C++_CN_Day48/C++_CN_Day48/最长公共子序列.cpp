#include<iostream>
#include<vector>
#include<string>
#define MAX(a,b) a>b?a:b

int main()
{
	std::string s1, s2;
	while (std::cin >> s1 >> s2)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		std::vector<std::vector<int>> v(len1, std::vector<int>(len2, 0));
		int count = 0;
		v[0][0] = (s1[0] == s2[0] ? 1 : 0);
		for (int i = 1; i < len2; i++)
		{
			v[0][i] = s1[0] == s2[i] ? 1 : 0;
			v[0][i] = MAX(v[0][i], v[0][i - 1]);
		}

		for (int i = 1; i < len1; i++)
		{
			v[i][0] = s1[i] == s2[0] ? 1 : 0;
			v[i][0] = MAX(v[i][0], v[i - 1][0]);
		}

		for (int i = 1; i < len1; i++)
		{
			for (int j = 1; j < len2; j++)
			{
				v[i][j] = MAX(v[i - 1][j], v[i][j - 1]);
				if (s1[i] == s2[j])
				{
					v[i][j] = MAX(v[i][j], v[i - 1][j - 1] + 1);
				}
			}
		}
		std::cout << v[len1 - 1][len2 - 1] << std::endl;
	}
	return 0;
}