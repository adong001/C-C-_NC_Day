#include<iostream>
using namespace std;

//1���ֱ�ʹ�����úͺ���ɽ���������ʹ�������������������ͬ
#define SWAP1(a,b)   {a=a^b;b=a^b;a=a^b;}
#define SWAP2(a,b)   {a+=b;b=a-b; a=a-b;}
inline void Swap(int &a, int&b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//2������ָ���ĺ�����������ɺ�����
//a����һ���ַ���ת��Ϊ���֣�����ֵ����У��ת���Ƿ�ɹ�
// qwdq2 /a/b/t  **-21232we
bool strtoi(const char * src, int &ret)
{
	int tmp, sum = 0;
	int flag = 1;
	while (*src <= 32)//�ܿ����ɴ�ӡ�ַ�
	{
		src++;
	}

	if (*src == '-')//�и��ţ���ǩ��¼
	{
		flag = -flag;
		src++;
	}


	if (*src<'0' || *src >'9')//��������������ַ�ֱ���˳�
	{
		return false;
	}

	while (*src >= '0'&& *src <= '9' && *src)//��������ת��Ϊ���ִ���sum
	{
		tmp = *src - '0';
		sum = sum * 10 + tmp;
		src++;
	}
	ret = flag * sum;
	return true;
}


//b����һ������ͨ��ָ�����ư�λ����ֱ�Ӹ���ԭ����
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