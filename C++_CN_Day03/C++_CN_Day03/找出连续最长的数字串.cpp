#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//1. ���⣺�ַ������ҳ�����������ִ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K 
//   ����һ���ַ���str������ַ���str�е�����������ִ� 
//
//���������� �������������1������������һ���ַ���str�����Ȳ�����255�� 
//
//��������� ��һ�������str��������������ִ��� 
//
//ʾ��1 : ���� abcd12345ed125ss123456789 
//	    ��� 123456789

int main1()
{
	string str;
	string tmp;
	int length = 0;
	auto pos = str.begin();
	int Max_length = 0;
	getline(cin, str);

	if (str.empty())
	{
		return 0;
	}
	//abcd12345ed125ss123456789
	for (auto i = str.begin(); i != str.end();)
	{
		/*while(i!= str.end() && ((i+1)!=str.end())&& ((*(i + 1) - *i) == 1))//�����������(��������)
		{
		auto ip = (*(i + 1) - *i);
		length++;
		i++;
		}*/
		while (i != str.end() && ((i + 1) != str.end()) && ((*(i + 1) - *i) == 1)&&'0'<= *i && *i <= '9')//ֻ����������
		{
			auto ip = (*(i + 1) - *i);
			length++;
			i++;
		}
		length++;
		i++;

		if (length > Max_length)
		{
			Max_length = length;
			pos = i;
		}
		length = 0;
	}
	tmp.insert(tmp.begin(), pos - Max_length, pos);
	cout << tmp << endl;

	return 0;
}


//int main()
//{
//	vector<int> v;
//	v.push_back(100);
//	v.push_back(200);
//	v.push_back(300);
//	v.push_back(400);
//	v.push_back(500);
//	for (auto ip = v.begin(); ip != v.end(); ip++)
//	{
//		if (*ip == 200)
//		{
//			ip = v.erase(ip);
//			cout << *ip << endl;
//		}
//	}
//	for (auto& i : v)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//    system("pause");
//    return 0;
//}

