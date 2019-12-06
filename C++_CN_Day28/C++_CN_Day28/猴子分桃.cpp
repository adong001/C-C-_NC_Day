#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
using namespace std;

int main1()

{
	int n;
	while (cin >> n)
	{

		if (n == 0)
			break;
		else
		{
			cout << (long)pow(5, n) - 4 << " " << (long)pow(4, n) + n - 4 << endl;
		}
	}
	return 0;
}