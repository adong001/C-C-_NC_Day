#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int backPackII(int m, vector<int> A, vector<int> V)
	{
		vector<int> retval(m, 0);
		retval[0] = V[0];//�����ŵ�n����Ʒ�󱳰�����ļ�ֵ����һ����Ʒ��Ϊ����
		int bagsize = m - A[0];//����ʣ���С

		for (int i = 1; i < A.size(); i++)
		{
			if (A[i] > m)//��ȫװ���£���Ʒ��С���ڱ�������
			{
				break;
			}
			else
			{
				if (A[i] <= bagsize)//����ʣ���С��װ�´���Ʒ
				{

				}

				else// ����ʣ���С��װ���´���Ʒ������һ�ε�
				{

				}
			}
		}
	}
};
int main()
{
	system("pause");
	return 0;
}