#pragma once

#include<iostream>
using namespace std;

void Swap(int *a, int *b);

void Print(int *ar, int n);

void Print(float *ar, int n);

void Sort(int *ar,int n);

void Sort(float *ar, int n);

void Test1();

void Sort2(int *ar, int size, int flag );//ȱʡ����ֻ���������Ͷ���ȱʡһ��

void InsertSort(int *ar, int size);//ֱ�Ӳ�������

void ShellSort(int *ar,int size);//ϣ������

void MergeSort(int *ar,int size);//�鲢����
void DealMergeSort(int *ar, int *tmp, int start, int end);//�鲢������Ҫ�����µĿռ䣬��һ����������װ����
//
void QuickSort(int *ar,int size);//��������
void DealQuickSort(int *ar, int start, int end);//����
int HoareSort(int *ar, int start, int end);//hoare��

void Test2();


void DealStructSort(void **p, int size);
void Test3();