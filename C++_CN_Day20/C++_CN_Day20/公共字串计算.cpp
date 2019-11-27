#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1,s2;
	int tmp = 0, max = 0;
	while (cin >> s1 >> s2)
	{
		if (s1.size() > s2.size())
		{
			s1.swap(s2);
		}
		int i,j;
		for (i = 0; i < s1.size(); i++)
		{
			for (j = i; j < s1.size(); j++)
			{
				tmp = j - i + 1;
				string res = s1.substr(i, tmp);
				if ((int)s2.find(res) < 0)
				{
					break;
				}

				if (tmp > max)
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