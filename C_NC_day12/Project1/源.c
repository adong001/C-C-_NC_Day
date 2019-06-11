#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
//
//
//unsigned int reverse_bit(unsigned int value)//10进制逆序
//{
//	int ret = 0;
//	int sum = 0;
//	while (value)
//	{
//		ret = value % 10;
//		sum = sum * 10 + ret;
//		value /= 10;
//	}
//	return sum;
//}
//unsigned int reverse_bit(unsigned int value)
//{
//	int ret = 0;
//	int sum = 0;
//	for (int i = 0; i < 32; i++,value /= 2)
//	{//00000000000000000000000000011001
//		ret = value % 2;
//		sum = sum * 2+ ret;   
//	}
//
//	return sum;
//}
//int main()
//{
//	printf("%u\n",reverse_bit(25));
//	system("pause");
//	return 0;
//}
//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//
//int average(int num1, int num2)
//{
//	return (num1 / 2 + num2 / 2 );
//}
//int average(int num1,int num2)
//{
//	return ((num1 >> 1) + (num2 >> 1));
//}
//int main()
//{
//
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	printf("average=%d\n",average(n, m));
//	system("pause");
//	return 0;
//}
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//
//
//int Find_one(int array[], int n)
//{
//	//任何数自本身与本身异或为0,任何数与0异或为本身
//	// 2   0010
//	// 3   0011
//	// 2^2 = 0000   = 0
//	// 2^3 = 0001   = 1
//	// 2^3^2 = 0011 = 3 
//	// 2^3^3 = 0010 = 2
//	int ret = 0;
//	for (int i = 0; i < n ; i++)
//	{
//		ret ^= array[i];
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	int ar[] = { 11, 22, 33, 44, 55, 44, 33, 22, 11 };
//	n = sizeof(ar) / sizeof(ar[0]);
//	printf("one is %d\n", Find_one(ar, n));
//	system("pause");
//	return 0;
//}
//4.
//有一个字符数组的内容为:"student a am i",
//			请你将数组的内容改为"i am a student".
//			要求：
//			不能使用库函数。
//			只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//			student a am i
//			i ma a tneduts
//			i am a student
//
//
//void reverse_word(char *src)  //翻转一句话中的每一个字母
//{
//	//			student a am i
//	//-》    	i ma a tneduts
//	char *str = src;
//	char *ptr = src;
//	while (*ptr != '\0')
//	{
//		ptr++;
//	}
//	ptr--; //ptr移到\0上一个位置
//	while (ptr >= str)
//	{
//		char temp = *ptr;
//		*ptr = *str;
//		*str = temp;
//		ptr--;
//		str++;
//	}
//}
//
//void reverse_letter(char* src)//翻转每个单词中每个字母
//{   //   i ma a tneduts
//	//-> i am a student
//	char *ptr = src;
//	char *str = src;      
//	while (*str != ' ')
//	{	
//		if (*str == '\0')  //若找到一句话中最后一个单词，翻转后，返回
//	  {
//		reverse_word(ptr);
//		return;
//	  }
//		str++;
//	}
//	*str = '\0';   //找到每个单词与单词之间的间隔' '后先将其置为'\0'用第一个函数翻转最后在改成' '
//	str++;
//	reverse_word(ptr);
//	*(str - 1) = ' ';
//	reverse_letter(str); //一个单词翻转完后，找到下一个单词开头进行递归
//}
//
//int main()
//{
//	char str[] = "student a am i";
//	reverse_word(str);
//	puts(str);
//	reverse_letter(str);
//	puts(str);
//	system("pause");
//	return 0;
//
//}

//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
// 原型 0000  0000  1011 1110  1111 0001  1101 0001
//奇数位0 0   0 0   1 1  1 1   1 1  0 0   1 0  0 0
//偶数位 0 0   0 0   0 1  1 0   1 1  0 1   1 1  0 1                              
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	printf("偶数位:");
//	for (int i = 30; i >=0; i-=2)     //偶数位
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("奇数位:");
//	for (int i = 31; i > 0; i -= 2)     //奇数位
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	system("pause");
//	return 0;
//}
//3. 输出一个整数的每一位。
//

//void print_everybit_qq(int value)  //正序打印
//{
//	if (value > 9)
//	{
//		print_everybit_qq(value / 10);
//	}
//	printf("%d ", value % 10);
//}
//void print_everybit_ww(int value) //逆序打印
//{  
//	printf("%d ", value % 10);
//	if (value > 9)
//	{
//		print_everybit_ww(value / 10);
//	}
//}
//int main()
//{
//	print_everybit_qq(1234);
//	print_everybit_ww(1234);
//	system("pause");
//	return 0;
//}
////4.编程实现：
////两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
////输入例子 :
////1999 2299
////输出例子 : 7
////
//int count_cmp_bits(int value1,int value2)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (((value1 >> i) & 1)!=((value2 >> i) & 1))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//
//int main()
//{
//	printf("%d\n", count_cmp_bits(128,127));
//	printf("%d\n", count_cmp_bits(1999,2299));
//	system("pause");
//	return 0;
//}
//int main()
//{
//
//
//	system("pause");
//	return 0;
//}


//库函数查找四大金刚
//strchr(str, find)
//strrchr(str, find);
//strstr(src, find)
//strpbrk(src, find);

