#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//��һ��string�����ж����ŵĺϷ���
 //1�����ַ������ַ�һ��false
 //2��ÿ������Ҫ���������
class Parenthesis {
public:
	bool chkParenthesis(string A, int n)
	{
		int count = 0;
		if (A.empty() || n % 2 != 0)//��Ϊ�պʹ��ĳ���Ϊ����ֱ��false
		{
			return false;
		}

		for (auto& ch : A)
		{
			if ((ch != '(' && ch != ')') || A[0] == ')')
		   //��֤���ܳ��ַ������ַ����ҵ�һ���ַ�����Ϊ')'
			{
				return false;
			}

			else if (ch == '(')//����������++
			{
				count++;
			}
			else//������--
			{
				count--;
			}
		}
		if (count != 0)//count--��0˵��ȫ����Գɹ�������ʧ��
		{
			return false;
		}

		else
		{
			return true;
		}
	}
};

int main()
{
	string str("()(())");
	Parenthesis test;
	cout << test.chkParenthesis(str, 6) << endl;
    system("pause");
    return 0;
}