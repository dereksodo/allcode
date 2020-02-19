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
const int maxn = 1e7 + 5;
const int maxm = 1e5 + 5;
int mp[100];
int ch[maxn][4];
int vis[maxn],len[maxm],ind[maxm],nxt[maxn],fa[maxn];
int tot;
char ss[maxn],s[105];
int que[maxn],h,t;
void insert(char *s,int x)
{
	len[x] = strlen(s);
	int u = 0;
	for(int i = 0;i < len[x]; ++i)
	{
		int c = mp[s[i]];
		if(!ch[u][c])
		{
			ch[u][c] = ++tot;
		}
		fa[ch[u][c]] = u;
		u = ch[u][c];
	}
	ind[x] = u;
}
void build(int x)
{
	for(int i = 0;i < 4; ++i)
	{
		if(ch[0][i])
		{
			que[++t] = ch[0][i];
		}
	}
	while(h < t)
	{
		int u = que[++h];
		for(int i = 0;i < 4; ++i)
		{
			if(ch[u][i])
			{
				nxt[ch[u][i]] = ch[nxt[u]][i];
				que[++t] = ch[u][i];
			}
			else
			{
				ch[u][i] = ch[nxt[u]][i];
			}
		}
	}
	for(int i = 0,u = 0,j;i < len[x]; ++i)
	{
		for(j = u = ch[u][mp[ss[i]]];j && !vis[j];j = nxt[j])
		{
			vis[j] = 1;
		}
	}
}
int gans(int x)
{
	int ans = len[x];
	for(int i = ind[x];i;i = fa[i],ans--)
	{
		if(vis[i])
		{
			return ans;
		}
	}
}
int main(int argc, char const *argv[])
{
	mp['S'] = 1;
	mp['W'] = 2;
	mp['N'] = 3;
	int n,m;
	scanf("%d%d%s",&n,&m,ss);
	for(int i = 0;i < m; ++i)
	{
		scanf("%s",s);
		insert(s,i);
	}
	len[m] = strlen(ss);
	build(m);
	for(int i = 0;i < m; ++i)
	{
		printf("%d\n",gans(i));
	}
	return 0;
}