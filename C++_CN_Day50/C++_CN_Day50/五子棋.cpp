#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool Horizontal(vector<string>& vs, int x, int y, char val)//��
{
	int count = 1;
	int y1 = y;
	for (; y1 - 1 >= 0 && vs[x][y1 - 1] == val; count++, y1--);//������
	for (; y + 1 < 20 && vs[x][y + 1] == val; count++, y++);//������
	return count >= 5 ? true : false;
}
bool Vertical(vector<string>& vs, int x, int y, char val)//��
{
	int count = 1;
	int x1 = x;
	for (; x1 - 1 >= 0 && vs[x1 - 1][y] == val; count++, x1--);//������
	for (; x + 1 < 20 && vs[x + 1][y] == val; count++, x++);//������
	return count >= 5 ? true : false;
}

bool LeftOblique(vector<string>& vs, int x, int y, char val)//��б
{
	int count = 1;
	int x1 = x, y1 = y;
	for (; x1 - 1 >= 0 && y1 - 1 >= 0 && vs[x1 - 1][y1 - 1] == val; count++, x1--, y1--);//б������
	for (; x + 1 < 20 && y + 1 < 20 && vs[x + 1][y + 1] == val; count++, x++, y++);//б������
	return count >= 5 ? true : false;
}

bool RightOblique(vector<string>& vs, int x, int y, char val)//��б
{
	int count = 1;
	int x1 = x, y1 = y;
	for (; x1 - 1 >= 0 && y1 + 1 < 20 && vs[x1 - 1][y1 + 1] == val; count++, x1--, y1++);//б������
	for (; x + 1 < 20 && y - 1 >= 0 && vs[x + 1][y - 1] == val; count++, x++, y--);//б������
	return count >= 5 ? true : false;
}

int main()
{
	vector<string> v(20);
	while (cin>>v[0])
	{
		bool flag = false;
		for (int i = 1; i < 20; i++)
		{
			getline(cin, v[i]);
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (v[i][j] != '.')
				{
					if (v[i][j] == '*')
					{
						if (Horizontal(v, i, j, '*') || Vertical(v, i, j, '*')
							|| LeftOblique(v, i, j, '*') || RightOblique(v, i, j, '*'))
						{
							cout << "Yes" << endl;
							flag = true;
							break;
						}
					}
					else
					{
						if (Horizontal(v, i, j, '+') || Vertical(v, i, j, '+')
							|| LeftOblique(v, i, j, '+') || RightOblique(v, i, j, '+'))
						{
							cout << "Yes" << endl;
							flag = true;
							break;
						}
					}
				}
			}
			if (flag)
			{
				break;
			}
		}
		if (!flag)
		{
			cout << "No" << endl;
		}
	}
	return 0;
}

//bool JudgeWin(vector<string>& v)
//{
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = 0; j < 20; j++)
//		{
//			if (v[i][j] != '.')
//			{
//				int  right =1, right_down =1,down =1,left_down =1;
//				for (int k = 1; k < 5; k++)//ͬʱ���ĸ��������Ĵ�,���ĸ�����ûȥ��
//				{
//					if (j < 16 && v[i][j + k] == v[i][j])//��
//					{
//						right++;
//					}
//					if (i < 16 && j < 16 && v[i][j] == v[i + k][j + k])//����
//					{
//						right_down++;
//					}
//					if (i < 16 && v[i + k][j] == v[i][j])//��
//					{
//						down++;
//					}
//					if (i > 3 && j < 16 && v[i - k][j + k] == v[i][j])//����
//					{
//						left_down++;
//					}
//				}
//				if (right == 5 || right_down == 5 || down == 5 || left_down == 5)
//				{
//					return true;
//				}
//
//			}
//
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	while (1)
//	{
//		vector<string> v(20);
//		bool flag = false;
//		for (int i = 0; i < 20; i++)
//		{
//			getline(cin, v[i]);
//		}
//		cout << (JudgeWin(v) ? "Yes" : "No") << endl;
//	}
//	return 0;
//}
