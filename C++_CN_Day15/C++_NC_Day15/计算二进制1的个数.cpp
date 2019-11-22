#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



int main1()
{
	int num;
	while (cin >> num)
	{
		int sum = 0;
		for (int i = 0; i < 32; i++)
		{
			sum += ((num >> i) & 1);
		}
		cout << sum << endl;
	}
    system("pause");
    return 0;
}