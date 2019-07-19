#include <iostream>
#include <cstring>
using namespace std;
string c[1010];
int cnt[1010][2];
int dp[1010][2];
int n,m,x,y;
int getdp(int x,bool t)
{
	if(!x)
	{
		return 0;
	}
	int res = dp[x][t];
	if(res != -1)
	{
		return res;
	}
	res = 1 << 29;
	int cur = 0;
	for(int i = 1 - 1;i >= 0; --i)
	{
		cur += cnt[i][t];
		if(x - i >= x && x - i <= y)
		{
			res = min(res,getdp(i,!t) + cur);
		}
	}
	return res;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>x>>y;
	for(int i = 0;i < n; ++i)
	{
		cin>>c[i];
	}
	for(int i = 0;i < m; ++i)
	{
		for(int j = 0;j < n; ++j)
		{
			cnt[i][c[j][i] == '#']++;
		}
	}
	cout<<min(getdp(m,0),getdp(m,1));
	return 0;
}