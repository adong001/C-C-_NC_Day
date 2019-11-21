#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool IsPrime(int num)
{
	int i, tmp;
	for (i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main2()
{
	int num;
	vector<int> res;
	int min = 0;
	int n1, n2;
	cin >> num;

	if (num <= 2)
	{
		return 0;
	}

	for (int i = 3; i <= num / 2; i++)
	{
		if (IsPrime(i) && IsPrime(num - i))
		{
			res.push_back(i);
			res.push_back(num - i);
		}
	}

	if (res.size() >= 2)
	{
		 min = res[1] - res[0];
		for (int i = 2; i < res.size(); i+=2)
		{
			if (min >(res[i + 1] - res[i]))
			{
				min = res[i + 1] - res[i];
				n1 = res[i];
				n2 = res[i + 1];
			}
		}
	}
	cout << n1<<endl<<n2<<endl;
	system("pause");
	return 0;
}


/*从最中间的位置查找来满足距离最近
*循环判断是否为素数*/
int main22()
{
	int n;
	while (cin >> n)
	{
		int mid = n / 2;
		int i;
		for (i = mid; i > 0; --i)
		{
			if (IsPrime(i) && (IsPrime(n - i)))
				break;
		}
		cout << i << endl << n - i << endl;
	}
	return 0;
}