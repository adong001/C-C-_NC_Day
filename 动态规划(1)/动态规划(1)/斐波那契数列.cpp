#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//��Ҷ�֪��쳲��������У�����Ҫ������һ������n��
//�������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
//n <= 39

class Solution 
{
public:
	int Fibonacci(int n) 
	{
		int fn = 1,fn_1 = 1, fn_2 = 1;
		if (n <= 0)
		{
			return 0;
		}
		if (n == 1 || n == 2)
		{
			return 1;
		}
		for (int i = 3; i <= n; i++)
		{
			fn_2 = fn_1;
			fn_1 = fn;
			fn = fn_1 + fn_2;
		}
		return fn;
	}
};

int main1()
{
	Solution t;
	cout << t.Fibonacci(5) << endl;
    system("pause");
    return 0;
}