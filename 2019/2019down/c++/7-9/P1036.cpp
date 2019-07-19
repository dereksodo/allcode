#include <bits/stdc++.h>
using namespace std;
int n,k;
const int maxn = 25;
int a[maxn];
int prime(int a)
{
	if(a < 2)
	{
		return 0;
	}
	if(a == 2)
	{
		return 1;
	}
	for(int i = 2;i * i <= a; ++i)
	{
		if(a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int ans;
map<int,int> mp;
void dfs(int step,int now,int sum,int mask)
{
//	for(int i = 1;i <= step; ++i)
//	{
//		printf("	");
//	}
//	printf("nowsum = %d,now = %d,step = %d\n",sum,now,step);
	if(now == k)
	{
		if(!mp[mask])
		{
			ans += prime(sum);
		}
		mp[mask] = 1;
		return;
	}
	for(int i = step + 1;i <= n; ++i)
	{
		dfs(i,now,sum,mask);
		dfs(i,now + 1,sum + a[i],mask | (1 << i));
	}
}
int main(int argc,char const *argv[])
{
	cin>>n>>k;
	for(int i = 1;i <= n; ++i)
	{
		scanf("%d",&a[i]);
	}
	dfs(0,0,0,0);
	printf("%d\n",ans);
	return 0;
}

