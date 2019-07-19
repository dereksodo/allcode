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
const int maxn = 50005;
struct ii{
	ll sum;
	ll l_ans;
	ll r_ans;
	ll ans;
};
struct segment_tree{
	ii node[maxn << 2];
	ll ql,qr;
	void pushup(ll index)
	{
		node[index].sum = node[index << 1].sum + node[index << 1 | 1].sum;
		node[index].l_ans = max(node[index << 1].l_ans,node[index << 1].sum + node[index << 1 | 1].l_ans);
		node[index].r_ans = max(node[index << 1 | 1].r_ans,node[index << 1 | 1].sum + node[index << 1].r_ans);
		node[index].ans = max(node[index << 1].ans,max(node[index << 1 | 1].ans,node[index << 1].r_ans + node[index << 1 | 1].l_ans));
	}
	void build(ll left,ll right,ll index)
	{
		if(left == right)
		{
			ll x;
			scanf("%lld",&x);
			node[index].sum = node[index].l_ans = node[index].r_ans = node[index].ans = x;
			return;
 		}
 		ll mid = left + right >> 1;
 		build(left,mid,index << 1);
 		build(mid + 1,right,index << 1 | 1);
 		pushup(index);
	}
	//a[index]->c
	void update(ll c,ll index,ll start,ll end,ll ind)
	{
		if(start == end)
		{
			node[ind].sum = node[ind].l_ans = node[ind].r_ans = node[ind].ans = c;
			return;
		}
		ll mid = (start + end) >> 1;
		if(mid >= index)
		{
			update(c,index,start,mid,ind << 1);
		}
		else
		{
			update(c,index,mid + 1,end,ind << 1 | 1);
		}
		pushup(ind);
	}
	ii query(ll index,ll left,ll right)
	{
		if(ql <= left && right <= qr)
		{
			return node[index];
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
		ii ret,a,b;
		a = query(index << 1,left,mid);
		b = query(index << 1 | 1,mid + 1,right);
		ret.sum = a.sum + b.sum;
		ret.ans = max(a.ans,max(a.r_ans + b.l_ans,b.ans));
		ret.l_ans = max(a.l_ans,a.sum + b.l_ans);
		ret.r_ans = max(b.r_ans,a.r_ans + b.sum);
		return ret;
	}
};
int main(int argc, char const *argv[])
{
	segment_tree s;
	ll n;
	cin>>n;
	s.build(1,n,1);
	ll m;
	cin>>m;
	while(m--)
	{
		ll op,x,y;
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op == 0)
		{
			s.update(y,x,1,n,1);
		}
		else
		{
			s.ql = x;
			s.qr = y;
			printf("%lld\n",s.query(1,1,n).ans);
		}
	}
	return 0;
}