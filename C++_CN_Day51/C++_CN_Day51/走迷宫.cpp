#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>

int pso[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };//��������

void DFS(std::vector<std::string>& m, int x, int y, int count, int& min)
{
	if (x < 0 || y < 0 || x >= 10 || y >= 10 || m[x][y] == '#' || m[x][y] == '*'||count > min)//Խ�磬������(*)��ǽ(#)��
	{
		return;
	}
	if (x == 9 && y == 8)//�ﵽ�յ�
	{
		min = (min < count) ? min : count;//ȡ�µ�·����
		return;
	}
	count++;
	char tmp = m[x][y];
	m[x][y] = '*';//*��Ǵ������߳�ȥ���ٻ�������ɻ�·�ˣ�������������
	DFS(m, x + 1, y, count,min);
	DFS(m, x - 1, y, count,min);
	DFS(m, x, y + 1, count,min);
	DFS(m, x, y - 1, count,min);
	m[x][y] = tmp;//�������ߵ�·���Ѿ�����¼��·������ȡ������ı�ǣ���¼����·�����⾭��
}
int main()
{
	std::vector<std::string> maps(10);
	while (std::cin >> maps[0])
	{
		for (int i = 1; i < 10; i++)
		{
			std::cin >> maps[i];
		}
		int count = 0,min = INT_MAX;
		DFS(maps, 0, 1, count, min);
		std::cout << min << std::endl;
	}
    return 0;
}