#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
#include<unordered_map>
using namespace std;

//给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//返回所有不常用单词的列表。您可以按任何顺序返回列表。
//
//示例 1：
//输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet", "sour"]
//
//示例 2：
//输入：A = "apple apple", B = "banana"
//输出：["banana"]
//
//提示：
//0 <= A.length <= 200
//0 <= B.length <= 200
//A 和 B 都只包含空格和小写字母。


class Solution {
public:
	//
	//unordered_set<string> GetWord(string s)//将字符按空格切割
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

		while (is >> str)//通过字符串输入输出流将空格截断成一个个单词
		{
			um[str]++;//哈希映射，若之前存在的单词对应的second++
		}
		for (auto& e : um)
		{
			if (e.second == 1)//若这个单词只出现一次，就push进去
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