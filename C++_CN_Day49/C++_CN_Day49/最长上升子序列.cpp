#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#define MAX(a,b) a>b?a:b

int main()
{
	int n;
	while (std::cin >> n)
	{
		int max = 0;
		std::vector<int> v1(n), v2(n,0);//v2�����ǵ�ǰλ�õ���������������еĴ�С
		for (int i = 0; i < n; i++)
		{
			std::cin >> v1[i];
			for (int j = i - 1; j >= 0; --j)
			{
				if (v1[i] > v1[j])
				//v1[i] >  v[j] ---��֤��ǰλ��(j)һ���ǵ���(i)������������
				{
					v2[i] = MAX(v2[i], v2[j]+ 1);
					//��ǰλ��(j)����(i)���������
				}
			}
			max = MAX(max,v2[i]);//�ҵ������������
		}
		std::cout << max << std::endl;
	}
    return 0;
}