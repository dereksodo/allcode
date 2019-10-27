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
const int maxn = 3e5 + 5;
struct edge{
	int value;
	int x,y;
}e[maxn];
struct ans{
	int x,y;
	int pos;
	int value;
	int val;
}qs[maxn];
int n,m,q;
int fa[maxn];
int find(int x)
{
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
bool cmp1(edge x,edge y)
{
	return x.value > y.value;
}
bool cmp2(ans x,ans y)
{
	return x.val > y.val;
}
bool cmp3(ans x,ans y)
{
	return x.pos < y.pos;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i <= m; ++i)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].value);
	}
	sort(e + 1,e + m + 1,cmp1);
	for(int i = 1;i <= q; ++i)
	{
		scanf("%d%d%d",&qs[i].x,&qs[i].y,&qs[i].val);
		qs[i].pos = i;
	}
	sort(qs + 1,qs + 1 + q,cmp2);
	for(int i = 1;i <= n; ++i)
	{
		fa[i] = i;
	}
	int nowpos = 1;
	for(int i = 1;i <= q; ++i)
	{
		while(e[nowpos].value >= qs[i].val && nowpos <= m)
		{
			int fx = find(e[nowpos].x);
			int fy = find(e[nowpos].y);
			if(fx != fy)
			{
				fa[fx] = fy;
			}
			++nowpos;
		}
		int fx = find(qs[i].x);
		int fy = find(qs[i].y);
		if(fx == fy)
		{
			qs[i].value = 1;
		}
	}
	sort(qs + 1,qs + q + 1,cmp3);
	for(int i = 1;i <= q; ++i)
	{
		if(qs[i].value)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}