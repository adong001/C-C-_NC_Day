#include"mahjong.h"
#include"data.h"
#include"goods.h"


//const char FindOnceFirstString(const char *src)
//{
//	if (!*src)
//	{
//		return NULL;
//	}
//	const char *tmp = src;
//	int arr[256] = { 0 };
//	while (*tmp)
//	{
//		arr[(int)*tmp] += 1;//���ַ�תΪint����Ϊ������±꣬����ֵ+1����Ϊ����ַ����ֵĴ���
//		tmp++;
//	}
//	tmp = src;
//	while (*tmp)
//	{
//		if (arr[(int)*tmp] == 1)
//		{
//			return *tmp;
//		}
//		tmp++;
//	}
//}
//char FindFirstRepeatString(char* src)
//{
//	if (!*src)
//	{
//		return NULL;
//	}
//	const char *tmp = src;
//	int arr[256] = { 0 };
//	while (*tmp)
//	{
//		arr[(int)*tmp] += 1;//���ַ�תΪint����Ϊ������±꣬����ֵ+1����Ϊ����ַ����ֵĴ���
//		tmp++;
//	}
//	tmp = src;
//	while (*tmp)
//	{
//		if (arr[(int)*tmp] == 2)
//		{
//			return *tmp;
//		}
//		tmp++;
//	}
//}

int main()
{
	//char ar[] = "ashjkqwertyuiozxcvbnmlkjhgfdrtyuzxcv";
	///*printf("%c",FindOnceFirstString(ar));*/
	//printf("%c\n", FindFirstRepeatString(ar));
	//const int i = 0;
	//printf("%d\n", &i);
	//int *j = (int*)&i;
	//*j = 1;
	//printf("%d,%d ,%d\n", i,&i, *j);
	Data d1(2018,11,19,500);
	//BossMenu();

	
	system("pause");
	return 0;
}