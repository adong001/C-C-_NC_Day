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
			while (i < j && !isalnum(s[i])){ i++; }//ȥ���Ĳ������ֺ���ĸ���ַ�
			while (j > i && !isalnum(s[j])){ j--; }
			if (j <= i)//ȥ����������ֱ��retrun
			{
				return true;
			}
			if (isdigit(s[i]) && isdigit(s[j]))//��������
			{
				if (s[i] == s[j])
				{
					i++;
					j--;
				}
				else
				{
					return false;
				}
			}
			else if(isalpha(s[i]) && isalpha(s[j]))//������ĸ
			{
				//��д��Сд��Сд���д: �ַ� ^= 32;
				//��д��Сд��Сд��Сд: �ַ� |= 32;
				//Сд���д����д���д: �ַ� &= -33;
				s[i] |= 32;//ȫ���Сд
				s[j] |= 32;
				if (s[i] == s[j])
				{
					i++;
					j--;
				}
				else
				{
					return false;
				}
			}
			else//����ĸ�����ֻ��
			{
				return false;
			}
		}
		return true;
	}
};

int main1()
{
	Solution s;
	cout << s.isPalindrome("A man, a plan, a canal : Panama");
    system("pause");
    return 0;
}