#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//һ�����������б�Ų�ͬ���򣬴�����ͬ��ŵ���
//ʹ�ô��������������ĺ���ʹ������к���֮����������Ӿ������˴���
//ͨ���Ƴ������е���ʹ���Ϊ���˴��ӣ������Ƴ�0����n-1��
//���� ��ĸ��� �� ������ı��
//��� ���Բ������˴��ӵĸ���

bool IsLuck(vector<int>& v)
{
	int sum = 0;
	int mul = 1;
	for (auto& vs : v)
	{
		sum += vs;
		mul *= vs;
	}
	if (sum > mul)
	{
		return true;
	}
	return false;
}

int FindLuck(vector<int>& v)
{
	static int count = 0;
	int n = v.size();
	if (n < 2)//ֻʣһ��ʱ������0,
	{
		return 0;
	}
	for (int i = 0; i < n; i++)//ɾ������
	{
		vector<int> tmp ;
		for (int j = 0; j < n - i; j++)//ѭ��ɾ���Ĵ�������ɾ���ĸ���5
		{
			for (int k = j; k < )
			{
				tmp.push_back(v[k]);
			}
		}
		if (IsLuck(v))
		{
			count++;
		}
	}
}

int main()
{
	vector<int> v;
	int n;
	cin >> n;

	if (n < 2)
	{
		return 0;
	}

	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	cout << FindLuck(v) << endl;
    system("pause");
    return 0;
}