#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
int main2()
{
	int tmp,cur;
	while (scanf("%d", &tmp) != EOF)
	{
		cur = tmp;
		int fn_0 = 0, fn_1 = 1, fn_2 = 2;
		while (tmp--)
		{
			fn_0 = fn_1 %= 1000000;
			fn_1 = fn_2 %= 1000000;
			fn_2 = fn_0 + fn_1;
		}
		if (cur >= 30)
		{
			printf("%06d", fn_0);
		}
		else
		{
			printf("%d", fn_0);
		}
	}
	return 0;
}
