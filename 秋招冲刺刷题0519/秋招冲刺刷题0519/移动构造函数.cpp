#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class A
{
private:
	string* m_s;
public:
	static int cn;
	string s()const
	{
		return *m_s;
	}

	A() = default;//缺省构造函数

	A(const string& str)//构造函数
	{
		cn++;
		m_s = new string;
		*m_s = str;
	}

	A(string&& str) :m_s(&str)//move构造函数
	{
		cn++;
	}

	A& operator=(A&& str)//重载移动复制运算符
	{
		cn++;
		m_s = str.m_s;
		return *this;
	}

	~A()//析构函数
	{
		if (cn <= 0)
		{
			delete m_s;
			m_s = nullptr;
		}
		else
		{
			cn--;
		}
	}

	//A(const A& str) = delete;//删除拷贝构造
};

int A::cn = 0;
int main4()
{
	string in ="23";
	//cin >> in;
	A a(in);
	cout << a.s() << endl;
	A b(move(a));
	cout << b.s() << endl;
	A c;
	c = move(b);
	cout << c.s() << endl;
    return 0;
}