#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int sum[6000],dp[6000];
#define INF (1 << 29)
int main()
{
	string s;
	int m;
	cin>>m;
	cin.ignore();
	getline(cin,s);
	int prev = -2;
	for(int i = 0;i < s.size(); ++i)
	{
		if(s[i] == '.' || s[i] == '?' || s[i] == '!')
		{
			v.push_back(i - prev - 1);
			prev = i;
		}
	}
	for(int i = 0;i < v.size(); ++i)
	{
		sum[i + 1] = sum[i] + v[i];
	}
	for(int i = 0;i <= v.size(); ++i)
	{
		dp[i] = INF;
	}
	dp[0] = 0;
	for(int i = 1;i <= v.size() ;++i)
	{
		for(int j = 0;j < i; ++j)
		{
			if(sum[i] - sum[j] + (i - j - 1) <= m)
			{
				dp[i] = min(dp[i],dp[j] + 1);
			}
		}
	}
	if(dp[v.size()] == INF)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%d\n",dp[v.size()]);
	}
	return 0;
}