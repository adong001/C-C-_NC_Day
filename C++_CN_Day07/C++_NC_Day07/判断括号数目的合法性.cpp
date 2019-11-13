#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//给一个string串，判断括号的合法性
 //1、出现非括号字符一律false
 //2、每个括号要求两两配对
class Parenthesis {
public:
	bool chkParenthesis(string A, int n)
	{
		int count = 0;
		if (A.empty() || n % 2 != 0)//串为空和串的长度为奇数直接false
		{
			return false;
		}

		for (auto& ch : A)
		{
			if ((ch != '(' && ch != ')') || A[0] == ')')
		   //保证不能出现非括号字符，且第一个字符不能为')'
			{
				return false;
			}

			else if (ch == '(')//出现左括号++
			{
				count++;
			}
			else//右括号--
			{
				count--;
			}
		}
		if (count != 0)//count--至0说明全部配对成功，否则失败
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