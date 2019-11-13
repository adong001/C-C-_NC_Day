#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;


bool length_sort(vector<string>& vs)
{
	int i;
	int size = vs.size();
	for (i = 1; i < size;i++)
	{
		if (vs[i].size() <= vs[i - 1].size())
		{
			return false;
		}
	}
	return true;
}

bool dirctionary(vector<string>& vs)
{
	int i;
	int size = vs.size();
	for (i = 1; i < size; i++)
	{
		if (vs[i] <= vs[i - 1])
		{
			return false;
		}
	}
	return true;
}
int main1()
{
	int n;
	vector<string> vs;
	cin >> n;
	vs.resize(n);
	for (auto& i : vs)
	{
		cin >> i;
	}

	if (length_sort(vs) && dirctionary(vs))
	{
		cout << "both" << endl;
	}

	else if (length_sort(vs))
	{
		cout << "lengths" << endl;
	}

	else if (dirctionary(vs))
	{
		cout << "lexicographically" << endl;
	}

	else
	{
		cout << "none" << endl;
	}

    system("pause");
    return 0;
}



//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (auto& e : v)
//		cin >> e;
//	bool lensort = true, dictsort = true;
//	for (int i = 1; i < v.size(); ++i) //i从1开始，比较当前字符串和上一字符串长度
//	{
//		if (v[i - 1].size() >= v[i].size())
//		{
//			lensort = false;
//			break;
//		}
//	}
//	for (int i = 1; i < v.size(); ++i) //i从1开始，比较当前字符串和上一字符串的ASCLL码
//	{
//		if (v[i - 1] >= v[i])
//		{
//			dictsort = false;
//			break;
//		}
//	}
//
//	if (lensort && dictsort)
//		cout << "both" << endl;
//	else if (!lensort && dictsort)
//		cout << "lexicographically" << endl;
//	else if (lensort && !dictsort)
//		cout << "lengths" << endl;
//	else
//		cout << "none" << endl;
//	return 0;
//}