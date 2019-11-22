#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;

int PerfectNum(int num)
{
	int count = 0;
	int i, j;
	for (i = 1; i <= num; i++)
	{
		int sum = 0;
		for (j = 1; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				sum += j;
				if (j != i / j)
				{
					sum += i / j;
				}
			}
		}
		sum -= i;
		if (sum == i)
		{
			count++;
		}
	}
	if (count > 0)
	{
		return count;
	}
	return -1;
}

int main()
{
	int num;
	while (cin >> num)
	{
		cout << PerfectNum(num) << endl;
	}
	system("pause");
	return 0;
}