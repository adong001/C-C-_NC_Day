#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>

int pso[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };//右左下上

void DFS(std::vector<std::string>& m, int x, int y, int count, int& min)
{
	if (x < 0 || y < 0 || x >= 10 || y >= 10 || m[x][y] == '#' || m[x][y] == '*'||count > min)//越界，相对起点(*)，墙(#)，
	{
		return;
	}
	if (x == 9 && y == 8)//达到终点
	{
		min = (min < count) ? min : count;//取下的路径数
		return;
	}
	count++;
	char tmp = m[x][y];
	m[x][y] = '*';//*标记从这里走出去，再回来就造成回路了，不能让走这里
	DFS(m, x + 1, y, count,min);
	DFS(m, x - 1, y, count,min);
	DFS(m, x, y + 1, count,min);
	DFS(m, x, y - 1, count,min);
	m[x][y] = tmp;//从这里走的路径已经被记录完路径数，取消这里的标记，记录其他路径从这经过
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