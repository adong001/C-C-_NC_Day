#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>

//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
int fib(int n)
{
	int ret;
	while (n > 2)
	{
		ret = fib(n - 1) + fib(n - 2);
	}
	return 1;
}
int main()
{
	printf("%d\n", fib(3));
	system("pause");
	return 0;
}
//
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
//int main()
//{
//    system("pause");
//    return 0;
//}
//
//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//
//int main()
//{
//    system("pause");
//    return 0;
//}
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//
//int main()
//{
//    system("pause");
//    return 0;
//}
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//int main()
//{
//    system("pause");
//    return 0;
//}
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//int main()
//{
//    system("pause");
//    return 0;
//}
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
//int main()
//{
//    system("pause");
//    return 0;
//}