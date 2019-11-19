#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;

bool IsPrime(int num)
{
	int i;
	for (i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int begin, end;
	cin >> begin >> end;
	if (begin<4 || end>10000 || begin > end)
	{
		return -1;
	}
	int i,j;

	for (i = begin; i <= end; i++)
	{
		for (j = begin / 2; j >= 2; j--)
		{

			if (begin % j == 0 && !IsPrime(begin + j))
			{
				begin += j;
				break;
			}
		}
	}

    system("pause");
    return 0;
}