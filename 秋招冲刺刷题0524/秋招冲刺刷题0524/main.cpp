#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define offsetof(TYPE,MEMBER) ((size_t)&((TYPE*)0)->MEMBER)

int main3()
{
	//int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };    
	//int *ptr1 = (int *)(&aa + 1);     
	//int *ptr2 = (int *)(*(aa + 1));    
	//printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));

	struct Test { 
		int Num;  //0
		char *pcName; //4
		short sDate;  //8
		char cha[20];  //10
		short sBa[3]; };
		Test t;
		printf("%d\n", offsetof(Test, Num));
		printf("%d\n", offsetof(Test, pcName));
		printf("%d\n", offsetof(Test, sDate));
		printf("%d\n", offsetof(Test, cha));
		printf("%d\n", offsetof(Test, sBa));
		Test* p = &t;
	//假设p 的值为0x100000。如下表表达式的值分别为多少？
		printf("%p\n", p);
		printf("%p\n", p + 0x1);  
		printf("%p\n", (unsigned long)p + 0x1); 
		printf("%p\n", (unsigned int*)p + 0x1); 
		return 0;
	 /*int a[5] = { 1, 2, 3, 4, 5 };     
	 int *ptr = (int *)(&a + 1);   
	 printf("%d,%d", *(a + 1), *(ptr - 1));*/
	//int a[] = { 1, 2, 3, 4 };

	//printf("%d\n", sizeof(a));//16
	//printf("%d\n", sizeof(a+0));//4
	//printf("%d\n", sizeof(*a));//4
	//printf("%d\n", sizeof(a+1));//4
	//printf("%d\n", sizeof(a[1]));//4
	//printf("%d\n", sizeof(&a));//4
	//printf("%d\n", sizeof(*&a));//4
	//printf("%d\n", sizeof(&a + 1));//4
	//printf("%d\n", sizeof(&a[0]));//4
	//printf("%d\n", sizeof(&a[0] + 1));//4


	/*char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr + 0));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(&arr[0] + 1));
	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr + 0));
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));
	char arr[] = "abcdef";
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr + 0));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(&arr + 1));*/
	/*short a = 0xff00;
	char* b = (char*)&a;
	if (*b == 0xff)
	{
		cout << "大端" << endl;
	}
	else
	{
		cout << "小端" << endl;
	}
	union un
	{
		char a;
		short b;
	};
	un u;
	u.b = 0xff00;
	
	if (u.a == 0xff)
	{
		cout << "大端" << endl;
	}
	else
	{
		cout << "小端" << endl;
	}*/
    return 0;
}