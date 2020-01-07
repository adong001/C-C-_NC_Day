#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<functional>
#include<cstdlib>
#include<map>
#include<set>
using namespace std;
typedef struct//����
{
	static int PartitionNum;//�������� 
	int m_PartitionId;//�����׵�����ַ
	int m_PartitionSize;//����
	int m_BlockId;//�հ׷����׵�ַ
}Partition;

typedef struct//���̿��ƿ�
{
	static int PCBNum;//��������
	string m_PidName;//��������
	int m_PidSize;//���̴�С
}PCB;

void ReadData();//��������
void Display1();
void Display_Partition();
void Display();//�������������������״̬
void Display_PCB();//��ʾ���̵�״̬
void FirstFit();//�״���Ӧ�㷨
void NextFit();//ѭ���״���Ӧ�㷨
void BestFit();//�����Ӧ�㷨
void WorstFit();//���Ӧ�㷨
