#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
#include<unordered_map>
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
	//
	//unordered_set<string> GetWord(string s)//���ַ����ո��и�
	//{
	//	unordered_set<string> ss;
	//	int i, j;
	//	for (i = 0; i < s.size();i = j)
	//	{
	//		for (j = i + 1; j <= s.size(); j++)
	//		{
	//			if (j <= s.size() && (isspace(s[j]) || j == s.size()))
	//			{
	//				ss.insert(s.substr(i, j - i));
	//				break;
	//			}
	//		}
	//		j++;
	//		while (j < s.size() && isspace(s[j]))
	//		{
	//			j++;
	//		}
	//	}
	//	return ss;
	//}
	vector<string> uncommonFromSentences(string A, string B)
	{
		unordered_map<string,int> um;

		istringstream is(A + " " + B);

		vector<string> vs;
		string str;

		while (is >> str)//ͨ���ַ���������������ո�ضϳ�һ��������
		{
			um[str]++;//��ϣӳ�䣬��֮ǰ���ڵĵ��ʶ�Ӧ��second++
		}
		for (auto& e : um)
		{
			if (e.second == 1)//���������ֻ����һ�Σ���push��ȥ
			{
				vs.push_back(e.first);
				
			}
		}
		return vs;
	}
};
int main()
{
	string A = "this apple is sweet", B = "this apple is sour";
	Solution s;
	vector<string> vs;
	vs = s.uncommonFromSentences(A, B);
	for (auto&e : vs)
	{
		cout << e << " ";
	}
    system("pause");
    return 0;
}