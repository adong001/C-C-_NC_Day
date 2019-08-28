#include<iostream>
using namespace std;

//1、分别使用引用和宏完成交换方法（使用内联），体会两者异同
#define SWAP1(a,b)   {a=a^b;b=a^b;a=a^b;}
#define SWAP2(a,b)   {a+=b;b=a-b; a=a-b;}
inline void Swap(int &a, int&b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//2、按照指定的函数声明，完成函数：
//a、将一个字符串转换为数字，返回值用来校验转换是否成功
// qwdq2 /a/b/t  **-21232we
bool strtoi(const char * src, int &ret)
{
	int tmp, sum = 0;
	int flag = 1;
	while (*src <= 32)//避开不可打印字符
	{
		src++;
	}

	if (*src == '-')//有负号，标签记录
	{
		flag = -flag;
		src++;
	}


	if (*src<'0' || *src >'9')//出现数字以外的字符直接退出
	{
		return false;
	}

	while (*src >= '0'&& *src <= '9' && *src)//出现数字转化为数字存入sum
	{
		tmp = *src - '0';
		sum = sum * 10 + tmp;
		src++;
	}
	ret = flag * sum;
	return true;
}


//b、将一个数字通过指定进制按位逆序（直接覆盖原数）
void sysReverse(int &num, int hex) 				
{
	int sum = 0;
	int tmp, i;	
	for (; num; num /= hex) 
	{                          
		tmp = num%hex;
		sum = sum*hex + tmp;
	}
	num = sum;
}

int main()
{
	int ret = 100;
	sysReverse(ret, 2);
	cout << ret << endl;
	/*int res= 1, booll;
	char ar1[] = " *  \n\a\b ***";
	char ar2[] = "   \n\a\b -9876***";
	char ar3[] = "  \n\a\b212188*433 ***";
	booll = strtoi(ar1, res);
	cout << res << "  " << booll << endl;
	booll = strtoi(ar2, res);
	cout << res << "  " << booll << endl;
	booll = strtoi(ar3, res);
	cout << res << "  " << booll << endl;*/
	system("pause");
	return 0;
}