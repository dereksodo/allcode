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
const int maxn = 1e5 + 10;
const int maxm = 10 * maxn;
int type,n,m,tot = 1;
int head[maxn],to[maxm],nxt[maxm];
int in[maxn],out[maxn];
int fg[maxm];
stack<int> ans;
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void dfs(int x)
{
	for(int &i = head[x],y;y = to[i],i;i = nxt[i])
	{
		int cnt = (type == 1 ? i / 2 : i - 1);
		int p = i & 1;
		if(fg[cnt])
		{
			continue;
		}
		fg[cnt] = 1;
		dfs(y);
		if(type == 1)
		{
			ans.push(p ? -cnt : cnt);
		}
		else
		{
			ans.push(cnt);
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&type,&n,&m);
	for(int i = 1,x,y;i <= m; ++i)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		if(type == 1)
		{
			add(y,x);
		}
		out[x]++,in[y]++;
	}
	if(type == 1)
	{
		for(int i = 1;i <= n; ++i)
		{
			if((in[i] + out[i]) & 1)
			{
				printf("NO");
				return 0;
			}
		}
	}
	else
	{
		for(int i = 1;i <= n; ++i)
		{
			if(in[i] != out[i])
			{
				printf("NO");
				return 0;
			}
		}
	}
	for(int i = 1;i <= n; ++i)
	{
		if(head[i])
		{
			dfs(i);
			break;
		}
	}
	if(ans.size() != m)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	while(!ans.empty())
	{
		printf("%d ",ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}