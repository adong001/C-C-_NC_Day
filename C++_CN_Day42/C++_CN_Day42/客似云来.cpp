#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

long long arr[100000];
int main2()
{
	arr[0] = 0, arr[1] = 1;
	int begin, end;
	while (std::cin >> begin >> end)
	{
		long long count = 0;
		for (int i = 2; i <= end; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		for (int i = begin; i <= end; i++)
		{
			count += arr[i];
		}
		std::cout << count << std::endl;
	}

	return 0;
}