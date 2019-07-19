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
const int maxn = 1e5 + 5;
int mod;
struct ii{
	ll lazy;
	ll sum;
	ll mul;
	ll times;
};
struct segment_tree{
	ii node[maxn];
	ll ql,qr;
	void pushup(ll index)
	{
		node[index].sum = node[index << 1].sum + node[index << 1 | 1].sum;
		node[index].mul = node[index << 1].mul * node[index << 1 | 1].mul;
		node[index].sum %= mod;
		node[index].mul %= mod;
	}
	void build(ll left,ll right,ll index)
	{
		if(left == right)
		{
			ll x;
			scanf("%lld",&x);
			node[index].sum = node[index].mul = x % mod;
			node[index].lazy = 0;
			return;
 		}
 		ll mid = left + right >> 1;
 		build(left,mid,index << 1);
 		build(mid + 1,right,index << 1 | 1);
 		pushup(index);
	}
	void pushdown(ll ind,ll leftnum,ll rightnum)
	{
		if(add[ind]
		{
			sum[ind << 1] += leftnum * add[ind];
			sum[ind << 1 | 1] += rightnum * add[ind];
			add[ind << 1] += add[ind];
			add[ind << 1 | 1] += add[ind];
			add[ind] = 0;
		}
	}
	ll mult(ll a,ll k)
	{
		if(k == 0)
		{
			return 1;
		}
		if(k == 1)
		{
			return 1;
		}
		a %= mod;
		ll res = mult(a,k / 2);
		res *= res;
		res %= mod;
		if(k & 1)
		{
			res *= k;
		}
		return res % mod;
	}
	//a[index]->c
	void update(ll c,ll left,ll right,ll start,ll end,ll ind)
	{
		if(left <= start && end <= right)
		{
			sum[ind] += c * (end - start + 1);
			mul[ind] *= mult(c,end - start + 1);
			add[ind] += c;
			times[ind] *= c;
			return;
		}
		ll mid = (start + end) >> 1;
		pushdown(ind,mid - start + 1,end - mid);
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
	
	return 0;
}