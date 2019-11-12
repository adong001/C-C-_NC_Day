#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int Max_Mid_Sum()
{
	int num;
	int size;
	vector<int> vres;
	cin >> size;
	vres.resize(size);
	for (int i = 0; i < size; ++i)
	{
		cin >> vres[i];
	}
	int tmp = 0, j, max = vres[0];
	for (j = 0; j < size; j++)
	{
		tmp += vres[j];
		if (tmp > max)
		{
			max = tmp;
		}
		else if(tmp < 0)
		{
			tmp = 0;
		}

	}
	return max;
}

int main()
{
	cout << Max_Mid_Sum() << endl;
	system("pause");
	return 0;
}
