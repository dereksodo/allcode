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
const int maxn = 1e5 + 5;
int ch[maxn][26],tot;
int vis[maxn],nxt[maxn],st[maxn];
int que[maxn],h,t;
char s[maxn],ss[maxn];
void insert()
{
	int l = strlen(s);
	int u = 0;
	for(int i = 0;i < l; ++i)
	{
		int c = s[i] - 'a';
		if(!ch[u][c])
		{
			ch[u][c] = ++tot;
		}
		u = ch[u][c];
	}
	vis[u] = l;
}
void build()
{
	for(int i = 0;i < 26; ++i)
	{
		if(ch[0][i])
		{
			que[++t] = ch[0][i];
		}
	}
	while(h < t)
	{
		int u = que[++h];
		for(int i = 0;i < 26; ++i)
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
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%s%d",ss,&n);
	while(n--)
	{
		scanf("%s",s);
		insert();
	}
	build();
	int l = strlen(ss);
	int u = 0;
	int top = 0;
	for(int i = 0;i < l; ++i)
	{
		int c = ss[i] - 'a';
		u = ch[u][c];
		st[++top] = u;
		s[top] = ss[i];
		if(vis[u])
		{
			top -= vis[u];
			u = st[top];
		}
	}
	for(int i = 1;i <= top; ++i)
	{
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}