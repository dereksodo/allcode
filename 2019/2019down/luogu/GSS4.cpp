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
using namespace std;
typedef long long ll;
#define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
void read(ll &x)
{
	x = 0;
	char s = getchar();
	while(s < '0' || s > '9')
	{
		s = getchar();
	}
	while(s >= '0' && s <= '9')
	{
		x = x * 10 + s - '0';
		s = getchar();
	}
}
struct ii{
	ll sum;
	ll maxp;
};
const ll maxn = 100005;
struct segment_tree{
	ii node[maxn << 2];
	ll qr,ql;
	void pushup(ll index)
	{
		node[index].sum = node[index << 1].sum + node[index << 1 | 1].sum;
		node[index].maxp = max(node[index << 1].maxp,node[index << 1 | 1].maxp);
	}
	void update(ll index,ll left,ll right)
	{
		if(node[index].maxp <= 1)
		{
			return;
		}
		if(left == right)
		{
			node[index].sum = sqrt(node[index].sum);
			node[index].maxp = node[index].sum;
			return;
		}
		ll mid = (left + right) >> 1;
		if(ql > mid)
		{
			update(index << 1 | 1,mid + 1,right);
			pushup(index);
			return;
		}
		if(qr <= mid)
		{
			update(index << 1,left,mid);
			pushup(index);
			return;
		}
		update(index << 1,left,mid);
		update(index << 1 | 1,mid + 1,right);
		pushup(index);
	}
	void build(ll index,ll left,ll right)
	{
		if(left == right)
		{
			read(node[index].sum);
			node[index].maxp = node[index].sum;
			return;
		}
		ll mid = left + right >> 1;
		build(index << 1,left,mid);
		build(index << 1 | 1,mid + 1,right);
		pushup(index);
	}
	ll query(ll index,ll left,ll right)
	{
		if(ql <= left && right <= qr)
		{
			return node[index].sum;
		}
		ll mid = left + right >> 1;
		if(ql > mid)
		{
			return query(index << 1 | 1,mid + 1,right);
		}
		if(qr <= mid)
		{
			return query(index << 1,left,mid);
		}
		return query(index << 1,left,mid) + query(index << 1 | 1,mid + 1,right);
	}
};
int main(int argc, char const *argv[])
{
	ll n;
	int kase = 0;
	while(scanf("%lld",&n) != EOF)
	{
		printf("Case #%d:\n",++kase);
		segment_tree s;
		s.build(1,1,n);
		ll m;
		read(m);
		while(m--)
		{
			ll op,x,y;
			scanf("%lld%lld%lld",&op,&x,&y);
			if(x > y)
			{
				swap(x,y);
			}
			s.ql = x;
			s.qr = y;
			if(op == 0)
			{
				s.update(1,1,n);
			}
			else
			{
				printf("%lld\n",s.query(1,1,n));
			}
		}
		printf("\n");
	}
	return 0;
}