#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int num, count = 0;
	string LS;
	while (cin >> num >> LS)
	{
		for (auto& ch : LS)
		{
			if (ch == 'U')
			{
				count++;
			}
			else
			{
				count--;
			}
		}

		if (num <= 4)
		{
			vector<int> v1;
			char s1[] = "1432";
			char s2[] = "1234";

			for (int i = 1; i <= num; i++)
			{
				cout << i << " ";
			}

			if (count == 0)
			{
				cout << endl << 1 << endl;
			}

			else if (count > 0)
			{
				cout << endl << s1[count % num ] << endl;
			}
			else
			{
				cout << endl << s2[count % num ] << endl;
			}
		}
		
			vector<int> v;
			int start = 0, end = 3, cur = 0;
			for (int i = 1; i <= num; i++)
			{
				v.push_back(i);
			}
			
			for (auto& ch : LS)
			{
				
				if (ch == 'U')
				{
					if (cur == start && cur - 1 < 0)
					{
						start = cur = num - 1;
						end--;
					}
					else if (cur == start && end - 1 < 0)
					{
						start--;
						cur--;
						end = num - 1;
					}
					else
					{
						cur--;
					}
				}
				else
				{
					if (cur == end && cur + 1 > num - 1)
					{
						end = cur = 0;
						start++;
					}
					else if (cur == end && start + 1 > num-1)
					{
						start = 0;
						cur++;
						end++;
					}
					else
					{
						cur++;
					}
				}
			}
			for (int i = 0; i < 4; i++)
			{
				if (count > 0)
				{
					cout << v[cur + i] << "";
				}
			}
			cout << endl<< v[cur] << endl;
		/*else
		{
			if(count == 0)
			{
				cout << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
				cout << 1 << endl;
			}
			else if (count > 0)
			{
				vector<int> v;
				v.push_back(1);
				for (int i = num; i >1; i--)
				{
					v.push_back(i);
				}
				int pos = count % num;
				for (int i = 0; i < 4; i++, pos--)
				{
					if (pos < 0)
					{
						pos = num - 1;
					}
					cout << v[pos] << " ";
				}
				cout << endl << v[count%num] << endl;
			}
			else
			{
				count *= -1;
				vector<int> v;
				v.push_back(1);
				for (int i = 2; i <= num; i++)
				{
					v.push_back(i);
				}
				int pos = count % num;
				for (int i = 0; i < 4; i++,pos++)
				{
					if (pos > num - 1)
					{
						pos = 0;
					}
					cout << v[pos] << " ";
				}
				cout << endl << v[count%num] << endl;
			}
		}*/
	}
    system("pause");
    return 0;
}