#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int Max_Same_Num(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 0;
	}
	else if (a % b == 0)
	{
		return b;
	}
	return Max_Same_Num(b, a % b);
}

int Min_Same_Num(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 0;
	}
	return (a / Max_Same_Num(a, b)) * b;
}
int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	cout << Min_Same_Num(num1, num2) << endl;
    system("pause");
    return 0;
}