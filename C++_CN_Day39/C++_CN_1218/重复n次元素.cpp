#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//����1��
//�ڴ�СΪ 2N ������ A ���� N + 1 ����ͬ��Ԫ�أ�������һ��Ԫ���ظ��� N �Ρ�
//�����ظ��� N �ε��Ǹ�Ԫ�ء�

class Solution {
public:
	int repeatedNTimes(vector<int>& A)
	{
		unordered_set<int> s;
		for (auto& e : A)
		{
			if (!(s.insert(e).second))
			{
				return e;
			}
		}
	}
};


int repeatedNTimes(vector<int>& A)
{
	unordered_map<int, int> um;
	int n = A.size() / 2;

	for (auto & e : A)
	{
		um[e]++;
	}

	for (auto & e : um)
	{
		if (e.second == n)
		{
			return e.first;
		}
	}
	return -1;
}

int main2()
{
    system("pause");
    return 0;
}