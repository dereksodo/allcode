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
const int maxn = 2e6 + 7;
const int maxe = 4e4 + 7;
const int inf = 0x3f3f3f3f;
int n,vis[maxn];//Because we have negative numbers, we have to define them before everything
				//there is no exact explanation as far as I know
				//if define after t[],will be judged as RE on loj
				//In c++ compiler u[v] = *(u + v)
				//,which will be completely replaced, like define
				//the compiler will not check it until runnig
				//however, my laptop(Apple) can pass all the data
				//all simple arrays are best defined first
				//hash it, or just simply add an offset, but notice memory use
struct node{
	int l,r,pri,cnt,sz,v;
	#define lc(x) t[x].l
	#define rc(x) t[x].r
	#define p(x) t[x].pri
	#define v(x) t[x].v
	#define s(x) t[x].sz
	#define c(x) t[x].cnt
}t[maxe];
//  whole tree's root
int root,tot;
//        index
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
		v(rt) = w;
		s(rt) = c(rt) = 1;
		p(rt) = rand();//must be random, so 
					   //the height will be
					   //balanced too
		lc(rt) = rc(rt) = 0;
		return;
	}
	++s(rt);
	if(v(rt) == w)
	{
		++c(rt);
	}
	else if(v(rt) > w)
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
int querypre(int w)
{
	int x = root,res = -1;
	while(x)
	{
		if(v(x) < w)
		{
			res = v(x),x = rc(x);
		}
		else
		{
			x = lc(x);
		}
	}
	return res;
}
int querynxt(int w)
{
	int x = root,res = -1;
	while(x)
	{
		if(v(x) > w)
		{
			res = v(x),x = lc(x);
		}
		else
		{
			x = rc(x);
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	int ans = 0;
	srand(time(NULL));
	int w;
	scanf("%d",&w);
	ans += w;
	vis[w] = 1;
	ins(root,w);
	while(--n)
	{
		scanf("%d",&w);
		if(vis[w])
		{
			continue;
		}
		int pre = querypre(w),nxt = querynxt(w);
		if(pre == -1 && nxt != -1)
		{
			pre = nxt;
		}
		if(nxt == -1 && pre != -1)
		{
			nxt = pre;
		}
		ans += min(abs(w - pre),abs(w - nxt));
		ins(root,w);
		vis[w] = 1;
	}
	printf("%d\n",ans);
	return 0;
}