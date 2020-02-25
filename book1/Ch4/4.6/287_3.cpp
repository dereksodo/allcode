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
struct node{
	int l,r,cnt,sz,v,pri;
	#define lc(x) t[x].l
	#define rc(x) t[x].r
	#define c(x) t[x].cnt
	#define s(x) t[x].sz
	#define v(x) t[x].v
	#define p(x) t[x].pri
}t[maxn];
int tot,root;
void upd(int &rt)
{
	s(rt) = s(lc(rt)) + s(rc(rt)) + c(rt);
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
		s(rt) = c(rt) = 1;
		lc(rt) = rc(rt) = 0;
		v(rt) = w,p(rt) = (rand() << 8) % maxn;
		return;
	}
	++s(rt);
	if(v(rt) == w)
	{
		++c(rt);
	}
	else if(v(rt) >= w)
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
void del(int &rt,int w)
{
	if(rt == 0)
	{
		return;
	}
	if(v(rt) == w)
	{
		if(c(rt) > 1)
		{
			--c(rt),--s(rt);
			return;
		}
		if(!lc(rt) || !rc(rt))
		{
			rt = lc(rt) + rc(rt);
			return;
		}
		if(p(lc(rt)) < p(rc(rt)))
		{
			rr(rt);
			del(rt,w);
		}
		else
		{
			lr(rt);
			del(rt,w);
		}
	}
	else
	{
		--s(rt);
		if(w < v(rt))
		{
			del(lc(rt),w);
		}
		else
		{
			del(rc(rt),w);
		}
	}
}
int querypre(int w)//return pos
{
	int x = root,res = -1;
	while(x)
	{
		if(v(x) <= w)
		{
			res = x,x = rc(x);
		}
		else
		{
			x = lc(x);
		}
	}
	return res;
}
int querynxt(int w)//return pos
{
	int x = root,res = -1;
	while(x)
	{
		if(v(x) >= w)
		{
			res = x,x = lc(x);
		}
		else
		{
			x = rc(x);
		}
	}
	return res;
}
int queryrnk(int w)
{
	int x = root,res = 0;
	while(x)
	{
		if(v(x) == w)
		{
			return res + s(lc(x)) + 1;
		}
		if(v(x) < w)
		{
			res += s(lc(x)) + c(x);
			x = rc(x);
		}
		else
		{
			x = lc(x);
		}
	}
	return res;
}
int querykth(int w)//return pos
{
	int x = root;
	while(x)
	{
		if(s(lc(x)) < w && s(lc(x)) + c(x) >= w)
		{
			return x;
		}
		if(s(lc(x)) >= w)
		{
			x = lc(x);
		}
		else
		{
			w -= s(lc(x)) + c(x);
			x = rc(x);
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int opt,x;
		scanf("%d%d",&opt,&x);
		if(opt == 1)
		{
			ins(root,x);
		}
		else if(opt == 2)
		{
			del(root,x);
		}
		else if(opt == 3)
		{
			printf("%d\n",queryrnk(x));
		}
		else if(opt == 4)
		{
			printf("%d\n",v(querykth(x)));
		}
		else if(opt == 5)
		{
			printf("%d\n",v(querypre(x - 1)));
		}
		else
		{
			printf("%d\n",v(querynxt(x + 1)));
		}
	}
	return 0;
}