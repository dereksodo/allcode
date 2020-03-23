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
const int maxn = 100005;
int head[maxn],to[maxn << 2],nxt[maxn << 2],tot;
void add(int u,int v)
{
	to[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
vector<int> st;
int vis[maxn],dep[maxn],cnt;
void dfs(int u)
{
	st.push_back(u);
	dep[u] = st.size();
	for(int i = head[u];i;i = nxt[i])
	{
		int v = to[i];
		if(!dep[v])
		{
			dfs(v);
		}
		else if(dep[u] - dep[v] + 1 >= cnt)
		{
			printf("2\n%d\n",dep[u] - dep[v] + 1);
			for(int i = dep[v] - 1;i < dep[u]; ++i)
			{
				printf("%d ",st[i]);
			}
			printf("\n");
			exit(0);
		}
	}
	if(!vis[u])
	{
		for(int i = head[u];i;i = nxt[i])
		{
			vis[to[i]] = 1;
		}
	}
	st.pop_back();
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(cnt * cnt < n)
	{
		++cnt;
	}
	for(int i = 0;i < m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	printf("1\n");
	for(int i = 1;cnt; ++i)
	{
		if(!vis[i])
		{
			printf("%d ",i);
			--cnt;
		}
	}
	printf("\n");
	return 0;
}