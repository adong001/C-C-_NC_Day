#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
//int main()
//{
//	int tmp;
//	std::vector<int> v;
//	std::list<int> l;
//	std::vector<int> res;
//	while (std::cin >> tmp)
//	{
//		v.resize(tmp);
//		for (int i = 0; i < tmp; i++)
//		{
//			l.push_front(tmp - i);
//			std::cin >> v[i];
//		}
//
//		for (int i = 1; i <= tmp; i++)
//		{
//			std::cout << i << " " << l.front() << std::endl;
//			res.push_back(v[i - 1]);
//			if (v[i - 1] == l.front())	
//			{
//				for (auto& e : res)
//				{
//					auto it = find(l.begin(), l.end(), e);
//					l.erase(it);
//				}
//				res.clear();
//			}
//		}
//	}
//
//
//    return 0;
//}
int main()
{
	int n, Min = 1, k = 1;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;//小堆
	while (std::cin >> n)
	{
		std::vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> v[i];
			q.push(v[i]);
			if (v[i] == Min)//找到当前最小
			{
				while (!q.empty() && q.top() == Min)
				{
					std::cout << k++ << " " << v[i] << std::endl;
					Min++;
					q.pop();//将最小的以后的都pop
				}
			}
		}

	}
	return 0;
}