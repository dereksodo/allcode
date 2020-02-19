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
const int maxn = 3e4 + 5;
char s[maxn];
int ch[maxn][2],a[maxn],nxt[maxn],tot;
int que[maxn],h,t,vis[maxn],done[maxn];
void insert()
{
	int u = 0,n = strlen(s);
	for(int i = 0;i < n; ++i)
	{
		int c = s[i] - '0';
		int &v = ch[u][c];
		if(!v)
		{
			v = ++tot;
		}
		u = v;
	}
	a[u] = 1;
}
void build()
{
	for(int i = 0;i < 2; ++i)
	{
		if(ch[0][i])
		{
			que[++t] = ch[0][i];
		}
	}
	while(h < t)
	{
		int u = que[++h];
		for(int i = 0;i < 2; ++i)
		{
			int &v = ch[u][i];
			if(v)
			{
				nxt[v] = ch[nxt[u]][i];
				a[v] |= a[nxt[v]];
				que[++t] = v;
			}
			else
			{
				v = ch[nxt[u]][i];
			}
		}
	}
}
void dfs(int x)
{
	vis[x] = done[x] = 1;
	for(int i = 0;i < 2; ++i)
	{
		int v = ch[x][i];
		if(done[v])
		{
			printf("TAK\n");
			exit(0);
		}
		else if(!vis[v] && !a[v])
		{
			dfs(v);
		}
	}
	done[x] = 0;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i)
	{
		scanf("%s",s);
		insert();
	}
	build();
	dfs(0);
	printf("NIE\n");
	return 0;
}