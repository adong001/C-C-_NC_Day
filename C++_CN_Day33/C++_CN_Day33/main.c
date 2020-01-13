#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void ch(char** ar)
{
	ar[0] = "123";
	ar[1] = "234";
}

int main()
{
	char* ar[5] = { 0 };
	ch(ar);

    system("pause");
    return 0;
}