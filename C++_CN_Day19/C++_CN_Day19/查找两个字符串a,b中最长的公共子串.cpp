#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int i, j;
		if (s1.size() > s2.size())
		{
			s1.swap(s2);
		}
		//abcdefghijklmnop
		//abcsafjklmnopqrstuvw

		string max;
		for (i = 0; i < s1.size(); i++)
		{
			
			for (j = i; j < s1.size(); j++)
			{
				string tmp = s1.substr(i,j-i+1);//局部变量，每次找完一个循环重新定义初始化
				if (int(s2.find(tmp)) < 0)//没找到,这里find的返回值是
				{
					break;
				}
				else if (tmp.size()>max.size())
				//这个题就是找最大字段和的变种，只要截取s1的所有存在的子段在s2中找到即可
				{
					max = tmp;
				}
			}
		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}