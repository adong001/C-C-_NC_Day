#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//分为以下三种情况：
//	1.当n = 1,m = 1时 ，总路径为1 + 1 = 2种
//	2.当n = 1(或m = 1)且 m > 1(n > 1)时，总路径为n +  m种，，，1.2情况可合并，此处只是为了更容易理解先抛出1
//	3.当n > 1 且 m > 1时，最终到达(n,m)点的情况只有两种 (n-1,m)和(n,m-1).这样的话可以通过递归相加两种情况的和

int pathnum(int n, int m)
{
	if (n > 1 && m > 1)
	{
		return pathnum(n - 1, m) + pathnum(n, m - 1);
	}

	else if (n == 1 || m == 1)
	{
		return n + m;
	}

	else
	{
		return 0;
	}
}

int main2()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathnum(n, m) << endl;
	}
	return 0;
}