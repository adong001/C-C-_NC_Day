#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

int main()
{
	std::string src, det;
	int count = 0;
	while (std::cin >> src >> det)
	{
		int len1 = src.size();
		int len2 = det.size();
		int pos;
		for (int i = 0; i < len1;)
		{

			int j = 0;
			pos = i;//��¼i��ʼ��λ��
			while (src[i] == det[j] && i < len1 && j < len2)
			{
				i++;
				j++;
			}
			if (j == len2)//�ҵ���,i�ͻᵽ��һ�����ҵ�λ�ã��´�ѭ��jҲ����0
			{
				count++;
			}
			else//û�ҵ�
			{
				i = pos + 1;//i�ӿ�ʼ�ҵ���һ��λ����
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}