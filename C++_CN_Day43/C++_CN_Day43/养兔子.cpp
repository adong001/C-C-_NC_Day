#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//int arr[91] = {1};
//int main()
//{
//	int tmp;
//	while (std::cin >> tmp)
//	{
//		arr[1] = 1, arr[2] = 2;
//		int i = 1;
//		for (i = 2; i <= tmp;i++)
//		{
//			arr[i] = arr[i - 1] + arr[i - 2];
//		}
//		std::cout << arr[tmp] << std::endl;
//	}
//    return 0;
//}

int main2()
{
	int tmp;
	while (std::cin >> tmp)
	{
		long f0 = 1,f1 = 1, f2 = 2;
		while (tmp--)
		{
			f0 = f1;
			f1 = f2;
			f2 = f1 + f0;
		}
		std::cout << f0 << std::endl;
	}
	return 0;
}