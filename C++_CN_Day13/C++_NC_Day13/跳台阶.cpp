#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
#include<vector>
#include <algorithm>
using namespace std;

int JumpStep()
{
	int begin =8, end =85678;
	int count = 0;
	//cin >> begin >> end;
	if (begin < 4 || end>100000 || begin > end)
	{
		return -1;
	}
	vector<int> steps(end + 1, INT_MAX);
	steps[begin] = 0;
	int i, j = 0;

	for (i = begin; i <= end; i++)
	{
		if (steps[i] == INT_MAX)
		{
			continue;
		}

		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0  && (i + j) <= end)
			{
				steps[i + j] = min(steps[i] + 1, steps[i + j]);
			}
			if (i % (i / j) == 0  && (i + i / j) <= end)
			{
				steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
			}
		}
	}

	if (steps[end] == INT_MAX)
	{
		return -1;
	}
	return steps[end];
}
int main2()
{
	cout << JumpStep() << endl;
	system("pause");
	return 0;
}