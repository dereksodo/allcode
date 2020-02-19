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
const int maxn = 605;
char s[maxn];
int ch[maxn][30],vis[maxn],nxt[maxn],tot;
int que[maxn],h,t;
int ans[maxn],acnt;
void insert(int x)
{
	int u = 0,n = strlen(s);
	for(int i = 0;i < n; ++i)
	{
		int c = s[i] - 'A';
		if(!ch[u][c])
		{
			ch[u][c] = ++tot;
		}
		u = ch[u][c];
	}
	vis[u] |= 1 << x;
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
				vis[ch[u][i]] |= vis[ch[nxt[u]][i]];
				que[++t] = ch[u][i];
			}
			else
			{
				ch[u][i] = ch[nxt[u]][i];
			}
		}
	}
}
int n;
const int maxm = maxn * (1 << 12);
int an1[maxm],an2[maxm],q1[maxm],q2[maxm],x,y;
int b[maxn][1 << 12];
void print(int y)
{
	if(an1[y])
	{
		print(an1[y]);
		printf("%c",an2[y] + 'A');
	}
}
void solve()
{
	x = y = 1;
	while(x <= y)
	{
		for(int i = 0;i < 26; ++i)
		{
			int u = q1[x],v = q2[x],ind = ch[u][i];
			if(!b[ind][v | vis[ind]])
			{
				an1[++y] = x,an2[y] = i;
				q1[y] = ind;
				q2[y] = v | vis[ind];
				b[ind][v | vis[ind]] = 1;
				if(q2[y] == (1 << n) - 1)
				{
					print(y);
					printf("\n");
					return;
				}
			}
		}
		++x;
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		scanf("%s",s);
		insert(i);
	}
	build();
	solve();
	return 0;
}