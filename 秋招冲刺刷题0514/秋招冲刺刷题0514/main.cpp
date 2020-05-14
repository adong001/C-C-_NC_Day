#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//1、链表题：一个链表的结点结构
typedef struct Node
{
	int data;
	Node *next;
	Node(int d, Node* n) :
		data(d),
		next(n)
	{}
} Node;
//
//合并两个已经递增排序不重复的单链表为一个排序的单链表，相同内容只保留一个
//如：单链表a : 1->2->3->4
//	 单链表b : 3->4->5
//			输出：1->2->3->4->5
//
void MergeList(Node* first, Node* second, Node* third)
{
	Node* tmp1 = first;
	Node* tmp2 = second;
	Node* cur = third;
	while (tmp1 != NULL && tmp2 != NULL)
	{
		if (tmp1->data < tmp2->data)
		{
			cur = new Node(tmp1->data, NULL);
			third
			tmp1 = tmp1->next;
		}
		else
		{
			cur = tmp2;
			tmp2 = tmp2->next;
		}
		cur = cur->next;
	}
	if (tmp2 == NULL)
	{
		cur = tmp1;
	}
	if (tmp1 == NULL)
	{
		cur = tmp2;
	}
}

int main()
{
	Node t4(4,NULL);
	Node t3(3, &t4);
	Node t2(2, &t3);
	Node t1(1, &t2);
	Node* first = &t1;

	Node n3(4, NULL);
	Node n2(3, &n3);
	Node n1(2, &n2);
	Node* second = &n1;
	
	Node* third = NULL;
	MergeList(first, second, third);
	delete[] third;
    return 0;
}