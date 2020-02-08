#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//给定一组字符，使用原地算法将其压缩。压缩后的长度必须始终小于或等于原数组长度。
//数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
//在完成原地修改输入数组后，返回数组的新长度。
//
//进阶：
//你能否仅使用O(1) 空间解决问题？
//
//示例 1：
//输入：
//["a", "a", "b", "b", "c", "c", "c"]
//输出：
//返回6，输入数组的前6个字符应该是：["a", "2", "b", "2", "c", "3"]
//说明：
//"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。

//示例 2：
//输入：
//["a"]
//输出：
//返回1，输入数组的前1个字符应该是：["a"]
//说明：
//没有任何字符串被替代。

//示例 3：
//输入：
//["a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b"]
//输出：
//返回4，输入数组的前4个字符应该是：["a", "b", "1", "2"]。
//说明：
//由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
//注意每个数字在数组中都有它自己的位置。

//注意：
//所有字符都有一个ASCII值在[35, 126]区间内。
//1 <= len(chars) <= 1000。


class Solution {
public:
	int compress(vector<char>& chars) 
	{
		char tmp = chars[0];
		int count = 1;
		int len = chars.size();
		int i;
		int flag = 1;
		int pos = 0;
		for (i = 0; i < len; )
		{
			tmp = chars[i];
			while (i < len && chars[i] == tmp)
			{
				count++;
				i++;
			}
			if (count > 1)//若这个字符需要被压缩则count>1
			{

				chars[pos] = tmp;//pos记录的是新的数组的下标,pos位置覆盖tmp字符，
				if (count > 9)//若某个字符的长度大于9，则需要分解
				{
					string str;
					int res = 0;
					while (count)//将其长度先转换为字符
					{
						str.push_back(count % 10 + '0');
						count /= 10;
					}
					reverse(str.begin(), str.end());
					for (auto& ch : str)//在覆盖到chars的对应位置
					{
						chars[++pos] = ch;
					}
				}
				else
				{
					chars[++pos] = count + '0';//pos+1位置覆盖tmp字符的长度
				}
				++pos;
				count = 0;//这个字符记录完毕，count置1，继续记录下一个
				flag = pos;//这个flag目的是防止数组中只有一个数据时,外层循环进不来，
				           //就把唯一的元素删掉了，而且还返回0
			}
			
		}
		chars.erase(chars.begin() + pos, chars.end());
		//删除时删pos位置以后的数据，不管进不进外层循环，都能保证正确删除
		return flag;
	}
};
int main222()
{

	Solution s;
	vector<char> ss{ 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	cout << s.compress(ss);
    system("pause");
    return 0;
}