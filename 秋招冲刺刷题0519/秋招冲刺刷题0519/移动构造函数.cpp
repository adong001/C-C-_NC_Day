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

	A() = default;//ȱʡ���캯��

	A(const string& str)//���캯��
	{
		cn++;
		m_s = new string;
		*m_s = str;
	}

	A(string&& str) :m_s(&str)//move���캯��
	{
		cn++;
	}

	A& operator=(A&& str)//�����ƶ����������
	{
		cn++;
		m_s = str.m_s;
		return *this;
	}

	~A()//��������
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

	//A(const A& str) = delete;//ɾ����������
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