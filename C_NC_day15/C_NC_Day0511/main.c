#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


//int  main()
//{
//	int a = 20;
//	int b = 10;
//	int *p = &a;
//	printf("%p\n", p);
//	p = &b;
//	printf("%p\n", p);
//	system("pause");
//	return 0;
//	char ptr[10] = "ABCDE";//}
//void swap1(int x, int y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//void swap2(int *x, int *y)
//{
//	int *tmp = x;
//	x = y;
//	y = tmp;
//}
//void swap3(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap1(a, b);
//	printf("a=%d b=%d\n", a, b);
//	swap2(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	swap3(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char a[] = { 1, 1, 1, 1 };
//	int *p = (int*)a; //*p的值为p向后偏移sizeof(int)个字节中间的得到的数值
//	printf("%d\n", *p);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//int ar[3][4];
//	//printf("%d %d %d\n", ar, ar[0],&ar[0][0]);
//	//printf("%d %d %d\n", ar, ar + 1, &ar[1]);
//	int ar[] = { 1, 2, 3, 4, 5 };
//	int *p = (int *)(&ar + 1);//&ar+1表示先取a的地址，再加一个sizeof(ar)的长度；
//	printf("%d\n", *(p - 1));
//	system("pause");
//	return 0;
//}
//void Sort1(int *ar, int n)
//{
//	int *q, *p,*end =ar+n-1,tmp;
//	for (p = ar; p < ar+n-1; p++)
//	{
//		for (q = ar; q < end; q++)
//		{
//			if (*q > *(q + 1))
//			{
//				tmp = *q;
//				*q = *(q+1);
//				*(q+1) = tmp;
//			}
//		}
//		end--;
//	}
//}
//void Sort(int *ar, int n)
//{ 
//	int temp;
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (ar[j] < ar[j + 1])
//			{
//				temp = ar[j];
//				ar[j] = ar[j + 1];
//				ar[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int ar[] = { 5, 2, 3, 4, 1 };
//	int n = SIZEOF(ar);	
//	int *p = ar;
//	Sort1(ar, n);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ",ar[i]);
//	}
//	printf("\n");
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", *(ar+i));
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	printf("\n");
//	for (p = ar; p < ar + n;++p)  //效率最高
//	{
//		printf("%d ", *(p));
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char a[]="123";
//	char b[] = "123";
//	const char c[] = "123";
//	const char d[] = "123";
//	char *q = "123";
//	char *p = "123";
//	const char *pp = "123";
//	const char *qq = "123";
//	if (a == b)
//	{
//		printf("a==b\n");
//	}
//	if (c == d)
//	{
//		printf("c==d\n");
//	}	if (p == q)
//	{
//		printf("q==p\n");
//	}
//	if (qq ==pp)
//	{
//	   printf("qq==pp\n");
//	}
//	if (p==qq)
//	{
//		printf("p==qq\n");
//	}
//	system("pasue");
//	return 0;
//}





//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB 
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//char* Left_Reverse(char str[], int n)
//{
//
//	//int len = strlen(str);
//	//int pos = len - n % len;
//	//reverse(str, 0, pos - 1);
//	//reverse(str, pos, len - 1);
//	//reverse(str, 0, len - 1);
//	int m = strlen(str);
//	//char tmp[20];
//	char *p;
//	if (m < n||n == 0)  //判断旋转个数是否超过字符串所能旋转的长度
//	{
//		return;
//	}
//	p = &str[n];  //让 p指向要左旋的第一个元素
//	for (int i = 0; i < n; ++i,++m)
//	{
//		str[m] = str[i];
//	}
//	str[m] = '\0';
//	return p;
//}
//int main()
//{
//	char str[20];
//	int n;
//	printf("请输入要处理的字符串：");
//	gets(str);
//	printf("请输入左旋的个数：");
//	scanf("%d", &n);
//	puts(Left_Reverse(str, n));
//	system("pause");
//	return 0;
//}

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.


//int Is_Reverse(char str1[], char str2[])
//{
//	int n = strlen(str1);
//	int m = strlen(str2);
//	if (m != n)
//	{
//		return 0;
//	}
//	if (strcmp(str1, str2) == 0)
//	{
//		return 1;
//	}
//	char *p = str2;
//	for (int i = 0; i < n; p++, ++i)
//	{
//		if (strcmp(str1, Left_Reverse(p, 1)) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	while (1)
//	{
//		char str1[20], str2[20];
//		gets(str1);
//		gets(str2);
//		printf("%d\n", Is_Reverse(str1, str2));
//	}
//	system("pause");
//	return 0;
//}

//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。

//void Find_Once(int ar[], int n)
//{
//	int tmp = 0;  // 得到两个出现一次的数字的异或值
//	int pos = 0;  // 记录数组中数的二进制位第一个为一的位置
//	int x = 0;     
//	int y = 0;    
//	for (int i = 0; i < n; i++)
//	{
//		tmp ^= ar[i];   //得到5^6的值   
//	}
//	for (int i = 0; i < 32; i++)
//	{
//		if ((tmp >> i) & 1 == 1) //第pos位为1说明那两个数二进制的那一位不同
//		{
//			pos = i;
//			break;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{   //将第pos位区分开来，为1的自然是出现过两次的数和那俩个唯一的数中的一个,
//		//为0的自然也是另外出现过两次的数和那俩个唯一的数中的l另一个
//		if ((ar[i] >> pos) & 1 == 1)
//		{
//			x ^= ar[i];//将pos位为1的全部异或消去相等的就得到了那个单独的数
//		}
//		else//同理,将pos位为0的全部异或消去相等的就得到了那个单独的数
//		{
//			y ^= ar[i];
//		}
//	}
//	printf("%d  %d\n", x, y);
//}
//int main()
//{
//	int ar[10] = { 1, 2, 3, 4, 5, 6, 4, 3, 2, 1 };
//	int n = SIZEOF(ar);
//	Find_Once(ar, n);
//	system("pause");
//	return 0;
//}
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
//
//int main()
//{
//	while (1)
//	{
//		int money = 0;
//		int count = 0;
//		printf("请输入购买金额：");
//		scanf("%d", &money);
//		while (money > 1)
//		{
//			count += (money/2)*2 ;
//			money = (money / 2) + money % 2;
//		}
//		//由运行结果可知：count=2*money-1;
//		printf("你可以喝%d瓶饮料\n", count + 1);
//	}
//	system("pause");
//	return 0;
//}
//
//
//3.模拟实现strcpy
//
//char* My_strcpy(char* str, const char* soure)
//{
//
//	char *ptr = str;
//	assert(ptr !=NULL && soure!=NULL);
//	while (*ptr++ = *soure++);
//	return str;
//}
//int main()
//{
//	char str[10];
//	char ptr[5] = "ab";
//	char ch[5] = "cd";
//	My_strcpy(str, ptr);
//	puts(str);
//	My_strcpy(str, My_strcpy(ptr, ch));
//	puts(str);
//	system("pause");
//	return 0;
//}
//4.模拟实现strcat
//
char* My_strcat(char* str, const char* soure)
{
	char *ptr = str;
	assert(str != NULL || soure != NULL);
    while (*ptr!= '\0')++ptr; //ptr 指向'\0'的位置上；
	while ((*ptr++ = *soure++));
	return str;
}
int main()
{
	char str[30] = "I am";
	char ptr[20] = " a student";
	char ch[] = " too ！";
	My_strcat(str, My_strcat(ptr,ch));
	puts(str);
	system("pause");
	return 0;
}







