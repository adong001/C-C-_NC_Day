#define _CRT_SECURE_NO_WARNINGS 1
//给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。
//比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，
//员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，
//因此没有体现在员工1的数据结构中。
//现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。
//
//示例 1:
//输入 : [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
//输出 : 11
//解释 :
//	员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
//注意 :
//	 一个员工最多有一个直系领导，但是可以有多个直系下属
//	员工数量不超过2000。
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Employee 
{
public:
	int id;
	int importance;
	vector<int> subordinates;
};

class Solution 
{
public:
	int getImportance(vector<Employee*> employees, int id) 
	{
		int Size = employees.size();
		if (Size <= 0 || id <= 0)//先判断员工人数，如果为0则不用找直接返回0
		{
			return 0;
		}
		int i;
		for (i = 0; i < Size; i++)//找到要求的员工的下属id的位置
		{
			if (employees[i]->id == id)//找到就break
			{
				break;
			}
		}
		if (i >= Size)//没找到
		{
			return 0;
		}
		map<int, Employee*> mp;//做map自动排序，将id小的放在前面，id越小说明等级越高
		for (auto& e : employees)
		{
			mp.insert(pair<int, Employee*>(e->id, e));
		}
		int count = 0;
		queue<int> q;
		q.push(id);//将要遍历的员工id的push进去
		for (; !q.empty();)
		{
			count += mp[q.front()]->importance;//每层序遍历累加自己和下属的重要度
			for (auto& e : mp[q.front()]->subordinates)//将下属id入队
			{
				q.push(e);
			}
			q.pop();//将自己出队，
		}
		return count;
	}
};

int main()
{
	return 0;

}