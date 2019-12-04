#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
//#include<cstring>
using namespace std;
#define ENTER_X 0   //���λ��
#define ENTER_Y 0

typedef struct//����
{
	int x;
	int y;
}Point;

int N,M;//�Թ���С
vector<Point> BestPath;
vector<Point> Path;
bool flag = true;


void GetPath(vector<vector<int>> &v, int row, int col)
{
	
	Point p = { row, col };
	Path.push_back(p);
	v[row][col] = 1;   //�ܽ���������Ϊ����

	if (row == N - 1 && col == M - 1)//�������
	{
		if (flag)//��һ��·��
		{
			for (auto ip = Path.begin(); ip != Path.end(); ip++)
			{
				BestPath.push_back(*ip);
			}
			flag = false;
		}

		else//���ǵ�һ�����ж��Ƿ�Ϊ���
		{
			if (Path.size() < BestPath.size())
			{
				BestPath.clear();
				for (auto ip = Path.begin(); ip != Path.end(); ip++)
				{
					BestPath.push_back(*ip);
				}

			}
		}
	}

	if (col -1  > 0 && v[row][col - 1] == 0)//���������ĸ�λ�ô����ҿ��ߣ��������
	{
		GetPath(v, row, col - 1);
	}
	if (row - 1 > 0 && v[row - 1][col] == 0)
	{
		GetPath(v, row - 1, col);
	}

	if (row + 1 < N && v[row + 1][col] == 0)
	{
		GetPath(v, row + 1, col);
	}
	if (col + 1 < N && v[row][col + 1] == 0)
	{
		GetPath(v, row, col + 1);
	}

	Path.pop_back();//��·��ͨ��
	v[row][col] = 0;//������δ��

}

int main()
{
	/*int mz[10][10] = {
		{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 1, 1, 0, 0, 1, 0, 1 },
		{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	};

	for (int i = 0; i < N; i++)
	{
		v.push_back(vector<int>());
		for (int j = 0; j < N; j++)
		{
			v[i].push_back(mz[i][j]);
		}
	}*/
/*  0 0 1 1 1 1 1 1 1 1
	1 0 0 1 1 0 0 1 0 1
	1 0 0 1 0 0 0 1 0 1
	1 0 0 0 0 1 1 0 0 1
	1 0 1 1 1 0 0 0 0 1
	1 0 0 0 1 0 0 0 0 1
	1 0 1 0 0 0 1 0 0 1
	1 0 1 1 1 0 1 1 0 1
	1 1 0 0 0 0 0 0 0 0
	1 1 1 1 1 1 1 1 1 0*/
	int  tmp;
	vector<vector<int>> v;
	while (cin >> N >> M)
	{
		for (int i = 0; i < N; i++)
		{
			v.push_back(vector<int>());

			for (int j = 0; j < M; j++)
			{
				cin >> tmp;
				v[i].push_back(tmp);
			}
		}
		GetPath(v, ENTER_X, ENTER_Y);
		//vector<Point>::iterator ip;
		for (auto  ip = BestPath.begin(); ip != BestPath.end(); ip++)
		{
			cout << "(" << ip->x << "," << ip->y << ")" << endl;
		}
	}
	system("pause");
	return 0;
}