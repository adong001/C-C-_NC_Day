#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//���ǿ�����2 * 1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
//������n��2 * 1��С�������ص��ظ���һ��2 * n�Ĵ���Σ��ܹ��ж����ַ�����

class Solution {
public:
	int rectCover(int number)
	{
		int fn = 1, fn_1 = 1, fn_2 = 1;
		if (number <= 0)
		{
			return 0;
		}
		if (number == 1)
		{
			return 1;
		}
		for (int i = 2; i <= number; i++)
		{
			fn_2 = fn_1;
			fn_1 = fn;
			fn = fn_1 + fn_2;
		}
		return fn;
	}
};
int main()
{
    system("pause");
    return 0;
}