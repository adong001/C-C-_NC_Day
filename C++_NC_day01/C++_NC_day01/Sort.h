#pragma once

#include<iostream>
using namespace std;

void Swap(int *a, int *b);

void Print(int *ar, int n);

void Print(float *ar, int n);

void Sort(int *ar,int n);

void Sort(float *ar, int n);

void Test1();

void Sort2(int *ar, int size, int flag );//缺省参数只能在声明和定义缺省一次

void InsertSort(int *ar, int size);//直接插入排序

void ShellSort(int *ar,int size);//希尔排序

void MergeSort(int *ar,int size);//归并排序
void DealMergeSort(int *ar, int *tmp, int start, int end);//归并排序需要开辟新的空间，做一个处理函数封装起来
//
void QuickSort(int *ar,int size);//快速排序
void DealQuickSort(int *ar, int start, int end);//处理
int HoareSort(int *ar, int start, int end);//hoare法

void Test2();


void DealStructSort(void **p, int size);
void Test3();