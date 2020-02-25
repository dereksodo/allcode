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
const int maxn = 1e5 + 7;
const int mod = 1e6;
struct node{
	int l,r,pri,cnt,sz,v;
	#define lc(x) t[x].l
	#define rc(x) t[x].r
	#define p(x) t[x].pri
	#define v(x) t[x].v
	#define s(x) t[x].sz
	#define c(x) t[x].cnt
}t[maxn];
int root,tot,delt;
void upd(int &rt)
{
	s(rt) = s(lc(rt)) + s(rc(rt)) + 1;
}
void lr(int &rt)
{
	int y = rc(rt);
	rc(rt) = lc(y);
	lc(y) = rt;
	s(y) = s(rt);
	upd(rt);
	rt = y;
}
void rr(int &rt)
{
	int y = lc(rt);
	lc(rt) = rc(y);
	rc(y) = rt;
	s(y) = s(rt);
	upd(rt);
	rt = y;
}
void ins(int &rt,int w)
{
	if(!rt)
	{
		rt = ++tot;
		v(rt) = w;
		s(rt) = 1;
		p(rt) = (rand() << 8) % (maxn << 3);
		lc(rt) = rc(rt) = 0;
		return;
	}
	++s(rt);
	if(v(rt) >= w)
	{
		ins(lc(rt),w);
		if(p(lc(rt)) < p(rt))
		{
			rr(rt);
		}
	}
	else
	{
		ins(rc(rt),w);
		if(p(rc(rt)) < p(rt))
		{
			lr(rt);
		}
	}
}
int del(int &rt,int w)//return the sz of deleted items
{
	if(rt == 0)
	{
		return 0;
	}
	if(w > v(rt))
	{
		int res = s(lc(rt)) + 1;
		rt = rc(rt);
		return res + del(rt,w);
	}
	else
	{
		int res = del(lc(rt),w);
		s(rt) -= res;
		return res;
	}
}
int query(int rt,int x)
{
	if(rt == 0)
	{
		return 0;
	}
	if(s(lc(rt)) + 1 == x)
	{
		return v(rt) + delt;
	}
	if(x <= s(lc(rt)))
	{
		return query(lc(rt),x);
	}
	else
	{
		return query(rc(rt),x - s(lc(rt)) - 1);
	}
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n,min_s;
	scanf("%d%d",&n,&min_s);
	char buf[10];
	int sum = 0;
	while(n--)
	{
		int x;
		scanf(" %s %d",buf,&x);
		if(buf[0] == 'I')
		{
			if(x >= min_s)
			{
				ins(root,x - delt);
			}
		}
		else if(buf[0] == 'A')
		{
			delt += x;
		}
		else if(buf[0] == 'S')
		{
			delt -= x;
			sum += del(root,min_s - delt);
		}
		else
		{
			if(x > s(root))
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n",query(root,s(root) - x + 1));
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}