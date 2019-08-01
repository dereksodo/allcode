#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll a[maxn],b[maxn],n,m;
pair<ll,ll> q[maxn];
ll qi;
struct segment_tree{
	ll op[maxn << 2];
	//             a                 b
	void update(ll left,ll right,ll start,ll end,ll ind)
	{
		if(left == start && end == right)
		{
			op[ind] = qi;
			return;
		}
		ll mid = start + end >> 1;
		if(left < mid)
		{
			update(left,min(mid,right),start,mid,ind << 1);
		}
		if(right > mid)
		{
			update(max(left,mid),right,mid,end,ind << 1 | 1);
		}
	}
	ll query(ll i,ll l,ll r,ll ind)
	{
		if(r - l == 1)
		{
			return op[ind];
		}
		ll mid = l + r >> 1;
		if(i < mid)
		{
			return max(op[ind],query(i,l,mid,id << 1));
		}
		return max(op[ind],query(i,mid,r,id << 1 | 1));
	}
};
segment_tree st;
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&a[i]);
	}
	for(ll i = 1;i <= n; ++i)
	{
		scanf("%lld",&b[i]);
	}
	for(ll i = 1;i <= m; ++i)
	{
		qi = i;
		int op;
		scanf("%d",&op);
		if(op == 2)
		{
			ll x;
			scanf("%lld",&x);
			ll ret = st.query(i,1,n,1);
			if(ret == 0)
			{
				printf("%lld\n",b[x]);
			}
			else
			{
				printf("%lld\n",a[x[ret] - y[ret] + x]);
			}
		}
		else
		{
			ll k;
			scanf("%lld%lld%lld",&q[i].first,&q[i].second,&k);
			st.update(q[i].second,q[i].second + k,1,n,1);
		}
	}
	return 0;
}