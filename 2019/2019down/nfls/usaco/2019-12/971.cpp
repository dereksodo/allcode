#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int c[30][30];
int dp[maxn],sum[30][maxn],mx[maxn];
char s[maxn];
int query(int x,int l,int r)
{
	return sum[x][r] - sum[x][l - 1];
}
int main()
{
	freopen("cowmbat.in","r",stdin);
	freopen("cowmbat.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	scanf("%s",s + 1);
	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			scanf("%d",&c[i][j]);
		}
	}
	for(int l = 0;l < m; ++l)
	{
		for(int i = 0;i < m; ++i)
		{
			for(int j = 0;j < m; ++j)
			{
				if(i != j & j != l && i != l)
				{
					c[i][j] = min(c[i][j],c[i][l] + c[l][j]);
				}
			}
		}
	}
	for(int i = 0;i < m; ++i)
	{
		for(int j = 1;j <= n; ++j)
		{
			sum[i][j] = c[s[j] - 'a'][i] + sum[i][j - 1];
		}
	}
	memset(mx,0x3f3f3f3f,sizeof(mx));
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0] = 0;
	for(int i = k;i <= n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			mx[j] = min(mx[j] + c[s[i] - 'a'][j],dp[i - k] + query(j,i - k + 1,i));
			dp[i] = min(dp[i],mx[j]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}