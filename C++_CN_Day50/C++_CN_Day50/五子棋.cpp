#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool Horizontal(vector<string>& vs, int x, int y, char val)//横
{
	int count = 1;
	int y1 = y;
	for (; y1 - 1 >= 0 && vs[x][y1 - 1] == val; count++, y1--);//向左走
	for (; y + 1 < 20 && vs[x][y + 1] == val; count++, y++);//向右走
	return count >= 5 ? true : false;
}
bool Vertical(vector<string>& vs, int x, int y, char val)//竖
{
	int count = 1;
	int x1 = x;
	for (; x1 - 1 >= 0 && vs[x1 - 1][y] == val; count++, x1--);//向上走
	for (; x + 1 < 20 && vs[x + 1][y] == val; count++, x++);//向下走
	return count >= 5 ? true : false;
}

bool LeftOblique(vector<string>& vs, int x, int y, char val)//左斜
{
	int count = 1;
	int x1 = x, y1 = y;
	for (; x1 - 1 >= 0 && y1 - 1 >= 0 && vs[x1 - 1][y1 - 1] == val; count++, x1--, y1--);//斜左上走
	for (; x + 1 < 20 && y + 1 < 20 && vs[x + 1][y + 1] == val; count++, x++, y++);//斜左下走
	return count >= 5 ? true : false;
}

bool RightOblique(vector<string>& vs, int x, int y, char val)//右斜
{
	int count = 1;
	int x1 = x, y1 = y;
	for (; x1 - 1 >= 0 && y1 + 1 < 20 && vs[x1 - 1][y1 + 1] == val; count++, x1--, y1++);//斜右上走
	for (; x + 1 < 20 && y - 1 >= 0 && vs[x + 1][y - 1] == val; count++, x++, y--);//斜右下走
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
//				for (int k = 1; k < 5; k++)//同时往四个方向走四次,这四个方向没去过
//				{
//					if (j < 16 && v[i][j + k] == v[i][j])//右
//					{
//						right++;
//					}
//					if (i < 16 && j < 16 && v[i][j] == v[i + k][j + k])//右下
//					{
//						right_down++;
//					}
//					if (i < 16 && v[i + k][j] == v[i][j])//下
//					{
//						down++;
//					}
//					if (i > 3 && j < 16 && v[i - k][j + k] == v[i][j])//左下
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
