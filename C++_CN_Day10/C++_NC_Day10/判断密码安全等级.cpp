#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
һ������       dgsayd$%12
5 �� : С�ڵ���4 ���ַ�
10 �� : 5 ��7 �ַ�
25 �� : ���ڵ���8 ���ַ�

������ĸ :
0 �� : û����ĸ
10 �� : ȫ����С����д��ĸ
20 �� : ��Сд�����ĸ

�������� :
0 �� : û������
10 �� : 1 ������
20 �� : ����1 ������

�ġ����� :
0 �� : û�з���
10 �� : 1 ������
25 �� : ����1 ������

�塢���� :
2 �� : ��ĸ������
3 �� : ��ĸ�����ֺͷ���
5 �� : ��Сд��ĸ�����ֺͷ���

�����������ֱ�׼ :
���ڵ���90 : �ǳ���ȫ
���ڵ���80 : ��ȫ
���ڵ���70 : �ǳ�ǿ
���ڵ���60 : ǿ
���ڵ���50 : һ��
���ڵ���25 : ��
���ڵ���0 : �ǳ���

��Ӧ���Ϊ��
VERY_WEAK,
WEAK,
AVERAGE,
STRONG,
VERY_STRONG,
SECURE,
VERY_SECURE

�������� :
	����һ���Զ�������
������� :
	�����Ӧ��ȫ�ȼ�

ʾ��1
����
	dgsayd$ % 12
���
	SECURE
*/
#include<iostream>
#include<string>
using namespace std;

int JudgeLength(string& src)
{
/*  5 �� : С�ڵ���4 ���ַ�
	10 �� : 5 ��7 �ַ�
	5 �� : ���ڵ���8 ���ַ�*/
	int length = src.size();
	if (length <= 4)
	{
		return 5;
	}
	else if (5 <= length && length <= 7)
	{
		return 10;
	}
	else
	{
		return 25;
	}
}
int JudgeLetter(string& src)
{
	//0 �� : û����ĸ
	//10 �� : ȫ����С����д��ĸ
	//20 �� : ��Сд�����ĸ
	int nums = 0;
	int caps = 0;
	int lowers = 0;
	for (auto& ch : src)
	{

		if(islower(ch))
		{
			lowers++;
		}
		else if (isupper(ch))
		{
			caps++;
		}
	}
	if ((lowers + caps) == 0)
	{
		return 0;
	}

	else if (lowers == 0 || caps == 0)
	{
		return 10;
	}

	else if (lowers != 0 && caps != 0)
	{
		return 20;
	}
}


int JudgeNum(string& src)
{
//	0 �� : û������
//	10 �� : 1 ������
//	20 �� : ����1 ������
	int nums = 0;
	for (auto& ch : src)
	{
		if (isdigit(ch))
		{
			nums++;
		}
	}
	if (nums == 0)
	{
		return 0;
	}

	else if (nums == 1)
	{
		return 10;
	}

	else if (nums > 1)
	{
		return 20;
	}
}


int JudgeSign(string& src)
{
//	0 �� : û�з���
//	10 �� : 1 ������
//	25 �� : ����1 ������
	int signs = 0;
	for (auto& ch : src)
	{
		if (!isalpha(ch) && !isdigit(ch))
		{
			signs++;
		}	
	}
	if (signs == 0)
	{
		return 0;
	}
	else if (signs == 1)
	{
		return 10;
	}
	else if (signs > 1)
	{
		return 25;
	}
}

int JudgeAward(string& src)
{
//	2 �� : ��ĸ������
//	3 �� : ��ĸ�����ֺͷ���
//	5 �� : ��Сд��ĸ�����ֺͷ���
	int award = 0;
	int lowers = 0;
	int caps = 0;
	int nums = 0;
	int signs = 0;
	for (auto& ch : src)
	{
		if (islower(ch))
		{
			lowers++;
		}
		else if(isupper(ch))
		{
			caps++;
		}

		else if (isdigit(ch))
		{
			nums++;
		}

		else if (!isalpha(ch) && !isdigit(ch))
		{
			signs++;
		}
	}

	if (signs == 0)
	{
		return 2;
	}

	else if (nums != 0 && (lowers + caps) != 0 && signs != 0)
	{
		return 3;
	}
	else if (nums != 0 && lowers != 0 && caps != 0 && signs != 0)
	{
		return 5;
	}
}

void Judge(string& src)
{
	int score = JudgeNum(src) + JudgeLength(src) + JudgeLetter(src) + JudgeSign(src) + JudgeAward(src);
	cout << "num ="<< JudgeNum(src) << endl;
	cout << "length =" << JudgeLength(src) << endl;
	cout << "letter =" << JudgeLetter(src) << endl;
	cout << "sign =" << JudgeSign(src) << endl;
	cout << "award =" << JudgeAward(src) << endl;

	if (score >= 90)
	{
		cout << "VERY_SECURE" << endl;
	}
	else if (score >= 80)
	{
		cout << "SECURE" << endl;
	}

	else if (score >= 70)
	{
		cout << "VERY_STRONG" << endl;
	}
	else if (score >= 60)
	{
		cout << "STRONG" << endl;
	}
	else if (score >= 50)
	{
		cout << "AVERAGE" << endl;
	}
	else if (score >= 25)
	{
		cout << "WEAK" << endl;
	}
	else if (score >= 0)
	{
		cout << "VERY_WEAK" << endl;
	}
}

int main()
{
	string src;
	cin >> src;
	Judge(src);
    system("pause");
    return 0;
}