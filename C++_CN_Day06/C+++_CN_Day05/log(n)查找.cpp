#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Finder {
public:

	int BinaryFind(vector<int>& A, int x)
	{
		//数据：5, 6, 1, 2, 3, 4,(5, 6)  //后面的5和6是虚拟的，只在坐标转换时使用，访问其值时模size得到真实坐标
		//坐标：0, 1，2，3, 4，5,(6，7)
		int pos = FindMutantPos(A);
		int size = A.size();
		int right = pos + size - 1;//right = 7
		int left = pos;            //left = 1  //相当于在二分查找
		int mid; 
		while (left<= right)
		{
			mid = (left  + right) / 2;
			if (A[mid % size] == x)//配对时用模的方法找到实际的坐标  1,2,3,4,模size还是自己真实的坐标，5,6模size就得到了0和1，真实坐标
			{  
				return mid % size;
			}
			else if (A[mid % size] > x)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return -1;
	}


	int FindMutantPos(vector<int>& A)//找数组的中突变点，例如{5，6, 1, 2, 3, 4}突变点为1，返回1的坐标2
	{
		int size = A.size();
		int left = 0;
		int right = size - 1;
		int mid = (left + right) / 2;
		while (mid != right && mid != left)
		{
			if (A[mid] > A[left])
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
			mid = (left + right) / 2;
		}
		return (mid == size-1) ? 0 : mid + 1;
	}

	int FindElement(vector<int> A, int x)
	{
		if (A.empty())
		{
			return -1;
		}
		return BinaryFind(A, x);
	}

};
int main2()
{//  6 9 11 45 1 4
	Finder test;
	vector<int> v = { 5, 6, 1, 2, 3, 4 };
	cout<<test.FindElement(v, 6)<<endl;
    system("pause");
    return 0;
}