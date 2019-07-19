#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll r;
struct mat{
	ll a[2][2];
	mat()
	{
		a[0][0] = a[1][1] = 1;
		a[0][1] = a[1][0] = 0;
	}
	void print()
	{
		for(ll i = 0;i < 2; ++i)
		{
			for(ll j = 0;j < 2; ++j)
			{
				printf("%lld ",a[i][j] % r);
			}
			printf("\n");
		}
	}
	const mat operator * (const mat &b)const
	{
		mat result;
		for(ll i = 0;i < 2; ++i)
		{
			for(ll j = 0;j < 2; ++j)
			{
				result.a[i][j] = 0;
				for(ll k = 0;k < 2; ++k)
				{
					result.a[i][j] += a[i][k] * b.a[k][j];
				}
				result.a[i][j] %= r;
			}
		}
		return result;
	}
};
const ll maxn = 100007;

struct segtree{
	mat ret[maxn << 2];//*4
	mat A[maxn];
	ll n;
	void pushup(ll ind)
	{
		ret[ind] = ret[ind << 1] * ret[ind << 1 | 1];
	}
	void build(ll start,ll end,ll ind)
	{
		if(start == end)
		{
			ret[ind] = A[start];
			return;
		}
		ll mid = (start + end) >> 1;
		build(start,mid,ind << 1);
		build(mid + 1,end,ind << 1 | 1);
		pushup(ind);
	}
	mat query(ll left,ll right,ll start,ll end,ll ind)
	{
		if(left <= start && end <= right)
		{
			return ret[ind];
		}
		if(left > end || right < start)
		{
			return mat();
		}
		ll mid = (start + end) >> 1;
		mat ans;
		if(left <= mid)
		{
			ans = ans * query(left,right,start,mid,ind << 1);
		}
		if(mid < right)
		{
			ans = ans * query(left,right,mid + 1,end,ind << 1 | 1);
		}
		return ans;
	}
};
segtree p;
int main(int argc, char const *argv[])
{
	ll n,m;
	cin>>r>>n>>m;
	for(ll i = 1;i <= n; ++i)
	{
		for(ll j = 0;j < 2; ++j)
		{
			for(ll k = 0;k < 2; ++k)
			{
				scanf("%lld",&p.A[i].a[j][k]);
			}
		}
	}
	p.build(1,n,1);
	while(m--)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		p.query(x,y,1,n,1).print();
	}
	return 0;
}