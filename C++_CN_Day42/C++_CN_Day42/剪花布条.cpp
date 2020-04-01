#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

int main()
{
	std::string src, det;
	int count = 0;
	while (std::cin >> src >> det)
	{
		int len1 = src.size();
		int len2 = det.size();
		int pos;
		for (int i = 0; i < len1;)
		{

			int j = 0;
			pos = i;//记录i开始的位置
			while (src[i] == det[j] && i < len1 && j < len2)
			{
				i++;
				j++;
			}
			if (j == len2)//找到了,i就会到下一个待找到位置，下次循环j也会置0
			{
				count++;
			}
			else//没找到
			{
				i = pos + 1;//i从开始找的下一个位置找
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}