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
				string tmp = s1.substr(i,j-i+1);//�ֲ�������ÿ������һ��ѭ�����¶����ʼ��
				if (int(s2.find(tmp)) < 0)//û�ҵ�,����find�ķ���ֵ��
				{
					break;
				}
				else if (tmp.size()>max.size())
				//��������������ֶκ͵ı��֣�ֻҪ��ȡs1�����д��ڵ��Ӷ���s2���ҵ�����
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