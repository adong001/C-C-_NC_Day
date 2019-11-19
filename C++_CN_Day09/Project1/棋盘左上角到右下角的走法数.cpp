#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//��Ϊ�������������
//	1.��n = 1,m = 1ʱ ����·��Ϊ1 + 1 = 2��
//	2.��n = 1(��m = 1)�� m > 1(n > 1)ʱ����·��Ϊn +  m�֣�����1.2����ɺϲ����˴�ֻ��Ϊ�˸�����������׳�1
//	3.��n > 1 �� m > 1ʱ�����յ���(n,m)������ֻ������ (n-1,m)��(n,m-1).�����Ļ�����ͨ���ݹ������������ĺ�

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