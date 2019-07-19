#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k;
const int maxn = 10005;
const int inf = 1e9 + 5;
int a[maxn],b[maxn],l[maxn],r[maxn];
int f[maxn],g[maxn];
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		r[i] = m + 1;
	}
	while(k--)
	{
		int j;
		scanf("%d",&j);
		scanf("%d%d",&l[j],&r[j]);
	}
	int i = 1;
	for(;i <= n; ++i)
	{
		for(int j = 1;j <= m; ++j)
		{
			g[j] = f[j];
			f[j] = inf;
		}
		for(int j = 1;j <= m; ++j)
		{
			int x = min(m,j + a[i]);
			f[x] = min(f[x],min(g[j],f[j]) + 1);
		}
		for(int j = l[i] + 1;j < r[i]; ++j)
		{
			if(j + b[i] <= m)
			{
				f[j] = min(f[j],g[j + b[i]]);
			}
		}
		int q = 0;
		for(int j = 1;j <= m; ++j)
		{
			if(j <= l[i] || j >= r[i])
			{
				f[j] = inf;
			}
			q |= (f[j] < 1e8);
		}
		if(!q)
		{
			break;
		}
	}
	if(i > n)
	{
		int ans = inf;
		for(int j = 1;j <= m; ++j)
		{
			ans = min(ans,f[j]);
		}
		printf("1\n%d\n",ans);
	}
	else
	{
		int ans = 0;
		for(int j = 1;j < i; ++j)
		{
			if(r[j] <= m)
			{
				ans++;
			}
		}
		printf("0\n%d\n",ans);
	}
	return 0;
}