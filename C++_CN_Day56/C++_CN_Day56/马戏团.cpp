#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool cmp1(pair<int, int> m1, pair<int, int> m2)
{
	return m1.first >= m2.first;
}
bool cmp2(pair<int, int> m1, pair<int, int> m2)
{
	return m1.first <= m2.first;
}

int main()
{
	int n;
	while (cin >> n)
	{
		unordered_map<int, int> m1;//存取正数(包括0);
		unordered_map<int, int> m2;//存取负数;
		int k, d, tmp, Max, mul;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			if (tmp >= 0)
			{
				m1[tmp] = i;
			}
			else
			{
				m2[tmp] = i;
			}
		}
		cin >> k >> d;

		sort(m1.begin(), m1.end(),cmp1);
		sort(m1.begin(), m1.end(),cmp2);
		if (k == 0)
		{
			cout << 0 << endl;
		}
		else if(k == 1)//乘数为偶数，可以由正负数交叉完成
		{
			cout << m1.begin()->first << endl;
		}
		else
		{

		}
	}
    return 0;
}


链接：https://www.nowcoder.com/questionTerminal/661c49118ca241909add3a11c96408c8
来源：牛客网

#include <stdio.h>
inline long long max(long long a, long long b){ return (a>b ? a : b); }
inline long long min(long long a, long long b){ return (a>b ? b : a); }

int main(){
	int N, K, D, i, j, k;
	long long stu[51], fm[11][51], fn[11][51], ans;
	while (~scanf("%d", &N)){
		for (i = 0; i<N; scanf("%lld", &stu[++i]));
		scanf("%d %d", &K, &D);
		for (i = 0; i <= K; ++i)
		for (j = 0; j <= N; fm[i][j] = fn[i][j] = 0, ++j);
		for (i = 1, ans = ~0LL; i <= N; ++i){
			fm[1][i] = fn[1][i] = stu[i];
			for (k = 2; k <= K; ++k){
				for (j = i - 1; j>0 && i - j <= D; --j){
					fm[k][i] = max(fm[k][i], max(fm[k - 1][j] * stu[i], fn[k - 1][j] * stu[i]));
					fn[k][i] = min(fn[k][i], min(fn[k - 1][j] * stu[i], fm[k - 1][j] * stu[i]));
				}
			}
			ans = max(ans, fm[K][i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		int k, d;
		cin >> k >> d;
		vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));
		vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));
		for (int i = 0; i < n; i++){
			dp_max[i][1] = a[i];
			dp_min[i][1] = a[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = 2; j <= k; j++){
				for (int m = max(0, i - d); m <= i - 1; m++){
					dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
					dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
				}
			}
		}
		long long max_value = dp_max[k - 1][k];
		for (int i = k; i < n; i++){
			max_value = max(max_value, dp_max[i][k]);
		}
		cout << max_value << endl;
	}
	return 0;
}