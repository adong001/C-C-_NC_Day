#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



int main()
{
	int n = 2;
	int m = 2;
	int N = n + m;
	int K = n;
	double res = 1.0;
	for (int i = 0; i < n; ++i)
	{
		res = res * (N - K + i) / i;
	}
	cout<<(int)res<<endl;
    system("pause");
    return 0;
}