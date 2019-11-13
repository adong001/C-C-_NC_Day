#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main1()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
	{
		e.resize(h, 1);
	}
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;// ��ǲ��ܷŵ����λ��     
				if ((i + 2) < w)
				{
					a[i + 2][j] = 0;
				}
				if ((j + 2) < h)
				{
					a[i][j + 2] = 0;
				}
			}
		}
	}
	cout << res;
	return 0;
}
int main22()//O(1)�㷨
{
	int W, H;
	cin >> W >> H;
	int x = W;
	int y = H;
	x = (x % 4 == 0 ? 0 : (4 - (x % 4)));//��Ҫ��չ����������
	y = (y % 4 == 0 ? 0 : (4 - (y % 4)));
	int xx = x + W;//��չ����ݺ����꣬Ϊ4�ı���
	int yy = y + H;
	int block = (xx * yy) / 2;//����ĸ�����Ϊ�ݺ�����˻���һ�㣬�ȼ�ȥ��չ���ǲ��֣���������չ�غϵĲ���
	block -= (x * yy + y * xx) / 2;
	if (x == 0 || y == 0)//û����չ�������ȥ�ص�����
	{
		//do nothing
	}

	else if (x <= 2 && y <= 2)//x y = (1,2)
	{
		block += x * y;
	}
	else if (x == 1 && y == 3 || x == 3 && y == 1)//x y =(1,3)
	{
		block += 2;
	}

	else if (x == 3 && y == 3)
	{
		block += 5;
	}

	else//x==2/3 && y==3/2
	{
		block += 4;
	}
	cout << block << endl;
	system("pause");
	return 0;
}