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
#include <numeric>
#include <sstream>
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
const int maxn = 20;
struct rect{
	int x1,x2,y1,y2,c;
	void scan()
	{
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
	}
};
rect rec[maxn];
int vis[maxn],ans,n;
int check(int k)
{
	for(int i = 1;i <= n; ++i)
	{
		if(rec[i].x2 == rec[k].x1 && rec[i].y1 <= rec[k].y2 && !vis[i])
		{
			return 0;
		}
	}
	return 1;
}
void dfs(int c,int has,int t)
{
	if(t >= ans)
	{
		return;
	}
	if(has == n)
	{
		ans = min(ans,t);
		return;
	}
	for(int i = 1;i <= n; ++i)
	{
		if(!vis[i] && check(i))
		{
			if(rec[i].c == c)
			{
				vis[i] = 1;
				dfs(c,has + 1,t);
				vis[i] = 0;
			}
			else
			{
				vis[i] = 1;
				dfs(rec[i].c,has + 1,t + 1);
				vis[i] = 0;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 1;i <= n; ++i)
	{
		rec[i].scan();
	}
	ans = n;
	dfs(-1,0,0);
	cout<<ans<<endl;
	return 0;
}