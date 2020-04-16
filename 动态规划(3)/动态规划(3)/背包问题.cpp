#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//��Ŀ����
//�� n ����Ʒ��һ����СΪ m �ı���.�������� A ��ʾÿ����Ʒ�Ĵ�С������ V ��ʾÿ����Ʒ�ļ�ֵ.
//�������װ�뱳�����ܼ�ֵ�Ƕ�� ?

/*
״̬��
F(i, j): ǰi����Ʒ�����СΪj�ı���������õ�����ֵ
״̬���ƣ����ڵ�i����Ʒ����һ�����⣬װ���£�����ѡ�񣬷Ż��߲���
���װ���£���ʱ�ļ�ֵ��ǰi-1���ļ�ֵ��һ����
F(i,j) = F(i-1,j)
�������װ�룺��Ҫ������ѡ����������
F(i, j) = max{F(i-1,j), F(i-1, j - A[i]) + V[i]}
F(i-1,j): ��ʾ���ѵ�i����Ʒ���뱳���У� �������ļ�ֵ����ǰi-1����Ʒ�����СΪj�ı���������ֵ
F(i-1, j - A[i]) + V[i]����ʾ�ѵ�i����Ʒ���뱳���У���ֵ����V[i],������Ҫ�ڳ�j - A[i]�Ĵ�С��
��i����Ʒ
��ʼ������0�к͵�0�ж�Ϊ0����ʾû��װ��Ʒʱ�ļ�ֵ��Ϊ0
F(0,j) = F(i,0) = 0
����ֵ��F(n,m)
*/
class Solution {
public:
	int backPackI(int m, vector<int> A, vector<int> V)
	{
		if (A.empty() || V.empty() || m < 1) {
			return 0;
		}
		//���һ��һ�У��������ó�ʼ����
		const int N = A.size() + 1;
		const int M = m + 1;
		vector<vector<int> > result;
		result.resize(N);
		//��ʼ������λ��Ϊ0����һ�к͵�һ�ж�Ϊ0����ʼ����
		for (int i = 0; i != N; ++i) {
			result[i].resize(M, 0);
		}
		for (int i = 1; i < N; ++i) {
			for (int j = 1; j != M; ++j) {
				//��i����Ʒ��A�ж�Ӧ������Ϊi-1: i��1��ʼ
				//�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ
				if (A[i - 1] > j) {
					result[i][j] = result[i - 1][j];
				}
				//�������װ�£������������װ���߲�װ
				//�����װ����Ϊ(i-1, j)
				//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i-1],װ��֮�������ֵ��Ϊ(i - 1, 
				j - A[i - 1]) + ��i����Ʒ�ļ�ֵV[i - 1]
					//�����װ�벻װ��ѡ�����ļ�ֵ
				else {
					int newValue = result[i - 1][j - A[i - 1]] + V[i - 1];
					result[i][j] = max(newValue, result[i - 1][j]);
				}
			}
		}
		//����װ��ǰN����Ʒ����Ʒ��СΪm������ֵ
		return result[N - 1][m];
	}

	/*
	�Ż��㷨��
	������㷨�ڼ����i��Ԫ��ʱ��ֻ�õ���i-1�е�Ԫ�أ����Զ�ά�Ŀռ�����Ż�Ϊһά�ռ�
	���������һά��������Ҫ�Ӻ���ǰ���㣬��Ϊ�����Ԫ�ظ�����Ҫ����ǰ���Ԫ��δ���£�ģ���ά�������һ�е�
	ֵ����ֵ
	*/


	int backPackII(int m, vector<int> A, vector<int> V) {
		if (A.empty() || V.empty() || m < 1) {
			return 0;
		}

		const int N = A.size();
		//���һ�У��������ó�ʼ��������Ϊ��һ����ƷҪ�õ�ǰ��ĳ�ʼֵ
		const int M = m + 1;
		vector<int> result;
		//��ʼ������λ��Ϊ0����һ�ж�Ϊ0����ʼ����
		result.resize(M, 0);
		//������Ʒ������λ�ò���Ҫƫ�ƣ�Ҫ��δ�Ż��ķ������ֿ�
		//�����i-1���Ϊ��һ�У�����δ���µ�һά����ֵ
		for (int i = 0; i != N; ++i) {
			for (int j = M - 1; j > 0; --j) {
				//�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ
				if (A[i] > j) {
					result[j] = result[j];
				}
				//�������װ�£������������װ���߲�װ
				//�����װ����Ϊ(i-1, j)
				//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i],װ��֮�������ֵ��Ϊ(i - 1, j 
				-A[i - 1]) + ��i����Ʒ�ļ�ֵV[i]
					//�����װ�벻װ��ѡ�����ļ�ֵ
				else {
					int newValue = result[j - A[i]] + V[i];
					result[j] = max(newValue, result[j]);
				}
			}
		}
		//����װ��ǰN����Ʒ����Ʒ��СΪm������ֵ
		return result[m];
	}
};
//};
//		class Solution {
//		public:
//			int backPackII(int m, vector<int> A, vector<int> V)
//			{
//				vector<int> retval(m, 0);
//				retval[0] = V[0];//�����ŵ�n����Ʒ�󱳰�����ļ�ֵ����һ����Ʒ��Ϊ����
//				int bagsize = m - A[0];//����ʣ���С
//
//				for (int i = 1; i < A.size(); i++)
//				{
//					if (A[i] > m)//��ȫװ���£���Ʒ��С���ڱ�������
//					{
//						break;
//					}
//					else
//					{
//						if (A[i] <= bagsize)//����ʣ���С��װ�´���Ʒ
//						{
//
//						}
//
//						else// ����ʣ���С��װ���´���Ʒ������һ�ε�
//						{
//
//						}
//					}
//				}
//			}
//		};
int main()
{
	system("pause");
	return 0;
}