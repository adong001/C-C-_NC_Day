#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��


void DeleteString_C(char* src, const char* dest)
{
	if (!src||!dest)
	{
		return;
	}
	char* ip1,*tmp = src;
	const char* ip2;
	for (ip2 = dest; *ip2; ip2++,tmp = src)//����dest��������src�в���ɾ��
	{
		while(*tmp)//�ҵ���һ��Ҫɾ��λ��
		{
			if (*tmp != *ip2)
			{
				tmp++;
			}
			else
			{
				break;
			}
		}

		if (*tmp)//���Ҫɾ���ַ���src��û�оͲ�ɾ��������һ��forѭ������һ��Ҫɾ���ַ�
		{
			for (ip1 = tmp++; *tmp; ip1++, tmp++)//��ip1=tmp++��tmpҪ����ip1��������������һ��λ��
			{
				while (*tmp == *ip2)
			    //ֱ���ҵ�����ɾ���Ǹ��ַ����磺src = "haaat",dest="a";
				//��Ҫ�ҵ���t��Ϊֹ;
				{
					tmp++;
				}
				*ip1 = *tmp;//��������ַ��Ƶ�ǰ�棻
			}
			*ip1 = '\0';//��Ϊtmp��'\0'λ�������ˣ�û�и�ip1����һ��λ�ø��ַ���������
		}
		
	}
}


template<class T>
void DeleteString_CPP(T src,const T dest)
{
	string src_str(src);
	string dest_str(dest);
	if (src_str.empty() || dest_str.empty())
	{
		return;
	}
	int pos;
	string::iterator ip1; 
	string::iterator src_begin = src_str.begin();//ѭ���ڶ�ε���end����������ֱ����һ����������������ջ����
	string::const_iterator ip2 = dest_str.begin();
	string::const_iterator dest_end = dest_str.end();//ѭ���ڶ�ε���end����������ֱ����һ����������������ջ����
	for (; ip2 != dest_end; ip2++)
	{
		do
		{
			pos = src_str.find(*ip2);//�ҵ�dest��һ���ַ���src�е�λ�÷���(�Ҳ�������-1)

			if (pos >= 0)//�ҵ���
			{
				ip1 = src_begin + pos;//ip1��¼Ҫɾ���ַ���λ�õĵ�����
				src_str.erase(ip1);
			}

		}while (pos >= 0);//src����������ظ��Ĵ�ɾ�ַ���ʹ��whileѭ��ɾ�����Ҳ���Ϊֹ(pos = -1)
	}
	strcpy(src, src_str.c_str());
}


void DeleteSameString()
{
	string src;
	string dest;
	getline(cin, src);
	getline(cin, dest);
	char str[256] = {};
	string tmp;
	if (src.empty() || dest.empty())
	{
		return;
	}
	int i;
	for (i = 0; i < dest.size(); i++)
	{
		str[dest[i]]++;
	}

	for (i = 0; i < src.size(); i++)
	{
		if (str[src[i]] == 0)
		{
			tmp += src[i];
		}
	}
	cout << tmp << endl;

}



int main2()
{
	//
	DeleteSameString();
    system("pause");
    return 0;
}