#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
using namespace std;

class LCA {
public:
	int getLCA(int a, int b)
	{
		queue<int> qur;
		queue<int> qul;

		if (a <= 0 || b <= 0)
		{
			return 0;
		}

		if (a == 1 || b == 1)
		{
			return 1;
		}
		
		int tmp_a = a;
		int tmp_b = b;
		while (tmp_a)
		{
			qur.push(tmp_a);
			tmp_a /= 2;
		}

		while (tmp_b)
		{
			qul.push(tmp_b);
			tmp_b /= 2;
		}

		if (qur.size() < qul.size())
		{
			qur.swap(qul);
		}

		int length = qur.size() - qul.size();
		for (int i = length; i; i--)
		{
			qur.pop();
		}

		for (int j = qur.size(); j; j--)
		{
			if (qul.front() == qur.front())
			{
				return qul.front();
			}
			qul.pop();
			qur.pop();
		}
		return 0;
	}
};

int main1()
{
	LCA test;
	cout << test.getLCA(12, 7) << endl;
    system("pause");
    return 0;
}