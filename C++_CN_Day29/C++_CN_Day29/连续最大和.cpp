#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	vector<int> v;
	int n, max = 0xffffffff,tmp = 0;
	while (cin >> n)
	{
		v.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		
		for (auto& e : v)
		{
			if (tmp >= 0)
			{
				tmp += e;
			}
			else
			{
				tmp = e;
			}

			if(max < tmp) 
			{
				max = tmp;
			}
		}
		cout << max << endl;;
	}
	
    system("pause");
    return 0;
}