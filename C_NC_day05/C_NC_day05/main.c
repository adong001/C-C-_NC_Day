#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//1.��ɲ�������Ϸ��
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
//				printf("�´��ˣ�\n");
//				continue;
//			}
//			else if (n < num)
//			{
//				printf("��С�ˣ�\n");
//				continue;
//			}
//			else
//			{
//				printf("��ϲ�㣬�¶��ˣ�\n");
//				break;
//			}
//		}
//
//	}
//	system("pause");
//	return 0;
//}
//2.д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
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
//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����
//int main()
//{
//	char ch[] = "123456";
//	char str[20];
//	int count = 0;
//	printf("********��ӭ�����������********\n\n");
//	printf("�������������룺\n");
//	while (1)
//	{
//		gets(str);
//		if (0 == strcmp(ch, str))
//		{
//			printf("*******������ȷ*******\n\n�����Ǹ���ƣ�����\n\n�˻����Ϊ��\n");
//			system("pause"); 
//			return 0;
//		}
//		else
//		{
//			count++;
//			if (count == 3)
//			{
//				printf("�������\n������������꣬�˻��Ѷ��ᣡ\n");
//				system("pause");
//				return 0;
//			}
//			else printf("������������������룺\n");
//		}
//	}
//	return 0;
//}

//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
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