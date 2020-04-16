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
		//��Data����FileData�У�findʱ��Ҫ����==���ܱ�֤��ȷ��
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
		string tmp = FileDir.substr(FileDir.rfind("\\") + 1);//�ļ���
		if (tmp.size() > 16)
		{
			tmp.erase(tmp.begin(), tmp.end() - 16);//�ļ������ȳ���16��ֻ��¼��16���ַ�
		}
		tmp = tmp + " " + ErrorLine;
		Data data(tmp);//����һ���ļ�������Ϣ����

		auto it = find(FileData.begin(), FileData.end(), data);
		if (it == FileData.end())//û�ҵ�
		{
			FileData.push_back(data);
		}
		else//�ҵ��͸�����ļ��Ĵ���++
		{
			it->num++;
		}
	}

	if (0 <= FileData.size() && FileData.size() <= 8)//������8����
	{
		for (auto& e : FileData)
		{
			cout << e.filename << " " << e.num << endl;
		}
	}
	else//���������ݳ���8����ֻ�����8λ
	{
		for (auto it = FileData.end() - 8; it < FileData.end(); it++)
		{
			cout << it->filename << " " << it->num << endl;
		}
	}
	return 0;
}