#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void HighAcc()
{
	string s1;
	string s2;
	string sum;
	int carry = 0,tmp;
	while (cin >> s1 >> s2)
	{
		reverse(s1.begin(),s1.end());
		reverse(s2.begin(), s2.end());
		char ss1[1024] = {0};
		char ss2[1024] = {0};
		int flag = 2;
		strcpy(ss1, s1.c_str());
		strcpy(ss2, s2.c_str());
		int size = (s1.size() > s2.size() ? s1.size() : s2.size());
		for (int i = 0; i < size; i++)
		{
			if (ss1[i] == '\0' || ss2[i] == '\0')
			{
				flag = 1;
			}
			tmp = (ss1[i] + ss2[i] + carry - flag* '0') % 10;//取相加后的低位
			carry = (ss1[i] + ss2[i] + carry - flag* '0') / 10;
			sum.push_back(tmp+'0');
		}

		for (auto ip = sum.rbegin(); ip != sum.rend(); ip++)
		{
			cout << *ip;
		}
		cout << endl;
	}
}

int main2()
{
	HighAcc();
    system("pause");
    return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main22()
{
	string a, b;
	while (cin >> a >> b)
	{
		int temp = 0, carry = 0;
		while (a.size()<b.size())
			a = "0" + a;
		while (a.size()>b.size())
			b = "0" + b;
		for (int i = a.size() - 1; i >= 0; i--)
		{

			temp = a[i] - '0' + b[i] - '0' + carry;
			a[i] = temp % 10 + '0';
			if (temp / 10)
				carry = 1;
			else
				carry = 0;
		}
		if (carry)
			a = "1" + a;
		cout << a << endl;
	}
	return 0;
}