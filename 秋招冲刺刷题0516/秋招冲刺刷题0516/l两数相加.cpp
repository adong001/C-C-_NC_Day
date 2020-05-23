#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，
//并且它们的每个节点只能存储 一位 数字。如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807


 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) 
	 {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int carry = 0,tmp,v2;
		ListNode* cur = l1;
		ListNode* pre = cur;
		while (cur != NULL || l2 != NULL || carry != 0)
		{
			if (cur == NULL)
			{
				cur = new ListNode(0);
				pre->next = cur;
			}
			if (l2 == NULL)
			{
				l2 = new ListNode(0);
			}
			tmp = (cur->val + l2->val) + carry;
			carry = tmp / 10;
			cur->val = tmp % 10;
			pre = cur;
			cur = cur->next;
			l2 = l2->next;
		}
		return l1;
	}
};
int main()
{
	Solution s;
	ListNode* l1 = new ListNode(5);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(4);
	l2->next->next = new ListNode(8);
	ListNode* tmp = s.addTwoNumbers(l1, l2);
    return 0;
}