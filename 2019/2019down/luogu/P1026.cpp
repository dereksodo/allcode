#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
string a[10];
int dp[205][50],sum[205][205];
string s,t;
int m,n;
int check(int l,int r)
{
	string x = t.substr(l,r - l + 1);
	for(int i = 1;i <= n; ++i)
	{
		if(x.find(a[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int p,k;
	cin>>p>>k;
	t = " ";
	for(int i = 1;i <= p; ++i)
	{
		cin>>s;
		t += s;
	}
	cin>>n;
	m = t.size() - 1;
	for(int i = 1;i <= n; ++i)
	{
		cin>>a[i];
	}
	for(int i = m;i >= 1; --i)
	{
		for(int j = i;j >= 1; --j)
		{
			sum[j][i] = sum[j + 1][i];
			if(check(j,i))
			{
				sum[j][i]++;
			}
		}
	}
	dp[0][0] = 0;
	for(int i = 1;i <= k; ++i)
	{
		dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
	}
	for(int i = 1;i <= m; ++i)
	{
		dp[i][1] = sum[1][i];
	}
	for(int i = 1;i <= m; ++i)
	{
		for(int j = 1;j <= k && j < i; ++j)
		{
			for(int l = j;l < i; ++l)
			{
				dp[i][j] = max(dp[i][j],dp[l][j - 1] + sum[l + 1][i]);
			}
		}
	}
	printf("%d\n",dp[m][k]);
	return 0;
}