// https://vjudge.net/problem/SPOJ-SEGSQRSS#
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 5;
ll a[maxn];
ll n,q;
struct segment_tree{
	ll t[maxn << 2];
	void pushup(ll x)
	{
		t[x] = t[x << 1] + t[x << 1 | 1];
	}
	void update1(ll c,ll left,ll right,ll start,ll end,ll ind)
	{
		if(left > end || right < start)
		{
			return;
		}
		if(left == right)
		{
			a[left] = c;
			t[ind] = c * c;
			return;
		}
		ll mid = (left + right) >> 1;
		if(start <= mid)
		{
			update1(c,left,mid,start,end,ind << 1);
		}
		if(right > mid)
		{
			update1(c,mid + 1,right,start,end,ind << 1 | 1);
		}
		pushup(ind);
	}
	void update2(ll c,ll left,ll right,ll start,ll end,ll ind)
	{
		if(left > end || right < start)
		{
			return;
		}
		if(left == right)
		{
			a[left] += c; 
			t[ind] = a[left] * a[left];
			return;
		}
		ll mid = (left + right) >> 1;
		if(start <= mid)
		{
			update2(c,left,mid,start,end,ind << 1);
		}
		if(right > mid)
		{
			update2(c,mid + 1,right,start,end,ind << 1 | 1);
		}
		pushup(ind);
	}
	void build(ll x,ll l,ll r)
	{
		if(l == r)
		{
			t[x] = a[l] * a[l];
			return;
		}
		ll mid = l + r >> 1;
		build(x << 1,l,mid);
		build(x << 1 | 1,mid + 1,r);
		pushup(x);
	}
	ll query(ll x,ll l,ll r,ll ql,ll qr)
	{
		if(l >= ql && r <= qr)
		{
			return t[x];
		}
		if(l > qr || r < ql)
		{
			return 0ll;
		}
		ll mid = l + r >> 1;
		ll left_value = query(x << 1,l,mid,ql,qr);
		ll right_value = query(x << 1 | 1,mid + 1,r,ql,qr);
		return left_value + right_value;
	}
};
segment_tree tree;
int main(int argc, char const *argv[])
{
	ll T;
	cin>>T;
	for(int cases = 1;cases <= T; ++cases)
	{
		memset(tree.t,0x00,sizeof(tree.t));
		cin>>n>>q;
		for(ll i = 1;i <= n; ++i)
		{
			scanf("%lld",&a[i]);
		}
		printf("Case %d:\n",cases);
		tree.build(1,1,n);
		while(q--)
		{
			ll flag;
			scanf("%lld",&flag);
			if(flag == 0)
			{
				ll start,end,x;
				scanf("%lld%lld%lld",&start,&end,&x);
				tree.update1(x,1,n,start,end,1);
			}
			else if(flag == 1)
			{
				ll start,end,x;
				scanf("%lld%lld%lld",&start,&end,&x);
				tree.update2(x,1,n,start,end,1);
			}
			else
			{
				ll start,end;
				scanf("%lld%lld",&start,&end);
				printf("%lld\n",tree.query(1,1,n,start,end));
			}
		}
	}
	return 0;
}