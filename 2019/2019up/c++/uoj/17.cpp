#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k;
const int maxn = 10005;
const int inf = 1e9 + 5;
int a[maxn],b[maxn];//
int l[maxn],r[maxn];//
int f[maxn],g[maxn];
//从x开始，f[x]为到达最小值
//g[maxn]为上一次的f[x]
int main(int argc, char const *argv[])
{
	cin>>n>>m>>k;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		r[i] = m + 1;//初始值，用来记录有没有管子
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
			int x = min(j + a[i],m);//不能出游戏边界
			f[x] = min(f[x],min(g[j],f[j]) + 1);//加一次
		}
		for(int j = l[i] + 1;j < r[i]; ++j)
		{
			if(j + b[i] <= m)//上一次的边界
			{
				f[j] = min(f[j],g[j + b[i]]);//减一次
			}
		}
		int q = 0;
		for(int j = 1;j <= m;++j)
		{
			if(j >= r[i] || j <= l[i])
			{
				f[j] = 1e9;
			}
			q |= f[j] < 1e8;
		}
		if(!q)
		{
			break;
		}
	}
	int ans = 0;
	if(i > n)
	{
		ans = inf;
		for(int i = 1;i <= m; ++i)
		{
			ans = min(ans,f[i]);
		}
		printf("1\n%d\n",ans);
	}
	else
	{
		for(int j = 1;j < i; ++j)
		{
			if(r[j] <= m)//有管子么？
			{
				ans++;
			}
		}
		printf("0\n%d\n",ans);
	}
	return 0;
}