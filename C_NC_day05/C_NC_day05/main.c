#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//1.完成猜数字游戏。
//
//int main()
//{
//	while (1)
//	{
//		srand((unsigned )time(NULL));
//		int num = rand()%100;
//		int n;
//		
//		while (1)
//		{ 
//			system("cls");
//		    scanf("%d", &n);
//			if (n > num)
//			{
//				printf("猜大了！\n");
//				continue;
//			}
//			else if (n < num)
//			{
//				printf("猜小了！\n");
//				continue;
//			}
//			else
//			{
//				printf("恭喜你，猜对了！\n");
//				break;
//			}
//		}
//
//	}
//	system("pause");
//	return 0;
//}
//2.写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）
//
//int FindValue(int ar[], int n, int value)
//{
//	int left = 0;
//	int right = n - 1;
//	int mid = (left + right) / 2;
//	while (left <= right)
//	{
//		if (ar[mid] == value)
//		{
//			return mid;
//		}
//		else if (ar[mid] > value)
//		{
//			right = mid - 1;
//			mid = (left + right) / 2;
//		}
//		else
//		{
//			left = mid + 1;
//			mid = (left + right) / 2;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int value;
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int n = SIZEOF(ar);
//	while (1)
//	{
//		scanf("%d", &value);
//		printf("%d\n", FindValue(ar, n, value));
//	}
//	system("pause");
//	return 0;
//}
//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。
//int main()
//{
//	char ch[] = "123456";
//	char str[20];
//	int count = 0;
//	printf("********欢迎来到天地银行********\n\n");
//	printf("请输入您的密码：\n");
//	while (1)
//	{
//		gets(str);
//		if (0 == strcmp(ch, str))
//		{
//			printf("*******密码正确*******\n\n但你是个穷逼！！！\n\n账户余额为空\n");
//			system("pause"); 
//			return 0;
//		}
//		else
//		{
//			count++;
//			if (count == 3)
//			{
//				printf("密码错误！\n输入次数已用完，账户已冻结！\n");
//				system("pause");
//				return 0;
//			}
//			else printf("密码错误！请您重新输入：\n");
//		}
//	}
//	return 0;
//}

//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
int main()
{
	char ch;
	while (ch = getchar())
	 {
        if (ch >= 'a'&&ch <= 'z')
		{
			ch -= 32;
			putchar(ch);
		}
		else if (ch >= 'A'&&ch <= 'Z')
		{
			ch += 32;
			putchar(ch);
		}
	}
    system("pause");
    return 0;
}