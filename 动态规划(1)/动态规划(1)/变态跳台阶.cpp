#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
//�����������һ��n����̨���ܹ��ж�����������
//��1�ף�ʣ��n-1��, ʣ��������f(n-1)
//��2�ף�ʣ��n-2�ף�ʣ��������f(n-2)
//.......
//��n�ף�ʣ��n-n�ף�ʣ��������f(0)
//
//f(n) = f(n - 1) + f(n - 2) + .......f(0)
//f(n - 1) = f(n - 2) + f(n - 3) + .......f(0)
//.......
//-->��̬���̣�f(n) = 2 * f(n - 1);
//
//
//����ʹ����ѧ���ɷ��о�һ��
//��ֵ:f(1) = 1;
//	 f(2) = 2*f(1) = 2
//	 f(3) = 2 * f(2) = 4
//	 f(4) = 2 * f(3) = 8
//	 ........
//-->�ռ����ʽ:f(n) = 2^(n-1)

class Solution {
public:
	//����һ:
	int jumpFloorII(int number)
	{
		int fn = 1,fn_1;
		if (number <= 0)
		{
			return 0;
		}
		for (int i = 2; i <= number; i++)
		{
			fn_1 = fn;
			fn = 2 * fn_1;
		}
		return fn;
	}
	int jumpFloorII2(int number)
	{
		return 1 << (number - 1);
	}
};

int main2()
{
    system("pause");
    return 0;
}