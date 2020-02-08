#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL)
	{}

};

class Solution
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> retval;
		queue<TreeNode*> qt;
		TreeNode* tmp = root;
		int length = 1;
		int count = 0;//��¼ÿһ��ĸ���
		if (!root)
		{
			return retval;
		}

		qt.push(tmp);
		while (!qt.empty())
		{
			for (int i = 0; i < length; i++)//���ϲ������Ԫ�ص����Һ��Ӷ����
			{
				tmp = qt.front();
				if (i + 1 == length)//���һ�������������һ��Ԫ��
				{
					retval.push_back(tmp->val);
				}
				qt.pop();
				if (tmp->left)
				{
					qt.push(tmp->left);
					count++;
				}
				if (tmp->right)
				{
					qt.push(tmp->right);
					count++;
				}
			}
			length = count;
			count = 0;
		}
		return retval;
	}
};
int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* lroot = new TreeNode(2);
	TreeNode* rroot = new TreeNode(3);
	root->left = lroot;
	root->right = rroot;
	TreeNode* lrroot = new TreeNode(5);
	TreeNode* rrroot = new TreeNode(4);
	lroot->right = lrroot;
	rroot->right = rrroot;

	vector<int> v = s.rightSideView(root);
	system("pause");
	return 0;
}