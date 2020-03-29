#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main2()
{
	int n;
	while (cin >> n)
	{
		cout << n << " = ";
		for (int i = 2; i <= sqrt(n); i++)
		{
			while (n % i == 0 && n != i)
			{
				cout << i << " * ";
				n /= i;
			}

		}
		cout << n << endl;
	}
    system("pause");
    return 0;
}