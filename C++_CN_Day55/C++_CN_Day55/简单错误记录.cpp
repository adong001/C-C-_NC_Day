#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Data
{
	string filename;
	int num;

	Data(string file)
	{
		filename = file;
		num = 1;
	}
	bool operator==(const Data& data)
		//把Data放在FileData中，find时需要重载==才能保证正确性
	{
		return filename == data.filename;
	}
};
int main()
{
	string FileDir;
	string ErrorLine;
	vector<Data> FileData;
	while (cin >> FileDir >> ErrorLine)
	{
		string tmp = FileDir.substr(FileDir.rfind("\\") + 1);//文件名
		if (tmp.size() > 16)
		{
			tmp.erase(tmp.begin(), tmp.end() - 16);//文件名长度超过16，只记录后16个字符
		}
		tmp = tmp + " " + ErrorLine;
		Data data(tmp);//构造一个文件错误信息对象

		auto it = find(FileData.begin(), FileData.end(), data);
		if (it == FileData.end())//没找到
		{
			FileData.push_back(data);
		}
		else//找到就给这个文件的次数++
		{
			it->num++;
		}
	}

	if (0 <= FileData.size() && FileData.size() <= 8)//长度再8以内
	{
		for (auto& e : FileData)
		{
			cout << e.filename << " " << e.num << endl;
		}
	}
	else//错误数条据超过8条，只输出后8位
	{
		for (auto it = FileData.end() - 8; it < FileData.end(); it++)
		{
			cout << it->filename << " " << it->num << endl;
		}
	}
	return 0;
}