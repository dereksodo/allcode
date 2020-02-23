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
const int maxn = 1e6 + 7;
const int inf = 1e9 + 10;
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
int root,tot,nodecnt,fg,ans;
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
		p(rt) = (rand() << 8) % maxn;
		lc(rt) = rc(rt) = 0;
		return;
	}
	++s(rt);
	if(v(rt) > w)
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
		return;
	}
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
void query(int k)
{
	int x = querypre(k);
	int y = querynxt(k);
	if(x == -1)
	{
		ans = (ans + v(y) - k) % mod;
		del(root,v(y));
		return;
	}
	if(y == -1)
	{
		ans = (ans + k - v(x)) % mod;
		del(root,v(x));
		return;
	}
	if(k - v(x) <= v(y) - k)
	{
		ans = (ans + k - v(x)) % mod;
		del(root,v(x));
	}
	else
	{
		ans = (ans + v(y) - k) % mod;
		del(root,v(y));
	}
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int m;
	scanf("%d",&m);
	for(int i = 1,opt,x;i <= m; ++i)
	{
		scanf("%d%d",&opt,&x);
		if(!nodecnt)
		{
			fg = opt;
			++nodecnt;
			ins(root,x);
		}
		else if(fg)
		{
			if(opt == 0)
			{
				--nodecnt;
				query(x);
			}
			else
			{
				++nodecnt;
				ins(root,x);
			}
		}
		else
		{
			if(opt == 0)
			{
				++nodecnt;
				ins(root,x);
			}
			else
			{
				--nodecnt;
				query(x);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}