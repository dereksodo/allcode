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
ll sum[maxn << 2],a[maxn],mod;
ll add[maxn << 2],mul[maxn << 2];
void pushup(int rt)
{
	sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % mod;
}
void pushdown(int rt,int len)
{
	if(mul[rt] == 1 && add[rt] == 0)
	{
		return;
	}
	sum[rt << 1] = (sum[rt << 1] * mul[rt] + add[rt] * (len + 1 >> 1)) % mod;
	sum[rt << 1 | 1] = (sum[rt << 1 | 1] * mul[rt] + add[rt] * (len >> 1)) % mod;
	
	mul[rt << 1] = mul[rt << 1] * mul[rt] % mod;
	mul[rt << 1 | 1] = mul[rt << 1 | 1] * mul[rt] % mod;

	add[rt << 1] = (add[rt << 1] * mul[rt] + add[rt]) % mod;
	add[rt << 1 | 1] = (add[rt << 1 | 1] * mul[rt] + add[rt]) % mod;	

	mul[rt] = 1,add[rt] = 0;
}
void build(int rt,int l,int r)
{
	mul[rt] = 1;
	add[rt] = 0;
	if(l == r)
	{
		scanf("%lld",&sum[rt]);
		sum[rt] %= mod;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1,l,mid);
	build(rt << 1 | 1,mid + 1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int left,int right,int fg,ll v)
{
	if(l > right || r < left)
	{
		return;
	}
	if(left <= l && r <= right)
	{
		if(fg == 2)
		{
			add[rt] = (add[rt] + v) % mod;
			sum[rt] = (sum[rt] + (r - l + 1) * v) % mod;
		}
		else
		{
			mul[rt] = mul[rt] * v % mod;
			add[rt] = add[rt] * v % mod;
			sum[rt] = sum[rt] * v % mod;
		}
		return;
	}
	pushdown(rt,r - l + 1);
	int mid = l + r >> 1;
	if(left <= mid)
	{
		update(rt << 1,l,mid,left,right,fg,v);
	}
	if(right > mid)
	{
		update(rt << 1 | 1,mid + 1,r,left,right,fg,v);
	}
	pushup(rt);
}
ll query(int rt,int l,int r,int left,int right)
{
	if(l > right || r < left)
	{
		return 0;
	}
	if(left <= l && r <= right)
	{
		return sum[rt];
	}
	pushdown(rt,r - l + 1);
	int mid = l + r >> 1;
	ll ans = 0;
	if(left <= mid)
	{
		ans += query(rt << 1,l,mid,left,right);
	}
	if(right > mid)
	{
		ans += query(rt << 1 | 1,mid + 1,r,left,right);
	}
	pushup(rt);
	return ans % mod;
}
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%lld",&n,&mod);
	build(1,1,n);
	scanf("%d",&m);
	while(m--)
	{
		int fg,t,g;
		scanf("%d%d%d",&fg,&t,&g);
		if(fg == 3)
		{
			printf("%lld\n",query(1,1,n,t,g));
		}
		else
		{
			ll c;
			scanf("%lld",&c);
			c %= mod;
			update(1,1,n,t,g,fg,c);
		}
	}
	return 0;
}