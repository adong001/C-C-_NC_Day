#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

bool IsBroWord(std::string src, std::string det)
{
	if (src.size() == det.size())
	{
		if (src == det)//��ͬ�Ĳ���
		{
			return false;
		}
		sort(src.begin(), src.end());
		sort(det.begin(), det.end());
		if (src == det)
		{
			return true;
		}
		return false;
	}
	return false;
	//int len1 = src.size();
	//int len2 = det.size();
	//if (len1 != len2)
	//{
	//	return false;
	//}
	//std::map<char,int> m;
	////first��¼src�Ƿ���det���ҹ���second��¼�ϴ��ҵ���λ�ã�����´�Ҫ�������ĸ�ʹ��ϴμ�¼���¸�λ�ÿ�ʼ��
	//int pos;
	//for (int i = 0; i < len1; i++)
	//{
	//	if (m.find(src[i]) != m.end())//�����ĸ֮ǰ�ҹ���
	//	{
	//		if ((pos = (det.find(src[i], m[src[i]] + 1))) != std::string::npos)//���ϴ��ҵ������ĸ����һ��λ�ÿ�ʼ��
	//		{
	//			m[src[i]] = pos;
	//		}
	//		else//û�ҵ�
	//		{
	//			return false;
	//		}
	//	}
	//	else//�����ĸ֮ǰû�ҹ�
	//	{
	//		if ((pos = (det.find(src[i]))) != std::string::npos)//��ͷ��ʼ��
	//		{
	//			m[src[i]] = pos ;
	//		}
	//		else//�ҵ�
	//		{
	//			return false;
	//		}
	//	}
	//}
	//return true;

}


int main1()
{
	int n;
	while (std::cin >> n)
	{

		std::string src;
		std::vector<std::string> tmp;
		int num;
		std::vector<std::string> vs(n);
		for (int i = 0; i < n; i++)
		{
			std::cin >> vs[i];
		}
		std::cin >> src >> num;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (IsBroWord(src, vs[i]))
			{
				count++;
				tmp.push_back(vs[i]);
			}
		}
		std::cout << count << " " << std::endl;;
		num = num<tmp.size() ? num : tmp.size();
		if (count >0)
		{
			for (int i = 0; i < num; i++)
			{
				std::cout << tmp[i] << " ";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}