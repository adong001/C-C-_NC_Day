#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//
//
//unsigned int reverse_bit(unsigned int value)//10��������
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
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
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
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//
//
//int Find_one(int array[], int n)
//{
//	//�κ����Ա����뱾�����Ϊ0,�κ�����0���Ϊ����
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
//��һ���ַ����������Ϊ:"student a am i",
//			���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����
//			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//			student a am i
//			i ma a tneduts
//			i am a student
//
//
//void reverse_word(char *src)  //��תһ�仰�е�ÿһ����ĸ
//{
//	//			student a am i
//	//-��    	i ma a tneduts
//	char *str = src;
//	char *ptr = src;
//	while (*ptr != '\0')
//	{
//		ptr++;
//	}
//	ptr--; //ptr�Ƶ�\0��һ��λ��
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
//void reverse_letter(char* src)//��תÿ��������ÿ����ĸ
//{   //   i ma a tneduts
//	//-> i am a student
//	char *ptr = src;
//	char *str = src;      
//	while (*str != ' ')
//	{	
//		if (*str == '\0')  //���ҵ�һ�仰�����һ�����ʣ���ת�󣬷���
//	  {
//		reverse_word(ptr);
//		return;
//	  }
//		str++;
//	}
//	*str = '\0';   //�ҵ�ÿ�������뵥��֮��ļ��' '���Ƚ�����Ϊ'\0'�õ�һ��������ת����ڸĳ�' '
//	str++;
//	reverse_word(ptr);
//	*(str - 1) = ' ';
//	reverse_letter(str); //һ�����ʷ�ת����ҵ���һ�����ʿ�ͷ���еݹ�
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

//2.��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�
// ԭ�� 0000  0000  1011 1110  1111 0001  1101 0001
//����λ0 0   0 0   1 1  1 1   1 1  0 0   1 0  0 0
//ż��λ 0 0   0 0   0 1  1 0   1 1  0 1   1 1  0 1                              
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	printf("ż��λ:");
//	for (int i = 30; i >=0; i-=2)     //ż��λ
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	printf("\n");
//	printf("����λ:");
//	for (int i = 31; i > 0; i -= 2)     //����λ
//	{
//		printf("%d ", (num >> i) & 1);
//	}
//	system("pause");
//	return 0;
//}
//3. ���һ��������ÿһλ��
//

//void print_everybit_qq(int value)  //�����ӡ
//{
//	if (value > 9)
//	{
//		print_everybit_qq(value / 10);
//	}
//	printf("%d ", value % 10);
//}
//void print_everybit_ww(int value) //�����ӡ
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
////4.���ʵ�֣�
////����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
////�������� :
////1999 2299
////������� : 7
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


//�⺯�������Ĵ���
//strchr(str, find)
//strrchr(str, find);
//strstr(src, find)
//strpbrk(src, find);

