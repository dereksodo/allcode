#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n;
long long a[maxn];
map<long long,bool> appear;
bool vis[maxn];
long long ans[maxn];
int pos = 0;
map<long long,bool> is_ok;
map<long long,int> mp;
void dfs(long long x,int pos)
{
	if(pos == n)
	{
		ans[pos] = x;
		for(int i = 0;i < n; ++i)
		{
			cout<<ans[i]<<" ";
		}
		exit(0);
	}
	if(!appear[x] || vis[mp[x]])
	{
		return;
	}
	vis[mp[x]] = 1;
	ans[pos] = x;
	if(is_ok[x])
	{
		dfs(x / 3,pos + 1);
	}
	dfs(x * 2,pos + 1);
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		cin>>a[i];
		if(a[i] % 3 == 0)
		{
			is_ok[a[i]] = 1;
		}
		appear[a[i]] = 1;
		mp[a[i]] = i;
	}
	pos = 0;
	for(int i = 0;i < n; ++i)
	{
		memset(vis,0x00,sizeof(vis));
		dfs(a[i],0);
	}
	return 0;
}