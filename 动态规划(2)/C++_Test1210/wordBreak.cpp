#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
//����һ���ַ���s��һ�鵥��dict���ж�s�Ƿ�����ÿո�ָ��һ���������У�ʹ�õ������������еĵ��ʶ���dict�еĵ��ʣ����п��԰���һ���������ʣ���
//���� :
//����s = ��leetcode����
//dict = ["leet", "code"].
//����true����Ϊ"leetcode"���Ա��ָ��"leet code".
//
//Given a string s and a dictionary of words dict, determine if s can be segmented into a space - separated sequence of one or more dictionary words.
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//Return true because"leetcode"can be segmented as"leet code".


class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		vector<bool> v(s.size() + 1, false);
		v[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (v[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					v[i] = true;
					break;
				}
			}
		}
		return v[s.size()];
	}
};
int main1()
{
    system("pause");
    return 0;
}