#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		int count = 0;
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num%i == 0)//找到一个因子
			{
				while (num%i == 0)//不断的短除它，直到不能除尽为止
				{
					num /= i;
				}
				count++;//对不同因子count+1即可
			}
		}
		if (num != 1)//出来以后，如果num不为1说明有一个因子是一个单个的质数，在给count加一次
		{
			count++;
		}
		cout << count << endl;
	}
    system("pause");
    return 0;
}