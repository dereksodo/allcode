#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1e9 + 5;
const int maxn = 10005;
int a[maxn],b[maxn],n,m,k;
int l[maxn],r[maxn];
int f[maxn],g[maxn];
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
int main(int argc, char const *argv[])
{
	// freopen("test.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		r[i] = m + 1;
	}
	while(k--)
	{
		int P;
		scanf("%d",&P);
		scanf("%d%d",&l[P],&r[P]);
	}
	//ok
	int i = 1;
	for(;i <= n; ++i)
	{
		memcpy(g,f,sizeof(f));
		for(int j = 1;j <= m; ++j)
		{
			f[j] = inf;
		}
		//ok
		for(int j = 1;j <= m; ++j)
		{
			int x = min(j + a[i],m);
			f[x] = min(f[x],min(f[j],g[j]) + 1);
		}
		//ok
		debug("f:");
		for(int j = 1;j <= m; ++j)
		{
			debug("%d,",f[j]);
		}
		debug("\n");
        //???
		for(int j = l[i] + 1;j < r[i]; ++j)//l[i]是边界，不能飞到，要加1
		{
			if(j + b[i] <= m)
			{
				//??
				f[j] = min(f[j],g[j + b[i]]);//下降不需要点击屏幕
			}
		}
		//ok	
		debug("f:");
		for(int j = 1;j <= m; ++j)
		{
			debug("%d,",f[j]);
		}
		debug("\n");

		int q = 0;
		for(int j = 1;j <= m; ++j)
		{
			//???
			if(j <= l[i] || j >= r[i])//同上
			{
				f[j] = inf;
			}
			q |= f[j] < 1e8;
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