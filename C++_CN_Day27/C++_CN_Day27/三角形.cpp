#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main2()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a + b > c && a + c > b && b + c > a )		
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}