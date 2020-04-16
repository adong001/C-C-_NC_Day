#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:

	//����һ:��̬�滮��ĳ��Ԫ�س���num��++��������û���־�num--,�ж�num>0˵�����ִ����ǵ�ǰ���ģ�num<=0,˵�����ǣ�tmp��Ҫ��ֵ
	//ʱ�临�Ӷȣ�O(N)���ռ临�Ӷȣ�O(N)
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		int len = numbers.size();
		int tmp = numbers[0];
		int num = 1;//ÿ��Ԫ��Ĭ�ϴ���Ϊ1
		for (int i = 1; i < len; i++)
		{
			//tmp��¼��ǰλ��֮ǰ��������Ԫ��
			if (numbers[i] == tmp)//tmp�������ͬ.��++
			{
				num++;
			}
			else//��tmp��һ��
			{
				if (num > 0)//tmp֮ǰ��¼�Ĵ���
				{
					num--;
				}
				else//tmp֮ǰ���ִ���С��1�Σ����¸�tmp��ֵ
				{
					tmp = numbers[i];
					num = 1;
				}
			}
		}
		num = count(numbers.begin(), numbers.end(), tmp);//���tmp��������ݾ��ǵ�ǰ���ִ�������
		if (num > len / 2)//��������һ��ͷ���
		{
			return tmp;
		}
		return 0;
	}

	//������:���������һ�������������һ�룬��ô�������һ���������м�
	//ʱ�临�Ӷ�O(N*LogN) �ռ临�Ӷ�O(1)
	int MoreThanHalfNum_Solution2(vector<int> numbers)
	{
		int num;
		int len = numbers.size() / 2;
		sort(numbers.begin(), numbers.end());
		num = count(numbers.begin(), numbers.end(), numbers[len]);
		return num > len ? numbers[len] : 0;
	}
	//������:ͨ��map��key����ĳ�����ݵ�ֵ��val��¼���ֵ���ֵĴ���������������һ��ͷ���
	//ʱ�临�Ӷ�O(N) �ռ临�Ӷ�O(N)
	int MoreThanHalfNum_Solution3(vector<int> numbers)
	{
		map<int, int> m;
		int count = 0;
		int len = numbers.size();
		for (int i = 0; i< len; i++)
		{
			count = ++m[numbers[i]];
			if (count > len / 2)
			{
				return numbers[i];
			}
		}
		return 0;
	}
};


int main1()
{
	vector<int> v = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Solution s;
	s.MoreThanHalfNum_Solution2(v);
	return 0;
}