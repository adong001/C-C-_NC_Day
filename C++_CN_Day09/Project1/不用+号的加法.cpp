#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class UnusualAdd {
public:
	/*int addAB(int A, int B)
	{
		return(A - (-B));
	}*/

	int addAB(int A, int B)
	{
		if (B == 0)
		{
			return A;
		}

		int sum = 0, carry = 0;
		{    // 1+1=0  1+0=1 0+1=1  0+0=0 ���������������һλ��ӵ����   
			sum = (A^B);//1.��¼�����������ֵ������������������һλ����ͬ���Ͳ��ý�λ��0+0��Ȼ���ý�λ�����ͻ���0�����ÿ��ǡ� 
			carry = (A&B) << 1;//��¼��������λ���ֵ����������������Ҫ��λ��λ������1������Щλ
			return addAB(sum, carry);//��λ�Ͳ�����λ��ӵݹ�ֱ����λΪ0
		}
	}

};
int main()
{
	UnusualAdd Test;
	cout << Test.addAB(1, 9) << endl;
    system("pause");
    return 0;
}