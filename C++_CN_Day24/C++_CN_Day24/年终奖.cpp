#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Bonus {
public:
	int getMaxValue(vector<vector<int> > board, int i, int j)
	{
		int MaxValue = board[i][j];//���һ���͵�һ��������
		if (i > 0 && j > 0)
		{
			MaxValue += max(getMaxValue(board, i - 1, j), getMaxValue(board, i, j - 1));//�ݹ������ֵ
		}

		else if (i == 0 && j == 0)//����һ�����ӽ���
		{
			return board[0][0];
		}

		else //��һ��(��һ��)û���ϱ�(���)�����⴦��
		{
			if (i == 0)//
			{
				MaxValue += getMaxValue(board, i, j - 1);
			}
			else
			{
				MaxValue += getMaxValue(board, i - 1, j);
			}

		}
		return MaxValue;
	}

	int getMost(vector<vector<int> > board)
	{
		return getMaxValue(board, 1, 1);
	}
};

int main1()
{
	vector<vector<int>> v;
	v.push_back(vector<int>());
	v[0].push_back(10);
	v[0].push_back(2);
	v.push_back(vector<int>());
	v[1].push_back(4);
	v[1].push_back(3);

	Bonus Test;
	Test.getMost(v);
	system("pause");
	return 0;
}