#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

#include<vector>
using namespace std;

//2. ���⣺�����г��ִ�������һ������� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | 
//
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//
//��������һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }
//
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2���������������� 0��
//
//����˼·1��
	//һ�������������г��ִ�������һ�룻��ôɾ����2������ͬ�����ֺ�
	//����������������г��ֵĴ���Ҳ�ǳ���һ�룻�����ظ��������̣����һ�����µ����־���Ŀ������
//	����ĳ����ʱtmp��¼�������num++����һ�����������������num++��
//	����,���num>0,num--,���num<=0,��tmp��¼��һ������ֵ������num++��ֱ�����������
//	���num�Ƿ�>0,���ھʹ����������������򲻴��ڡ�
//����˼·2��
//	1.�������Ÿ���
//	2.��õ����м���Ǹ���
//	3.�����������������˼���
//	4.��������size/2�ͷ����������򷵻�0
		  
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty())
		{
			return 0;
		}

		int tmp = numbers[0];
		int num = 1;
		int i;

		for (i = 1; i < numbers.size();i++)
		{
			if (numbers[i] == tmp)//��¼���ֵ
			{
				num++;//������++
			}

			else//��ǰ��ֵ��tmp�����ֵ��һ��
			{
				if (num > 0)//��������¼��tmp��ֵ����1��
				{
					num--;
				}

				else//tmp֮ǰ���ֵĴ���С��1��,���¸�tmp��ֵ
				{
					tmp = numbers[i];
					num = 1;
				}
			}
		}
		num = count(numbers.begin(),numbers.end(),tmp);

		if (num>numbers.size() / 2)
		{
			return tmp;
		}
		return 0;
	}
};
int main1111()
{
	Solution test;
	vector<int> ar = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };//
	cout << test.MoreThanHalfNum_Solution(ar) << endl;
    system("pause");
    return 0;
}