#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<priority_queue>
#include<algorithm>

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
	int tmp;
	priority_queue<int, vector<int>> q;
	return 0;
}