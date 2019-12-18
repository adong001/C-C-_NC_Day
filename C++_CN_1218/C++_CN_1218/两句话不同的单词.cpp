#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_set>
using namespace std;

//������������ A �� B �� ��������һ���ɿո�ָ��ĵ��ʡ�ÿ�����ʽ���Сд��ĸ��ɡ���
//���һ������������һ��������ֻ����һ�Σ�����һ��������ȴû�г��֣���ô������ʾ��ǲ������ġ�
//�������в����õ��ʵ��б������԰��κ�˳�򷵻��б�
//
//ʾ�� 1��
//���룺A = "this apple is sweet", B = "this apple is sour"
//�����["sweet", "sour"]
//
//ʾ�� 2��
//���룺A = "apple apple", B = "banana"
//�����["banana"]
//
//��ʾ��
//0 <= A.length <= 200
//0 <= B.length <= 200
//A �� B ��ֻ�����ո��Сд��ĸ��


class Solution {
public:
	
	unordered_set<string> GetWord(string s)
	{
		unordered_set<string> ss;
		int i, j;
		for (i = 0; i < s.size();i = j)
		{
			for (j = i + 1; j < s.size(); j++)
			{
				if (j < s.size() ||isspace(s[j]))
				{
					ss.insert(s.substr(i, j - i));
					break;
				}
			}
			j++;
			while (isspace(s[j]) && j < s.size())
			{
				j++;
			}
		}
		return ss;
	}
	vector<string> uncommonFromSentences(string A, string B)
	{
		unordered_set<string> ss1,ss2;
		vector<string> vs;
		ss1 = GetWord(A);
		ss2 = GetWord(B);
		for (auto& e : ss2)
		{
			if (!ss1.insert(e).second)
			{
				vs.push_back(e);
			}
		}
		return vs;
	}
};
int main()
{
	string A = "this apple is sweet", B = "this apple is sour";
	Solution s;
	unordered_set<string> ss1;
	vector<string> vs;
	ss1 = s.GetWord(A);
	vs = s.uncommonFromSentences(A, B);
	for (auto&e : vs)
	{
		cout << e << " ";
	}
    system("pause");
    return 0;
}