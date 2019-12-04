#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;



int main()
{
	int num,tmp;
	vector<int> v(1001, 0);
	v[0] = 1;
	v[1] = 1;
	for (int i = 2; i < 1001;i++)
	{
		v[i] = (v[i - 1]%1000 + v[i - 2]%1000)%1000;
	}
	while (cin>>num)
	{
		while(num--)
		{
			cin >> tmp;
			printf("%04d", v[tmp]);
		}
		cout << endl;
	}
    system("pause");
    return 0;
}