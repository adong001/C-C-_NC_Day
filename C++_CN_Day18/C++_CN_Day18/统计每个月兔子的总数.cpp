#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main()
{
	int month;
	int fn = 1, fn_1 = 1, fn_2 = 1;
	while (cin >> month)
	{
		while (month > 2)
		{
			fn_2 = fn_1;
			fn_1 = fn;
			fn = fn_1 + fn_2;
			month--;
		}
		cout << fn << endl;
	}
	system("pause");
	return 0;
}