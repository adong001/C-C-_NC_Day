#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
//示例 1：
//输入 : "babad"
//输出 : "bab"
//注意 : "aba" 也是一个有效答案。
//
//示例 2：
//输入 : "cbbd"
//输出 : "bb"

class Solution
{
public:
	bool IsPalindrom(string& s)
	{
		int end = s.size() - 1;
		for (int start = 0; start <= end; start++, end--)
		{
			if (s[start] != s[end])
			{
				return false;
			}
		}
		return true;
	}
	string longestPalindrome(string s)
	{
		int max = 0;

	}
};
//class test
//{
//public:
//	void f1()
//	{
//		cout << "f1" << endl;
//	}
//	void f2()const
//	{
//		cout << " f2" << endl;
//	}
//	void f3()
//	{
//		f2();
//	}
//	void f4()const
//	{
//		const_cast<test&>(*this).f1();
//	}
//};
//int main()
//{
//	test t1;
//	const test t2;
//	t1.f1();
//	t1.f2();
//	const_cast<test&>(t2).f1();
//	t2.f2();
//    return 0;
//}

//class Test
//{
//private:
//	char* str;
//	static int count;
//public:
//	Test(char* s)
//	{
//		if (count == 0)//资源没有被引用
//		{
//			str = new char[strlen(s) + 1];
//			strcpy(str, s);
//			count++;
//		}
//		else//资源被引用，浅拷贝
//		{
//			str = s;
//		}
//		
//	}
//
//	Test(const Test& t)
//	{
//		str = t.str;//资源肯定被引用了
//		count++;//资源计数器++
//	}
//
//	void Set(char* s)//改变资源
//	{
//		if (count > 1)//除自己外还有其他对象引用资源，就要重现开批空间，其他对象依然指向源空间
//		{
//			str = new char[strlen(s) + 1];//重新开辟新空间，不影响其他对象指向原来的空间资源
//			strcpy(str, s);
//			count--;//资源计数器--
//		}
//		else//只有自己使用资源
//		{
//			strcpy(str, s);//直接改变即可
//		}
//	}
//
//	void Get()
//	{
//		cout << str << endl;
//	}
//
//	~Test()
//	{
//		if (count == 1)//只有自己引用资源才能释放资源
//		{
//			delete[] str;
//		}
//		else//否则资源计数器--
//		{
//			count--;
//		}
//		
//	}
//};
//
//int Test::count = 0;
//
//int main()
//{
//	char* str = "student";
//	Test T1(str);
//	Test T2(T1);
//	T1.Set("stu");
//	T2.Get();
//	return 0;
//}
#include<cstring>
int main()
{
	string s;
	while (cin >> s)
	{
		int Size = s.size();
		int max = 0, len = 0, i, pos;
		for (i = 0; i < Size;)
		{
			for (; i < Size && i + 1 < Size && isdigit(s[i]) && s[i + 1] - s[i] == 1; i++, len++);
			i++;
			max > len ? max : max = len, pos = i;
			len = 0;
		}
		string ret(s.begin() + pos - max - 1, s.begin() + pos);
		cout << ret << endl;;
	}
}