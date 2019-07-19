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
const int maxn = 10005;
int n,m,k;
pair<int,int> a[maxn];
pair<int,int> p[maxn];
int inf = INT_MAX;
int ans;
int aaa;
void dfs(int pos,int now,int y)
{
	aaa = max(aaa,pos);
	if(now > ans || y > m)
	{
		return;
	}
	printf("pos = %d,now = %d,y = %d\n",pos,now,y);
	if(pos == n - 1)
	{
		ans = min(ans,now);
		return;
	}
	if(p[pos].first == -1
		|| (y > p[pos].first && y < p[pos].second))
	{
		for(int i = 1;i <= 3; ++i)
		{
			dfs(pos + 1,now + i,y + a[pos].first * i);
		}
		if(y > a[pos].second)
		{
			dfs(pos + 1,now + 1,y - a[pos].second);
		}
	}
	else
	{
		return;
	}
}
int main(int argc, char const *argv[])
{
	aaa = 0;
	freopen("test.txt","r",stdin);
	ans = inf;
	cin>>n>>m>>k;
	for(int i = 0;i < n; ++i)
	{
		scanf("%d %d",&a[i].first,&a[i].second);
		p[i].first = p[i].second = -1;
	}
	for(int i = 0;i < k; ++i)
	{
		int x;
		scanf("%d %d %d",&x,&p[x].first,&p[x].second);
		p[x].second = m - p[x].second + 1; 
	}
	int ret = inf;
	for(int i = 0;i < n; ++i)
	{
		dfs(0,0,i);
		if(ans != inf)
		{
			ret = min(ret,ans);
		}
	}
	if(ret == inf)
	{
		printf("0\n%d\n",aaa);
	}
	else
	{
		printf("1\n%d\n",ret);
	}
	return 0;
}