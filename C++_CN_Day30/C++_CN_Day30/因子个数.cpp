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
			if (num%i == 0)
			{
				count++;
			}
		}
		cout << count << endl;
	}
    system("pause");
    return 0;
}