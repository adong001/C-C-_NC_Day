#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	vector<int> bottle;
	bottle.resize(10);
	int i;
	for (i = 0; cin >> bottle[i]; i++)
	{
		int sum = 0;
		if (bottle[i] == 0)
		{
			break;
		}

		while (bottle[i] / 3)
		{
			sum += bottle[i] / 3;
			bottle[i] = (bottle[i] / 3 + bottle[i] % 3);
		}

		if (bottle[i] == 2)
		{
			sum++;
		}
		bottle[i] = sum;
	}

	for (int j = 0; j < i;j++)
	{
		cout << bottle[j] << endl;
	}
	system("pause");
	return 0;
}