#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
//根据逆波兰表示法，求表达式的值。
//有效的运算符包括  + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//说明：
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

//示例 1：
//输入 : ["2", "1", "+", "3", "*"]
//输出 : 9
//解释 : ((2 + 1) * 3) = 9

//示例 2：
//输入 : ["4", "13", "5", "/", "+"]
//输出 : 6
//解释 : (4 + (13 / 5)) = 6

//示例 3：
//输入 : ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//输出 : 22
//解释 :
//((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22


class Solution {
public:
	int getnum(string& s)
	{
		int sign = 1;
		int num = 0;
		int tmp = 0;
		int i = 0;
		int len = s.size();
		if (s[0] == '-')
		{
			sign = -1;
			i++;
		}
		for (; i < len; i++)
		{
			num = tmp * 10 + s[i] - '0';
			tmp = num;
		}
		return sign * num;

	}
	int evalRPN(vector<string>& tokens) 
	{
		stack<int> st;
		int tmp;
		int len = tokens.size();
		for (int i = 0; i < len;i++)
		{
			if (tokens[i].size() > 1)
			//超过一位的数字(必须要与一位的区分，有可能有负数，要处理前面的-号)
			{
				st.push(getnum(tokens[i]));
			}
			else if (isdigit(tokens[i][0]))//一位的数字
			{
				st.push(getnum(tokens[i]));
			}
			else//运算符
			{
				tmp = st.top();
				st.pop();
				switch (tokens[i][0])
				{
				case '+':st.top() += tmp; 
					break;
				case '-':st.top() -= tmp;
					break;
				case '*':st.top() *= tmp;
					break;
				case '/':st.top() /= tmp;
					break;

				}
			}
		}
		return st.top();
	}
};
int main()
{
	Solution s;
	vector<string> vs = { "2", "1", "+", "3", "*" };
	s.evalRPN(vs);
    system("pause");
    return 0;
}