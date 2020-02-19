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
const int inf = 0x3f3f3f3f;
int v,e,ned;
struct Edge{
	int from,to,v,col;
	Edge(){};
	Edge(int a,int b,int c,int d):from(a),to(b),v(c),col(d){};
}eg[maxn];
bool cmp(Edge a,Edge b)
{
	if(a.v == b.v)
	{
		return a.col < b.col;
	}
	return a.v < b.v;
}
int f[maxn],mst;
int ff(int x)
{
	return f[x] == x ? x : (f[x] = ff(f[x]));
}
int check(int s)
{
	for(int i = 1;i <= v; ++i)
	{
		f[i] = i;
	}
	for(int i = 0;i < e; ++i)
	{
		if(!eg[i].col)
		{
			eg[i].v += s;
		}
	}
	sort(eg,eg + e,cmp);
	int cnt = 0,num = 0;
	mst = 0;
	for(int i = 0;i < e; ++i)
	{
		int f1 = ff(eg[i].from);
		int f2 = ff(eg[i].to);
		if(f1 != f2)
		{
			mst += eg[i].v;
			f[f1] = f2;
			cnt += (1 - eg[i].col);
			if(++num == v - 1)
			{
				break;
			}
		}
	}
	for(int i = 0;i < e; ++i)
	{
		if(!eg[i].col)
		{
			eg[i].v -= s;
		}
	}
	return cnt < ned;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&v,&e,&ned);
	int cnt = 0,sum = 0;
	for(int i = 0;i < e; ++i)
	{
		int f,t,vv,c;
		scanf("%d%d%d%d",&f,&t,&vv,&c);
		++f,++t;
		eg[i] = Edge(f,t,vv,c);
		cnt += c;
	}
	int l = -111,r = 111,ans = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid))
		{
			r = mid - 1;
		}
		else
		{
			ans = mst - mid * ned;
			l = mid + 1;
		}
	}
	printf("%d\n",ans);
	return 0;
}