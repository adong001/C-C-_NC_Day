#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//����һ�������(ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ���ransom�ܲ���
//�ɵڶ����ַ���magazines������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��

//(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼��)

//ע�⣺
//����Լ��������ַ�����ֻ����Сд��ĸ��
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true


class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) 
	{
		int hx[26] = { 0 };
		for (auto& ch : magazine)//��������ĸ++
		{
			hx[ch - 'a']++;
		}
		for (auto& ch : ransomNote)
		{
			if (hx[ch - 'a'] == 0)//û�������ĸ
			{
				return false;
			}
			else//�������ĸ��--
			{
				hx[ch - 'a']--;
			}
		}
		return true;
	}
};
int main1()
{
    system("pause");
    return 0;
}