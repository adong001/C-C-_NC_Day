#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;

//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//
//ʾ�� 1:
//���� : "A man, a plan, a canal: Panama"
//��� : true

//ʾ�� 2 :
// ���� : "race a car"
// ��� : false


class Solution {
public:
	bool isPalindrome(string s) 
	{
		int i,j;
		for (i = 0, j = s.size() - 1; i < j;)
		{
			if (isalnum(s[i] && isalnum(s[j])))//
			{
				if (s[i] == s[j] || s[i] - 32 == s[j] || s[i] + 32 == s[j])
				{
					i++;
					j--;
				}
				else if (!isalpha(s[i]) || !isalpha(s[j]))
				{
					if (!isalpha(s[i]))
					{
						i++;
					}
					if (!isalpha(s[j]))
					{
						j--;
					}
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout<<s.isPalindrome("0P");
    system("pause");
    return 0;
}