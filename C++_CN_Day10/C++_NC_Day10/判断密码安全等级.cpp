#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
一、长度       dgsayd$%12
5 分 : 小于等于4 个字符
10 分 : 5 到7 字符
25 分 : 大于等于8 个字符

二、字母 :
0 分 : 没有字母
10 分 : 全都是小（大）写字母
20 分 : 大小写混合字母

三、数字 :
0 分 : 没有数字
10 分 : 1 个数字
20 分 : 大于1 个数字

四、符号 :
0 分 : 没有符号
10 分 : 1 个符号
25 分 : 大于1 个符号

五、奖励 :
2 分 : 字母和数字
3 分 : 字母、数字和符号
5 分 : 大小写字母、数字和符号

六、最后的评分标准 :
大于等于90 : 非常安全
大于等于80 : 安全
大于等于70 : 非常强
大于等于60 : 强
大于等于50 : 一般
大于等于25 : 弱
大于等于0 : 非常弱

对应输出为：
VERY_WEAK,
WEAK,
AVERAGE,
STRONG,
VERY_STRONG,
SECURE,
VERY_SECURE

输入描述 :
	输入一个自定义密码
输出描述 :
	输出对应安全等级

示例1
输入
	dgsayd$ % 12
输出
	SECURE
*/
#include<iostream>
#include<string>
using namespace std;

int JudgeLength(string& src)
{
/*  5 分 : 小于等于4 个字符
	10 分 : 5 到7 字符
	5 分 : 大于等于8 个字符*/
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
	//0 分 : 没有字母
	//10 分 : 全都是小（大）写字母
	//20 分 : 大小写混合字母
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
//	0 分 : 没有数字
//	10 分 : 1 个数字
//	20 分 : 大于1 个数字
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
//	0 分 : 没有符号
//	10 分 : 1 个符号
//	25 分 : 大于1 个符号
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
//	2 分 : 字母和数字
//	3 分 : 字母、数字和符号
//	5 分 : 大小写字母、数字和符号
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