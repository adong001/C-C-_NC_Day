#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int GreatestDommonDivisor(int num1, int num2)
{
	while (num2)
	{
		int tmp = num2;
		num2 = num1 % num2;
		num1 = tmp;
	}
	return num1;
}

int main()
{
	int n, blood = 0;
	vector<int> v;
	while (cin >> n >> blood)
	{
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			if (v[i] <= blood)
			{
				blood += v[i];
			}
			else
			{
				blood += GreatestDommonDivisor(v[i], blood);
			}
		}
		cout << blood << endl;
	}
    system("pause");
    return 0;
}