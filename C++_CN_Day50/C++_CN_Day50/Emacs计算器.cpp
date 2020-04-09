#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>

int main2()
{
	int n;
	while (std::cin >> n)
	{
		std::stack<int> st;
		std::vector<std::string> vs(n);
		int res;
		std::string s;
		for (int i = 0; i < n; i++)
		{
			std::cin >> vs[i];
		}
		for (int i = 0; i < n; i++)
		{
			s = vs[i];
			if (s != "+" && s != "-" && s != "+" && s != "/")
			{
				st.push(atoi(s.c_str()));
			}
			else
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();

				if (s == "+")
				{
					st.push(left + right);
				}
				else if (s == "-")
				{
					st.push(left - right);
				}
				else if (s == "*")
				{
					st.push(left * right);
				}
				else if (s == "/")
				{

					if (right != 0)
					{
						st.push(left / right);
					}
					else
					{
						return 0;
					}
				}

			}
		}
		std::cout << st.top() << std::endl;
	}
	return 0;
}