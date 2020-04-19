#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>

struct Person
{
	int weight;
	int height;
};
bool cmp(const Person& p1, const Person& p2)
{
	if (p1.weight != p2.weight)
	{
		return p1.weight < p2.weight;//���ذ���С������
	}
	else
	{
		return p1.height <= p2.height;//��߰��Ӹߵ���
	}
}
std::istream & operator >> (std::istream &is, Person &p)
{
	is >> p.weight >> p.height;
	return is;
}

int main2()
{
	int N;
	while (std::cin >> N)
	{
		int count = 0;
		int num;
		std::vector<Person> vp(N);
		for (int i = 0; i < N; i++)
		{
			std::cin >>num >> vp[i];
		}
		sort(vp.begin(), vp.end(), cmp);//�Ȱ������Ÿ���

		std::vector<int> dp(N);//dp���Ӧvp��Ӧ��λ�ô���ǰ�浽��ǰλ���޺��������߶�
		dp[0] = 1;//��ʼ����һ��Ԫ��Ϊ1
		for (int i = 1; i < N; i++)
		{
			dp[i] = 1;//ÿ�ε���ĳ��Ԫ��ʱ����͸߶�Ϊ1
			for (int j = 0; j < i; j++)
			{
				//ÿ�ζ��ӵ�һ��Ԫ�������ҵ���ǰλ����ʹ�޺����߶����
				//����һ��Ԫ��vp[j]�ȵ�ǰԪ��vp[i]���ߵڸ�(����������)��
				//����һ��Ԫ������¼����߸߶�+1(dp[j]+1)Ҫ���ڵ�ǰԪ�صĸ߶�dp[i]
				if (vp[j].height <= vp[i].height && dp[j] + 1 > dp[i])
				{
					//������㣬�͸��µ�ǰԪ�ص���߸߶�
					dp[i] = dp[j] + 1;
				}
			}
		}
		int Max = dp[0];
		for (int i = 1; i < N; i++)//�ҳ��߶ȼ�¼�������߶�
		{
			Max = Max > dp[i] ? Max : dp[i];
		}

		std::cout << Max << std::endl;
	}
	return 0;
}