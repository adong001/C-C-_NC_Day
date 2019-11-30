#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class A
{
private:
public:
	static int a;
};

int A::a = 0;

int main()
{
	int num;
	string LS;
	while (cin >> num >> LS)
	{
		int start = 1, cur = 1;
		if (num <= 4)
		{
			
			for (auto& ch : LS)
			{
				if (ch == 'U')
				{
					if (cur == 1)
					{
						cur = num;
					}
					else
					{
						cur--;
					}
				}
				else
				{
					if (cur == num)
					{
						cur = 1;
					}
					else
					{
						cur++;
					}
				}
			}
			int i;
			for (i = 1; i < num; i++)
			{
				cout << i << " ";
			}
			cout << num << endl;
			cout << cur << endl;
		}

		else
		{
			for (auto& ch : LS)
			{

				if (ch == 'U')
				{
					if (cur == start)
					{
						if (cur == 1)
						{
							start = num - 3;
							cur = num;
						}
						else
						{
							cur--;
							start--;
						}
					}
					else
					{
						cur--;
					}

				}
				else
				{
					if (cur == num  && start == num - 3)
					{
						cur = 1;
						start = 1;
					}
					else if (start != num - 3 && cur == start + 3)
					{
						cur++;
						start++;
					}
					else
					{
						cur++;
					}
				}
			}
			for (int i = 0; i < 3; i++)
			{
				cout << i + start << " ";

			}
			cout << start + 3 << endl;
			cout  << cur << endl;
		}
	}
	system("pause");
	return 0;
}